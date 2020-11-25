#pragma once
#include<iostream>


class Node
{
private:
	int key_;
	Node* prev_, * next_;
public:
	Node();
	friend std::istream& operator>>(std::istream&, const Node&);
	friend std::ostream& operator<<(std::ostream&, const Node&);
	int& key();
	Node*& prev();
	Node*& next();
};