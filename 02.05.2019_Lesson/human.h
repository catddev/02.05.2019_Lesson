#pragma once
#include<string>
#include<iostream>
using namespace std;

class Human {
protected: //чтобы у дочернего класса private свойства опеределялись как public а не private и были доступны методам дочернего класса
	string name;
	string surname;
//private:
	int age;
public:
	Human();
	Human(string name, string surname, int age);
	void print() {
		cout << name << " " << surname << " " << age << endl;
	}

	string getName();
	string getSurname();
	int getAge();
	
	void setName(string n);
	void setSurname(string sn);
	void setAge(int age);

};