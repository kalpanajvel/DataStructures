#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include<iostream>
//#include<utility>


// Forward Reference
//template <typename T>
//std::ostream & operator<<(std::ostream & os, const List<T> & lst);

template <typename T> class List
{
private:
	Node<T>* frontptr;
	Node<T>* backptr;
public:
	List();
	List(const List<T> & lstobj);
	List<T>& operator = (List<T> rhs);
	~List();
	void push_front(const T & value);
	void push_back(const T & value);
	bool pop_front(T & value);
	bool pop_back(T & value);
	bool isEmpty() const;
	void printList() const;
	void reverseList();
	//friend std::ostream & operator<< <>(std::ostream & os, const List<T> & lst);
	// Overload the stream insertion operator to print the list
};

template <typename T> List<T>::List() :frontptr(0), backptr(0) {}

//copy constructor
template <typename T>
List<T>::List(const List<T> & lstobj)
{
	if (lstobj.frontptr == nullptr)
		frontptr = backptr = nullptr;
	else
	{
		Node<T> * objcurrentptr = lstobj.frontptr;
		Node<T> * newobjcurrentptr;
		frontptr = new Node<T>(objcurrentptr->data);
		newobjcurrentptr = frontptr;
		//objcurrentptr = objcurrentptr->next;
		while (objcurrentptr->next)
		{
			newobjcurrentptr->next = new  Node<T>(objcurrentptr->next->data);
			objcurrentptr = objcurrentptr->next;
			newobjcurrentptr = newobjcurrentptr->next;
		}
		backptr = newobjcurrentptr;
	}
}

//assignment operator
template <typename T>
List<T> & List<T>::operator = (List<T> byValList)  //This will call copy constructor since we are passing by value
{
	std::swap(frontptr, byValList.frontptr); //copies this to byValList and byValList data is swapped to this
	return *this;       //while exiting from this function the byValList scope ends and calls destructor

}
template <typename T> List<T>::~List()
{
	while (frontptr)
	{
		Node<T>* tempptr = frontptr;
		//tempptr = frontptr;
		frontptr = frontptr->next;
		delete tempptr;
	}
	frontptr = backptr = nullptr;
}

template <typename T> bool List<T>::isEmpty() const
{
	return frontptr == 0;

}

template <typename T> void List<T> ::push_front(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	//newNode->data = value;
	if (isEmpty())
		frontptr = backptr = newNode;
	/*else if(frontptr == backptr)
	{
	newNode->next = frontptr;
	frontptr->next = backptr;
	}*/
	else
	{
		newNode->next = frontptr;
		frontptr = newNode;
	}
}

template <typename T> void List<T>::push_back(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	//newNode->data = value;
	if (isEmpty())
		frontptr = backptr = newNode;
	/*else if(frontptr == backptr)
	{
	backptr = newNode;
	frontptr->next = backptr;
	}*/
	else
	{
		backptr->next = newNode;
		backptr = newNode;
	}
}

template <typename T> bool List<T> ::pop_front(T& value)
{
	if (isEmpty())
	{
		return false;
		//cout << "\nEmpty List";
	}
	else if (frontptr == backptr)
	{
		value = frontptr->data;
		delete frontptr;
		frontptr = backptr = 0;
		//return true;
	}
	else
	{
		value = frontptr->data;
		Node<T>* tempptr;
		tempptr = frontptr;
		frontptr = frontptr->next;
		delete tempptr;
		//return true;
	}
	return true;
}

template <typename T> bool List<T> ::pop_back(T& value)
{
	Node<T>* tempptr;
	if (isEmpty())
	{
		return false;
		//cout << "\nEmpty List";
	}
	else if (frontptr == backptr)
	{
		value = backptr->data;
		delete backptr;
		frontptr = backptr = 0;
		//return true;
	}
	else
	{
		tempptr = frontptr;
		//value = tempptr->data;
		while (tempptr->next != backptr)
		{
			tempptr = tempptr->next;
		}
		value = backptr->data;
		delete backptr;
		backptr = tempptr;
		tempptr->next = 0;
		//return true;
	}
	return true;
}
template <typename T>
void List<T>::reverseList()
{
	if (isEmpty())
		std::cout << "\nList is empty!!";
	else
	{
		Node<T> * current = frontptr;
		Node<T> * current_next = nullptr;
		Node<T> * back = nullptr;
		Node<T> * last = frontptr;
		while (current)
		{
			frontptr = current;
			current_next = current->next;
			current->next = back;
			back = current;
			current = current_next;
		}
		if (frontptr == backptr)
			backptr = last;
	}
}

template <typename T>
void List<T> ::printList() const
{
	if (isEmpty())
		std::cout << "\nEmpty List";
	else
	{
		Node<T>* currentptr = frontptr;
		std::cout << "\n{";
		while (currentptr)
		{
			std::cout << currentptr->data;
			currentptr = currentptr->next;
			if (currentptr)
				std::cout << "->";
		}
		std::cout << "}";
	}
}

// Overload the stream insertion operator to print the list
/*template <typename T>
std::ostream & operator<< (std::ostream & os, const List<T> & lst) {
os << '{';
if (!lst.isEmpty()) {
Node<T> * currentPtr = lst.frontptr;
while (currentPtr) {
os << currentPtr->getdata();
if (currentPtr != lst.backptr) os << ',';
currentPtr = currentPtr->getnext();
}
}
os << '}';
}*/


#endif#pragma once
