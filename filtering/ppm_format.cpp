#include "ppm_format.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

#include "Image.h"

namespace imaging
{
	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

	enum readState { TYPE = 0, WIDTH, HEIGHT, MAX, PIXEL };

	Image * ReadPPM(const char * filename)
	{

		ifstream file;
		cout << "filename = " << filename << endl;

		file.open(filename, ios::binary);//in);//binary);

		if (!file.is_open())
		{
			cerr << "Counld not open file \n";
			return NULL;
		}

		string type;
		Color * data = (Color *)malloc(sizeof(Color));
		int W = 0;
		int H = 0;
		int max = 0;
		char comment = '#';

		string word;
		readState rst = TYPE;

		while (file >> word)
		{
			if (word[0] == comment)	//an h leji pou diavazoume xekinaei me # tote pareleipse thn kai phda sthn epomenh grammh
			{
				getline(file, word); //getline = diavazei mia olokliri grammi kai paei stthn apo katw		
			}
			else
			{
				switch (rst)
				{
				case TYPE:
					type = word;
					if (type != "P6")
					{
						cerr << "ERROR: Application supports only P6 format \n";
						return NULL;
					}
					cout << "Type: " << type << endl;
					rst = WIDTH;
					break;

				case WIDTH:
					W = atoi(word.c_str());
					cout << "Width: " << W;
					rst = HEIGHT;
					break;

				case HEIGHT:
					H = atoi(word.c_str());
					cout << "Height: " << H;
					rst = MAX;
					break;

				case MAX:
					max = atoi(word.c_str());
					if (max > 255)
					{
						cerr << "ERROR: Application supports only color range 0-255 \n";
						return NULL;
					}
					cout << "Max: " << max;
					rst = PIXEL;
					getline(file, word);
					break;
				}//end switch

				if (rst == PIXEL)
				{

					cout << "Succefully read Image data" << endl;

					data = (Color*)calloc(H*W, sizeof(Color));

					for (int i = 0; i < H*W; i++)
					{
						unsigned char c;

						file.read(reinterpret_cast<char *>(&c), 1);

						data[i].r = (float)c / 255.0f;


						file.read(reinterpret_cast<char *>(&c), 1);

						data[i].g = (float)c / 255.0f;

						file.read(reinterpret_cast<char *>(&c), 1);

						data[i].b = (float)c / 255.0f;
					}

				}//end if

			}//end else



			cout << "End of ppm file." << endl;

		}//end while


		cout << "Type: " << type << endl;

		cout << "Width: " << W << endl;

		cout << "Height: " << H << endl;

		cout << "Max: " << max;



		Image * theImage = new Image(W, H, data);


		Color * buffer = (Color*)theImage->getRawDataPtr();


		return theImage;

		file.close();
	}//end ReadPPM


	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

	bool WritePPM(Image & image, const char * filename)
	{
		ofstream file;


		file.open(filename, ios::binary | ios::out | ios::trunc);

		if (!file.is_open())
		{
			std::cout << "Counld not open file \n"; // mhnyma lathoys
			return false;
		}

		unsigned int w = image.getWidth();
		unsigned int h = image.getHeight();
		Color * buffer = (Color*)image.getRawDataPtr();

		file << "P6";
		file.write(" ", 1);
		file << w;
		file.write(" ", 1);
		file << h;
		file.write(" ", 1);
		file << "255";
		file.write(" ", 1);

		for (unsigned int i = 0; i < h*w; i++)
		{

			unsigned char red = ((unsigned char) (buffer[i].r * 255.0f));
			unsigned char green = ((unsigned char)(buffer[i].g * 255.0f));
			unsigned char blue = ((unsigned char)(buffer[i].b * 255.0f));

			file.write(reinterpret_cast<const char *>(&red), 1);
			file.write(reinterpret_cast<const char *>(&green), 1);
			file.write(reinterpret_cast<const char *>(&blue), 1);

		}

		file.close();

		return true;
	}







	////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////

}//end imaging
