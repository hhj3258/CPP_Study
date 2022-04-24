#include<iostream>
#include<deque>
#include<vector>
using namespace std;

// 오늘의 주제 : deque

// vector : 동적 배열
// [                     ]

// list : 이중 연결 리스트
// [ ] <-> [ ] <-> [ ] <-> [ ]

// deque : double-ended-queue 데크
// [             ]
// [             ]
// [             ]

int main()
{
	// 시퀀스 컨테이너 (Sequence Container)
	// 데이터가 삽입 순서대로 나열되는 형태
	// vector, list, deque

	vector<int> v(3, 1);
	deque<int> dq(3, 1);

	v.push_back(1);
	v.push_back(2);

	dq.push_back(1);
	dq.push_back(2);	// dq[4]

	dq.push_front(3);
	dq.push_front(4);

	deque<int>::iterator it = dq.begin() + 2;
	dq.insert(it, 6);

	// - deque의 동작 원리
	// - 중간 삽입/삭제 (BAD/BAD) 
	// --> 데이터는 연속적으로 존재하므로 데이터를 밀어줘야 함.(블럭끼리는 따로 존재하지만)
	// - 처음/끝 삽입/삭제 (GOOD/GOOD)
	// - 임의 접근 (OK)

	return 0;
}