#include "Image.h"
#include "ppm_format.h"
#include "Filter.h"
#include "Gray.h"
#include "ColorFilter.h"
#include "Blur.h"
#include "Diff.h"
#include "Median.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

std::string createName(std::string oldname)
{

	std::string new_name;
	std::size_t pos = oldname.find('.');
	std::string strStart = oldname.substr(0, pos);

	new_name.append(strStart);
	new_name.append(".filtered");
	new_name.append(".ppm"); //den mas noiazei ti exei edw


	return new_name;
}



int main(int argc, char *argv[])
{

	imaging::Image * im = new imaging::Image();

	const char * in_filename; //in_filename = to arxeio pou tha diavasei to ppm

	//const char * out_filename;
	std::string out_filename;

	unsigned int width, height;
	float average_r, average_g, average_b;
	float sum_r = 0;
	float sum_g = 0;
	float sum_b = 0;



	if (argc < 2) // argc should be 2 for correct execution
		std::cout << "usage: " << argv[0] << " <filename>\n";	// We print argv[0] assuming it is the program name

	if (argc < 3)
		return 0;


	in_filename = argv[argc-1];

	bool flag_in;

	std::cout << "in_filename = " << in_filename << std::endl;
	std::cout << "in_filename = " << (std::string)in_filename << std::endl;
	flag_in = *im << (std::string)in_filename;
	std::cout << "flag = " << flag_in << std::endl;




	width = im->getWidth();
	height = im->getHeight();



	std::cout << "Image dimensions are: " << width << " X " << height << std::endl;

	Color * buffer = (Color *)im->getRawDataPtr();

	unsigned int buffer_size = width * height;


	std::cout << "size of buffer = " << buffer_size << std::endl;


	////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////


	imaging::Filter *f;

	Color color;

	imaging::Image * newImage = new imaging::Image(*im);
	
	int i = 1;

	while (i < argc - 1)
	{
		if (strcmp(argv[i], "-f") == 0)
		{
			i++;
		}
		else if (strcmp(argv[i], "gray") == 0)
		{
			f = new imaging::Gray();
			newImage = f->apply(*newImage);
			i++;
		}
		else if (strcmp(argv[i], "color") == 0)
		{
			if (atof(argv[i + 1])>1.0f || atof(argv[i + 2])>1.0f || atof(argv[i + 3])>1.0f)
			{
				std::cout << "The colors you selected are out of range.\n";
				break;
			}
			color.r = atof(argv[i + 1]);
			color.g = atof(argv[i + 2]);
			color.b = atof(argv[i + 3]);
			f = new imaging::ColorFilter(color);
			newImage = f->apply(*newImage);

			i = i + 4;
		}
		else if (strcmp(argv[i], "blur") == 0)
		{
			f = new imaging::Blur();
			newImage = f->apply(*newImage);
			i++;
		}
		else if (strcmp(argv[i], "median") == 0)
		{
			f = new imaging::Median();
			newImage = f->apply(*newImage);
			i++;
		}
		else if (strcmp(argv[i], "diff") == 0){
			f = new imaging::Diff();
			newImage = f->apply(*newImage);
			i++;
		}
		else 
		{
			std::cout << "You gave wrong type of arguments\n";
			break;
		}
	}

	out_filename = createName((std::string)in_filename);

	flag_in = *newImage >> out_filename;







	///////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////




	std::cout << "Exiting the program.." << std::endl;

	return 0;
}