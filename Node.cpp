#include "Node.h"
#include<iostream>


Node::Node()
{
	key_ = 0;
	prev_ = next_ = 0;
}


int& Node::key()
{
	return key_;
}


Node*& Node::prev()
{
	return prev_;
}


Node*& Node::next()
{
	return next_;
}


/*friend ostream& operator<<(ostream&, const Node&)
{

}*/