#ifndef _DIFF
#define _DIFF

#include "Filter.h"

namespace imaging
{
	class Diff : public Filter
	{

	public:

		Diff() : Filter("Diff"){};

		virtual Image * apply(Image & src);
					
	};
}

#endif