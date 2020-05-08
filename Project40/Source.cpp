#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

unsigned tm = GetTickCount();
int tm1;
bool vin = false;

#define gre SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
#define yell SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
#define fonn SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);


struct rating {

	string name;
	int rt;
	int lv;

};

string rat = "rat.txt";
fstream in;
const int ho = 27;
const int ve = 27;
int mas[ho][ve];


void raiting_maze_save(rating* arr, int& amount) {
	in.open(rat, fstream::in | fstream::out);
	bool isopen = in.is_open();
	if (isopen == false) {
		cout << "Error: file nout open" << endl;
	}
	else {

		for (int i = 0; i < amount; i++)
		{
			in << arr[i].name << " " << arr[i].rt << " " << arr[i].lv << " ";
		}
	}
	in.close();

}

void menulvl(int& vubir) {
	system("CLS");
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	cout << "PLEASE SELECT A LEVEL \n\n    \t\t\t1---2---3---4\n    \t\t\t";
	cin >> vubir;
}

void menu(int &vubir) {
	string start = "WELCOME TO MAZE GAME ";
	string indev = "To select a level, press 1";
	string ind = "Complete the maze on time 2";
	string ray = "Player rankings 3";
	string howto = "Use the arrow keys and traverse through the maze. Exit is marked '9'.";
	cout << endl;
	cout << "\n\n\n\n\n\n\n    \t\t\t";
	for (auto ch : start) {
		cout << ch;
		Sleep(40);
	} cout << endl << endl;
	cout << "    \t\t   ";
	for (auto ch : indev) {
		cout << ch;
		Sleep(40);
	} cout << endl;
	cout << "\t\t";
	for (auto ch : ind) {
		cout << ch;
		Sleep(40);
	}cout << endl;
	cout << "\t\t";
	for (auto ch : ray) {
		cout << ch;
		Sleep(40);
	}cout << endl;
	cout << "\t\t";
	for (auto ch : howto) {
		cout << ch;
		Sleep(40);
	} cout << endl << endl << endl;
	cin >> vubir;

}

rating* Add(rating* arr, int amount)
{
	if (amount == 0)
	{
		arr = new rating[amount + 1];
	}
	else
	{
		rating* temp = new rating[amount + 1];

		for (int i = 0; i < amount; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	return arr;
}

void tempp(int tm1) {
	int s = 0;
	int h = 0;
	int m = 0;

	s = tm1 / 1000;
	h = s / 60 / 60;
	m = s / 60 % 60;
	s = s % 60;
	cout << h << " hours, " << m << " minuts "
		<< s << " seconds";


}

void printLevel(int& vubir, string lvl1, string lvl2, string lvl3, string lvl4) {

	switch (vubir)
	{
	case 1: {
		break; }
	case 2: {
		lvl1 = lvl2;
		break; }
	case 3: {
		lvl1 = lvl3;
		break; }
	case 4: {
		lvl1 = lvl4;
		break; }
	case 9: {
		break; }

	default:  cout << "Enter to vid 1 do 4. Enter 9 exit" << endl;
		break;
	}




	in.open(lvl1, fstream::in | fstream::out);

	bool isopen = in.is_open();
	if (isopen == false) {
		cout << "Error: file nout open" << endl;
	}
	else {
		while (!in.eof()) {

			for (int i = 0; i < ho; i++)
			{
				for (int j = 0; j < ve; j++) {
					in >> mas[i][j];
				}
			}
		}

	}
	in.close();


}


void runmaze(int& vubir, int c, rating* arre, int& r, int amount) {
	int x = 0;
	int y = 1;
	int exit_x = 25;
	int exit_y = 26;
	mas[exit_x][exit_y] = 3;
	mas[x][y] = 2;
	int it = 0;
	int vub = 0;

	srand(time(0));


	unsigned tm = GetTickCount();

	while (c != 57)
	{

		if (it == 1000) {

			it++;
		}

		for (int i = 0; i < ho; i++)
		{
			for (int j = 0; j < ve; j++)
			{

				if (mas[i][j] == 0)
				{

					cout << static_cast<char>(176);
					cout << static_cast<char>(176);
				}
				if (mas[i][j] == 1)
				{
					cout << "  ";
				}
				if (mas[i][j] == 2)
				{
					cout << static_cast<char>(254);
					cout << static_cast<char>(254);
				}
				if (mas[i][j] == 4)
				{
					cout << static_cast<char>(178);
					cout << static_cast<char>(178);
				}

			}
			cout << endl;
		}

		cout << endl;

		c = _getch();

		switch (c)
		{

		case 75: { //вліво

			if (mas[x][y - 1] != 0 && mas[x][y - 1] != 4) {


				mas[x][y] = 1;
				y--;
				mas[x][y] = 2;
			}

			if (mas[x][y - 1] != 0 && mas[x][y - 1] == 4) {
				mas[x][y] = 1;
				do
				{
					x = rand() % 25 + 1;
					y = rand() % 25 + 1;
				} while (mas[x][y] != 1);

				mas[x][y] = 2;
			}

		}; break;
		case 72: { //верх
			if (mas[x - 1][y] != 0 && mas[x - 1][y] != 4) {

				mas[x][y] = 1;
				x--;
				mas[x][y] = 2;
			}
			if (mas[x - 1][y] != 0 && mas[x - 1][y] == 4) {
				mas[x][y] = 1;
				do
				{
					x = rand() % 25 + 1;
					y = rand() % 25 + 1;
				} while (mas[x][y] != 1);

				mas[x][y] = 2;

			}
		}; break;
		case 77: { //право
			if (mas[x][y + 1] != 0 && mas[x][y - 1] != 4) {

				mas[x][y] = 1;
				y++;
				mas[x][y] = 2;
			}
			if (mas[x][y + 1] != 0 && mas[x][y + 1] == 4) {
				mas[x][y] = 1;
				do
				{
					x = rand() % 25 + 1;
					y = rand() % 25 + 1;
				} while (mas[x][y] != 1);

				mas[x][y] = 2;
			}
		}
			   ; break;
		case 80: { //низ
			if (mas[x + 1][y] != 0 && mas[x][y - 1] != 4) {
				mas[x][y] = 1;
				x++;
				mas[x][y] = 2;
			}
			if (mas[x + 1][y] != 0 && mas[x + 1][y] == 4) {
				mas[x][y] = 1;
				do
				{
					x = rand() % 25 + 1;
					y = rand() % 25 + 1;
				} while (mas[x][y] != 1);

				mas[x][y] = 2;
			}

			break;
		}

		default: {

		}
			   break;

		}
		system("cls");

		if (mas[exit_x][exit_y] == 2) {
			cout << "Your Win" << endl;
			c = 57;
			vin = true;
			tm = (GetTickCount() - tm);

			tm1 = tm;
			tempp(tm1);

		}
	}

}

void sort_mazerating(rating* arre, int& amount) {
	int tmp;
	string tmname;
	int tmlv;

	for (int j = 0; j < amount - 1; j++) {
		for (int i = 0; i < amount - j - 1; i++) {
			if (arre[i].rt > arre[i + 1].rt) {
				tmp = arre[i].rt;
				tmname = arre[i].name;
				tmlv = arre[i].lv;

				arre[i].rt = arre[i + 1].rt;
				arre[i + 1].rt = tmp;
				arre[i].name = arre[i + 1].name;
				arre[i + 1].name = tmname;
				arre[i].lv = arre[i + 1].lv;
				arre[i + 1].lv = tmlv;

			}
		}
	}
}

void add_maze_reting(rating* arre, int& amount, int& llv) {
	int vub;
	cout << endl << endl;
	cout << "Do you want to save the result? (1 - yes, 0 - no)" << endl;
	cin >> vub;
	if (vub == 1) {

		cout << "Enter name  ";
		cin >> arre[amount].name;
		arre[amount].lv = llv;
		arre[amount].rt = tm1;
		amount++;
	}
}

void raiting_vuvid(rating* arre, int& amount) {

	system("cls");
	sort_mazerating(arre, amount);

	cout << " Rating\t" << "   Name\t " << "\t\tTime\t\t" << " Level\t" << endl;
	cout << "===========================================================" << endl;
	for (int i = 0; i < amount; i++)
	{
		if (i <= 2)
		{
			gre
				int tm2 = arre[i].rt;
			cout << i + 1 << ")\t" << arre[i].name << "\t| ";  tempp(tm2); cout << "\t| " << arre[i].lv << endl;
			fonn
		}
		else if (i <= 6) {
			yell
				int tm2 = arre[i].rt;
			cout << i + 1 << ")\t" << arre[i].name << "\t| ";  tempp(tm2); cout << "\t| " << arre[i].lv << endl;
			fonn
		}
		else {
			int tm2 = arre[i].rt;
			cout << i + 1 << ")\t" << arre[i].name << "\t| ";  tempp(tm2); cout << "\t| " << arre[i].lv << endl;
		}

	}
	cout << "===========================================================" << endl;
	cout << "\n\n\n";
	

}


int main()
{
	int r = 0;
	int amount = 0;
	rating* arre = 0;
	string lvl1 = "if.txt";
	string lvl2 = "if2.txt";
	string lvl3 = "if3.txt";
	string lvl4 = "if4.txt";
	int llv = 0;
	int vubir = 0;
	int c = 0;
	in.open(rat, fstream::in | fstream::out);
	bool ft = true;
	bool ft1 = true;

	while (!in.eof()) {

		if (ft) {
			arre = Add(arre, amount);
			in >> arre[amount].name;
			ft = false;
		}
		else if (ft1) {
			in >> arre[amount].rt;
			ft1 = false;

		}
		else {
			in >> arre[amount].lv;
			ft = true;
			ft1 = true;

			amount++;

		}

	}
	in.close();

		do {
			menu(vubir);
			switch (vubir)
			{
			case 1: {
				menulvl(vubir);
				llv = vubir;
				printLevel(vubir, lvl1, lvl2, lvl3, lvl4);
				runmaze(vubir, c, arre, r, amount);
				if (vin)
				{
					vin = false;
				}

				break;
			}
			case 2: {
				menulvl(vubir);
				llv = vubir;
				printLevel(vubir, lvl1, lvl2, lvl3, lvl4);
				runmaze(vubir, c, arre, r, amount);
				if (vin)
				{
					arre = Add(arre, amount);
					add_maze_reting(arre, amount, llv);
					raiting_maze_save(arre, amount);
					vin = false;
				}
				break;
			}
			case 3: {
				raiting_vuvid(arre, amount);

				cout << "\t\t\t\t Exit enter 9 ";
				cin >> vubir;
				break;
			}


			}

		} while (vubir != 9);

	cout << endl;
	cout << " \t\t\tGodbay\t " << endl;
	return 0;
}