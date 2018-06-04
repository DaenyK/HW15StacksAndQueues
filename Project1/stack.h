#pragma once
#include "Headers.h"

template <typename type>
class Stack
{
private:
	type * els;
	size_t length;
	size_t buf_size;
public:
	Stack();
	Stack(type * arr, int n);
	Stack(const Stack<type> & obj);
	virtual ~Stack();

	type & top();
	void push(type e);
	void pop();
	size_t size();
	bool empty();
	void operator[](type e);
	void operator = (type e);

	void operator+(Stack <type> obj);
};