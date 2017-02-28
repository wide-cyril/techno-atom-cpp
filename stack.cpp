//----------------------------------------------------------------
//! @file Stack.cpp
//! Implements member functions of stack class 
//!
//! @author Kirill Shirokov, 2017
//----------------------------------------------------------------

#include "stack.h"

stack::stack() :
	count_(0), size_(init_size)
{
	data_ = new value_type[init_size];
}

stack::stack(size_t size) :
	count_(0), size_(size)
{
	data_ = new value_type[size];
}

stack::stack(const stack& that) :
	count_(that.count_), size_(that.size_)
{
	ASSERT_OK();
	data_ = new value_type[size_];
	for (int i = 0; i < count_; i++)
		data_[i] = that.data_[i];
}

stack::stack(stack&& that) :
	count_(that.count_), size_(that.size_), data_(that.data_)
{
	ASSERT_OK();
	that.data_ = NULL;
}

stack::~stack()
{
	if (data_)
		delete[] data_;
}

stack &stack::operator=(stack &another)
{
	ASSERT_OK();
	if (this != &another)
	{
		delete[] data_;
		size_ = another.size_;
		count_ = another.count_;
		ASSERT_OK();
		data_ = new value_type[size_];
		for (int i = 0; i < count_; i++)
			data_[i] = another.data_[i];
	}
	ASSERT_OK();
	return *this;
}

stack &stack::operator=(stack &&another)
{
	ASSERT_OK();
	if (this != &another)
	{
		delete[] data_;
		size_ = another.size_;
		count_ = another.count_;
		data_ = another.data_;
		another.data_ = NULL;
	}
	ASSERT_OK();
	return *this;
}

bool stack::ok() const
{
	return !(count_ > size_ || data_ == NULL);
}

bool stack::dump() const
{
	std::ofstream _dump("dump.txt");
	if (_dump.fail())
		return false;

	_dump << "Stack\n{\n"
			<< "\tsize_ = "	   << size_
			<< "\n\tcount_ = " << count_
			<< "\n\tdata_";

	if (data_)
	{
		_dump << "\n\t{";
		for (int i = 0; i < size_; i++)
			_dump << "\n\t\tdata_[" << i << "] = " << data_[i];
		_dump << "\n\t}";
	}
	else
		_dump << "\n\t\tis NULL";
	_dump << '\n}';
	_dump.close();
	return true;
}

bool stack::push(value_type elem)
{
	ASSERT_OK();
	if (count_ == size_)
	{
		value_type *temp = (value_type*)realloc(data_, sizeof(value_type) * (size_ << 1));
		if (temp)
		{
			data_ = temp;
			size_ <<= 1;
		}
		else
			return false;
	}
	data_[count_++] = elem;
	ASSERT_OK();
	return true;
}

stack::value_type stack::pop()
{
	ASSERT_OK();
	int value;
	if (count_)
		value = data_[--count_];
	else
		throw 42;
	if (count_ <= size_ >> 1 && size_ >> 1 > 4)
		data_ = (value_type*)realloc(data_, sizeof(value_type) * (size_ >>= 1));
	ASSERT_OK();
	return value;
}

size_t stack::size() const
{
	return size_;
}

size_t stack::length() const
{
	return count_;
}