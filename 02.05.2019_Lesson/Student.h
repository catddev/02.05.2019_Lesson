#pragma once;
#include"human.h"//родительский класс

//операторы ввода вывода для родителей и детей отдельно перегружаются всегда! У каждого свой френд, френды не наследуются!


//указывается от какого класса наследование, если написать public то все методы из родительского public наследуются как public
// class Student: private Human
class Student:public Human {
public:
	/*void print() {
		cout << this->name << " " << surname << " " << age << endl;
	}*/
	Student(): Human(){}
	Student(string name, string surname, int age):Human(name, surname, age){}

};