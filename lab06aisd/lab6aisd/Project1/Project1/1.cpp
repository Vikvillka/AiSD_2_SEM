//#include <iostream>
//#include <string>
//#include <windows.h>
//
//using namespace std;
//
//const int TABLE_SIZE = 32768;
//
//struct HashTableItem {
//    int phone;
//    string name;
//    HashTableItem* next;
//};
//
//int hashFunction(int phone) {
//    return phone % TABLE_SIZE;
//}
//
//struct HashTable {
//    HashTableItem* table[TABLE_SIZE];
//
//    HashTable() {
//        for (int i = 0; i < TABLE_SIZE; i++) {
//            table[i] = NULL;
//        }
//    }
//
//    void addItem(int phone, string name) {
//        int index = hashFunction(phone);
//
//        HashTableItem* newItem = new HashTableItem;
//        newItem->phone = phone;
//        newItem->name = name;
//        newItem->next = NULL;
//
//        if (table[index] != NULL) {
//            HashTableItem* current = table[index];
//            while (current->next != NULL) {
//                current = current->next;
//            }
//            current->next = newItem;
//        }
//        else {
//            table[index] = newItem;
//        }
//    }
//
//    HashTableItem* findItem(int phone) {
//        int index = hashFunction(phone);
//
//        HashTableItem* current = table[index];
//        while (current != NULL) {
//            if (current->phone == phone) {
//                cout << "Найдено: Номер: " << current->phone << " ФИО: " << current->name << endl;
//            }
//            current = current->next;
//        }
//
//        return NULL;
//    }
//
//    void removeItem(int phone) {
//        int index = hashFunction(phone);
//
//        HashTableItem* current = table[index];
//        HashTableItem* previous = NULL;
//        while (current != NULL) {
//            if (current->phone == phone) {
//                if (previous == NULL) {
//                    table[index] = current->next;
//                }
//                else {
//                    previous->next = current->next;
//                }
//                delete current;
//                return;
//            }
//            previous = current;
//            current = current->next;
//        }
//    }
//
//    void printTable() {
//        for (int i = 0; i < TABLE_SIZE; i++) {
//            if (table[i] != NULL) {
//                HashTableItem* current = table[i];
//                while (current != NULL) {
//                    cout << "Номер: " << current->phone << " ФИО: " << current->name << endl;
//                    current = current->next;
//                }
//            }
//        }
//    }
//};
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int choice;
//    HashTable myTable;
//    int number;
//    string FIO;
//start:
//
//    puts("1 - ввод элемента");
//    puts("2 - удаление элемента по имени");
//    puts("3 - вывод таблицы на экран");
//    puts("4 - поиск");
//    puts("0 - выход");
//
//    cin >> choice;
//    switch (choice) {
//    case 1: {
//        cout << "Введите номер(формат 123456): ";
//        cin >> number;
//        cin.ignore();
//        cout << "Введите ФИО: ";
//        getline(cin, FIO);
//        myTable.addItem(number, FIO);
//        break;
//    }
//    case 2: {
//        int key_input;
//        cout << "Номер на удаление: ";
//        cin >> key_input;
//        myTable.removeItem(key_input);
//        break;
//    }
//    case 3: {
//        myTable.printTable();
//        break;
//    }
//    case 4: {
//        int key_input;
//        cout << "Номер на поиск: ";
//        cin >> key_input;
//        myTable.findItem(key_input);
//
//        break;
//    }
//    case 0:  exit(0);
//    default: exit(1);
//    }
//    system("pause");
//    system("cls");
//    goto start;
//
//    return 0;
//}