#include <iostream>
#include "Warrior.h"
using namespace std;
void Warrior::setting() {		//���� ���� ����
	set(150, 60, 10, 13);
}
void Warrior::skill() {			//��ų����
	if (Mp == 0) {		//Mp�� �����ϸ� 
		cout << "������ �����մϴ�. ��ų ��뿡 �����Ͽ����ϴ�.";
		Damage = 5;		//Enemy�� Armor��ŭ �������� �༭ ���ذ� 0�� �ǰ� ��
	}
	else {				//Mp�� �������� ������
		Damage = 15;	//Damage�� Skill_Damage�� ����
		Mp -= 10;		//Mp�� 10��ŭ ���
	}
}
void Warrior::unskill() {		//��ų�����
	Damage = 13;		//Damage�� �⺻ ������ Damage�� ����
}