#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm>
#include <initializer_list>

template<typename T>
class Vector {
public:
	explicit Vector(int initSize = 0) :theSize(initSize),
		theCapacity(initSize + SPARE_CAPACITY)
	{	object = new T[theCapacity];	}
	Vector(const Vector&rhs) :theSize(rhs.theSize), theCapacity(rhs.theCapacity), object(nullptr)
	{
		object = new T[theCapacity];
		for (int k = 0; k < theSize; ++k)
			object[k] = rhs.object[k];
		}
	Vector(const std::initializer_list<T> il):theSize(il.size()),theCapacity(il.size()), object(nullptr)
	{
		int i = 0;
		object = new T[theSize];
		for (auto x : il)
			object[i++] = x;
	}
	Vector & operator=(const Vector&rhs)
	{
		Vector newdata = rhs;
		std::swap(*this, newdata);
		return *this;
	}
	~Vector() {
		delete[] object;
	}
	Vector(Vector &&rhs):theSize(rhs.theSize),theCapacity(rhs.theCapacity),object(rhs.object)
	{
		rhs.object = nullptr;
		rhs.theCapacity = 0;
		rhs.theSize = 0;
	}
	Vector & operator=(Vector &&rhs)
	{
		std::swap(theSize, rhs.theSize);
		std::swap(theCapacity, rhs.theCapacity);
		std::swap(object, rhs.object);
		return *this;
	}
	void resize(int newSize)
	{
		if (newSize > theCapacity)
			reserve(newSize * 2);
		theSize = newSize;
	}
	void reserve(int newCapacity)
	{
		if (newCapacity < theSize)
			return;
		auto newdata = new T[newCapacity];
		for (int k = 0; k < theSize; ++k)
			newdata[k] = std::move(object[k]);

		theCapacity = newCapacity;
		std::swap(object, newdata);
		delete[] newdata;
	}
	T & operator[](int index)
	{
		return objects[index];
	}
	const 	T & operator[](int index) const
	{
		return objects[index];
	}
	bool empty()const
	{
		return size() == 0;
	}
	int size()const
	{
		return theSize;
	}
	int capacity()const
	{
		return theCapacity;
	}
	void push_back(const T&x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		object[theSize++] = x;
	}
	void push_back(T&&x)
	{
		if (theSize == theCapacity)
			reserve(2 * theCapacity + 1);
		object[theSize++] = std::move(x);
	}
	void pop_back()
	{
		--theSize;
	}
	const T & back() const
	{
		return object[theSize - 1];
	}
	
	typedef T* iterator;
	typedef const T* const_iterator;

	iterator  begin()	{	return &object[0];}
	const const_iterator cbegin()const { return &object[0]; }
	iterator end()	{	return &object[size()];	}
	const const_iterator cend() const { return &object[size()]; }

	static const int SPARE_CAPACITY = 16;
private:
	int theSize;
	int theCapacity;
	T * object;
};


#endif // !VECTOR_H
