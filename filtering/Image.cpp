#include <algorithm>
#include "Image.h"
#include "ppm_format.h"
#include <iostream>

using namespace std;
namespace imaging
{

	Color Image::getPixel(unsigned int x, unsigned int y) const
	{
		if (x < getWidth() && y < getHeight())
		{
			int position = x + y*getWidth();

			Color *pixel = new Color();


			pixel->r = buffer[position].r;
			pixel->g = buffer[position].g;
			pixel->b = buffer[position].b;

			return *pixel;
		}

		Color *black = new Color();
		return *black;
	}

	void Image::setPixel(unsigned int x, unsigned int y, Color & value)
	{
		if (x < getWidth() && y < getHeight())
		{
			int position = x + y*getWidth();

			buffer[position].r = value.r;
			buffer[position].g = value.g;
			buffer[position].b = value.b;
		}

	}

	void Image::setData(const Color * & data_ptr)
	{
		if (getWidth() != 0 && getHeight() != 0 && buffer != nullptr) 
		{
			unsigned int buffer_size = getHeight() * getWidth();
			for (unsigned int i = 0; i < buffer_size; i++)
			{
				buffer[i] = data_ptr[i];
			}
		}
	}



	Image::Image() :Array(0, 0){}

	Image::Image(unsigned int width, unsigned int height) :Array(width, height){}

	Image::Image(unsigned int width, unsigned int height, const Color * data_ptr) : Array(width, height)
	{
		Image::setData(data_ptr);

	}

	Image::Image(const Image &src) : Array(src){}

	Image::~Image()
	{
		delete[] buffer;
	}

	Image & Image::operator = (const Image & right)
	{
		cout << "In Image Copy assignment operator!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
		if (this != &right)
		{
		
			width = right.getWidth();
		
			height = right.getHeight();
		
			if (buffer != nullptr)
				delete[] buffer;
			
			buffer = (Color *)calloc(width*height, sizeof(Color));

			memcpy(buffer, right.buffer, width*height*sizeof(Color));

		}

		return *this;

	}



	bool Image::operator << (string filename)
	{
		
		Image * image;
		
		const char * filen = filename.c_str();

		image = ReadPPM(filen);
		
		*this = *image;
		
		
		return true;
	}

	bool Image::operator >> (string filename)
	{
		
		const char * filen = filename.c_str();
		
		bool flag;
				
		flag = WritePPM(*this, filen);
		
		return flag;
	}

}