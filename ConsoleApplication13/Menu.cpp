#include <iostream>
#include "Menu.h"
#include "Character.h"
using namespace std;
int Menu::Get_Player() { return Player; }	//직업 반환
bool Menu::Get_Play_Game() { return Play_Game; }	//게임시작 반환
void Menu::Judge() {			//난이도와 직업 설정되었는지 판단
	if ((Job == true) & (Level == true)) {
		cout << "게임을 시작합니다!" << endl;
		Play_Game = true;
	}
	else
		cout << "모든 설정이 완료되지 않았습니다" << endl;
}
void Menu::Choose() {			//1,2,3선택하여 난이도, 직업, 게임시작선택
	int i;
	cin >> i;
	while (true) {		//무한루프
		if (cin.fail()) {	//입력된게 정수가 아니면
			cout << "숫자를 입력하세요 >> " << endl;
			cin.clear();	//fail비트 초기화
			cin.ignore(256, '\n');	//버퍼 초기화
			cin >> i;
		}
		else {				//입력돈게 정수면
			if (i == 1) {	//1) 난이도 선택
				Select_Level();
				break;
			}
			else if (i == 2) {	//2) 직업선택
				Select_Job();
				break;
			}
			else if (i == 3) {	//3) 게임시작
				Judge();
				break;
			}
			else {
				cout << "1,2,3중에 한 숫자만 입력해 주세요" << endl;
				cin >> i;
			}
		}
	}
}
void Menu::Select_Level() {	//난이도 선택
	cout << "[난이도 선택]" << endl;
	cout << "1.쉬움  2.보통  3.어려움" << endl;
	cout << "선택 : ";
	int i;
	cin >> i;
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "숫자를 입력해 주세요." << endl;
			cin >> i;
		}
		else {
			if (i == 1) {	//난이도 쉬움-> 적 3마리 
				Character::enemy = 3;	//적 3마리 설정
				cout << "난이도 쉬움 선택" << endl;
				Level = true;	//난이도 설정완료
				break;
			}
			else if (i == 2) {	//난이도 보통-> 적 4마리 
				Character::enemy = 4;		//적 4마리 설정
				cout << "난이도 보통 선택" << endl;
				Level = true;	//난이도 설정완료
				break;
			}
			else if (i == 3) {	//난이도 어려움-> 적5마리
				Character::enemy = 5;		//적 5마리 설정
				cout << "난이도 어려움 선택" << endl;
				Level = true;	//난이도 설정완료
				break;
			}
			else {
				cout << "1,2,3 중에 한 숫자만 입력해주세요" << endl;
				cin >> i;
			}
		}
	}
}
void Menu::Select_Job() {	//직업선택
	int i;
	cout << "[직업 선택]" << endl;
	cout << "1.전사  2.마법사  3.도적" << endl;
	cout << "선택 : ";
	cin >> i;
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "숫자를 입력해 주세요." << endl;
			cin >> i;
		}
		else {
			if (i == 1) {	//직업-> 전사
				Player = 1;	//전사 설정
				cout << "전사 선택" << endl;
				Job = true;	//직업 설정 완료
				break;
			}
			else if (i == 2) {	//직업->마법사
				Player = 2;		//마법사 설정 완료
				cout << "마법사 선택" << endl;
				Job = true;		//직업 설정 완료
				break;
			}
			else if (i == 3) {	//직업->도적
				Player = 3;		//도적 설정 완료
				cout << "도적 선택" << endl;
				Job = true;		//직업 설정 완료
				break;
			}
			else {
				cout << "1,2,3 중에 한 숫자만 입력해주세요" << endl;
				cin >> i;
			}
		}
	}
};