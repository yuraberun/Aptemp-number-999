#include <iostream>
#include <math.h>
#include <list>
#include <string>
#include <vector>
#include <Windows.h>
#include "PlayerManager.h"
#include "HeroManager.h"
#include "TeamManager.h"
#include "Session.h"
using namespace std;
PlayerManager playermanager;
HeroManager heromanager;
TeamManager teammanager;
Session session;
string winner;


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


auto HeroMenu2()
{
	string action, name;
	int id;
	bool exist;
	system("cls");
	cout << "1)Знайти героя за ім'ям" << endl;
	cout << "2)Знайти героя за id" << endl;
	getline(cin, action);
	if (action == "1")
	{
		system("cls");
		cout << "Введіть ім'я: ";
		cin >> name;
		exist = heromanager.GetHeroByName(name);
		if (exist)
		{
			cout << "1)Видалити цього героя" << endl;
			cout << "2)Повернутися назад" << endl;
			cin >> action;
			if (action == "1")
			{
				system("cls");
				heromanager.DeletePlayer(name, 0);
				cout << "Герой видалений";
				Sleep(700);
			}
		}
		else
		{
			cout << "Героя з таким ім'ям не існує";
			Sleep(700);
		}
		action = "";
	}
	if (action == "2")
	{
		system("cls");
		cout << "Введіть id: ";
		cin >> id;
		exist = heromanager.GetHeroById(id);
		if (exist)
		{
			cout << "1)Видалити цього героя" << endl;
			cout << "2)Повернутися назад" << endl;
			cin >> action;
			if (action == "1")
			{
				system("cls");
				heromanager.DeletePlayer("", id);
				cout << "Герой видалений";
				Sleep(700);
			}
		}
		else
		{
			cout << "Героя з таким id не існує";
			Sleep(700);
		}
	}
}
auto HeroMenu1()
{
	int damage, hp;
	bool copy;
	string action, name;
	system("cls");
	cout << "Придумайте ім'я для героя: ";
	cin >> name;
	cout << "Damage: ";
	cin >> damage;
	cout << "Hp: ";
	cin >> hp;
	copy = heromanager.CreateHero(name, damage, hp);
	while (copy)
	{
		system("cls");
		cout << "Це ім'я уже зайняте" << endl;
		cout << "Придумайте нове: ";
		cin >> name;
		copy = heromanager.CreateHero(name, damage, hp);
	}
	cout << "Герой створенний";
	Sleep(700);
}
auto HeroMenu()
{
	{
		string action;
		while (action != "3")
		{
			system("cls");
			cout << "1)Додати героя" << endl;
			cout << "2)Профіль героя" << endl;
			cout << "3)Повернутися в головне меню" << endl;
			getline(cin, action);
			if (action == "1")
				HeroMenu1();
			if (action == "2")
				HeroMenu2();
		}
	}
}


auto TeamMenu1()
{
	system("cls");
	teammanager.GenerateNewTeam(playermanager, heromanager);
	cout << "Команди створені" << endl;
	Sleep(700);
	system("cls");
	string action;
	teammanager.GetTeamInfo(playermanager, heromanager);
	cout << "1)Повернутися назад" << endl;
	getline(cin, action);
}
auto TeamMenu()
{
	string action;
	while (action != "2")
	{
		system("cls");
		cout << "1)Створити дві комадни" << endl;
		cout << "2)Повернутися до головного меню" << endl;
		getline(cin, action);
		if (action == "1")
			TeamMenu1();
	}
}

auto SessionMenu()
{
	int n = 1;
	system("cls");
	session.TeamOne(teammanager);
	session.TeamTwo(teammanager);
	winner = session.Winner();
	session.CalculateWinner(winner, teammanager, playermanager);
	if (winner == "1")
	{
		cout << "Перемогла перша команда";
	}
	if (winner == "2")
	{
		cout << "Виграла друга команда";
	}
	if (winner == "0")
	{
		cout << "Нічія";
	}
	if (winner == "-1")
		cout << "Команди ще не створені";
	Sleep(1000);
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
		if (action == "2")
			HeroMenu();
		if (action == "3")
			TeamMenu();
		if (action == "4")
			SessionMenu();
	}
}