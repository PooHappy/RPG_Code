#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
class Character {
protected:
	int Hp;
	int Mp;
	int Armor;
	int Damage;
	//각 스텟 설정
public:
	static int enemy;
	virtual void setting() = 0;	//가상함수 setting()
	virtual void unskill() = 0;	//가상함수 unskill()
	virtual void skill() = 0;	//가상함수 skill()
	void set(int h, int m, int a, int d);	//스텟 설정 함수
	void game(Character& e);	//게임 시작 함수
};

#endif CHARACTER_H