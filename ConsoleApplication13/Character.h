#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H
class Character {
protected:
	int Hp;
	int Mp;
	int Armor;
	int Damage;
	//�� ���� ����
public:
	static int enemy;
	virtual void setting() = 0;	//�����Լ� setting()
	virtual void unskill() = 0;	//�����Լ� unskill()
	virtual void skill() = 0;	//�����Լ� skill()
	void set(int h, int m, int a, int d);	//���� ���� �Լ�
	void game(Character& e);	//���� ���� �Լ�
};

#endif CHARACTER_H