#include <iostream>
#include <ctime>
using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n;
	//���������� n-�� ����� ������������������ ��������� � ������� �����
	cout << "������� N ����� ������������������ ���������: ";
	cin >> n;
	cout << "\n";
	unsigned int start_time = clock();
	long long int a = 0, b = 1, c;
	if (n <= 2) {
		if (n == 1) {
			cout << n << " ������� ������������������ ��������� ����� " << a << "\n\n\n";
		}
		if (n == 2) {
			cout << n << " ������� ������������������ ��������� ����� " << b << "\n\n\n";
		}
	}
	else {
		for (int i = 3; i <= n + 1; i++) {
			c = a + b;
			a = b;
			b = c;
		}
		cout << n << " ������� ������������������ ��������� ����� " << b << "\n\n";
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	double sec = ((end_time - start_time) / 1000) ;
	cout << "����� ���������� : " << sec << " �." << (end_time - start_time)%1000<<"��." << endl;
	return 0;
}
