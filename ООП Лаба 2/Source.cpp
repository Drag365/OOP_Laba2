#include <iostream>

class Line {
protected:
	int x1, y1, x2, y2;
public:
	Line() {
		printf("Line()\n");
		x1 = 0;
		y1 = 0;
		x2 = 0;
		y2 = 0;
	}
	Line(int x1, int y1, int x2, int y2) {
		printf("Line(%d, %d, %d, %d)\n", x1, y1, x2, y2);
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	}

	Line(const Line&l) {
		printf("Line(const Line &p)\n");
		x1 = l.x1;
		y1 = l.y1;
		x2 = l.x2;
		y2 = l.y2;
	}

	~Line() {
		printf("~Line() %d, %d, %d, %d deleted\n", x1, y1, x2, y2);
	}
	void move(int dx1, int dy1, int dx2, int dy2) {
		printf("\n������ ����� move(%d, %d, %d, %d)\n", dx1, dy1, dx2, dy2);
		x1 = x1 + dx1;
		y1 = y1 + dy1;
		x2 = x2 + dx2;
		y2 = y2 + dy2;
	}

	void printRectangle() {
		printf("x1 = %d, y1 = %d, x2 = %d, y2 = %d\n", x1, y1, x2, y2);
	}

	void reset();
};

void Line::reset() {
	printf("\n������ ����� reset()\n");
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

class coloredLine: public Line {
protected:
	int color;
public:
	coloredLine() : Line() {
		printf("coloredLine()\n");
		color = 0;
	}
	coloredLine(int x1, int y1, int x2, int y2, int color) : Line(x1,y1,x2,y2) {
		printf("coloredLine(%d, %d, %d, %d, %d)\n", x1, y1, x2, y2, color);
		this->color = color;
	}

	coloredLine(const coloredLine& l) {
		printf("coloredLine(const coloredLine &p)\n");
		color = l.color;
		x1 = l.x1;
		y1 = l.y1;
		x2 = l.x2;
		y2 = l.y2;
	}

	~coloredLine() {
		printf("~coloredLine() %d, %d, %d, %d, color = %d deleted\n", x1, y1, x2, y2, color);
	}
	void change_color(int new_color) {
		printf("\n������ ����� change_color(%d)\n", new_color);
		color += new_color;
	}
};

class Angle {
private:
	Line* p1;
	Line* p2;
public:
	Angle() {
		printf("Angle()\n");
		p1 = new Line;
		p2 = new Line;
	}
	Angle(int x11, int y11, int x12, int y12, int x21, int y21, int x22, int y22) {
		printf("Angle(%d, %d, %d, %d, %d, %d, %d, %d)\n", x11,y11,x12,y12,x21,y21, x22, y22);
		p1 = new Line(x11, y11, x12, y12);
		p2 = new Line(x21, y21, x22, y22);
	}

	Angle(const Angle& s) {
		printf("Angle(const Angle &p)\n");
		p1 = new Line(*(s.p1));
		p2 = new Line(*(s.p2));
		//this->p1 = s.p1;
		//this->p2 = s.p2;
	}

	~Angle() {
		printf("~Angle() {\n");
		p1->printRectangle();
		p2->printRectangle();
		printf("} deleted\n");
		delete p1;
		delete p2;
	}
};

void main()
{
	setlocale(LC_ALL, "RUS");
	printf("������� ����������� ������ ����� ��� ����������: \n");
	Line l;
	printf("\n������� ����������� ������ ����� c �����������: \n");
	Line l1(1, 2, 1, 4);
	printf("\n������� ����������� ������ ����� � ���������� �������� �����: \n");
	Line l2 = l1;

	printf("\n������� ����������� ������ ������� ����� ��� ����������: \n");
	coloredLine cl;
	printf("\n������� ����������� ������ ������� ����� c �����������: \n");
	coloredLine cl1(1, 2, 1, 4, 255);
	printf("\n������� ����������� ������ ������� ����� � ���������� �������� �����: \n");
	coloredLine cl2 = cl1;

	printf("\n������� ������������ ������ ����� ��� ����������: \n");
	Line *l3 = new Line;
	printf("\n������� ������������ ������ ����� c �����������: \n");
	Line *l4 = new Line (1, 2, 1, 4);
	printf("\n������� ������������ ������ ����� � ���������� �������� �����: \n");
	Line *l5 = new Line(*l4);
	printf("\n������� ������������ ������ ������� ����� ��� ����������: \n");
	coloredLine* �l3 = new coloredLine();
	printf("\n������� ������������ ������ ������� ����� c �����������: \n");
	coloredLine* �l4 = new coloredLine(1, 2, 1, 4, 255);
	printf("\n������� ������������ ������ ������� ����� � ���������� �������� �����: \n");
	coloredLine* �l5 = new coloredLine(*�l4);
	
	l3->move(1, 2, 3, 4);
	l4->reset();
	�l4->change_color(122);

	printf("\n������� ������������ �������\n");
	delete l3;
	delete l4;
	delete l5;
	delete �l3;
	delete �l4;
	delete �l5;
	

	printf("���������� ���������� �� ����������� ��������� ��������:");
	Angle a;
	Angle a1(1, 2, 1, 4, 2, 5, 2, 8);
	Angle a2 = a1;

	printf("���������� ���������� � ������������ ��������� ��������:");
	Angle* a3 = new Angle;
	Angle* a4 = new Angle(1, 2, 1, 4, 2, 5, 2, 8);
	Angle* a5 = new Angle(*a4);
	delete a3;
	delete a4;
	delete a5;

	
}