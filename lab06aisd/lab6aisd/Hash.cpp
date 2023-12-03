#pragma once
#include "Hash.h"
#include"Hash_Twin_Chain.h"
#include <iostream>
struct AAA
{
	int key;
	char* mas;
};
namespace listx
{
	bool Object::insert(void* data)
	{
		bool rc = NULL;
		if (head == NULL)
			head = new Element(NULL, data, head);
		else
			if (!scan2(data))
				head = (head->prev = new Element(NULL, data, head));
		return rc;
	}
	//-------------------------------
	Element* Object::search(void* data)
	{
		Element* rc = head;
		while ((rc != NULL) && ((((AAA*)rc->data)->key) != ((AAA*)data)->key))
			rc = rc->next;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByElement(Element* e)
	{
		bool rc = NULL;
		if (rc = (e != NULL))
		{
			if (e->next != NULL)
				e->next->prev = e->prev;
			if (e->prev != NULL)
				e->prev->next = e->next;
			else
				head = e->next;
			delete e;
		}
		std::cout << "элемент удален" << std::endl;
		return rc;
	}
	//-------------------------------
	bool Object::deleteByData(void* data)
	{
		return deleteByElement(search(data));
	}
	//-------------------------------
	Element* Object::getLast()
	{
		listx::Element* e = this->getFirst(), * rc = this->getFirst();
		while (e != NULL)
		{
			rc = e;
			e = e->getNext();
		};
		return rc;
	}
	Object create()
	{
		return *(new Object());
	};
	//-------------------------------
	void Object::scan()
	{
		listx::Element* e = this->getFirst();
		bool k = 0;
		while (e != NULL)
		{
			std::cout << "Ключ: " << ((AAA*)e->data)->key << "; " << "Значение: " << ((AAA*)e->data)->mas << "\t";
			e = e->getNext();
			k = 1;
		};
		if (!k)
		{
			std::cout << "Пусто";
		}
	}
	void Object::scan1(void* data)
	{
		listx::Element* e = this->getFirst();
		bool k = 0;
		while (e != NULL)
		{
			if ((((AAA*)data)->key) == ((AAA*)e->data)->key)
			{
				std::cout << "Ключ: " << ((AAA*)e->data)->key << "; " << "Значение: " << ((AAA*)e->data)->mas << "\t" << std::endl;
			}
			e = e->getNext();
		};
	}

	bool Object::scan2(void* data)
	{
		listx::Element* e = this->getFirst();
		bool k = false;
		while (e != NULL)
		{
			if ((((AAA*)data)->key) == ((AAA*)e->data)->key)
			{
				std::cout << "этот ключ был использован, выберите другой" << std::endl;
				k = true;
				break;
			}
			e = e->getNext();
		}
		return k;
	}

}