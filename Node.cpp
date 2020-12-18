#include "Node.h"


Node::Node()
{
	key_ = 0;
	prev_ = next_ = 0;
}


Node::Node(int key)
{
	key_ = key;
	prev_ = next_ = 0;
}


Node::Node(Node* prev, Node* next)
{
	prev_ = prev;
	next_ = next;
	key_ = 0;
}


/*std::istream& operator>>(std::istream& in, Node& node)
{
	in >> node.key_;
	return in;
}


std::ostream& operator<<(std::ostream& out, const Node& node)
{
	out << node.key_;
	return out;
}


int& Node::key()
{
	return key_;
}


Node* Node::prev()
{
	return prev_;
}


Node* Node::next()
{
	return next_;
}*/