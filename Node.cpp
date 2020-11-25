#include "Node.h"


Node::Node()
{
	key_ = 0;
	prev_ = next_ = 0;
}


std::istream& operator>>(std::istream& in, const Node& node)
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


Node*& Node::prev()
{
	return prev_;
}


Node*& Node::next()
{
	return next_;
}