#pragma once
#ifndef MENU_H
#define MENU_H
class Menu {
private:
	int Player;		//플레이어의 직업 선택
	bool Level = false;	//난이도 설정되면 true
	bool Job = false;	//플레이어의 직업 설정되면 true
	bool Play_Game = false;	//Level과 Job설정되면 true
public:
	int Get_Player();	//직업 반환
	bool Get_Play_Game();	//게임시작 반환
	void Select_Level();	//난이도 설정
	void Select_Job();		//직업 설정
	void Judge();
	void Choose();
};
#endif MENU_H