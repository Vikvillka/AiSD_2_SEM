#include "Hash_Twin_Chain.h"
#include "Hash.h"
#include <iostream>

struct AAA
{
	int key;
	char* mas;
	AAA(int k, char* z)
	{
		key = k;
		mas = z;
	}
};
namespace hashTC
{
	Object create(int size, int(*f)(void*))
	{
		return *(new Object(size, f));
	};


	int universal(int key, int size, int p)	// обеспечивает равномерное хеширование: дл€ очередного ключа веро€тности помещени€ его в любую €чейку совпадают
	{
		int h = 0, a = 314445, b = 37542;
		h = (a * h + key) % size;
		return (h < 0) ? (h + size) : h;
	}
    
	
	//bool Object::isPrime(int key) {
	//	int i;
	//	for (i = 2; i <= sqrt(key); i++) {
	//		if (key % i == 0) {
	//			return false;
	//		}
	//	}
	//	return true;
	//};
	//int Object::find_Prime(int key, int size0) {
	//	int res = key;
	//	for (res;; res++) {
	//		if (isPrime(res)) {
	//			return res;
	//		}
	//	}
	//};
	//int Object::hashFunction(void* data)                                 // изменена функци€ хешировани€, на универсальную
	//{
	//	int key = FunKey(data);
	//	int p = find_Prime(key, sizeO);
	//	int a = rand() % p;
	//	int b = rand() % p;
	//	int hkey = ((a * key + b) % p) % sizeO;
	//	return (hkey);
	//};


	int Object::hashFunction(void* data)                  // начальна€ функци€ дл€ хешировани€, можно использовать дл€ демонстрации колизий(показать образование св€зных списков в таблице)
	{
		return (FunKey(data) % sizeO);
	};
	
	bool Object::insert(void* data)
	{
		return (Hash[hashFunction(data)].insert(data));
	};
	bool Object::deleteByData(void* data)
	{
		for (int i = 0; i < sizeO; i++)
		{
			listx::Element* e = Hash[i].getFirst();
			bool k = 0;
			while (e != NULL)
			{
				if ((((AAA*)data)->key) == (((AAA*)e->data)->key))
				{
					return(Hash[i].deleteByElement(e));
				}
				e = e->getNext();
			};
		}
	};
	listx::Element* Object::search(void* data)
	{
		return Hash[hashFunction(data)].search(data);
	};
	void Object::Scan()
	{
		for (int i = 0; i < sizeO; i++)
		{
			std::cout << i + 1 << ". ";
			Hash[i].scan();
			std::cout << '\n';
		}
	};
	void Object::Scan1(void* data)
	{
		std::cout << "ответ: " << std::endl;
		for (int i = 0; i < sizeO; i++)
		{
			Hash[i].scan1(data);
		}
	};
}