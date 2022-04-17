#include <iostream>
//#include <list>
using namespace std;

// 오늘의 주제 : list 구현

template<typename T>
class Node
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}

public:
	Node* _next;
	Node* _prev;
	T           _data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}

	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Iterator operator++(int)
	{
		Iterator<T> temp = *this;

		_node = _node->_next;

		return temp;
	}

	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	Iterator operator--(int)
	{
		Iterator<T> temp = *this;

		_node = _node->_prev;

		return temp;
	}

	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return (_node == right._node);
	}

	bool operator!=(const Iterator& right)
	{
		return (_node != right._node);
	}

public:
	Node<T>* _node;
};

template <typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>();
		_header->_next = _header;
		_header->_prev = _header;
	}

	~List()
	{
		while (_size > 0)
			pop_back();

		delete _header;
	}

	void push_back(const T& value)
	{
		AddNode(_header, value);
	}

	void pop_back()
	{
		RemoveNode(_header->_prev);
	}

	// <-> [header] <->
	Node<T>* AddNode(Node<T>* before, const T& value)
	{
		// 새로운 노드 생성 후 _data 넣어줌
		Node<T>* node = new Node<T>(value);

		// 추가할 노드
		node->_prev = before->_prev;
		node->_next = before;

		// prevNode 노드
		Node<T>* prevNode = before->_prev;
		prevNode->_next = node;

		// before 노드
		before->_prev = node;

		_size++;

		return node;
	}

	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode;
	}

	int size() { return _size; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(_header->_next); }

	iterator end() { return iterator(_header); }

	iterator insert(iterator it, const T& value)
	{
		Node<T>* node = AddNode(it._node, value);
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header;
	int _size;
};

int main()
{
	List<int> li;
	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			// 5번 인덱스에 값 i 를 넣고 eraseIt에 위치를 기억시킨다.
			eraseIt = li.insert(li.end(), i);
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back();

	li.erase(eraseIt);

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}