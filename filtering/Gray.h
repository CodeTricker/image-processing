#ifndef _GRAY
#define _GRAY

#include "Filter.h"

namespace imaging
{
	class Gray : public Filter
	{
	public:

		Gray() : Filter("Gray"){};

		virtual Image * apply(Image & src);
	};


} //namespace imaging
#endif