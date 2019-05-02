#include "Tutor.h"


void Tutor::setSubject(string subject)
{
	this->subject = subject;
}

void Tutor::print()
{
	Human::print();
	cout << subject << endl;
}
