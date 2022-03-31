#pragma once

// ���漱��: Player ��� Ŭ������ �Ʒ����� ������ ����!
class Player;
class Field;

// is - a = ���� �� �÷��̾��
// has - a = ���� �� �÷��̾ ������
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

