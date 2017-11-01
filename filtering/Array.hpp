//------------------------------------------------------------
//
// C++ course assignment code 
//
// G. Papaioannou, 2016
//
//

#ifndef _ARRAY_IMPLEMENTATION_
#define _ARRAY_IMPLEMENTATION_

#include "Array.h"
#include "Vec3.h"
#include <iostream>
using namespace std;

namespace math
{

	template <typename T>
	void * const Array<T>::getRawDataPtr()
	{
		return buffer;
	}

	template <typename T>
	T & Array<T>::operator () (int x, int y)
	{
			int position = x + y*getWidth();

			T *element;
			
			element = buffer[position];

			return *element;	
	}

	template <typename T>
	const T & Array<T>::operator () (int x, int y) const
	{
			int position = x + y*getWidth();

			T *element;
			
			element = buffer[position];

			return *element;		
	}

	template <typename T>
	Array<T>::Array(unsigned int w, unsigned int h)
	{
		
		width = w;
		height = h;
		buffer = (T *)calloc(width*height, sizeof(T));
		
	}

	template <typename T>
	Array<T>::Array(const Array<T> & source)
	{
		width = source.getWidth();
		
		height = source.getHeight();
		
		buffer = (T *)calloc(width*height, sizeof(T));
		
		memcpy(buffer, source.buffer, width*height*sizeof(T));
	}

	template <typename T>
	Array<T> & Array<T>::operator = (const Array<T> & source)
	{
		if (this != &right)
		{
			width = source.getWidth();

			height = source.getHeight();

			if (buffer != nullptr)
				delete[] buffer;

			buffer = (component_t *)calloc(3 * width*height, sizeof(Vec3<T>));

			buffer = (T*)calloc(width*height, sizeof(T));

			memcpy(buffer, right.buffer, width*height*sizeof(T));
		}

		return *this;
	}

	template <typename T>
	bool Array<T>::operator == (const Array<T> & right) const
	{
		bool flag = true;

		if (getwidth() == right.getWidth() && getHeight() == right.getHeight())
		{
			for (unsigned int i = 0; i < getWidth()*getHeight; i++)
			{
				if (buffer[i] != right.buffer[i])
					flag = false;
			}
		}
		else
		{
			flag = false;
		}

		return flag;
	}

	template <typename T>
	void Array<T>::resize(unsigned int new_width, unsigned int new_height)
	{
		if (getWidth() != 0 && getHeight() != 0 && buffer != nullptr) //&&buffer is allocated
		{

				unsigned int min_width = 0;
				unsigned int min_height = 0;
				unsigned int new_buffer_size = new_width * new_height;
				T * new_buffer = (T *)calloc(new_buffer_size, sizeof(T));

				if (new_width < getWidth())
					min_width = new_width;
				else
					min_width = getWidth();

				if (new_height < getHeight())
					min_height = new_height;
				else
					min_height = getHeight();


				for (unsigned int i = 0; i < min_width; i++)
				{
					for (unsigned int j = 0; j < min_height; j++)
					{
						new_buffer[i + j*new_width] = buffer[(i + j*getWidth())];
					}
				}
				delete [] buffer;
				buffer = new_buffer;
				width = new_width;
				height = new_height;


		}//end first if
		else
		{
			width = new_width;
			height = new_height;
			buffer = (T *)calloc(new_width*new_height, sizeof(T));
		}
	}
	//}



	template <typename T>
	Array<T>::~Array()
	{
		delete[] buffer;
	}



}// namespace math

#endif
