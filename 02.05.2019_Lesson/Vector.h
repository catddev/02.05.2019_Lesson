#pragma once
#include <iostream>
#include<iomanip>
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
	Vector(const Vector& obj);
	virtual ~Vector();//not pure (!=0)

	virtual int size() = 0;//pure virtual - чистый виртуальный метод (абстрактный), теперь весь класс становится невесомым!
	//теперь этот метод нельзя вызывать здесь, только после реализации у детей
	//реализация обязательно у ребенка, а не у родителя
	//чистый метод обязательно должен быть у всех детей! Если не реализовать, то и ребенок будет абстрактным классом, и нельзя будет создать объект этого класса напрямую
	//абстрактные классы нельзя использовать напрямую, придутся обращаться через child классы

	//Vector<T> operator=(const Vector<T>&obj);
	void add(T el);
	void del();
	T& operator[](int index);
	void operator()(T v);
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
	//cout << "Destruct vector" << endl;
	delete[] els;
}

//template<typename T>
//inline Vector<T> Vector<T>::operator=(const Vector<T>& obj)
//{
//	this->cur_size = obj.cur_size;
//	this->buf_size = obj.cur_size;
//	this->els = new T[buf_size];
//	for (int i = 0; i < cur_size; i++) {
//		els[i] = obj.els[i];
//	}
//	return *this;
//}

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
	else if (cur_size < buf_size)
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

//template<typename T>
//inline int Vector<T>::size()
//{
//	return cur_size;
//}

template<typename T>
inline void Vector<T>::print()
{
	for (int i = 0; i < Vector<T>::cur_size; i++)// cur_size because size() not allowed as it is pure
		cout << setw(5) << left << els[i] << " ";
	cout << endl << endl;
}