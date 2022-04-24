#include<iostream>
#include<vector>
#include<list>
using namespace std;

// 오늘의 주제 : list
// - vector랑 기능이 겹쳐서 사실 많이 사용할 일은 없다.
// - vector가 동적배열 방식이라면, list는 노드 방식

// list : 연결 리스트
// 단일 / 이중(STL) / 원형

// 메모리에 연속적으로 저장되지 않는다.
// 다음 데이터의 '위치정보(포인터)'를 가지고 있는다.
// 각 데이터를 '노드'라고 한다.
// [1] - ...메모리들... -> [2] - ...메모리들... -> [3]

// 단일 : [1] -> [2] -> [3] -> [4]
// 이중 : [1] <-> [2] <-> [3] <-> [4] <-> [_Myhead : end() ] <-> [1]
// 원형 : [1] <-> [2] <-> [3] <-> [4] <-> [1]

// 노드는 병사, 리스트는 부대
class Node
{
public:
	// 노드 타입의 '포인터'를 들고 있다는 것에 유의하자. -> 결국은 포인터를 들고 있는 것
	// (Node 자체를 들고 있다면 Node 클래스 완성을 위해 재귀적으로 Node를 호출하게 되는 모순 발생)
	Node* _next;	//다음 노드 주소
	Node* _prev;	//이전 노드 주소
	int _data;			//원소 값
	
};

int main()
{
	// list (연결 리스트)
	// - list의 동작 원리
	// - 중간 삽입/삭제 (GOOD)
	// - 처음/끝 삽입/삭제 (GOOD)
	// - 임의 접근 (불가능)

	list<int> li;
	for (int i = 0; i < 100; i++)
		li.push_back(i);

	//li.push_front(10);
	int size = li.size();
	
	int first = li.front();
	int last = li.back();

	//li[3] = 10;		// Error! 임의 접근 불가

	// vector의 iterator와 내부 동작 방식은 다르다
	list<int>::iterator itBegin=li.begin();
	list<int>::iterator itEnd = li.end();

	int* ptrBegin = &(li.front());
	int* ptrEnd = &(li.back());

	// 메모리 구조를 보면 itEnd와 itBegin이 연결되어 있지만,
	// (--itBegin) 을 통해 itEnd로 가는 것은 안됨.
	// li.end() : 에러 방지용 더미 데이터
	//list<int>::iterator itTest1 = --itBegin;	// Error! : itEnd로 갈 수 없음.
	//list<int>::iterator itTest2 = --itEnd;		// OK!
	//list<int>::iterator itTest3 = ++itEnd;	// Error! : itBegin으로 갈 수 없음.

	for (list<int>::iterator it = li.begin(); it != li.end(); ++it)
	{
		cout << *it << endl;
	}

	//li.insert(itBegin, 100);
	//li.erase(li.begin());
	//li.pop_front();
	//li.remove(10);	// 값이 10인 원소를 '모두' 삭제한다

	// 중간 삽입/삭제의 시간복잡도?
	// * 임의 접근이 안 된다.
	// * 그런데 중간 삽입/삭제 시간복잡도는 O(1) ??
	// ex) 50번 인덱스에 있는 데이터 삭제!
	list<int>::iterator it = li.begin();
	for (int i = 0; i < 50; i++)
		++it;
	li.erase(it);
	// 결론: iterator 등과 같이 인덱스 위치를 기억하고 있을 때
	// 삭제한다면 O(1)이 맞음. 하지만 모른다면? O(n)

	return 0;
}