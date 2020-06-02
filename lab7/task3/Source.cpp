#include <iostream>
#include<string>

using namespace std;

class Set {
public:
	virtual void push_back(string) = 0;
	virtual void show() = 0;
	virtual void add(Set*) = 0;
	virtual void mult(Set*) = 0;
	virtual void sim_sub(Set*) = 0;
};

class set_int :public Set {

	int size = 0;
	int* mas = new int[size];
public:
	void add(Set* a) {
		set_int *tmp = (set_int*)a;
		for (int i = 0; i < tmp->size; i++) {
			bool ch = true;
			for (int j = 0; j < this->size; j++) {
				if (this->mas[j] == tmp->mas[i]) {
					ch = false;
				}
			}
			if (ch) {
				this->push_back(to_string(tmp->mas[i]));
			}
		}
	}
	void mult(Set* a) {
		set_int* tmp = (set_int*)a;
		set_int  temp;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < tmp->size; j++) {
				if (this->mas[i] == tmp->mas[j]) {
					temp.push_back(to_string(this->mas[i]));
				}
			}
		}
		*this = temp;
		return;
	}
	void sim_sub(Set* a) {
		set_int* tmp = (set_int*)a;
		set_int  temp, temp2;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < tmp->size; j++) {
				if (this->mas[i] == tmp->mas[j]) {
					temp.push_back(to_string(this->mas[i]));
				}
			}
		}
		for (int i = 0; i < this->size; i++) {
			bool ch = true;
			for (int j = 0; j < temp.size; j++) {
				if (this->mas[i] == temp.mas[j]) {
					ch = false;
				}
			}
			if (ch) {
				temp2.push_back(to_string(this->mas[i]));
			}
		}
		for (int i = 0; i < tmp->size; i++) {
			bool ch = true;
			for (int j = 0; j < temp.size; j++) {
				if (tmp->mas[i] == temp.mas[j]) {
					ch = false;
				}
			}
			if (ch) {
				temp2.push_back(to_string(tmp->mas[i]));
			}
		}
		*this = temp2;
		return;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << mas[i] << " ";
		}
		cout << endl;
	}
	void push_back(string data) {
		int value = atoi(data.data());
		int* tmp = new int[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = mas[i];
		}
		tmp[size] = value;
		mas = tmp;
		size++;
	}
};




//string
class set_str :public Set {
	int size = 0;
	string* mas = new string[size];
public:
	void add(Set* a) {
		set_str* tmp = (set_str*)a;
		for (int i = 0; i < tmp->size; i++) {
			bool ch = true;
			for (int j = 0; j < this->size; j++) {
				if (this->mas[j] == tmp->mas[i]) {
					ch = false;
				}
			}
			if (ch) {
				this->push_back(tmp->mas[i]);
			}
		}
	}
	void mult(Set* a) {
		set_str* tmp = (set_str*)a;
		set_str  temp;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < tmp->size; j++) {
				if (this->mas[i] == tmp->mas[j]) {
					temp.push_back(this->mas[i]);
				}
			}
		}
		*this = temp;
		return;
	}
	void sim_sub(Set* a) {
		set_str* tmp = (set_str*)a;
		set_str  temp, temp2;
		for (int i = 0; i < this->size; i++) {
			for (int j = 0; j < tmp->size; j++) {
				if (this->mas[i] == tmp->mas[j]) {
					temp.push_back(this->mas[i]);
				}
			}
		}
		for (int i = 0; i < this->size; i++) {
			bool ch = true;
			for (int j = 0; j < temp.size; j++) {
				if (this->mas[i] == temp.mas[j]) {
					ch = false;
				}
			}
			if (ch) {
				temp2.push_back(this->mas[i]);
			}
		}
		for (int i = 0; i < tmp->size; i++) {
			bool ch = true;
			for (int j = 0; j < temp.size; j++) {
				if (tmp->mas[i] == temp.mas[j]) {
					ch = false;
				}
			}
			if (ch) {
				temp2.push_back(tmp->mas[i]);
			}
		}
		*this = temp2;
		return;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << mas[i] << " ";
		}
		cout << endl;
	}
	void push_back(string data) {
		string value = data;
		string* tmp = new string[size + 1];
		for (int i = 0; i < size; i++) {
			tmp[i] = mas[i];
		}
		tmp[size] = value;
		mas = tmp;
		size++;
	}
};

int main(void) {
	//int
	Set* set1, *set2;
	set_int tmp, tmp1;
	set1 = &tmp;
	cout << "INT" << endl;
	cout << "set1 = ";
	set1->push_back("10");
	set1->push_back("20");
	set1->push_back("40");
	set1->show();

	cout << endl;
	cout << "set2 = ";
	set2 = &tmp1;

	set2->push_back("20");
	set2->push_back("50");
	set2->push_back("30");
	set2->show();

	cout << endl;

	cout << "set1+set2 =  ";
	set1->add(set2);
	set1->show();

	cout << endl;
	cout << "set1 * set2 =  ";
	set1->mult(set2);
	set1->show();

	cout << endl;
	cout << "set1 - set2 =  ";
	set1->sim_sub(set2);
	set1->show();


	//string
	Set* set_1, *set_2;
	set_str tmp_1, tmp_2;
	set_1 = &tmp_1;
	cout << "STRING" << endl;
	cout << "set1 = ";
	set_1->push_back("10");
	set_1->push_back("20");
	set_1->push_back("40");
	set1->show();

	cout << endl;
	cout << "set2 = ";
	set_2 = &tmp_2;

	set_2->push_back("20");
	set_2->push_back("50");
	set_2->push_back("30");
	set_2->show();

	cout << endl;

	cout << "set1+set2 =  ";
	set_1->add(set_2);
	set_1->show();

	cout << endl;
	cout << "set1 * set2 =  ";
	set_1->mult(set_2);
	set_1->show();

	cout << endl;
	cout << "set1 - set2 =  ";
	set_1->sim_sub(set_2);
	set_1->show();


	return 0;
}