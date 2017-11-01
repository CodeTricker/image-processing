#include "Gray.h"



namespace imaging
{
	
	Image * Gray::apply(Image & src)
	{
		std::cout << "\n Applying gray filter...\n";
		Color color;
		//unsigned int m;
		float m;
		Image * image = new Image(src);

		for (unsigned int i = 0; i<src.getWidth(); i++)
		{
			for (unsigned int j = 0; j <src.getHeight(); j++)
			{
				color = src.getPixel(i, j);
				//m = (unsigned int)(color.r + color.g + color.b) / 3;
				m = (color.r + color.g + color.b) / 3;
				color.r = m;
				color.g = m;
				color.b = m;
				image->setPixel(i, j, color);
			}
		}

		std::cout << "The filter was succesfully applied\n";
		
		return image;
	}


}