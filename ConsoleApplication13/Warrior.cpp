#include <iostream>
#include "Warrior.h"
using namespace std;
void Warrior::setting() {		//전사 스텟 세팅
	set(150, 60, 10, 13);
}
void Warrior::skill() {			//스킬사용시
	if (Mp == 0) {		//Mp가 부족하면 
		cout << "마나가 부족합니다. 스킬 사용에 실패하였습니다.";
		Damage = 5;		//Enemy의 Armor만큼 데미지를 줘서 피해가 0이 되게 함
	}
	else {				//Mp가 부족하지 않으면
		Damage = 15;	//Damage를 Skill_Damage로 변경
		Mp -= 10;		//Mp는 10만큼 사용
	}
}
void Warrior::unskill() {		//스킬사용후
	Damage = 13;		//Damage를 기본 스텟의 Damage로 설정
}