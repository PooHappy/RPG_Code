#pragma once
#ifndef MENU_H
#define MENU_H
class Menu {
private:
	int Player;		//�÷��̾��� ���� ����
	bool Level = false;	//���̵� �����Ǹ� true
	bool Job = false;	//�÷��̾��� ���� �����Ǹ� true
	bool Play_Game = false;	//Level�� Job�����Ǹ� true
public:
	int Get_Player();	//���� ��ȯ
	bool Get_Play_Game();	//���ӽ��� ��ȯ
	void Select_Level();	//���̵� ����
	void Select_Job();		//���� ����
	void Judge();
	void Choose();
};
#endif MENU_H