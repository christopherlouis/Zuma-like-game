#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
#include<stdlib.h>


//Christopher Louis - c14190088
//Daniel Marthin - c14190086
//Bryant Septian - c14190095

using namespace std;

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}

template<typename T>
class Node {
private:
	T value;
	Node* next;
public:
	Node() {
		value = 0;
		next = NULL;
	}
	void setValue(T _value) {
		value = _value;
	}
	T getValue() {
		return value;
	}
	void setNext(Node* _next) {
		next = _next;
	}
	Node* getNext() {
		return next;
	}
};

template<typename n>
class LinkedList {
private:
	Node<n>* head;
	Node<n>* tail;
	int size;
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void addValue(n _value) {
		Node<n>* tmp = new Node<n>;
		tmp->setValue(_value);
		if (head == NULL) {
			head = tmp;
			tail = head;
		}
		else {
			tail->setNext(tmp);
			tail = tmp;
		}
		size++;
	}
	n getValue(int index) {
		Node<n>* temp = head;
		int co = 0;
		if (index == 0) {
			return head->getValue();
		}
		else {
			while (co <= index - 1) {
				temp = temp->getNext();
				co++;
			}
			return temp->getValue();
		}
	}
	void deleteValue(int _index) {
		Node<n>* temp = head;
		int co = 0;
		int counter = countBall(_index);
		//kalo kepala yang ditembak
		if (_index == 0) {
			size = size - counter;
			while (counter != 0) {
				head = head->getNext();
				counter--;
			}
		}
		else {
			//buat getnext sampe index
			while (co < _index - 1) {
				temp = temp->getNext();
				co++;
			}
			size = size - counter;
			//delete ke kanan sesuai jumlah countballball
			while (counter != 0) {
				temp->setNext(temp->getNext()->getNext());
				counter--;
			}
		}
	}
	void sliptengah(int _index, int _value) {
		Node<n>* tmp = new Node<n>;
		tmp->setValue(_value);
		Node<n>* temp = head;
		int co = 0;
		//buat getnext sampai index tujuan
		while (co < _index) {
			temp = temp->getNext();
			co++;
		}
		if (_index == 0) {
			tmp->setNext(head);
			head = tmp;
		}
		else {
			Node<n>* temp2 = head;
			int co2 = 0;
			while (co2 < _index - 1) {
				temp2 = temp2->getNext();
				co2++;
			}
			temp2->setNext(tmp);
			tmp->setNext(temp);
		}
		size++;
	}
	//jumlah bola yang sama yang ditembak
	int countBall(int _index) {
		Node<n>* temp = head;
		int co = 0;
		int counterBall = 0;
		//buat getnext sampai index tujuan
		while (co < _index) {
			temp = temp->getNext();
			co++;
		}
		int cek = temp->getValue();
		//buat cek berapa bola kanannya yang sama
		while (cek == temp->getValue()) {
			counterBall++;
			temp = temp->getNext();
		}
		return counterBall;
	}
	int getSize() {
		return size;
	}
	void display() {
		Node<n>* tmp = head;
		int co = 0;
		while (tmp && co < 26) {
			cout << tmp->getValue() << "   ";
			tmp = tmp->getNext();
			co++;
		} cout << endl;
	}
	void display2() {
		Node<n>* tmp = head;
		int co = 0;
		int co2 = 0;
		while (co2 < 26) {
			tmp = tmp->getNext();
			co2++;
		}
		while (tmp && co < 26) {
			cout << tmp->getValue() << "   ";
			tmp = tmp->getNext();
			co++;
		} cout << endl;
	}
	void display3() {
		Node<n>* tmp = head;
		int co = 0;
		int co2 = 0;
		while (co2 < 52) {
			tmp = tmp->getNext();
			co2++;
		}
		while (tmp && co < 26) {
			cout << tmp->getValue() << "   ";
			tmp = tmp->getNext();
			co++;
		} cout << endl;
	}
	void display4() {
		Node<n>* tmp = head;
		int co = 0;
		int co2 = 0;
		while (co2 < 78) {
			tmp = tmp->getNext();
			co2++;
		}
		while (tmp && co < 26) {
			cout << tmp->getValue() << "   ";
			tmp = tmp->getNext();
			co++;
		} cout << endl;
	}

};

class Bullet {
protected:
	int bulet;
public:
	Bullet() {
		bulet = 0;
	}
	void setBullet() {
		srand(time(NULL));
		bulet = rand() % 4 + 1;
	}
	int getBullet() {
		return bulet;
	}
};

class Game {
protected:
	LinkedList<char> idx;
	LinkedList<int> value;

	Bullet peluru;
	int score = 0;
public:
	Game() {

	}
	void Initialization() {
		idx.addValue('A');
		idx.addValue('B');
		idx.addValue('C');
		idx.addValue('D');
		idx.addValue('E');
		idx.addValue('F');
		idx.addValue('G');
		idx.addValue('H');
		idx.addValue('I');
		idx.addValue('J');
		idx.addValue('K');
		idx.addValue('L');
		idx.addValue('M');
		idx.addValue('N');
		idx.addValue('O');
		idx.addValue('P');
		idx.addValue('Q');
		idx.addValue('R');
		idx.addValue('S');
		idx.addValue('T');
		idx.addValue('U');
		idx.addValue('V');
		idx.addValue('W');
		idx.addValue('X');
		idx.addValue('Y');
		idx.addValue('Z');
		peluru.setBullet();
	}
	void update() {
		srand(time(NULL));
		int angka;
		angka = rand() % 4 + 1;
		value.addValue(angka);
		
	}
	void draw() {
		gotoxy(45, 1);
		cout << "====== ALOHA ZOUMA ======" << endl;
		gotoxy(8, 3);
		idx.display();
		if (value.getSize()<26)
		{
			gotoxy(8, 4);
			value.display();
		}
		else if (value.getSize()>=26 && value.getSize()<52)
		{
			gotoxy(8, 4);
			value.display();
			gotoxy(8, 5);
			value.display2();
		}
		else if (value.getSize() >= 52 && value.getSize() < 78)
		{
			gotoxy(8, 4);
			value.display();
			gotoxy(8, 5);
			value.display2();
			gotoxy(8, 6);
			value.display3();
		}
		else
		{
			gotoxy(8, 4);
			value.display();
			gotoxy(8, 5);
			value.display2();
			gotoxy(8, 6);
			value.display3();
			gotoxy(8, 7);
			value.display4();
		}
		
		gotoxy(80, 9);
		cout << "Score : " << score << endl;
		gotoxy(25, 9);
		cout << "Score : " << score << endl;
		gotoxy(52, 8);
		cout << "--Bullet--" << endl;
		gotoxy(56, 10);
		cout << peluru.getBullet() << endl;
		gotoxy(51, 12);
		cout << "Tembak Index" << endl;
	}
	void processInput() {
		gotoxy(56, 13);
		int cek = 0;
		if (_kbhit()) {
			char ch = _getch();
			if (ch == 'a') {
				cout << ch << endl;
				cek = 0;
				
			}
			if (ch == 'b') {
				cout << ch << endl;
				cek = 1;
			}
			if (ch == 'c') {
				cout << ch << endl;
				cek = 2;
			}
			if (ch == 'd') {
				cout << ch << endl;
				cek = 3;
			}
			if (ch == 'e') {
				cout << ch << endl;
				cek = 4;
			}
			if (ch == 'f') {
				cout << ch << endl;
				cek = 5;
			}
			if (ch == 'g') {
				cout << ch << endl;
					cek = 6;
			}
			if (ch == 'h') {
				cout << ch << endl;
					cek = 7;
			}
			if (ch == 'i') {
				cout << ch << endl;
					cek = 8;
			}
			if (ch == 'j') {
				cout << ch << endl;
					cek = 9;
			}
			if (ch == 'k') {
				cout << ch << endl;
					cek = 10;
			}
			if (ch == 'l') {
				cout << ch << endl;
					cek = 11;
			}
			if (ch == 'm') {
				cout << ch << endl;
					cek = 12;
			}
			if (ch == 'n') {
				cout << ch << endl;
					cek = 13;
			}
			if (ch == 'o') {
				cout << ch << endl;
					cek = 14;
			}
			if (ch == 'p') {
				cout << ch << endl;
					cek = 15;
			}
			if (ch == 'q') {
				cout << ch << endl;
					cek = 16;
			}
			if (ch == 'r') {
				cout << ch << endl;
					cek = 17;
			}
			if (ch == 's') {
				cout << ch << endl;
					cek = 18;
			}
			if (ch == 't') {
				cout << ch << endl;
					cek = 19;
			}
			if (ch == 'u') {
				cout << ch << endl;
					cek = 20;
			}
			if (ch == 'v') {
				cout << ch << endl;
					cek = 21;
			}
			if (ch == 'w') {
				cout << ch << endl;
					cek = 22;
			}
			if (ch == 'x') {
				cout << ch << endl;
					cek = 23;
			}
			if (ch == 'y') {
				cout << ch << endl;
					cek = 24;
			}
			if (ch == 'z') {
				cout << ch << endl;
					cek = 25;
			}
			if (value.getSize() < 26)
			{
				cek = cek;
			}
			else if (value.getSize() >=26 && value.getSize() < 52)
			{
				if (value.getSize() > cek + 26)
				{
					cek = cek + 26;
				}
				else
				{
					cek = cek;
				}
			}
			else if (value.getSize() >= 52 && value.getSize() < 78)
			{
				if (value.getSize() > cek + 52)
				{
					cek = cek + 52;
				}
				else
				{
					cek = cek + 26;
				}
			}
			else
			{
				if (value.getSize() > cek + 78)
				{
					cek = cek + 78;
				}
				else
				{
					cek = cek + 52;
				}
			}
			
			if (peluru.getBullet() == value.getValue(cek)) {
				for (int i = 0; i < value.countBall(cek); i++) {
					score = score + 10;
				}
				value.deleteValue(cek);
				peluru.setBullet();
			}
			else
			{
				value.sliptengah(cek, peluru.getBullet());
			}
		}
	}
	void run() {
		while (true)
		{
			system("cls");
			draw();
			update();
			processInput();
			if (value.getSize() == 105)
			{
				system("cls");
				gotoxy(49, 1);
				cout << "ANDA COPO" << endl;
				gotoxy(48, 2);
				cout << "Score : " << score << endl;
				exit(1);
			}
			Sleep(500);
		}
	}
};

int main() {
	Game start;
	start.Initialization();
	start.run();

	return 0;
}
