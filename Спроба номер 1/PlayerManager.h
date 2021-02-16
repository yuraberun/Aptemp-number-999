#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Player.h"
using namespace std;
class PlayerManager
{
private:
	list <Player> PlayerList;
public:
	Player player, copy;

	auto CreatePlayer(string PlayerName)
	{
		bool used_name = true;
		for (auto i : PlayerList)   //���� �������� �� ������� ��'� �����
		{
			if (PlayerName == i.return_name())
				return used_name;
		}
		used_name = false;
		player.add_name(PlayerName);
		player.add_id(rand() % 899 + 100);     //id ���������� �� 100 �� 999
		player.add_rank(0);
		PlayerList.push_back((player));
		return used_name;
	}

	auto DeletePlayer(string PlayerName, int PlayerId)  //��� ����� ������� ������ �� ������ �� ��������� ��'� ��� id
	{
		for (auto i : PlayerList)
		{
			if ((PlayerId == i.return_id()) || (PlayerName == i.return_name()))
			{
				PlayerList.remove(i);
				break;
			}
		}
	}

	auto ShowPlayerInfo(Player player1)
	{
		cout << "Name: " << player1.return_name() << endl;
		cout << "Id: " << player1.return_id() << "  ";
		cout << "rank: " << player1.return_rank() << endl;
	}

	auto GetHeroByName(string PlayerName)
	{
		bool exist = false;     //���� ������ � ����� ��'�� �� ����, ����� ������� exist = false
		for (auto i : PlayerList)
		{
			if (PlayerName == i.return_name())
			{
				ShowPlayerInfo(i);
				exist = true;
				return exist;
			}
		}
		return exist;
	}

	auto GetHeroById(int PlayerId)
	{
		bool exist = false;       //���� ������ � ����� id �� ����, ����� ������� exist = false
		for (auto i : PlayerList)
		{
			if (PlayerId == i.return_id())
			{
				ShowPlayerInfo(i);
				exist = true;
				break;
			}
		}
		return exist;
	}
};