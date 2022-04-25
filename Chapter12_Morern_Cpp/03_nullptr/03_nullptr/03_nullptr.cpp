#include <iostream>
#include <memory>
using namespace std;

// 오늘의 주제 : nullptr

class Knight
{
public:
	void Test()
	{

	}
};

Knight* FindKnight()
{
	// TODO

	return nullptr;
}

void Test(int a)
{
	cout << "Test(int a)" << endl;
}

void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}

// nullptr 구현
const
class
{
public:
	// 그 어떤 타입의 포인터와도 치환 가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	// 그 어떤 타입의 멤버 포인터와도 치환 가능
	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	// 주소값 &를 막는다
	// ex) &_nullptr 과 같이 쓸 수 없음.
	void operator&() const; 
}  _nullptr; // const NullPtr _nullptr; 이라고 쓴 것과 같음(객체 생성)

int main()
{
	// nullptr
	// - 오동작 방지
	// - 가독성 증가

	int* ptr1 = NULL;   // c++ 11 이전 문법
	int* ptr2 = nullptr;

	// 1) 오동작 방지
	Test(0);
	// NULL : 0을 #define 한 것
	Test(NULL);     // Test(int) 호출, 의도와 다르게 동작.
	Test(nullptr);  // Test(void*) 호출

	// 2) 가독성 증가
	auto* knight = FindKnight();
	if (knight == nullptr)
	{
	}


#pragma region 직접 구현한 nullptr 사용
	Test(_nullptr);

	if (knight == _nullptr) {}

	void (Knight:: * memFunc)();
	memFunc = &Knight::Test;

	if (memFunc == _nullptr)
	{

	}

#pragma endregion

	return 0;
}
