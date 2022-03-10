#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습 문제

int N;
const int MAX = 100;
int board[MAX][MAX];

void PrintBoard()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setfill('0') << setw(2) << board[i][j] << ' ';
		}
		cout << '\n';
	}
}

enum DIR
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP = 3,
};

bool CanGo(int i, int j)
{
	if (i < 0 || i >= N)
		return false;
	if (j < 0 || j >= N)
		return false;
	if (board[i][j] != 0)
		return false;

	return true;
}

void SetBoard()
{
	int now_num = 1;
	int i = 0;
	int j = 0;
	int dir = RIGHT;

	int di[] = { 0,1,0,-1 };
	int dj[] = { 1,0,-1,0 };

	while (true)
	{
		board[i][j] = now_num;

		if (now_num == N * N)
			break;

		int nextI = i + di[dir];
		int nextJ = j + dj[dir];

		if (CanGo(nextI, nextJ))
		{
			i = nextI;
			j = nextJ;
			now_num++;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();

	return 0;
}