#include<iostream>
#include<vector>
using namespace std;
int main(void) {
	vector<int> mas;
	setlocale(LC_ALL, "rus");
	cout << "¬ведите количество пиратов: ";
	int size;
	cin >> size;
	cout << "¬ведите счет: ";
	int m=1;
	cin >> m;
	for (int i = 0; i < size; i++) {
		mas.push_back(i + 1);
	}
	int pointer = 0;
	while (size > 1) {
		pointer += m-1;
		while (pointer >= size) {
			pointer -= size;
		}
		cout << "”бит " << mas[pointer] << " ѕират" << endl;
		mas.erase(mas.begin() + pointer);
		size--;
	}
	cout << mas[0];
	return 0;
}