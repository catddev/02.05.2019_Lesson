#include"human.h"

Human::Human()
{
	name = "";
	surname = "";
	age = 0;
}

Human::Human(string name, string surname, int age)
{
	this->name = name;
	this->surname = surname;
	this->age = age;
}

string Human::getName()
{
	return name;
}

string Human::getSurname()
{
	return surname;
}

int Human::getAge()
{
	return age;
}

void Human::setName(string n)
{
	name = n;
}

void Human::setSurname(string sn)
{
	surname = sn;
}

void Human::setAge(int age)
{
	this->age = age;
}
