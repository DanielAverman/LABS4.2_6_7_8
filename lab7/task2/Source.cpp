#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

template<class c>
class set {
	int size = 0;
	c* values = new c[size];
public:

	void add(c value) {
		c* tmp = new c[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = values[i];
		}
		tmp[size] = value;
		values = tmp;
		size++;
	}
	c* retMas() {
		return values;
	}

	set<c> operator+(const set<c> & right) {
		set<c> tmp;
		tmp = *this;
		for (int i = 0; i < size; i++) {
			bool ch = true;
			for (int j = 0; j < tmp.size; j++) {
				if (right.values[i] == tmp.values[j])
				{
					ch = false;
					break;
				}
			}
			if (ch) {
				tmp.add(right.values[i]);
			}
		}
		return tmp;
	}
	friend 	set<c> operator*(set<c>& left, const set<c>& right) {
		set<c>* tmp = new set<c>;
		for (int i = 0; i < right.size; i++) {
			for (int j = 0; j < left.size; j++) {
				if (right.values[i] == left.values[j])
				{
					tmp->add(right.values[i]);
				}
			}
		}
		return *tmp;
	}
	friend 	set<c> operator-(set<c>& left, const set<c>& right) {
		set<c> tmp;

		for (int i = 0; i < right.size; i++) {

			for (int j = 0; j < left.size; j++) {
				if (right.values[i] == left.values[j])
				{
					tmp.add(right.values[i]);
				}
			}
		}
		set<c> tmp2;
		for (int g = 0; g < right.size; g++) {
			bool ch = true;
			for (int i = 0; i < tmp.size; i++) {
				if (right.values[g] == tmp.values[i]) {
					ch = false;
					break;
				}
			}
			if (ch) {
				tmp2.add(right.values[g]);
			}
		}
		for (int g = 0; g < left.size; g++) {
			bool ch = true;
			for (int i = 0; i < tmp.size; i++) {
				if (left.values[g] == tmp.values[i]) {
					ch = false;
					break;
				}
			}
			if (ch) {
				tmp2.add(left.values[g]);
			}
		}
		return tmp2;
	}
	set<c>& operator=(const set<c>& right) {
		if (this != &right) {
			this->values = right.values;
			this->size = right.size;
		}
		return *this;
	}
	/*c& operator[](const int index) {
		return values[index];
	}*/

	void print() {
		for (int i = 0; i < size; i++) {
			cout << values[i] << " ";
		}
		cout << endl;
	}

};
int main(void) {
	cout << "INT:" << endl;
	ifstream file;
	file.open("input.txt");
	if (!file) {
		cout << "Файл не был открыт!" << endl;
		return 0;
	}
	set<int> set1, set2, set3, set4, set5;
	char* buf = new char[200];
	file.getline(buf, 200);
	char* pch = strtok(buf, " ,.-"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
	set1.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set1.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set1.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set1.add(atoi(pch));
	file.getline(buf, 200);
	pch = strtok(buf, " ,.-"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
	set2.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set2.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set2.add(atoi(pch));
	pch = strtok(NULL, " ,.-");
	set2.add(atoi(pch));

	file.close();

	cout << "Set1: ";
	set1.print();

	cout << "Set2: ";
	set2.print();

	set3 = set1 + set2;
	cout << "set1+set2 = ";
	set3.print();

	set4 = set1 * set2;
	cout << "set1*set2 = ";
	set4.print();
	
	set5 = set1 - set2;
	cout << "set1-set2 = ";
	set5.print();



	cout << endl << "STRING:" << endl;
	set<string> set_1, set_2, set_3, set_4, set_5;
	set_1.add("qwe");
	set_1.add("asd");
	set_1.add("zxc");
	cout << "Set1: ";
	set_1.print();
	
	set_2.add("asd");
	set_2.add("ewq");
	set_2.add("cxz");
	cout << "Set2: ";
	set_2.print();
	
	set_3 = set_1 + set_2;
	cout << "Set1+Set2 = ";
	set_3.print();

	set_4 = set_1 * set_2;
	cout << "Set1*Set2 = ";
	set_4.print();
	
	set_5 = set_1 - set_2;
	cout << "Set1-Set2 = ";
	set_5.print();
	return 0;
}