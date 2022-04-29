#include <iostream>

// 오늘의 주제 : delete (삭제된 함수)

class Knight
{
public:
	Knight()
	{

	}

	// delete 사용방법
	// 완벽하게 삭제하는 방법
	// public 영역에 쓰는 게 관례
	void operator=(const Knight& k) = delete;

private:
	// 반쪽짜리 삭제 방법
	Knight(const Knight& rhs);
	// friend 는 접근이 가능하도록 만들 수도 있다. <- 사실 하면 안됨.
	friend class Admin;
};

class Admin
{
public:
	void CopyKnight(const Knight& rhs)
	{
		Knight k(rhs);
	}
};

int main()
{
	Knight k1;
	Knight k2;

	//k1 = k2;    // Error!

	return 0;
}