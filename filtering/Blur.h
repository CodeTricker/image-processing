#ifndef _BLR
#define _BLR

#include "Filter.h"

namespace imaging
{
	class Blur : public Filter
	{
	
	public:
	
		Blur() : Filter("Blur"){};

		virtual Image * apply(Image & src);

		
	};

}
#endif

