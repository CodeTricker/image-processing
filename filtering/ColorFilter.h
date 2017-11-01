#ifndef _COLORFILTER
#define _COLORFILTER

#include "Filter.h"
using namespace std;

namespace imaging
{
	class ColorFilter : public Filter
	{
	protected:

		const Color color;

	public:

		ColorFilter(const Color c) :
			Filter("Color"), color(c) {};

		Color getColor()
		{
			return color;
		}

		virtual Image * apply(Image & src);

		
	};


}
#endif