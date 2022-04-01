#include<iostream>
using namespace std;
#include "Player.h"

// 오늘의 주제 : 전방선언
// [항상 전방선언을 사용하되, 상속 구조와 같이 
// 정말 어쩔 수 없는 상황에서만 헤더에서 헤더를 포함]

int main()
{
	// Player 는 몇 바이트?
	// - int 2개 = 4 * 2 = 8 byte

	Player p1;	// 지역변수 (Stack)
	Player* p2 = new Player();	// 동적할당 (Heap)
	p1._targetP2 = p2;

	return 0;
}