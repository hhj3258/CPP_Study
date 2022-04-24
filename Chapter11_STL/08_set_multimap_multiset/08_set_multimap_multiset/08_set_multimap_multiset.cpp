#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>

// 오늘의 주제 : set, multimap, multiset
// - multimap : 중복을 허용하는 map
// - multiset : 중복을 허용하는 set

int main()
{
	multimap<int, int> mm;

	// 넣기
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 400));
	mm.insert(make_pair(2, 500));
	// mm[1] =500;		// [ ] 연산자 사용 불가

	// 빼기
	// key 1에 해당하는 모든 value가 삭제된다.
	unsigned int count = mm.erase(1);	// count = 3

	// iterator를 사용하여 동일 key의 1개의 value만 삭제
	multimap<int, int>::iterator itFind = mm.find(2);
	if (itFind != mm.end())
		mm.erase(itFind);
	

	// 특정 키 값의 범위 찾기(순회하기)
	mm.insert(make_pair(3, 600));
	mm.insert(make_pair(3, 700));
	mm.insert(make_pair(3, 800));

	auto itLower = mm.lower_bound(3);
	auto itUpper = mm.upper_bound(3);

	for (auto it = itLower; it != itUpper; ++it)
		cout << (*it).first << " " << (*it).second << endl;

	return 0;
}