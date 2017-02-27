#pragma once

#include <fstream>

const size_t init_size = 16;			// size of data after construct

class stack
{
public:
	typedef int value_type;				// type in stack

	stack();							// constructor
	stack(size_t size);					// constructor too
	stack(const stack &);				// copy constructor
	stack(stack &&);					// move constructor
	~stack();							// destructor

	stack &operator=(stack &another);	// copy assignment
	stack &operator=(stack &&another);	// moce assignment

	bool ok();							// ok
	bool dump();						// dump

	bool push(value_type);				// push
	value_type pop();					// pop

	size_t size();						// size of data
	size_t length();					// number of elements
	
	static int obj_counter;				// object counter
private:
	int number;							// object number

	value_type *data_;					// data
	size_t count_;						// counter for elements
	size_t size_;						// size of data
};