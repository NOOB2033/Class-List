#include "List.h"
#include "Enum.h"


void List::add(Node* prev, Node* node)
{
	Node* next = prev->next();
	node->prev() = prev;
	node->next() = next;
	prev->next() = node;
	next->prev() = node;
}


void List::remove(Node* node)
{
	Node* prev = node->prev();
	Node* next = node->next();
	prev->next() = next;
	next->prev() = prev;
}


Node* List::searchPlace(Node* node)
{
	Node* p1 = node->prev();
	for (; p1 != head_ && p1->key() > node->key(); p1 = p1->prev());
	return p1;
}


Node* List::searchIndex(int index)
{
	if (index < 0)
		throw Invalid_index;
	Node* node = head_->next();
	for (; node != tail_ && index > 0; node = node->next(), index--);
	return node;
}


List::List()
{
 	head_ = new Node();
	tail_ = new Node(head_, 0);
	head_->next() = tail_;
}


List::List(int size) : List()
{
	if (size < 0)
		throw Invalid_size;
	for (int i = 0; i < size; i++)
		addToTail(i);
}


List::List(int* arr, int size) : List()
{
	for (int i = 0; i < size; i++)
		addToTail(arr[i]);
}


List::List(const List& copyList) : List()
{
	for (Node* i = copyList.head_->next(); i != copyList.tail_; i = i->next())
		addToTail(i->key());
}


List::~List()
{
	clear();
	delete head_;
	delete tail_;
}


std::istream& operator>>(std::istream& in, const List& list)
{
	for (Node* i = list.head_->next(); i != list.tail_; i = i->next())
		in >> i->key();
	return in;
}


std::ostream& operator<<(std::ostream& out, const List& list)
{
	for (Node* i = list.head_->next(); i != list.tail_; i = i->next())
		out << i->key() << " ";
	return out;
}


bool List::empty()
{
	if (head_->next() == tail_)
		return true;
	return false;
}


void List::addToHead(int key)
{
	Node* node = new Node(key);
	add(head_, node);
}


void List::addToTail(int key)
{
	Node* node = new Node(key);
	add(tail_->prev(), node);
}


void List::addToPosition(Node* node, int index)
{
	add(searchIndex(index)->prev(), node); //если индекс больше, чем количество узлов - добавляем перед хвостом
}


void List::addAfterKey(Node* node, int key)
{
	if (search(key))
		add(search(key), node);
}


void List::deleteFromHead()
{
	if (!empty()) {
		Node* node = head_->next();
		remove(node);
		delete node;
	}
}


void List::deleteFromTail()
{
	if (!empty()) {
		Node* node = tail_->prev();
		remove(node);
		delete node;
	}
}


void List::deleteFromPosition(int index)
{
	if (!empty()) {
		Node* node = searchIndex(index);
		if (node != tail_) {
			remove(node);
			delete node;
		}
		else                // если равен хвосту, то удаляем последний элемент
			deleteFromTail();
	}
}


void List::deleteByKey(int key)
{
	Node* node = search(key);
	if (node)
		remove(node);
	delete node;
}


void List::clear()
{
	for (; !empty();)
		deleteFromHead();
}


void List::sort()
{
	Node* node;
	for (Node* i = head_->next()->next(); i != tail_; i = i->next()) {
		node = i;
		remove(node);
		add(searchPlace(node), node);
	}
}


int List::searchMax()
{
	int max = head_->next()->key();
	for (Node* i = head_->next()->next(); i != tail_; i = i->next())
		if (i->key() > max)
			max = i->key();
	return max;
}


int List::searchMin()
{
	int min = head_->next()->key();
	for (Node* i = head_->next()->next(); i != tail_; i = i->next())
		if (i->key() < min)
			min = i->key();
	return min;
}


Node* List::search(int key)
{
	for (Node* i = head_->next(); i != tail_; i = i->next())
		if (i->key() == key)
			return i;
	return nullptr;
}


bool List::operator==(const List& other)
{
	Node* node1 = head_->next();
	Node* node2 = other.head_->next();
	for (; node1->key() == node2->key() && node1 != tail_ && node2 != other.tail_; node1 = node1->next(), node2 = node2->next());
	if (node1 == tail_ && node2 == other.tail_)
		return true;
	return false;
}


bool List::operator!=(const List& other)
{
	Node* node1 = head_->next();
	Node* node2 = other.head_->next();
	for (; node1->key() == node2->key() && node1 != tail_ && node2 != other.tail_; node1 = node1->next(), node2 = node2->next());
	if (node1 == tail_ && node2 == other.tail_)
		return false;
	return true;
}


int& List::operator[](int index)
{
	return searchIndex(index)->key();
}


List& List::operator=(const List& other)// ссылки
{
	if (this != &other) {
		clear();
		for (Node* i = other.head_->next(); i != other.tail_; i = i->next())
			addToTail(i->key());
	}
	return *this;
}


List& List::operator+=(const List& other)
{
	for (Node* i = other.head_->next(); i != other.tail_; i = i->next())
		addToTail(i->key());
	return *this;
}


List List::operator+(const List& other)
{
	return List(*this) += other;
}