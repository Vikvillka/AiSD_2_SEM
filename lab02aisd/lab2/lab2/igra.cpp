#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <math.h>
#include <conio.h>
#include <string>

using namespace std;

HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
void GoToXY(short x, short y)
{
	SetConsoleCursorPosition(hStdOut, { x, y });
}
void haha()
{
	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	GoToXY(20, 1);
	cout << " _   _                                      ___        " << endl;
	GoToXY(20, 2);
	cout << "| |_| |  _____    ____     ___     ____    __ __   __ __   ____" << endl;
	GoToXY(20, 3);
	cout << " \\   /  | ____|  /    \\   /   \\   /    \\  |  |  | | |/ /  /    \\" << endl;
	GoToXY(20, 4);
	cout << "  | |   | |     |  #  |  / _#_ \\ |  #  |  |  |  | | |\\ \\ |  #  |" << endl;
	GoToXY(20, 5);
	cout << "  |_|   |_|      \\__/_|  |_/ \\_|  \\__/_|  \\___/_| |_||_|  \\__/_| " << endl;
	
}
int main() {

	setlocale(LC_ALL, "Russian");
	srand(unsigned(time(NULL)) * 100 * 100 * 100 * 100);

	int menufor = 1;


	while (menufor != 0) {

		
		char n, otvet;
		int chislo;
		
		cout << "                                                      \n";
		cout << "   1 - ������ ���� - ��������                         \n";
		cout << "   2 - ���������� ���������                           \n";
		cout << "\n";
		cout << "\n";
		
		cin >> n;
		system("cls");

		
		switch (n) {

			
		case '1': {
			
			
			haha();
			GoToXY(21, 8);
			cout << "������� ���������� �������� � ������� �� ������� �������� ����� \n";
			cin >> chislo;
			GoToXY(21, 10);
			cout << "��������� ����� ����� �� ����������     \n";
			GoToXY(21, 12);
			system("pause");
			system("cls");
			
			//���� ��������
			int a = 1;
			int randomchislo = chislo / 2, kolvo = 0, diapozon = chislo / 2;
			while (a != 2) {
				haha();
				GoToXY(30, 9);
				cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
				GoToXY(30, 10);
				cout << " ||       ���� ����� " << randomchislo <<" ?          ||" << "\n";
				GoToXY(30, 11);
				cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
				
				cout << "\n";
				GoToXY(0, 12);
				cout << " 1 - ������                        \n";
				cout << " 2 - ������                        \n";
				cout << " 3 - ������                        \n";
				cout << "\n";
				cin >> otvet;
				system("cls");
				haha();
				while (otvet > '3' || otvet < '1') {
					GoToXY(30, 9);
					cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";
					GoToXY(30, 10);
					cout << " ||       ���� ����� " << randomchislo << " ?          ||" << "\n";
					GoToXY(30, 11);
					cout << " xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n";

					cout << "\n";
					GoToXY(0, 12);
					cout << " 1 - ������                        \n";
					cout << " 2 - ������                        \n";
					cout << " 3 - ������                        \n";
					cout << "\n";
					cin >> otvet;
					system("cls");
					haha();
				}
				
				kolvo = kolvo + 1;
				if (otvet == '1') {
					if (kolvo == 1) {
						randomchislo = diapozon - diapozon / 2;
						diapozon = diapozon / 2;
					}
					else {
						randomchislo = randomchislo - diapozon;
					}
					if (diapozon == 0) {
						randomchislo = randomchislo - 1;
					}
				}
				if (otvet == '2') {
					if (kolvo == 1) {
						randomchislo = diapozon + diapozon / 2;
						diapozon = diapozon / 2;
					}
					else {
						randomchislo = randomchislo + diapozon;
					}
					if (diapozon == 0) {
						randomchislo = randomchislo + 1;
					}
				}
				if (otvet == '3') {
					a = 2;
				}
				diapozon = diapozon / 2;
			}
			system("cls");
			haha();
			
			int max_shag = 0, gread = chislo;
			while (gread != 0) {
				gread = gread / 2;
				max_shag = max_shag + 1;
			}
			
			GoToXY(40, 9);
			
			cout << "����������                      \n";
			
			cout << "----------------------------------------------------------\n";
			cout << " �� �������� ����� " << randomchislo << "\n";
			cout << "----------------------------------------------------------\n";
			cout << " ��������� ������������ " << kolvo << " ������� \n";
			cout << "----------------------------------------------------------\n";
			cout << " ������������ ���������� ����� ��������� ������ =  " << max_shag << "\n";
			cout << "----------------------------------------------------------\n\n\n";
			
			system("pause");
			system("cls");
			break;
		}

				
		case '2': {
			system("cls");
			cout << "\n\nXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n";
			cout << "XX                                                   xX\n";
			cout << "XX                ��������� ���������                XX\n";
			cout << "XX                                                   XX\n";
			cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n";
			return 0;
			break;
		}

				
		default: {
			
			cout << "�� ����� ������������ ������� ���������� ���������, � ���� ���������� � ����\t\n";
			
			break;
		}
		}
	}

	return 0;
}