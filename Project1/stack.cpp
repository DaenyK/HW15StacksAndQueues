#include "Stack.h"

template<typename type>
Stack<type>::Stack()
{
	els = nullptr;
	length = 0;
	buf_size = 0;
}

template<typename type>
Stack<type>::Stack(type * arr, int n)
{
	this->length = n;
	this->els = new type[length];
	this->buf_size = length;
	for (int i = 0; i < length; i++)
		this->els[i] = arr[i];
}

template<typename type>
Stack<type>::Stack(const Stack<type> & obj)
{
	this->length = obj.length;
	this->buf_size = obj.length;
	this->els = new type[length];
	for (int i = 0; i < length; i++)
		this->els[i] = obj.els[i];
}

template<typename type>
Stack<type>::~Stack()
{
	delete[]els;
}

template<typename type>
type & Stack<type>::top()
{
	return els[length - 1];
}

template<typename type>
void Stack<type>::push(type e)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new type[buf_size];
	}

	else if (buf_size <= length)
	{
		buf_size *= 2;
		type * temp = new type[buf_size];
		for (int i = 0; i < length; i++)
			temp[i] = els[i];
		delete[] els;
		els = temp;
	}
	els[length++] = e;
}

template<typename type>
void Stack<type>::pop()
{
	length--;
}

template<typename type>
size_t Stack<type>::size()
{
	return size_t(length);
}

template<typename type>
bool Stack<type>::empty()
{
	return (size() == 0);
}

template<typename type>
void Stack<type>::operator[](type e)
{
	if (buf_size == 0)
	{
		buf_size = 2;
		els = new type[buf_size];
	}
	else if (buf_size <= length)
	{
		buf_size *= 2;
		type * temp = new type[buf_size];
		for (int i = 0; i < length; i++)
		{
			temp[i] = els[i];
		}
		delete[] els;
		els = temp;
	}
	els[length++] = e;
}

template<typename type>
void Stack<type>::operator=(type e)
{
	els = e;
}

template<typename type>
void Stack<type>::operator+(Stack<type> obj)
{
	Stack<type> newStack;
	newStack.length = this->lenght + obj.lenght;
	newStack.els = new type[newStack.length];
	type *a;
		size_t newLen = this->lenght + obj.lenght;
		a = new type[newLen];
	
		for (int i = 0; i < this->lenght; i++)
			a[i] = this->els[i];
		for (int i = this->lenght; i < newLen; i++)
			a[i] = obj.els[i - this->length];
	
		int j;
		for (int i = 0; i < newLen; i++)
		{
			for (j = (newLen - 1); j > i; j--)
			{
				if (a[j - 1] > a[j])
				{
					type temp = a[j - 1];
					a[j - 1] = a[j];
					a[j] = temp;
				}
			}
		}
		for (int i = 0; i < newLen; i++)
		{
			newStack.els[i] = a[i];
			cout << newStack.els[i];
		}
}

//template<typename type>
//void Stack<type>::operator+(Stack<type> obj)
//{
//	Stack<type> newStack;
//
//	newStack.length = this->lenght + obj.lenght;
//	newStack.els = new type[newStack.length];
//
//	//for (int i = 0; i < this->length; i++)
//	//	newStack.els[i] = this->els[i];
//	//for (int i = this->lenght; i < newStack.length; i++)
//	//	newStack.els[i] = obj.els[i - this->length];
//
//	type *a;
//	size_t newLen = this->lenght + obj.lenght;
//	a = new type[newLen];
//
//	for (int i = 0; i < this->lenght; i++)
//		a[i] = this->els[i];
//	for (int i = this->lenght; i < newLen; i++)
//		a[i] = obj.els[i - this->length];
//
//	int j;
//	for (int i = 0; i < newLen; i++)
//	{
//		for (j = (newLen - 1); j > i; j--)
//		{
//			if (a[j - 1] > a[j])
//			{
//				type temp = a[j - 1];
//				a[j - 1] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//	for (int i = 0; i < newLen; i++)
//		newStack.els[i] = a[i];
//}
//
