#include <iostream>
#include "Wizard.h"
using namespace std;
void Wizard::setting() {		//마법사 스텟 세팅
	set(120, 80, 7, 10);
}
void Wizard::skill() {			//스킬사용시
	if (Mp == 0) {		//Mp가 부족하면 
		cout << "마나가 부족합니다. 스킬 사용에 실패하였습니다.";
		Damage = 5;		//Enemy의 Armor만큼 데미지를 줘서 피해가 0이 되게 함
	}
	else {				//Mp가 부족하지 않으면
		Damage = 30;	//Damage를 Skill_Damage로 변경
		Mp -= 10;		//Mp는 10만큼 사용
	}
}
void Wizard::unskill() {		//스킬사용후
	Damage = 10;		//Damage를 기본 스텟의 Damage로 설정
}