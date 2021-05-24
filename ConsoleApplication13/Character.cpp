#include <iostream>
#include "Character.h"
using namespace std;
int Character::enemy = 0;	//적의 수를 설정하기 위한 스테틱변수
void Character::set(int h, int m, int a, int d) {
	Hp = h, Mp = m, Armor = a, Damage = d;
}
void Character::game(Character& e) {
	int count = 1;	//라운드별 전투횟수
	int ct = 0;
	int round = 1;	//라운드 횟수
	int select;		//일반공격 or 스킬공격 선택
	e.setting();	// Enemy 스텟설정
	while (true) {
		cout << "<ROUND" << round << "-" << count << ">" << endl;
		cout << "당신 : HP(" << Hp << ")    MP(" << Mp << ")" << endl;
		cout << "상대 : HP(" << e.Hp << ")" << endl;
		cout << "1. 일반공격    2. 스킬사용" << endl;
		cout << "선택 : ";
		cin >> select;
		while (true) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(256, '\n');
				cout << "숫자를 입력해 주세요." << endl;
				cin >> select;
			}
			else {
				if (select == 1) {	//일반공격시 unskill()통해 일반데미지로 설정
					unskill();
					break;
				}
				else if (select == 2) {	//스킬공격시 skill()통해 스킬데미지로 설정
					skill();
					break;
				}
				else {
					cin.clear();
					cin.ignore(256, '\n');
					cout << "1 또는 2만 입력해주세요";
					cin >> select;
				}
			}
		}
		e.Hp = e.Hp - Damage + e.Armor;	//Enemy의 Hp는 플레이어의 Damage + Enemy의 아머만큼 피해를 입는다.
		cout << "당신은 상대에게 " << Damage - e.Armor << "의 피해를 입혔습니다" << endl;
		Hp = Hp - e.Damage + Armor;	//플레이어의 Hp는 Enemy의 Damage + 플레이어의 Armor만큼의 피해를 입는다.
		cout << "당신은 상대로부터  " << e.Damage - Armor << "의 피해를 입었습니다" << endl;
		if (e.Hp <= 0) {	//Enemy의 피가 0이하가 되면 
			cout << "적을 처치했습니다!" << endl;
			e.Hp = 40;		//Enemy의 피를 40으로 초기화하며 다음 적을 상대하게 한다.
			round++;		//라운드를 하나 증가시키고
			count = 0;		//count를 0으로 설정
		}
		if ((enemy) == (round - 1)) {		//설정한 enemy의 수와 round-1(상대한 적)의 수가 같으면 플레이어 승리
			cout << "당신은 승리하였습니다" << endl;
			break;
		}
		if (Hp <= 0) {		//플레이어의 HP가 0 이하가 되면 패배
			cout << "당신은 패배하였습니다" << endl;
			break;
		}
		count++;		//count를 증가시켜 전투 횟수 증가
		cout << endl;
	}
}