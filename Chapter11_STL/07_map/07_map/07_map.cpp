#include<vector>
#include<iostream>
#include<map>
using namespace std;

// 오늘의 주제 : map

class Player
{
public:
	Player() : _playerId(0) {	}
	Player(int playerId) : _playerId(playerId) { }

public:
	int _playerId;
};

int main()
{
	// vector, list, deque 은 시퀀스 컨테이너
	// map은 연관 컨테이너

#pragma region vector의 치명적 약점
	vector<Player*> v;

	// 1만명 입장
	for (int i = 0; i < 10000; i++)
	{
		Player* p = new Player(i);
		v.push_back(p);
	}

	// 5천명 퇴장
	for (int i = 0; i < 5000; i++)
	{
		int randIndex = rand() % v.size();

		Player* p = v[randIndex];
		delete p;

		v.erase(v.begin() + randIndex);
	}

	// (ID = 2만 플레이어)가 (ID = 1만 플레이어)를 공격하고 싶어요
	// Q) ID = 1만인 Player를 찾아주세요
	// A) 찾아본다
	bool found = false;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->_playerId == 1000)
		{
			found = true;
			break;
		}
	}

	// vector, list의 치명적인 단점
	// -> 원하는 조건에 해당하는 데이터를 빠르게 찾을 수 없다!
#pragma endregion

	// map : 균형 이진 트리 (AVL)
	// - 균형 이진 트리 : 오른쪽 서브트리의 높이와 왼쪽 서브 트리의 
	// - 높이 차이가 1 이하인 이진 탐색 트리.
	// - 노드 기반

	class Node
	{
	public:
		Node* _left;
		Node* _right;
		// DATA
		//int _key;
		//Player* _value;
		pair<int, Player*> _data;
	};

	// (Key, Value)
	map<int, int> m;

	pair<map<int, int>::iterator, bool> retInsert;	// <넣은 위치, 성공 여부>
	retInsert = m.insert(make_pair(1, 100));
	retInsert = m.insert(make_pair(1, 100));

	// 1만명 입장
	for (int i = 0; i < 10000; i++)
	{
		m.insert(pair<int, int>(i, i * 100));
	}

	// 5천명 퇴장
	unsigned int eraseCnt = 0;
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i = 0; i < 5000; i++)
	{
		int randValue = rand() % 10000;

		// Erase By Key
		// randValue 값이 있었다면 -> 1
		// randValue 값이 없었다면 -> 0
		eraseCnt = m.erase(randValue);
	}

	// Q) ID = 1000인 Player를 찾고 싶다!
	// A) 매우 빠르게 찾을 수 있음
	map<int, int>::iterator findIt = m.find(1000);
	if (findIt != m.end())
		cout << "찾음" << endl;
	else
		cout << "못찾음" << endl;

	// map 순회
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
	{
		pair<const int,int>& p = (*it);
		int key = (*it).first;
		int value = (*it).second;

		cout << key << " " << value << endl;
	}

	// 없으면 추가, 있으면 수정
	m[5] = 500;
	// [] 연산자 사용 시 주의점
	// 대입(=)을 하지 않더라도 데이터가 추가된다!!!
	m.clear();
	for (int i = 0; i < 10; i++)
		cout << m[i] << endl;	// m[i] = 0 과 같은 의미
	// 결론 : 조회만 하고 싶다면, m.find() 를 사용하자!

	return 0;
}