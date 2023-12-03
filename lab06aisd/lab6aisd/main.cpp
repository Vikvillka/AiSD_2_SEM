#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int TABLE_SIZE = 32768;

struct HashTableItem {
    int phone;
    string name;
    HashTableItem* next;
};

int hashFunction(int phone) {
    return phone % TABLE_SIZE;
}

class HashTable {
private:
    HashTableItem* table[TABLE_SIZE];
public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    void addItem(int phone, string name) {
        int index = hashFunction(phone);

        HashTableItem* newItem = new HashTableItem;
        newItem->phone = phone;
        newItem->name = name;
        newItem->next = NULL;

        if (table[index] != NULL) {
            HashTableItem* current = table[index];
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newItem;
        }
        else {
            table[index] = newItem;
        }
    }

    HashTableItem* findItem(int phone) {
        int index = hashFunction(phone);

        HashTableItem* current = table[index];
        while (current != NULL) {
            if (current->phone == phone) {
                return current;
            }
            current = current->next;
        }

        return NULL;
    }

    void removeItem(int phone) {
        int index = hashFunction(phone);

        HashTableItem* current = table[index];
        HashTableItem* previous = NULL;
        while (current != NULL) {
            if (current->phone == phone) {
                if (previous == NULL) {
                    table[index] = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            if (table[i] != NULL) {
                HashTableItem* current = table[i];
                while (current != NULL) {
                    cout << "�����: " << current->phone << " ���: " << current->name << endl;
                    current = current->next;
                }
            }
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    HashTable myTable;
    int k, number; 
    string FIO;

    cout << "������� �����, ������� ������ �������� �����: ";
    cin >> k;
    for (int i = 0; i < k; i++) {
        cout << "������� �����(������ 123456): ";
        cin >> number;
        cin.ignore();
        cout << "������� ���: ";
        getline(cin, FIO);
        myTable.addItem(number, FIO);
    }

    myTable.printTable();
    cout << "\n";

    HashTableItem* item = myTable.findItem(123456);

    if (item != NULL) {
        cout << "�������: �����: " << item->phone << " ���: " << item->name << endl;
    }

    myTable.removeItem(123456);

    cout << "\n";

    myTable.printTable();

    cout << "\n";

    return 0;
}