#include "stack.h"

#define equ(stream, item) stream << #item" = " << item << '\n'
#define NOWSTACK(num)	logs_ << "now stack #" << num << " is\n";\
						if (data_)\
						{\
							logs_ << "{ ";\
							if (count_)\
								logs_ << data_[0];\
							for (int i = 1; i < count_; i++)\
								logs_ << ", " << data_[i];\
							logs_ << " }\n";\
						}\
						else\
							logs_ << "NULL\n";\
						equ(logs_,size_);\
						equ(logs_,count_) << '\n';

int stack::obj_counter = 0;
std::ofstream logs_;

stack::stack() : count_(0), size_(init_size)
{
	data_ = new value_type[init_size];
	if (obj_counter == 0)
		logs_.open("logs_.txt");
	logs_ << "stack #" << (number = ++obj_counter) << " was created\n";
	NOWSTACK(number);
}

stack::stack(size_t size) : count_(0), size_(size)
{
	data_ = new value_type[size];
	if (obj_counter == 0)
		logs_.open("logs_.txt");
	logs_ << "stack #" << (number = ++obj_counter) << " was created\n";
	NOWSTACK(number);
}

stack::stack(const stack& that): count_(that.count_), size_(that.size_)
{
	logs_ << "copy constructor was called\n";
	data_ = new value_type[size_];
	for (int i = 0; i < count_; i++)
		data_[i] = that.data_[i];
	logs_ << "stack #" << (number = ++obj_counter) << " was created\n";
	NOWSTACK(number);
}

stack::stack(stack&& that) : count_(that.count_), size_(that.size_)
{
	logs_ << "move constructor was called\n";
	data_ =	that.data_;
	that.data_ = NULL;
	logs_ << "stack #" << (number = ++obj_counter) << " was created\n";
	NOWSTACK(number);
}

stack::~stack()
{
	if (data_)
		delete[] data_;
	logs_ << "stack #" << number << " was deleted\n";
	if(--obj_counter == 0)
		logs_.close();
}

stack &stack::operator=(stack &another)
{
	logs_ << "operator=(copy) was called\n";
	if (this != &another) {
		delete[] data_;
		size_ = another.size_;
		count_ = another.count_;
		data_ = new value_type[size_];
		for (int i = 0; i < count_; i++)
			data_[i] = another.data_[i];
		NOWSTACK(number);
	}
	else
		logs_ << "this == another\n";
	return *this;
}

stack &stack::operator=(stack &&another)
{
	logs_ << "operator=(move) was called\n";
	if (this != &another) {
		delete[] data_;
		size_ = another.size_;
		count_ = another.count_;
		data_ = another.data_;
		another.data_ = NULL;
		NOWSTACK(number);
	}
	else
		logs_ << "this == another\n";
	return *this;
}

bool stack::ok()
{
	return true;
}

bool stack::dump()
{
	return true;
}

bool stack::push(value_type elem)
{
	if (count_ == size_) {
		data_ = (value_type*)realloc(data_, sizeof(value_type) * (size_ <<= 1));
		logs_ << "size_ was changed\n \n";
	}
	if (data_) {
		data_[count_++] = elem;
		logs_ << "new element was pushed\n";
		NOWSTACK(number);
		return 0;
	}
	logs_ << "data_ was NULL idk why\n\n";
	return 1;
}

stack::value_type stack::pop()
{
	int value;
	if (count_)
		value = data_[--count_];
	else {
		logs_ << "count_ = 0, pop wasn't done\n\n";
		
	}
	if (count_ <= size_ >> 1)
		data_ = (value_type*)realloc(data_, sizeof(value_type) * (size_ >>= 1));
	logs_ << "top was deleted\n";
	NOWSTACK(number);
	return value;
}

size_t stack::size()
{
	return size_;
}

size_t stack::length()
{
	return count_;
}