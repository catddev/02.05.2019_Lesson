#include "Student.h"

void Student::print()
{
	Human::print();
	cout << group << " " << grade << endl;
}
ostream & operator<<(ostream & os, Student obj)
{
	os << obj.name << " " << obj.surname << " " << obj.age << " " << obj.group << " " << obj.grade << endl;
	return os;
}