#pragma once
#include<iostream>


class Node
{
private:
	int key_;
	Node* prev_, * next_;
	friend class List;
public:
	Node();
	Node(int);
	Node(Node*, Node*);
	friend std::istream& operator>>(std::istream&, const List&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	//int key();
	//Node* prev();
	//Node* next();
};