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
	while (m.Get_Play_Game() == false) {	//Judge를 통해 Play_Game이 true가 되면 while문 탈출
		cout << "-----Menu-----" << endl << "1. 난이도 설정하기" << endl << "2. 직업 선택하기" << endl << "3. 게임하기" << endl;
		cout << "선택 : ";
		m.Choose();		//난이도, 직업 설정 & 게임 시작 선택
	}
	if (m.Get_Player() == 1) {			//선택한 직업이 전사면
		Character* c = new Warrior();	//전사를 업캐스팅
		c->setting();					//전사의 스텟으로 설정한 후
		c->game(*e);					//게임시작
	}
	else if (m.Get_Player() == 2) {		//선택한 직업이 마법사면	
		Character* c = new Wizard();	//마법사를 업캐스팅
		c->setting();					//마법사의 스텟으로 설정한 후
		c->game(*e);					//게임시작
	}
	else {								//선택한 직업이 도적히면
		Character* c = new Thief();		//도적을 업캐스팅
		c->setting();					//도적의 스텟으로 설정한 후
		c->game(*e);					//게임시작
	}
}