#ifndef NODE_H
#define NODE_H

template <typename T> class List;
template < typename T> class Node
{
private:
	T data;
	Node *next;

public:
	T getdata() const { return data; }
	Node * getnext() const { return next; }
	Node(T d) : data(d), next(0) { };

	friend class List<T>;
};
#endif#pragma once
