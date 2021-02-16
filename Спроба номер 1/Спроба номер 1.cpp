#include <iostream>
#include <math.h>
#include <list>
#include <string>
#include <vector>
#include <Windows.h>
#include "PlayerManager.h"
using namespace std;
PlayerManager playermanager;


auto PlayerMenu2()
{
	string action, name;
	int id;
	bool exist;
	system("cls");
	cout << "1)Знайти профіль за нікнеймом" << endl;
	cout << "2)Знайти профіль за id" << endl;
	getline(cin, action);
	if (action == "1")
	{
		system("cls");
		cout << "Введіть нікнейм: " << endl;
		cin >> name;
		exist = playermanager.GetHeroByName(name);
		if (exist)
		{
			cout << "1)Видалити цього гравця" << endl;
			cout << "2)Повернутися назад" << endl;
			cin >> action;
			if (action == "1")
			{
				system("cls");
				playermanager.DeletePlayer(name, 0);
				cout << "Гравець видалений";
				Sleep(700);
			}
		}
		else
		{
			cout << "Гравця з таким нікнеймом не існує";
			Sleep(700);
		}
		action = "";
	}
	if (action == "2")
	{
		system("cls");
		cout << "Введіть id: ";
		cin >> id;
		exist = playermanager.GetHeroById(id);
		if (exist)
		{
			cout << "1)Видалити цього гравця" << endl;
			cout << "2)Повернутися назад" << endl;
			cin >> action;
			if (action == "1")
			{
				system("cls");
				playermanager.DeletePlayer("", id);
				cout << "Гравець видалений";
				Sleep(700);
				action = "";
			}
		}
		else
		{
			cout << "Гравця з таким id не існує";
			Sleep(700);

		}
	}
}
auto PlayerMenu1()
{
	bool copy;
	string action, name;
	system("cls");
	cout << "Придумайте нікнейм: ";
	cin >> name;
	copy = playermanager.CreatePlayer(name);
	while (copy)
	{
		system("cls");
		cout << "Цей нікнейм зайнятий" << endl;
		cout << "Придумайте новий: ";
		cin >> name;
		copy = playermanager.CreatePlayer(name);
	}
	cout << "Гравець створенний";
	Sleep(700);
}
auto PlayerMenu()
{
	string action;
	while (action != "3")
	{
		system("cls");
		cout << "1)Додати гравця" << endl;
		cout << "2)Профіль гравця" << endl;
		cout << "3)Повернутися в головне меню" << endl;
		getline(cin, action);
		if (action == "1")
			PlayerMenu1();
		if (action == "2")
			PlayerMenu2();
	}
}


int main()
{
	SetConsoleOutputCP(1251);
	srand(time(0));
	string action;
	while (action != "6")
	{
		system("cls");
		cout << "1)Меню гравця" << endl;
		cout << "2)Меню героїв" << endl;
		cout << "3)Меню команд" << endl;
		cout << "4)Поєдинок" << endl;
		cout << "5)Історія поєдинків" << endl;
		cout << "6)Вийти" << endl;
		getline(cin, action);
		if (action == "1")
			PlayerMenu();
	}
}