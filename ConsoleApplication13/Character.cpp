#include <iostream>
#include "Character.h"
using namespace std;
int Character::enemy = 0;	//���� ���� �����ϱ� ���� ����ƽ����
void Character::set(int h, int m, int a, int d) {
	Hp = h, Mp = m, Armor = a, Damage = d;
}
void Character::game(Character& e) {
	int count = 1;	//���庰 ����Ƚ��
	int ct = 0;
	int round = 1;	//���� Ƚ��
	int select;		//�Ϲݰ��� or ��ų���� ����
	e.setting();	// Enemy ���ݼ���
	while (true) {
		cout << "<ROUND" << round << "-" << count << ">" << endl;
		cout << "��� : HP(" << Hp << ")    MP(" << Mp << ")" << endl;
		cout << "��� : HP(" << e.Hp << ")" << endl;
		cout << "1. �Ϲݰ���    2. ��ų���" << endl;
		cout << "���� : ";
		cin >> select;
		while (true) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "���ڸ� �Է��� �ּ���." << endl;
				cin >> select;
			}
			else {
				if (select == 1) {	//�Ϲݰ��ݽ� unskill()���� �Ϲݵ������� ����
					unskill();
					break;
				}
				else if (select == 2) {	//��ų���ݽ� skill()���� ��ų�������� ����
					skill();
					break;
				}
				else {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "1 �Ǵ� 2�� �Է����ּ���";
					cin >> select;
				}
			}
		}
		e.Hp = e.Hp - Damage + e.Armor;	//Enemy�� Hp�� �÷��̾��� Damage + Enemy�� �ƸӸ�ŭ ���ظ� �Դ´�.
		cout << "����� ��뿡�� " << Damage - e.Armor << "�� ���ظ� �������ϴ�" << endl;
		Hp = Hp - e.Damage + Armor;	//�÷��̾��� Hp�� Enemy�� Damage + �÷��̾��� Armor��ŭ�� ���ظ� �Դ´�.
		cout << "����� ���κ���  " << e.Damage - Armor << "�� ���ظ� �Ծ����ϴ�" << endl;
		if (e.Hp <= 0) {	//Enemy�� �ǰ� 0���ϰ� �Ǹ� 
			cout << "���� óġ�߽��ϴ�!" << endl;
			e.Hp = 40;		//Enemy�� �Ǹ� 40���� �ʱ�ȭ�ϸ� ���� ���� ����ϰ� �Ѵ�.
			round++;		//���带 �ϳ� ������Ű��
			count = 0;		//count�� 0���� ����
		}
		if ((enemy) == (round - 1)) {		//������ enemy�� ���� round-1(����� ��)�� ���� ������ �÷��̾� �¸�
			cout << "����� �¸��Ͽ����ϴ�" << endl;
			break;
		}
		if (Hp <= 0) {		//�÷��̾��� HP�� 0 ���ϰ� �Ǹ� �й�
			cout << "����� �й��Ͽ����ϴ�" << endl;
			break;
		}
		count++;		//count�� �������� ���� Ƚ�� ����
		cout << endl;
	}
}