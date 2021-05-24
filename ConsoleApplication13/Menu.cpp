#include <iostream>
#include "Menu.h"
#include "Character.h"
using namespace std;
int Menu::Get_Player() { return Player; }	//���� ��ȯ
bool Menu::Get_Play_Game() { return Play_Game; }	//���ӽ��� ��ȯ
void Menu::Judge() {			//���̵��� ���� �����Ǿ����� �Ǵ�
	if ((Job == true) & (Level == true)) {
		cout << "������ �����մϴ�!" << endl;
		Play_Game = true;
	}
	else
		cout << "��� ������ �Ϸ���� �ʾҽ��ϴ�" << endl;
}
void Menu::Choose() {			//1,2,3�����Ͽ� ���̵�, ����, ���ӽ��ۼ���
	int i;
	cin >> i;
	while (true) {		//���ѷ���
		if (cin.fail()) {	//�ԷµȰ� ������ �ƴϸ�
			cout << "���ڸ� �Է��ϼ��� >> " << endl;
			cin.clear();	//fail��Ʈ �ʱ�ȭ
			cin.ignore(256, '\n');	//���� �ʱ�ȭ
			cin >> i;
		}
		else {				//�Էµ��� ������
			if (i == 1) {	//1) ���̵� ����
				Select_Level();
				break;
			}
			else if (i == 2) {	//2) ��������
				Select_Job();
				break;
			}
			else if (i == 3) {	//3) ���ӽ���
				Judge();
				break;
			}
			else {
				cout << "1,2,3�߿� �� ���ڸ� �Է��� �ּ���" << endl;
				cin >> i;
			}
		}
	}
}
void Menu::Select_Level() {	//���̵� ����
	cout << "[���̵� ����]" << endl;
	cout << "1.����  2.����  3.�����" << endl;
	cout << "���� : ";
	int i;
	cin >> i;
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "���ڸ� �Է��� �ּ���." << endl;
			cin >> i;
		}
		else {
			if (i == 1) {	//���̵� ����-> �� 3���� 
				Character::enemy = 3;	//�� 3���� ����
				cout << "���̵� ���� ����" << endl;
				Level = true;	//���̵� �����Ϸ�
				break;
			}
			else if (i == 2) {	//���̵� ����-> �� 4���� 
				Character::enemy = 4;		//�� 4���� ����
				cout << "���̵� ���� ����" << endl;
				Level = true;	//���̵� �����Ϸ�
				break;
			}
			else if (i == 3) {	//���̵� �����-> ��5����
				Character::enemy = 5;		//�� 5���� ����
				cout << "���̵� ����� ����" << endl;
				Level = true;	//���̵� �����Ϸ�
				break;
			}
			else {
				cout << "1,2,3 �߿� �� ���ڸ� �Է����ּ���" << endl;
				cin >> i;
			}
		}
	}
}
void Menu::Select_Job() {	//��������
	int i;
	cout << "[���� ����]" << endl;
	cout << "1.����  2.������  3.����" << endl;
	cout << "���� : ";
	cin >> i;
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "���ڸ� �Է��� �ּ���." << endl;
			cin >> i;
		}
		else {
			if (i == 1) {	//����-> ����
				Player = 1;	//���� ����
				cout << "���� ����" << endl;
				Job = true;	//���� ���� �Ϸ�
				break;
			}
			else if (i == 2) {	//����->������
				Player = 2;		//������ ���� �Ϸ�
				cout << "������ ����" << endl;
				Job = true;		//���� ���� �Ϸ�
				break;
			}
			else if (i == 3) {	//����->����
				Player = 3;		//���� ���� �Ϸ�
				cout << "���� ����" << endl;
				Job = true;		//���� ���� �Ϸ�
				break;
			}
			else {
				cout << "1,2,3 �߿� �� ���ڸ� �Է����ּ���" << endl;
				cin >> i;
			}
		}
	}
};