#pragma once
#include<iostream>
using namespace std;

class Node
{
private:
	int key_;
	Node* prev_, * next_;
public:
	Node();
	friend ostream& operator<<(ostream&, const Node&);
	int& key();
	Node*& prev();
	Node*& next();
};