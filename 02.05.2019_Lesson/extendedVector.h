#pragma once
#include"Vector.h"

template <typename T>
class extendedVector:public Vector<T> {
public:
	extendedVector():Vector<T>(){}
	extendedVector(int size):Vector<T>(size){}
	//extendedVector(T* els, int cur_size; int buf_size):Vector(els, cur_size; buf_size){}
	//extendedVector(const extendedVector& obj):Vector<T>(const Vector& obj){}
	~extendedVector();
	void del_front();
	void add_front(T el);

	//void add_pos(T el);
	//void del_pos();
	//void empty();
};

template<typename T>
inline extendedVector<T>::~extendedVector()
{
	delete[] Vector<T>::els;
}

template<typename T>
inline void extendedVector<T>::del_front()
{
	for (int i = 0; i < Vector<T>::size(); i++)
		Vector<T>::els[i] = Vector<T>::els[i + 1];
	Vector<T>::cur_size--;
}

template<typename T>
inline void extendedVector<T>::add_front(T el)
{
	if (Vector<T>::buf_size == 0)
	{
		Vector<T>::buf_size = 4;
		Vector<T>::els = new T[Vector<T>::buf_size];
		Vector<T>::els[0] = el;
		Vector<T>::cur_size++;
	}
	else if (Vector<T>::cur_size == Vector<T>::buf_size) {
			Vector<T>::buf_size *= 2;
			T *tmp = new T[Vector<T>::buf_size];

			tmp[0] = el;
			for (int i = 0; i < Vector<T>::cur_size; i++)
				tmp[i + 1] = Vector<T>::els[i];
			delete[] Vector<T>::els;
			Vector<T>::els = tmp;
			Vector<T>::cur_size++;
			//return;
	}
	else if (this->cur_size < this->buf_size) {
		Vector<T>::els[0] = el;
		for (int i = 0; i < Vector<T>::cur_size; i++)
			Vector<T>::els[i + 1] = Vector<T>::els[i];

		Vector<T>::cur_size++;
	}
}
