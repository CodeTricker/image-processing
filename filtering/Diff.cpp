#include "Diff.h"
#include <vector> 

namespace imaging
{
	Image * Diff::apply(Image & src)
	{
		std::cout << "Applying Diff Filter...\n";
		vector<float> vred;
		vector<float> vgreen;
		vector<float> vblue;
		//Color vred;
		//Color vgreen;
		//Color vblue;

		Image * image = new Image(src);


		for (unsigned int i = 0; i< src.getWidth(); i++)
		{
			for (unsigned int j = 0; j<src.getHeight(); j++)
			{
				int count = 0;
				float red = 0;
				float green = 0;
				float blue = 0;

				Color c1;
				Color c2;
				for (int m = -1; m <= 1; m++)
				{
					for (int n = -1; n <= 1; n++)
					{

						if ((i + m<src.getWidth()) && ((int)i + m >= 0) && (j + n<src.getHeight()) && ((int)j + n >= 0))
						{

							count++;
							c1 = src.getPixel((int)i + m, (int)j + n);

							red = c1.r;
							green = c1.g;
							blue = c1.b;

							vred.push_back(red);
							vgreen.push_back(green);
							vblue.push_back(blue);
						}
					}
				}


				std::sort(vred.begin(), vred.end());
				std::sort(vgreen.begin(), vgreen.end());
				std::sort(vblue.begin(), vblue.end());


				c2.r = vred[vred.size() - 1] - vred[0];
				c2.g = vgreen[vgreen.size() - 1] - vgreen[0];
				c2.b = vblue[vblue.size() - 1] - vblue[0];
				image->setPixel(i, j, c2);

				vred.clear();
				vblue.clear();
				vgreen.clear();
			}
		}

		std::cout << "The filter was succesfully applied\n";
		return image;
	}


}