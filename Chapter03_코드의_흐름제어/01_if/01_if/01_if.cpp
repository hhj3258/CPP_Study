#include <iostream>
using namespace std;

enum {
	SCISSORS = 1,
	ROCK,
	PAPER
};

void Game01(int user, int computer, int* score, int* cnt);

int main()
{
	srand(time(0));

	int score=0;
	int cnt=1;

	while (true) {
		cout << "가위(1) 바위(2) 보(3) 골라주세요!" << endl;
		int user;
		cin >> user;

		int computer = rand()%3;

		if (user > 3) break;
		Game01(user, computer, &score, &cnt);
		
	}
}

void Game01(int user, int computer, int* score, int* cnt) {
    int isWin;
	if (user == SCISSORS) {
		cout << "가위(유저) vs ";
		if (computer == SCISSORS) {
			cout << "가위(컴퓨터) 비겼습니다.";
			isWin = 1;
		}
		else if (computer == ROCK) {
			cout << "바위(컴퓨터) 졌습니다..." ;
			isWin = 0;
		}
		else {
			cout << "보(컴퓨터) 이겼습니다!";
			isWin = 2;
		}
		cout << endl;
	}
	else if (user == ROCK) {
		cout << "바위(유저) vs ";
		if (computer == SCISSORS) {
			cout << "가위(컴퓨터) 이겼습니다!";
			isWin = 2;
		}
		else if (computer == ROCK) {
			cout << "바위(컴퓨터) 비겼습니다.";
			isWin = 1;
		}
		else {
			cout << "보(컴퓨터) 졌습니다...";
			isWin = 0;
		}
		cout << endl;
	}
	else {
		cout << "보(유저) vs ";
		if (computer == SCISSORS) {
			cout << "가위(컴퓨터) 졌습니다...";
			isWin = 0;
		}
		else if (computer == ROCK) {
			cout << "바위(컴퓨터) 이겼습니다!";
			isWin = 2;
		}
		else {
			cout << "보(컴퓨터) 비겼습니다.";
			isWin = 1;
		}
		cout << endl;
	}

	cout << "현재 승률 : ";
	if (isWin == 0) {
		cout << *score / *cnt;
		(*cnt)++;
	}
	else if (isWin == 2) {
		*score += 100;
		cout << *score / *cnt;
		(*cnt)++;
	}
	else {
		cout << *score / *cnt;
	}
	cout << "%" << endl;
	
}

