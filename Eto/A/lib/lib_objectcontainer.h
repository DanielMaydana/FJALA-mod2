#ifndef LIB_OBJECT_CONTAINER_H
#define LIB_OBJECT_CONTAINER_H

class lib_object;

class lib_objectcontainer
{
	lib_object* obj;
	
public:
	lib_objectcontainer(lib_object*);
	~lib_objectcontainer();
	lib_object& get();
};


#endif
