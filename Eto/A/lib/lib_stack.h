#ifndef __LIB_STACK_H
#define __LIB_STACK_H

#include "lib_array_list.h"
#include "lib_object.h"
#include "lib_objectcontainer.h"

class lib_stack{
	private:
		lib_array_list stack;
	public:
		lib_stack();
		lib_objectcontainer pop();
		void push(lib_object* obj);
		bool is_empty()const;
};
#endif