#ifndef _FILTER
#define _FILTER

#include <algorithm>
#include <iostream>
#include "Image.h"
using namespace std;

namespace imaging
{

	/*! Abstract class Filter is the common core for specialized filters.
	*/

	class Filter
	{
		protected:

			const string name;

		public:

			/*! Constructor with the name of the filter.
			*
			* \param filter_name is the desired name of the filter.
			*/
			Filter(string filter_name) :
				name(filter_name){};

			/*! Reports the name of the filter
			*
			* \return the name
			*/
			const string getName() 
			{
				return name; 
			}
			/*! Applies the filter to the image.
			*
			* \param src is the source image to apply the filter
			*
			* \return a pointer to a new Image object.
			*/
			virtual Image * apply(Image & src) = 0; //amigws virtual
	};


} //namespace imaging
#endif