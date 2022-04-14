#include<iostream>
#include<vector>
using namespace std;

// 오늘의 주제 : vector 구현


template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr)
	{

	}

	Iterator(T* ptr) :_ptr(ptr)
	{

	}

	// ++iterator
	Iterator& operator++ ()
	{
		_ptr++;
		return *this;
	}

	// iterator++
	Iterator operator++ (int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator& operator-- ()
	{
		_ptr--;
		return *this;
	}

	Iterator operator-- (int)
	{
		Iterator temp = *this;
		_ptr--;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	Iterator operator-(const int count)
	{
		Iterator temp = *this;
		temp._ptr -= count;
		return temp;
	}

	bool operator== (const Iterator& right)
	{
		return (_ptr == right._ptr);
	}

	bool operator!= (const Iterator& right)
	{
		// 위에서 만든 operator== 을 호출한다.
		return !(_ptr == right._ptr);
	}

	T& operator*()
	{
		return *_ptr;
	}

public:
	T* _ptr;
};

template<typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0)
	{

	}

	~Vector()
	{
		// _data != nullptr 이면
		if (_data)
			delete[] _data;
	}

	// [             ]
	void push_back(const T& val)
	{
		// 벡터가 꽉 찼으면 증설
		if (_size == _capacity)
		{
			int newCapacity = static_cast<int>(_capacity * 1.5);

			// 예외상황) newCapacity가 정수이므로 증가하지 않을 수도 있음
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_data[_size] = val;
		_size++;
	}

	void reserve(int capacity)
	{
		_capacity = capacity;

		// 더 큰 영역 할당
		T* newData = new T[_capacity];

		// 데이터 복사
		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		// 이전 데이터 삭제
		if (_data)
			delete[] _data;

		_data = newData;
	}

	T& operator[] (const int idx) { return _data[idx]; }

	int size() { return _size; }
	int capacity() { return _capacity; }

	// 단순히 커서를 맨 앞으로 옮겨준다.
	// (실제 vector 클래스에서는 clear() 후에 남아있는 원소들에 접근을 못하도록 막아놨음)
	void clear() { _size = 0; }

public:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator(&_data[0]); }
	iterator end() { return (begin() + _size); }

private:
	T* _data;
	int _size;
	int _capacity;
};

int main()
{
	Vector<int> v;
	vector<int> test_v;
	test_v.push_back(111);
	//v.reserve(100);	//capacity 설정

	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.size() << " " << v.capacity() << endl;
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	cout << "------------------------------------" << endl;
	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << endl;
	}

	return 0;
}