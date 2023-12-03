#pragma once
#pragma once
#include "Hash.h"

namespace hashTC
{
	struct Object
	{
		int sizeO;
		int(*FunKey)(void*);
		listx::Object* Hash;
		Object(int size, int(*f)(void*))
		{
			sizeO = size;
			FunKey = f;
			Hash = new listx::Object[size];
		};
		int hashFunction(void* data);
		bool insert(void* data);
		listx::Element* search(void* data);
		bool deleteByData(void* data);
		void Scan();
		void Scan1(void* data);
		/*bool isPrime(int);
		int find_Prime(int,int);*/
	};
	Object create(int size, int(*f)(void*));
}
#pragma once