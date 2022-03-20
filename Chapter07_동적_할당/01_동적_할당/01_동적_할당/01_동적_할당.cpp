#include<iostream>
using namespace std;

// 오늘의 주제 : 동적 할당

// 메모리 구조 복습!
// - 실행할 코드가 저장되는 영역 -> 코드 영역
// - 전역(global)/정적(static) 변수 -> 데이터 영역
// - 지역 변수/매개 변수 -> 스택 영역
// - 동적 할당 -> 힙 영역

// 지금까지 데이터 영역 / 스택 영역을 이용해서
// 이런 저런 프로그램을 잘 만들어 왔다!
// 굳이 새로운 영역이 필요할까?

// 실제 상황)
// - MMORPG 동접 1명~5만명, 몬스터 1마리~500만마리
// - 몬스터 생성 이벤트 -> 5분동안 몬스터가 10배 많이 나옴

// - 스택 영역
// 함수가 끝나면 같이 정리되는 불안정한 메모리
// 잠시 함수에 매개변수 넘긴다거나, 하는 용도로는 OK
// - 메모리 영역
// 프로그램이 실행되는 도중에는 '무조건' 사용되는 공간

// 희망사항)
// - 필요할 때만 사용하고, 필요없으면 반납할 수 있는!
// - 그러면서도 (스택과는 다르게) 우리가 생성/소멸 시점을 관리할 수 있는!
// - 그런 아름다운 메모리 없나? -> HEAP
// 동적할당과 연관된 함수/연산자 : malloc 과 free,    new 와 delete,    new[] 와 delete[]

// malloc
// - 할당할 메모리 크기를 건내준다.
// - 메모리 할당 후 시작 주소를 가리키는 포인터를 반환해준다 (메모리 부족 시 NULL)
// free
// - malloc (혹은 기타 calloc, realloc 등의 사촌) 을 통해 할당된 영역을 해제
// - 힙 관리자가 할당/미할당 여부를 구분해서 관리

// new , delete
// - c++에서 추가됨
// - malloc/free는 함수!   new/delete는 연산자(operator)

// new가 malloc에 비해 좋긴 한데~ 배열과 같이 N개 데이터를 같이 할당하려면?
// - new[] / delete[]

// malloc/free vs new/delete
// - 사용 편의성 -> new/delete 승!
// - 타입에 상관없이 특정한 크기의 메모리 영역을 할당받으려면? -> malloc/free 승!
// 
// 그런데 둘의 가장 가장 근본적인 중요한 차이는 따로 있음!
// new/delete는 (생성타입이 클래스일 경우) 생성자/소멸자를 호출해준다!!!


class Monster
{
public:
	Monster()
	{
		cout << "Monster()" << endl;
	}

	~Monster()
	{
		cout << "~Monster()" << endl;
	}

public:
	int _hp;
	int _x;
	int _y;
};

int main()
{
	// 스택영역에 이런 배열을 선언하게 될 때 문제 발생
	// 	1. 스택 오버플로우 -> 배열 크기가 너무 큼.
	// 2. 유저 수가 적어도 몬스터가 항상 500만마리 준비되어 있음. 메모리 낭비.
	//Monster monster[500 * 10000];

	// 유저 영역 [메모장] [LOL] [곰플레이어]
	// -------------------------------------------
	// 커널 영역 (Windows 등의 핵심 코드)

	// 유저 영역) 운영체제에서 제공하는 API 호출 -> 메모리 줘
	// 커널 영역) 메모리 할당해서 건내줌
	// 유저 영역) ㄳㄳ 잘쓸게요~

	// 커널 영역은 기본적으로 바쁘기 때문에 유저 영역에서는 메모리 요청 시 
	// 큼지막하게(여유있게) 한 번에 메모리를 요청한다.
	// [                                                         ] <- 큼지막하게 요청하고 잘라쓴다.
	// c++에서는 기본적으로 CRT(C런타임 라이브러리)의 [힙 관리자] 를 통해 힙 영역 사용
	// 단, 정말 원한다면 우리가 직접 API를 통해 힙을 생성하고 관리할 수도 있음 (MMORPG 서버 메모리 풀링)
	
	// size_t 가 있는 헤더 파일에 정의되어 있는 size_t
	// 64비트 체제에서 size_t == unsigned __int64
	// 그 이외 체제에서 size_t == unsigned int
#ifdef _WIN64
	typedef unsigned __int64 size_t;
#else
	typedef unsigned int     size_t;
#endif

	// 그런데 잠깐! void* 는 무엇일까?
	// * 가 있으니까 포인터는 포인터 (주소를 담는 바구니) => OK
	// 타고 가면 void 아무것도 없다 ? => NO
	// 타고 가면 void 이고, 뭐가 있는지 모르겠으니까 너가 적당히 변환해서 사용해라 => OK
	void* pointer = malloc(sizeof(Monster));

	Monster* m1 = (Monster*)pointer;
	m1->_hp = 100;
	m1->_x = 1;
	m1->_y = 2;

	// 다 쓰고 나서 해제
	free(pointer);

	// Heap Overflow
	// - 유효한 힙 범위를 초과해서 사용하는 문제
	// ex) malloc(4) 로 할당했다면, Monster의 크기보다 작게 할당해줬기 때문에 문제가 생김.

	// Double Free
	// 	- free()를 두 번 사용해서 생기는 문제. -> 해제된 메모리를 또 해제하면 문제.
	// - 이건 대부분 그냥 크래시만 나고 끝난다.

	// Use-After-Free
	// - 해제된 메모리에 접근해서 무언가 수정하면 생기는 문제.
	// free(pointer);
	// m1->_hp = 200;
	// 
	// 바로 크래시가 나면 다행이지만 그렇지 않을 확률도 매우 큼.
	// 동적 할당 및 해제를 정확하게 알고 사용해야 하는 이유.
	// 
	// 해제 후 nullptr 등으로 깔끔하게 밀어주는 방법 등으로 예방 가능.
	//free(pointer);
	//pointer = nullptr;
	//m1 = nullptr;


	// new 와 delete
	Monster* m2 = new Monster;
	m2->_hp = 200;
	m2->_x = 2;
	m2->_y = 3;
	delete m2;

	// new[] 와 delete[]
	Monster* m3 = new Monster[5];
	m3->_hp = 200;
	m3->_x = 2;
	m3->_y = 3;

	Monster* m4 = (m3 + 1);
	m4->_hp = 300;
	m4->_x = 4;
	m4->_y = 5;

	delete[] m3;

	return 0;
}