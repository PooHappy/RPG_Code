#include <iostream>
#include "Wizard.h"
using namespace std;
void Wizard::setting() {		//������ ���� ����
	set(120, 80, 7, 10);
}
void Wizard::skill() {			//��ų����
	if (Mp == 0) {		//Mp�� �����ϸ� 
		cout << "������ �����մϴ�. ��ų ��뿡 �����Ͽ����ϴ�.";
		Damage = 5;		//Enemy�� Armor��ŭ �������� �༭ ���ذ� 0�� �ǰ� ��
	}
	else {				//Mp�� �������� ������
		Damage = 30;	//Damage�� Skill_Damage�� ����
		Mp -= 10;		//Mp�� 10��ŭ ���
	}
}
void Wizard::unskill() {		//��ų�����
	Damage = 10;		//Damage�� �⺻ ������ Damage�� ����
}