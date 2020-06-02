#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(void) 
{
	List<int> l1;
	List<int> l2;
	l1.init();
	l1.push(10);
	l1.push(30);
	l1.push(50);

	std::cout << "List1: ";
	l1.loop();
	std::cout << std::endl;

	l2.push(11);
	l2.push(33);
	l2.push(55);
	l2.push(56);

	std::cout << "List2: ";
	l2.loop();
	std::cout << std::endl;


	l2.delFromData(55);
	std::cout << "Elements with value 55 deleted from List2" << std::endl;
	std::cout << "List2: ";
	l2.loop();
	std::cout << std::endl;

	std::cout << "List1 + 5 = ";
	l1 + 5;
	l1.loop();
	std::cout << std::endl;

	List<string> l3;
	l3.push("Test");
	l3.push("Test1");
	l3.push("Test2");

	std::cout << "List3: ";
	l3.loop();
	std::cout << std::endl;

	l3.clear();
	std::cout << "List3: ";
	l3.loop();
	std::cout << std::endl;




	system("pause");
	return 0;
}