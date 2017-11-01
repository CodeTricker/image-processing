#include "Blur.h"

namespace imaging
{
	Image * Blur::apply(Image & src)
	{
		std::cout << "\nApplying Blur Filter...\n";
		Image * image = new Image(src);

		for (unsigned int i = 0; i< src.getWidth(); i++)
		{
			for (unsigned int j = 0; j<src.getHeight(); j++)
			{

				int count = 0;
				float red = 0;
				float blue = 0;
				float green = 0;
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
							red = red + c1.r;
							green = green + c1.g;
							blue = blue + c1.b;
						}
					}
				}
				red = red / count;
				green = green / count;
				blue = blue / count;

				c2.r = red;
				c2.g = green;
				c2.b = blue;

				image->setPixel(i, j, c2);

			}
		}
		std::cout << "The filter was succesfully applied\n";
		return image;


	}


}