#pragma once
#include"Vector.h"

template <typename T>
class extendedVector :public Vector<T> {
public:
	extendedVector() :Vector<T>() {}
	extendedVector(int size) :Vector<T>(size) {}
	//~extendedVector();
	virtual int size();

	void del_front();
	void add_front(T el);

	void del_pos(int pos);
	void add_pos(int pos, T el);

	bool empty();
	//friend ostream& operator<<(ostream& os, const extendedVector<T> & obj);
};

//для наследования шаблонного класса необходимо использовать this->(обращаемся к свойствам и методам данного класса)
//либо Vector<T>::(обращаемся к свойствам и методам родительского класса)

//template<typename T>
//inline extendedVector<T>::~extendedVector()
//{
//	cout << "Destcruct extended vec" << endl;
//	delete[] Vector<T>::els;
//}

template<typename T>
inline int extendedVector<T>::size()
{
	return this->cur_size;
}

template<typename T>
inline void extendedVector<T>::del_front()
{
	for (int i = 0; i < this->size(); i++)
		this->els[i] = this->els[i + 1];
	this->cur_size--;
}

template<typename T>
inline void extendedVector<T>::add_front(T el)
{
	if (this->buf_size == 0)
	{
		this->buf_size = 4;
		this->els = new T[this->buf_size];
		this->els[0] = el;
	}
	else if (this->cur_size == this->buf_size) {
		this->buf_size *= 2;
		T *tmp = new T[this->buf_size];

		for (int i = 0; i < this->cur_size; i++)
			tmp[i + 1] = this->els[i];
		tmp[0] = el;
		delete[] this->els;
		this->els = tmp;
	}
	else if (this->cur_size < this->buf_size) {

		for (int i = 0; i < Vector<T>::cur_size; i++)
			//IMPORTANT: order of elements copyed - from the end as vector is changed from the beginning
			this->els[Vector<T>::cur_size - i] = this->els[this->cur_size - i - 1];
		this->els[0] = el;
	}
	this->cur_size++;
}

template<typename T>
inline void extendedVector<T>::del_pos(int pos)
{
	for (int i = pos; i < this->size(); i++)
		this->els[i] = this->els[i + 1];
	this->cur_size--;
}

template<typename T>
inline void extendedVector<T>::add_pos(int pos, T el)
{
	if (pos >= this->cur_size) {
		this->add(el);
	}
	else if (this->cur_size == this->buf_size) {
		this->buf_size *= 2;
		T *tmp = new T[this->buf_size];

		for (int i = 0; i < this->cur_size; i++) {
			if (i == pos)
				tmp[pos] = el;
			else if (i > pos)
				tmp[i + 1] = this->els[i];
			else
				tmp[i] = this->els[i];
		}
		delete[] this->els;
		this->els = tmp;
		this->cur_size++;
	}
	else if (this->cur_size < this->buf_size) {

		for (int i = pos, j = 0; i < this->cur_size; i++, j++)
			//IMPORTANT: order of elements copyed - from the end as vector is changed from the given position
			this->els[this->cur_size - j] = this->els[this->cur_size - j - 1];
		this->els[pos] = el;

		this->cur_size++;
	}
}

template<typename T>
inline bool extendedVector<T>::empty()
{
	return(this->cur_size == 0);
}

//template<typename T>
//ostream & operator<<(ostream & os, const extendedVector<T> &obj)
//{
//	for (int i = 0; i < this->size(); i++)
//		os << obj.els[i] << " ";
//	return os;
//}