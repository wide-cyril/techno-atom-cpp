#pragma once

#include <fstream>
#include <iostream>

typedef int elem_type;

const unsigned init_size = 16;

class stack
{
	elem_type *data;
	unsigned count;
	unsigned size;
	std::ofstream logs;
public:
	stack();
	~stack();
	int push(elem_type);
	int pop();
	elem_type get_top();
};