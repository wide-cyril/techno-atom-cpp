//----------------------------------------------------------------
//! @file Stack.h
//! Defines a stack class
//!
//! @author Kirill Shirokov, 2017
//----------------------------------------------------------------


#pragma once

#include <fstream>
#include <assert.h>

//----------------------------------------------------------------
//! Macro to test object integrity
//----------------------------------------------------------------
#define ASSERT_OK()					\
	if (!ok())						\
	{								\
		dump();						\
		assert(!"stack is ok");		\
	}

//----------------------------------------------------------------
//! Stack class
//----------------------------------------------------------------

class stack
{
public:
	typedef int value_type;				//!< Element type

//----------------------------------------------------------------
//! Default constructor
//----------------------------------------------------------------
	stack();

//----------------------------------------------------------------
//! Consturctor with parameter
//!
//! @param size Size of stack data array
//----------------------------------------------------------------
	stack(size_t);

//----------------------------------------------------------------
//! Copy constructor
//!
//! @param that const lvalue reference to the object
//----------------------------------------------------------------
	stack(const stack &);

//----------------------------------------------------------------
//! Move constructor
//!
//! @param that rvalue reference to the object
//----------------------------------------------------------------
	stack(stack &&);

//----------------------------------------------------------------
//! Destructor
//----------------------------------------------------------------
	~stack();

//----------------------------------------------------------------
//! Copy assignment
//!
//! @param another lvalue reference to the object
//!
//! @return lvalue reference to this object
//----------------------------------------------------------------
	stack &operator=(stack &);

//----------------------------------------------------------------
//! Move assignment
//!
//! @param another rvalue reference to the object
//!
//! @return lvalue reference to this object
//----------------------------------------------------------------
	stack &operator=(stack &&);

//----------------------------------------------------------------
//! Silent verifier
//!
//! @return Is object ok or broken
//----------------------------------------------------------------
	bool ok() const;

//----------------------------------------------------------------
//! Dumper
//!
//! @return Has dump made successfully
//----------------------------------------------------------------
	bool dump() const;

//----------------------------------------------------------------
//! Add element to the stack
//!
//! @param elem The element to be added
//!
//! @return Have adding done successfully
//----------------------------------------------------------------
	bool push(value_type);

//----------------------------------------------------------------
//! Remove element from the stack
//! It'll throw exception(int), if stack is empty
//!
//! @param elem The element to be removed
//!
//! @return Element that was removed
//----------------------------------------------------------------
	value_type pop();

//----------------------------------------------------------------
//! Stack data capacity
//!
//! @return Stack data capacity
//----------------------------------------------------------------
	size_t size() const;

//----------------------------------------------------------------
//! Number of elements in the stack
//!
//! @return Number of elements in the stack
//----------------------------------------------------------------
	size_t length() const;

private:
	static const size_t init_size = 4;	//!< Default size of data
	value_type *data_;					//!< Data
	size_t count_;						//!< Counter for elements
	size_t size_;						//!< Size of data
};
