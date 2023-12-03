#include "Hash_Twin_Chain.h"
#include <iostream>
#include <windows.h>
#include <tchar.h>
#include <fstream>
#include "Lists.h"
#include <chrono>

#define MAXLENGTH 100
using namespace std;


struct AAA
{
	int key;
	const char* mas;
	AAA(int k, const char* z)
	{
		key = k;
		mas = z;
	}
	AAA()
	{
		key = 0;
		mas = "";
	}
};
//-------------------------------
int hf(void* d)                                                                         
{
	AAA* f = (AAA*)d;
	return f->key;
}
//-------------------------------
void AAA_print(listx::Element* e)
{
	std::cout << ((AAA*)e->data)->key << '-' << ((AAA*)e->data)->mas << " / ";
}
//-------------------------------
void foutF(ofstream& f, char* name);

int main(/*int argc, _TCHAR* argv[]*/)
{
	setlocale(LC_ALL, "rus");                                                           
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(0));
	int current_size = 0;                                                                                                                  
	cout << "Введите размер таблицы: ";                                       
	cin >> current_size;                                                                 
	hashTC::Object H = hashTC::create(current_size, hf);
	int choice;
	int k;
	for (;;)																			
	{
		cout << "1 - вывод таблицы" << endl;
		cout << "2 - добавить элемент таблицы" << endl;
		cout << "3 - удалить элемент таблицы по ключу" << endl;
		cout << "4 - найти элемент по ключу" << endl;
		cout << "ваш выбор" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:  exit(0);
		case 2: {	  AAA* a = new AAA;
			char* str = new char[MAXLENGTH];
			cout << "введите номер телефона : ";
			cin >> k;
			cin.ignore();
			a->key = k;
			cout << "введите ФИО: ";
			cin.getline(str, 100, '\n');
			a->mas = str;
			H.insert(a);
		}
			  break;
		case 1: H.Scan();
			break;
		case 3: {	  AAA* b = new AAA;
			cout << "введите ключ: ";
			cin >> k;
			b->key= k;
			H.deleteByData(b);
		}
			  break;
		case 4: {AAA* c = new AAA;
			cout << "введите ключ: ";
			cin >> k;
			c->key = k;
			auto begin = std::chrono::high_resolution_clock::now();
			H.Scan1(c);
			auto end = std::chrono::high_resolution_clock::now();
			auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin);
			int long el = elapsed.count();
			std::cout << "time of working : " << el << " mks" << "о\n\n\n" << std::endl;
		}
			  break;
		}
	}
	return 0;
}

