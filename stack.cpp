#include "stack.h"

#define equ(stream, item) stream << #item" = " << item << '\n'

stack::stack() : count(0), size(init_size)
{
	logs.open("logs.txt");
	data = new elem_type[init_size];
	logs << "stack was created\n";
}

stack::~stack()
{
	if (data)
		delete[] data;
	logs << "stack was deleted.";
	logs.close();
}

int stack::push(elem_type elem)
{
	if (count == size) {
		data = (elem_type*)realloc(data, sizeof(elem_type) * (size <<= 1));
		logs << "size was changed\n \n";
	}
	if (data) {
		data[count++] = elem;
		logs << "new element was pushed\n";
		logs << "now stack is\n";
		logs << "{ " << data[0];
		for (int i = 1; i < count; i++)
			logs << ", " << data[i];
		logs << " }\n";
		logs << "size = " << size << '\n';
		logs << "count = " << count << "\n \n";
		return 0;
	}
	logs << "data was NULL idk why\n\n";
	return 1;
}

int stack::pop()
{
	if (count)
		--count;
	else {
		logs << "count = 0, pop haven't done\n\n";
		return 1;
	}
	if (count <= size >> 1)
		data = (elem_type*)realloc(data, sizeof(elem_type) * (size >>= 1));
	logs << "top was deleted\n";
	logs << "now stack is\n";
	if (data)
	{
		logs << "{ " << data[0];
		for (int i = 1; i < count; i++)
			logs << ", " << data[i];
		logs << " }\n";
	}
	else
		logs << "NULL\n";
	logs << "size = " << size << '\n';
	logs << "count = " << count << "\n\n";
	return 0;
}

elem_type stack::get_top()
{
	logs << "request for top\n";
	if (count && data) {
		logs << "top was returned\n\n";
		return data[count - 1];
	}
	logs << "top wasn't returned!!\n\n";
	throw -1;
}