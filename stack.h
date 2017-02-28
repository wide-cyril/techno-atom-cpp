#pragma once

#include <fstream>

class stack
{
public:
	typedef int value_type;				// type in stack

	stack();							// constructor
	stack(size_t);						// constructor too
	stack(const stack &);				// copy constructor
	stack(stack &&);					// move constructor
	~stack();							// destructor

	stack &operator=(stack &);			// copy assignment
	stack &operator=(stack &&);			// move assignment

	bool ok() const;					// ok
	bool dump() const;					// dump

	bool push(value_type);				// push
	value_type pop();					// pop

	size_t size() const;				// size of data
	size_t length() const;				// number of elements

private:
	static const size_t init_size = 4;	// default size of data

	value_type *data_;					// data
	size_t count_;						// counter for elements
	size_t size_;						// size of data
};