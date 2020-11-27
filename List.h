#pragma once
#include"Node.h"


class List
{
private:
	Node* head_, * tail_;
	void add(Node* prev, Node* node);
	void del(Node* node);
	Node* searchPlace(Node*);
	Node* searchIndex(int);
public:
	List();
	List(int);
	List(int*, int);
	List(const List&);
	~List();
	friend std::istream& operator>>(std::istream&, const List&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	bool empty();
	void addToHead(int);
	void addToTail(int);
	void addToPosition(Node*, int);
	void addAfterKey(Node*, int);
	void deleteFromHead();
	void deleteFromTail();
	void deleteFromPosition(int);
	void deleteByKey(int);
	void clear();
	void sort();
	int searchMax();
	int searchMin();
	Node* search(int);
	bool operator==(const List&);
	bool operator!=(const List&);
	int& operator[](int);
	List operator=(const List&);
	List operator+=(const List&);
	List operator+(const List&);
};