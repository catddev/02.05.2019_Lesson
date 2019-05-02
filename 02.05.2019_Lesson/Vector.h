#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Vector {
protected:
	T *els;
	int cur_size;
	int buf_size;
public:
	Vector();
	Vector(int size);
	//Vector(T*els, int cur_size, int buf_size);
	Vector(const Vector& obj);
	~Vector();

	Vector<T> operator=(const Vector<T>&obj);
	void add(T el);
	void del();
	T& operator[](int index);
	void operator()(T v);
	int size();
	void print();

};

template<typename T>
inline Vector<T>::Vector()
{
	els = NULL;
	cur_size = 0;
	buf_size = 0;
}

template<typename T>
inline Vector<T>::Vector(int size)
{
	cur_size = 0;
	buf_size = size;
	els = new T[buf_size];
}

//template<typename T>
//inline Vector<T>::Vector(T * els, int cur_size, int buf_size)
//{
//	this->cur_size = cur_size;
//	this->buf_size = buf_size;
//	delete[] this->els;
//	this->els = els;
//}

template<typename T>
inline Vector<T>::Vector(const Vector & obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.buf_size;
	for (int i = 0; i < cur_size; i++)
		els[i] = obj.els[i];
}

template<typename T>
inline Vector<T>::~Vector()
{
	delete[] els;
}

template<typename T>
inline Vector<T> Vector<T>::operator=(const Vector<T>& obj)
{
	this->cur_size = obj.cur_size;
	this->buf_size = obj.cur_size;
	this->els = new T[buf_size];
	for (int i = 0; i < cur_size; i++) {
		els[i] = obj.els[i];
	}
	return *this;
}

template<typename T>
inline void Vector<T>::add(T el)
{
	if (buf_size == 0)
	{
		buf_size = 4;
		els = new T[buf_size];
		els[cur_size++] = el;
	}
	else if (cur_size == buf_size) {
			buf_size *= 2;
			T *tmp = new T[buf_size];

			for (int i = 0; i < cur_size; i++)
				tmp[i] = els[i];
			delete[] els;
			els = tmp;
			els[cur_size++] = el;
	}
	else 
		els[cur_size++] = el;
}

template<typename T>
inline void Vector<T>::del()
{
	cur_size--;
}

template<typename T>
inline T & Vector<T>::operator[](int index)
{
	return els[index];
}

template<typename T>
inline void Vector<T>::operator()(T v)
{
	for (int i = 0; i < cur_size; i++)
		els[i] = v;
}

template<typename T>
inline int Vector<T>::size()
{
	return cur_size;
}

template<typename T>
inline void Vector<T>::print()
{
	for (int i = 0; i < Vector<T>::size(); i++)
		cout << els[i] << endl;
	cout << endl;
}
