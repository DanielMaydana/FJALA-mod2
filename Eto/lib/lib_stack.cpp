#include "lib_stack.h"


lib_stack::lib_stack()
{
	
}

lib_objectcontainer lib_stack::pop()
{
	lib_object& obj = stack.get(stack.length()-1);
	stack.decrease_length();
	
	return lib_objectcontainer { &obj };
}

void lib_stack::push(lib_object* obj)
{
	stack.add(obj);
}

bool lib_stack::is_empty()const
{
	return stack.length()==0;	
}