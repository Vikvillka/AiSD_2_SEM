#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "russian");

	int n, fibonachi(int);
	//���������� n-�� ����� ������������������ ��������� � ������� �����
	cout << "������� N ����� ������������������ ���������: ";
	cin >> n;
	unsigned int start_time = clock();
	int a = 0, b = 1;
	cout << "\n";
	cout << n << " ������� ������������������ ��������� ����� " << fibonachi(n) << "\n\n\n";
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	double sec= (end_time - start_time)/1000;
	cout << "����� ���������� : " << sec << " �." << (end_time - start_time) % 1000 << "��." << endl;
	return 0;
}
int fibonachi(int n) {
	if (n <= 2) {
		if (n == 1) {
			return 1;
		}
		if (n == 0) {
			return 0;
		}
	}
	return fibonachi(n - 1) + fibonachi(n - 2);
}