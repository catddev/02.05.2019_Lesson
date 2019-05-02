#pragma once;
#include"human.h"

class Tutor:public Human {
private:
	string subject;
public:
	Tutor() :Human() {};
	Tutor(string name, string surname, int age, string subject) :Human(name, surname, age) {
		this->subject = subject;
	}
	void setSubject(string subject);
	void print();
};