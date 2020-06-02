#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>

using namespace std;



class Abiturient {
	string Surname;
	string Name;
	string Lastname;
	string Address;
	int    Marks[5];

public:
	void setFIO(string, string, string);
	void setAddress(string);
	void setMarks(int, int, int, int, int);
	void setAbiturient(string, string, string, string, int, int, int, int, int);
	void show();
	string getSurname();
	string getName();
	string getLastname();
	string getAddress();
	int*   getMarks();
	int    getMarksSum();
	
};

void outAbiturientListNegMarks(Abiturient*, int);
void outAbiturientListSunN(Abiturient*, int);
void outAbiturientListMaxMarks(Abiturient*, int);
void outAbiturientListNegMarksFile(Abiturient*, int);
void outAbiturientListSunNFile(Abiturient*, int);
void outAbiturientListMaxMarksFile(Abiturient*, int);
bool isAbiturientNegMark(Abiturient);
void sortAbiturients(Abiturient*, int);

int main(void) {
	Abiturient A[5];
	Abiturient *array = new Abiturient[5];
	int length = 5;
	string surname, name, lastname, address;
	int mark1, mark2, mark3, mark4, mark5;

	setlocale(LC_ALL, "rus");
	ifstream file;
	file.open("input.txt");
	if (!file) {
		cout << "Файл не был открыт!" << endl;
		return 0;
	}

	int i = 0;
	cout << "---------------------------------------" << endl << "Abiturien List" << endl;
	while (!file.eof()) {
		char* buf = new char[200];
		file.getline(buf, 200);
		char* pch = strtok(buf, " ,.-"); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
		surname = pch;
		pch = strtok(NULL, " ,.-");
		name = pch;
		pch = strtok(NULL, " ,.-");
		lastname = pch;
		pch = strtok(NULL, " ,.-");
		address = pch;
		pch = strtok(NULL, " ,.-");
		mark1 = atoi(pch);
		pch = strtok(NULL, " ,.-");
		mark2 = atoi(pch);
		pch = strtok(NULL, " ,.-");
		mark3 = atoi(pch);
		pch = strtok(NULL, " ,.-");
		mark4 = atoi(pch);
		pch = strtok(NULL, " ,.-");
		mark5 = atoi(pch);
		A[i].setAbiturient(surname, name, lastname, address,
			mark1, mark2, mark3, mark4, mark5);
		A[i].show();
		cout << endl;
		i++;
	}
	cout << "---------------------------------------" << endl;
	file.close();
	//
	ofstream file1;
	file1.open("output.txt");
	for (int i = 0; i < length; i++) {
		file1 << A[i].getSurname() << " " << A[i].getName() << " " << A[i].getLastname() << " " << A[i].getAddress()
			<< A[i].getMarks()[0] << " " << A[i].getMarks()[1] << " " << A[i].getMarks()[2] << " " << A[i].getMarks()[3] << " " << A[i].getMarks()[4] << endl;
	}
	file1.close();
	//
	outAbiturientListNegMarks(A, length);
	outAbiturientListSunN(A, length);
	outAbiturientListMaxMarks(A, length);
	//
	//binary
	ofstream file2;
	file2.open("output.btv", ios::binary);
	for (int i = 0; i < length; i++) {
		file2.write((char*)&A[i], sizeof(A[0]));
	}

	file2.close();

	ifstream file3;
	file3.open("output.btv", ios::binary);
	for (int i = 0; i < length; i++) {
		file3.read((char*)array, sizeof(Abiturient) * 10);
	}
	file3.close();

	array[0].show();
	array[1].show();
	array[2].show();
	array[3].show();
	array[4].show();

	system("pause");
	return 0;
}

void Abiturient::setFIO(string surname, string name, string lastname) {
	Surname = surname;
	Name = name;
	Lastname = lastname;
}

void Abiturient::setAddress(string address) {
	Address = address;
}

void Abiturient::setMarks(int x1, int x2, int x3, int x4, int x5) {
	Marks[0] = x1;
	Marks[1] = x2;
	Marks[2] = x3;
	Marks[3] = x4;
	Marks[4] = x5;
}

void Abiturient::setAbiturient(string surname, string name, string lastname, string address, int x1, int x2, int x3, int x4, int x5) {
	setFIO(surname, name, lastname);
	setAddress(address);
	setMarks(x1, x2, x3, x4, x5);
}

string Abiturient::getSurname() {
	if (Surname.empty())
		return NULL;
	return Surname;
}

string Abiturient::getName() {
	if (Name.empty())
		return NULL;
	return Name;
}

string Abiturient::getLastname() {
	if (Lastname.empty())
		return NULL;
	return Lastname;
}

string Abiturient::getAddress() {
	if (Address.empty())
		return NULL;
	return Address;
}

int* Abiturient::getMarks() {
	if (Marks == NULL)
		return NULL;
	return Marks;
}

int Abiturient::getMarksSum() {
	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += Marks[i];
	}
	return sum;
}

void Abiturient::show() {
	cout << "Abiturient: " << Surname << " " << Name << " " << Lastname << " " << "; Address: " << Address;
	cout << "; Marks[" << Marks[0] << ", " << Marks[1] << ", " << Marks[2] << ", " << Marks[3] << ", " << Marks[4] << "]";
}

void outAbiturientListNegMarks(Abiturient* A, int length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (isAbiturientNegMark(A[i])) {
			count++;
			if (count == 1)
				cout << "---------------------------------------" << endl << "List with negetives" << endl;
			A[i].show();
			cout << endl;
		}
	}
	cout << "---------------------------------------" << endl;
}

bool isAbiturientNegMark(Abiturient abit) {
	for (int i = 0; i < 5; i++) {
		if (abit.getMarks()[i] < 4)
			return true;
	}
	return false;
}

void outAbiturientListSunN(Abiturient* A, int length) {
	cout << "---------------------------------------" << endl;
	cout << "Type the Sum = ";
	int sum = 0;
	cin >> sum;
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (A[i].getMarksSum() >= sum){
			count++;
			if (count == 1)
				cout << "List with Sum > " << sum << endl;
			A[i].show();
			cout << endl;
		}
	}
	cout << "---------------------------------------" << endl;
}

void outAbiturientListMaxMarks(Abiturient* A, int length) {
	cout << "---------------------------------------" << endl;
	cout << "Type the N(count of students) = ";
	int N = 0;
	bool isHalfPassed = false;
	cin >> N;
	sortAbiturients(A, length);
	int average = A[N - 1].getMarksSum();
	cout << "List with max rating" << endl;
	for (int i = 0; i < N; i++) {
		A[i].show();
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
	cout << "List with halfpassed rating" << endl;
	for (int i = 0; i < length; i++) {
		if ((A[i].getMarksSum() == average) && (i != N-1)) {
			isHalfPassed = true;
			A[i].show();
			cout << endl;
		}
	}
	if (isHalfPassed) {
		A[N - 1].show();
		cout << endl;
	}
	cout << "---------------------------------------" << endl;
}

void outAbiturientListNegMarksFile(Abiturient *A, int length)
{
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (isAbiturientNegMark(A[i])) {
			count++;
			if (count == 1)
				cout << "---------------------------------------" << endl << "List with negetives" << endl;
			A[i].show();
			cout << endl;
		}
	}
	cout << "---------------------------------------" << endl;
}

void outAbiturientListSunNFile(Abiturient *, int)
{
}

void outAbiturientListMaxMarksFile(Abiturient *, int)
{
}

void sortAbiturients(Abiturient* A, int length) {
	for (int i = 0; i < length; i++) {
		for (int j = i+1; j < length; j++) {
			if (A[i].getMarksSum() < A[j].getMarksSum()) {
				Abiturient tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
		}
	}
}