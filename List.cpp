#include "List.h"
#include "Enum.h"


void List::add(Node* prev, Node* node)
{
	Node* next = prev->next_;
	node->prev_ = prev;
	node->next_ = next;
	prev->next_ = node;
	next->prev_ = node;
}


void List::remove(Node* node)
{
	Node* prev = node->prev_;
	Node* next = node->next_;
	prev->next_ = next;
	next->prev_ = prev;
}


Node* List::searchPlace(Node* node)
{
	Node* p1 = node->prev_;
	for (; p1 != head_ && p1->key_ > node->key_; p1 = p1->prev_);
	return p1;
}


Node* List::searchIndex(int index)
{
	if (index < 0)
		throw Invalid_index;
	Node* node = head_->next_;
	for (; node != tail_ && index > 0; node = node->next_, index--);
	return node;
}


List::List()
{
 	head_ = new Node();
	tail_ = new Node(head_, 0);
	head_->next_ = tail_;
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
	for (Node* i = copyList.head_->next_; i != copyList.tail_; i = i->next_)
		addToTail(i->key_);
}


List::~List()
{
	clear();
	delete head_;
	delete tail_;
}


std::istream& operator>>(std::istream& in, const List& list)
{
	for (Node* i = list.head_->next_; i != list.tail_; i = i->next_)
		in >> i->key_;
	return in;
}


std::ostream& operator<<(std::ostream& out, const List& list)
{
	for (Node* i = list.head_->next_; i != list.tail_; i = i->next_)
		out << i->key_ << " ";
	return out;
}


bool List::empty()
{
	if (head_->next_ == tail_)
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
	add(tail_->prev_, node);
}


void List::addToPosition(Node* node, int index)
{
	add(searchIndex(index)->prev_, node); //если индекс больше, чем количество узлов - добавляем перед хвостом
}


void List::addAfterKey(Node* node, int key)
{
	if (search(key))
		add(search(key), node);
}


void List::deleteFromHead()
{
	if (!empty()) {
		Node* node = head_->next_;
		remove(node);
		delete node;
	}
}


void List::deleteFromTail()
{
	if (!empty()) {
		Node* node = tail_->prev_;
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
	for (Node* i = head_->next_->next_; i != tail_; i = i->next_) {
		node = i;
		remove(node);
		add(searchPlace(node), node);
	}
}


int List::searchMax()
{
	int max = head_->next_->key_;
	for (Node* i = head_->next_->next_; i != tail_; i = i->next_)
		if (i->key_ > max)
			max = i->key_;
	return max;
}


int List::searchMin()
{
	int min = head_->next_->key_;
	for (Node* i = head_->next_->next_; i != tail_; i = i->next_)
		if (i->key_ < min)
			min = i->key_;
	return min;
}


Node* List::search(int key)
{
	for (Node* i = head_->next_; i != tail_; i = i->next_)
		if (i->key_ == key)
			return i;
	return nullptr;
}


bool List::operator==(const List& other)
{
	Node* node1 = head_->next_;
	Node* node2 = other.head_->next_;
	for (; node1->key_ == node2->key_ && node1 != tail_ && node2 != other.tail_; node1 = node1->next_, node2 = node2->next_);
	if (node1 == tail_ && node2 == other.tail_)
		return true;
	return false;
}


bool List::operator!=(const List& other)
{
	Node* node1 = head_->next_;
	Node* node2 = other.head_->next_;
	for (; node1->key_ == node2->key_ && node1 != tail_ && node2 != other.tail_; node1 = node1->next_, node2 = node2->next_);
	if (node1 == tail_ && node2 == other.tail_)
		return false;
	return true;
}


int& List::operator[](int index)
{
	return searchIndex(index)->key_;
}


List& List::operator=(const List& other)// ссылки
{
	if (this != &other) {
		clear();
		for (Node* i = other.head_->next_; i != other.tail_; i = i->next_)
			addToTail(i->key_);
	}
	return *this;
}


List& List::operator+=(const List& other)
{
	for (Node* i = other.head_->next_; i != other.tail_; i = i->next_)
		addToTail(i->key_);
	return *this;
}


List List::operator+(const List& other)
{
	return List(*this) += other;
}


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