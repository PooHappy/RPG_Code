#include <iostream>
#include "Menu.h"
#include "Character.h"
#include "Enemy.h"
#include "Thief.h"
#include "Warrior.h"
#include "Wizard.h"
using namespace std;
int main() {
	Menu m;
	cout << "Dengeon Adventure!" << endl;
	Character* e = new Enemy();
	while (m.Get_Play_Game() == false) {	//Judge�� ���� Play_Game�� true�� �Ǹ� while�� Ż��
		cout << "-----Menu-----" << endl << "1. ���̵� �����ϱ�" << endl << "2. ���� �����ϱ�" << endl << "3. �����ϱ�" << endl;
		cout << "���� : ";
		m.Choose();		//���̵�, ���� ���� & ���� ���� ����
	}
	if (m.Get_Player() == 1) {			//������ ������ �����
		Character* c = new Warrior();	//���縦 ��ĳ����
		c->setting();					//������ �������� ������ ��
		c->game(*e);					//���ӽ���
	}
	else if (m.Get_Player() == 2) {		//������ ������ �������	
		Character* c = new Wizard();	//�����縦 ��ĳ����
		c->setting();					//�������� �������� ������ ��
		c->game(*e);					//���ӽ���
	}
	else {								//������ ������ ��������
		Character* c = new Thief();		//������ ��ĳ����
		c->setting();					//������ �������� ������ ��
		c->game(*e);					//���ӽ���
	}
}