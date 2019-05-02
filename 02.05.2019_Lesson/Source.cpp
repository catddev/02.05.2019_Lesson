#include"Student.h"
#include"Tutor.h"
#include"extendedVector.h"

int main() {
	Student s("name", "surname", 18, "smp-182", 100);
	s.print(); //несмотря на то, что print() - это метод класса Human, он доступен классу студент из родителського класса

	s.setName("Denis");
	s.print();

	cout << endl << endl;
	Tutor t("aaa", "bbb", 30, "C++");
	t.print();
	t.setName("Anton");
	t.setSurname("Makarenko");
	t.setAge(55);
	t.setSubject("Literature");
	t.print();

	extendedVector<int> eV;

	//777???
	
	//for (int i = 0; i < 5; i++) {
	//	eV.add_front(100);
	//	eV.add(777);//why not first?
	//	//eV.add_front(100);
	//}
	for (int i = 0; i < 5; i++)
	{
		eV.add_front(333);
		eV.add(777);
	}
	
	//eV.del();
	//eV.del_front();
	cout << endl;
	eV.print();

	system("pause");
	return 0;
}