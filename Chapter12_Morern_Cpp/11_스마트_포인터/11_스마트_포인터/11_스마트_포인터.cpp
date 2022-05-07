#include<iostream>
using namespace std;

// 오늘의 주제 : 스마트 포인터(smart pointer)

class Knight
{
public:
	Knight() { cout << "Knight 생성" << endl; }
	~Knight() { cout << "Knight 소멸" << endl; }

	void Attack()
	{
		if (_target)
		{
			_target->_hp -= _damage;
			cout << "HP: " << _target->_hp << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	shared_ptr<Knight> _target = nullptr;
};

// weak_ptr을 들고있는 Knight 클래스
class WKnight
{
public:

	void Attack()
	{
		// _target의 포인터가 날아가지 않았다면
		if (_target.expired() == false)
		{
			// _target이 유효하다면 shared_ptr을 받아와서 사용
			shared_ptr<WKnight> sptr = _target.lock();

			sptr->_hp -= _damage;
			cout << "HP: " << sptr->_hp << endl;
		}
		else
		{
			cout << "_target이 유효하지 않음" << endl;
		}
	}

public:
	int _hp = 100;
	int _damage = 10;
	weak_ptr<WKnight> _target;
};

/////////////////////////////////////////////////////////////////////

// 참조 횟수 관리 클래스
class RefCountBlock
{
public:
	// refCount가 0이 되면 아무도 참조하지 않는 것 -> 메모리 날려도 됨
	int _refCount = 1;
	int _weakCount = 1;
};


// shared_ptr : 참조 카운트 방식
template<typename T>
class SharedPtr
{
public:
	SharedPtr() { }	// 이 땐 아무것도 안함

	SharedPtr(T* ptr) : _ptr(ptr)
	{
		if (_ptr != nullptr)
		{
			_block = new RefCountBlock();
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	SharedPtr(const SharedPtr& rhs) : _ptr(rhs._ptr), _block(rhs._block)
	{
		// rhs가 nullptr이 아니었다면
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	void operator=(const SharedPtr& rhs)
	{
		_ptr = rhs._ptr;
		_block = rhs._block;

		// rhs가 nullptr이 아니었다면
		if (_ptr != nullptr)
		{
			_block->_refCount++;
			cout << "RefCount : " << _block->_refCount << endl;
		}
	}

	~SharedPtr()
	{
		// 참조하고 있는 포인터가 있다면
		if (_ptr != nullptr)
		{
			_block->_refCount--;
			cout << "RefCount : " << _block->_refCount << endl;

			// 참조 횟수가 0이라면
			if (_block->_refCount == 0)
			{
				// 포인터와 블럭을 삭제한다.
				delete _ptr;
				delete _block;

				cout << "Delete Data" << endl;
			}
		}
	}

public:
	T* _ptr = nullptr;    // 여러 타입의 포인터 지원
	RefCountBlock* _block = nullptr;
};

int main()
{
#pragma region 쌩 포인터를 쓸 때의 문제점

	// - 댕글링 포인터(Dangling Pointer) : 포인터가 여전히 해제된 메모리 영역을 가리키는 문제
	/*
	{
		Knight* k1 = new Knight();
		Knight* k2 = new Knight();

		k1->_target = k2;

		delete k2;

		// 위험!) k2는 이미 delete 되었는데 Attack()에서 k2에 접근하고 있음
		// -> 메모리 오염 발생
		k1->Attack();
	}
	*/

#pragma endregion

#pragma region 스마트 포인터

	/*

	// 스마트 포인터 : 포인터를 알맞은 정책에 따라 관리하는 객체
	// - 포인터를 래핑(wrapping)해서 사용
	// shared_ptr, weak_ptr, unique_ptr

	SharedPtr<Knight> k2;
	{
		SharedPtr<Knight> k1(new Knight());
		cout << "-----------------------------------" << endl;
		k2 = k1;
		cout << "-----------------------------------" << endl;
	}
	cout << "-----------------------------------" << endl << endl;


	shared_ptr<Knight> k3 = make_shared<Knight>();
	{
		shared_ptr<Knight> k4 = make_shared<Knight>();
		k3->_target = k4;
	}
	// 여전히 k3._target이 k4의 포인터를 참조하고 있다.
	k3->Attack();

	*/

#pragma endregion

#pragma region shared_ptr의 순환참조 문제

	// 아래의 경우 kk1과 kk2 모두 참조카운트 값이 최소 1 이상을 유지하게 된다.
	// 메모리가 삭제되지 않는다.
	shared_ptr<Knight> kk1 = make_shared<Knight>();

	shared_ptr<Knight> kk2 = make_shared<Knight>();

	// kk1 <-> kk2 서로 주시(참조)하고 있다
	kk1->_target = kk2;
	kk2->_target = kk1;

	kk1->Attack();

	// 순환참조 해결 : 순환참조하고 있는 것들을 직접 순환 구조를 끊어준다.
	kk1->_target = nullptr;
	kk2->_target = nullptr;

#pragma endregion

#pragma region weak_ptr을 사용한 순환참조 해결

	shared_ptr<WKnight> wk1 = make_shared<WKnight>();

	{
		shared_ptr<WKnight> wk2 = make_shared<WKnight>();

		// target이 이제 weak_ptr 이다.
		// - weak_ptr<WKnight> _target;
		wk1->_target = wk2;
		wk2->_target = wk1;

		// wk2는 이 블럭을 넘어가면 해제된다.
	}

	wk1->Attack();	// _target이 유효하지 않음

#pragma endregion


	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr;	// error!) unique_ptr은 유일해야 함.
	unique_ptr<Knight> uptr2 = std::move(uptr);

	cout << "-----------------------------------" << endl;
	return 0;
}