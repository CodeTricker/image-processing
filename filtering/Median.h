#ifndef _MEDIAN
#define _MEDIAN

#include "Filter.h"


namespace imaging
{
	class Median : public Filter
	{
	
	public:

		Median() : Filter("Median"){};

		virtual Image * apply(Image & src);

		
	};
}

#endif