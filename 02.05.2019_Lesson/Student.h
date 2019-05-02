#pragma once;
#include"human.h"//родительский класс

//операторы ввода вывода для родителей и детей отдельно перегружаются всегда! У каждого свой френд, френды не наследуются!


//указывается от какого класса наследование, если написать public то все методы из родительского public наследуются как public
// class Student: private Human
class Student:public Human {
private:
	string group;
	int grade;
public:
	/*void print() {
		cout << this->name << " " << surname << " " << age << endl;
	}*/
	Student(): Human(){}
	//конструкторы для родителей и детей прописывать отдельно!
	Student(string name, string surname, int age, string group, int grade):Human(name, surname, age){
		this->group = group;
		this->grade = grade;
	}
	//когда для ребенка пишем свой принт(), то родительский принт деактивируется
	//но если его назвать по другому, то родительский принт будет работать
	void print();

};