#include "ColorFilter.h"


namespace imaging
{
	Image * ColorFilter::apply(Image & src)
	{
		std::cout << "Applying Color Filter...\n";

		Image * image = new Image(src);

		float red, green, blue;
		Color cl = getColor();
		Color color;

		red = cl.r;
		green = cl.g;
		blue = cl.b;

		for (unsigned int i = 0; i<src.getWidth(); i++)
		{
			for (unsigned int j = 0; j<src.getHeight(); j++)
			{

				color = src.getPixel(i, j);
				color.r = red * color.r;
				color.g = green * color.g;
				color.b= blue * color.b;
				image->setPixel(i, j, color);


			}
		}
		std::cout << "The filter was succesfully applied\n";
		return image;
	}



}
