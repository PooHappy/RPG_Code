#include <iostream>
#include "Thief.h"
using namespace std;
void Thief::setting() {		//���� ���� ����
	set(120, 60, 7, 16);
}
void Thief::skill() {			//��ų����
	if (Mp == 0) {		//Mp�� �����ϸ� 
		cout << "������ �����մϴ�. ��ų ��뿡 �����Ͽ����ϴ�.";
		Damage = 5;		//Enemy�� Armor��ŭ �������� �༭ ���ذ� 0�� �ǰ� ��
	}
	else {				//Mp�� �������� ������
		Damage = 24;	//Damage�� Skill_Damage�� ����
		Mp -= 10;		//Mp�� 10��ŭ ���
	}
}
void Thief::unskill() {		//��ų�����
	Damage = 16;		//Damage�� �⺻ ������ Damage�� ����
}