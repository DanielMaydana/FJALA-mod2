#include "lib_objectcontainer.h"

#include "lib_object.h"

lib_objectcontainer::lib_objectcontainer
		(lib_object* obj)
	: obj { obj }
{
}

lib_objectcontainer::~lib_objectcontainer()
{
	delete obj;
}

lib_object& lib_objectcontainer::get()
{	
	return *obj;
}

