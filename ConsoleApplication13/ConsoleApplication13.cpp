#include <iostream>
using namespace std;
static int Won=0;
static int Sun=0;
static int Sagak=0;
static bool drawing=false;
static bool Show = false;
static bool Inf = false;
static bool Exit = false;
class Shape  {
	Shape* next;
protected:
	virtual void draw() = 0;
public :
	Shape() { next = NULL; }
	virtual ~Shape() {}
	void paint() { draw(); };
	Shape* add(Shape* p) { this->next = p; return p; };
	Shape* getNext() { return next; }
};
class Circle :public Shape {
protected :
	virtual void draw() {
		cout << "--Circle--" << endl;
	}
public :

}; 
class Rect :public Shape {
protected:
	virtual void draw() {
		cout << "--Rectangle--" << endl;
	}
public:

}; 
class Line :public Shape {
protected:
	virtual void draw() {
		cout << "--Line--" << endl;
	}
public:

};

class UI {
public :
	static int Won;
	static int Sun;
	static int Sagak;
	static bool drawing;
	static bool Show;
	static bool Inf;
	static bool Exit;
	void Select_Shape() {
		int i;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cout << "숫자만 입력하세요." << endl;
				cin.clear();
				cin.ignore();
			}
			else {
				if (i == 1) {
					Sun++;
					drawing = true;
					break;
				}
				else if (i == 2) {
					Won++; 
					drawing = true;
					break;
				}
				else if (i == 3) {
					Sagak++;
					drawing = true;
					break;
				}
				else {
					cout << "1,2,3 중 하나만 입력하세요" << endl;
				}
			}
		}
	}
	void Select_Delete() {
		int i;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cout << "숫자만 입력하세요." << endl;
				cin.clear();
				cin.ignore();
			}
			else {
				if (i == 1) {
					Sun--;
					break;
				}
				else if (i == 2) {
					Won--;
					break;
				}
				else if (i == 3) {
					Sagak--;
					break;
				}
				else {
					cout << "1,2,3 중 하나만 입력하세요" << endl;
				}
			}
		}
	}
	void Select_AllShow() {
		Show = true;
	}
	void Select_Information() {
		Inf = true;
	}
	void Select_OFF() {
		Exit = true;
	}
	void Choose() {
		int i;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cout << "숫자만 입력하세요." << endl;
				cin.clear();
				cin.ignore();
			}
			else {
				if (i == 1) {
					Select_Shape();
					break;
				}
				else if (i == 2) {
					Select_Delete();
					break;
				}
				else if (i == 3) {
					Select_AllShow();
					break;
				}
				else if (i == 4) {
					Select_Information();
				}
				else if (i == 5) {
					Select_OFF();
				}
				else {
					cout << "1,2,3,4,5 중 하나만 입력하세요" << endl;
				}
			}
		}
	}
};
class GraphicEditor {
private :
	Shape* pStart;
	Shape* pLast;
public :
	GraphicEditor() {
		pStart = NULL;
		pLast = NULL;
	}
	~GraphicEditor() {
		Shape* p = pStart;
		while (p != pStart) {
			Shape* q = p->getNext();
			delete p;
			p = q;
		}
	}
	void run();
};
void GraphicEditor::run() {

}
int main()
{
	UI u;
	Shape* g = new Circle();
	u.Choose();
	if (drawing == true) {
		Shape* g = new Circle();
		g->add(g);
	}

	new GraphicEditor();
	
	cout << "그래픽 에디터입니다." << endl;
}
