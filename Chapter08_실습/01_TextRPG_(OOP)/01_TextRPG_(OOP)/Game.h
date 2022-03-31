#pragma once

// 전방선언: Player 라는 클래스가 아래에서 등장할 것임!
class Player;
class Field;

// is - a = 게임 은 플레이어냐
// has - a = 게임 이 플레이어를 가지냐
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();

private:
	Player* _player;
	Field* _field;
};

