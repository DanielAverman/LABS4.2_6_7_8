#define _CRT_SECURE_NO_WARNINGS
#include<fstream>
#include<iostream>
#include<vector>
#include <windows.h>
#include<ctype.h>
#include<algorithm>
#include<string>
using namespace std;


struct Pair {
	string city = "";
	vector<pair<string, int>> rest;
};
bool compareStr(Pair a, Pair b) {
	return (a.city < b.city);
}
int main(void) {
	vector<Pair> arr;
	int max_rest = 0;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_CTYPE, "Russian");
	
	ifstream file;
	file.open("info.txt");
	if (!file) {
		cout << "Файл не открыт!" << endl;
		return 0;
	}
	if (file.peek() == EOF) {
		cout << "Файл пуст!" << endl;
		return 0;
	}

	while (!file.eof()) {
		Pair tmp;
		char* buf = new char[100];
		file.getline(buf, 99);
		if (buf != "") {
			for (int i = 0; i < 99; i++) {
				buf[i] = tolower(buf[i]);
			}
			char* pch = strtok(buf, " ,.");
			pch[0] = toupper(pch[0]);
			tmp.city = pch;
			pch = strtok(NULL, " ,.");
			pch[0] = toupper(pch[0]);
			pair<string, int> tmp2;
			tmp2.first = pch;
			pch = strtok(NULL, " ,.");
			tmp2.second = atoi(pch);
			tmp.rest.push_back(tmp2);
			bool ch = true;
			for (int i = 0; i < arr.size(); i++) {
				if (tmp.city == arr[i].city && ch) {
					ch = false;
					arr[i].rest.push_back(tmp2);

				}
			}
			if (ch) {
				arr.push_back(tmp);
			}
		}
	}



	sort(arr.begin(), arr.end(), compareStr);



	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i].city << ":" << endl;
		if (arr[i].rest.size() > max_rest) {
			max_rest = arr[i].rest.size();
		}
		for (int j = 0; j < arr[i].rest.size(); j++) {
			cout << arr[i].rest[j].first << " " << arr[i].rest[j].second << endl;
		}
		cout << endl;
	}

	cout << "Введите количество ресторанов: ";
	int a;
	cin >> a;
	cout << endl;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].rest.size() >= a) {
			cout << arr[i].city << ":" << endl;
			for (int j = 0; j < arr[i].rest.size(); j++) {
				cout << arr[i].rest[j].first << " " << arr[i].rest[j].second << endl;
			}
			cout << endl;
		}
	}
	cout << endl;

	cout << "Города с максимальным числом ресторанов: " << endl;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].rest.size() == max_rest) {
			cout << arr[i].city << ":" << endl;
			for (int j = 0; j < arr[i].rest.size(); j++) {
				cout << arr[i].rest[j].first << " " << arr[i].rest[j].second << endl;
			}
			cout << endl;
		}
	}
	cout << endl;

	string city, rest;
	cin.clear();
	cout << "Введите город: ";
	cin >> city;
	if (city == "") {
		cout << "Ошибка";
		return 0;
	}
	for (int i = 0; i < city.length(); i++) {
		city[i] = tolower(city[i]);
	}
	city[0] = toupper(city[0]);

	cout << "Введите ресторан: ";
	cin >> rest;
	if (rest == "") {
		cout << "Ошибка";
		return 0;
	}
	for (int i = 0; i < rest.length(); i++) {
		rest[i] = tolower(rest[i]);
	}
	rest[0] = toupper(rest[0]);


	for (int i = 0; i < arr.size(); i++) {
		if (arr[i].city == city) {
			for (int j = 0; j < arr[i].rest.size(); j++) {
				if (arr[i].rest[j].first == rest) {
					cout << "Введите новое название: ";
					cin >> arr[i].rest[j].first;
					break;
				}
			}
			break;
		}
	}
	cout << endl;
	cout << endl << endl;
	for (int i = 0; i < arr.size(); i++) {

		cout << arr[i].city << ":" << endl;
		for (int j = 0; j < arr[i].rest.size(); j++) {
			cout << arr[i].rest[j].first << " " << arr[i].rest[j].second << endl;
		}
		cout << endl;

	}
	return 0;
}