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
		for (auto i : PlayerList)   //÷икл перев≥р€Ї чи введене ≥м'€ в≥льне
		{
			if (PlayerName == i.return_name())
				return used_name;
		}
		used_name = false;
		player.add_name(PlayerName);
		player.add_id(rand() % 899 + 100);     //id генеруЇтьс€ в≥д 100 до 999
		player.add_rank(0);
		PlayerList.push_back((player));
		return used_name;
	}

	auto DeletePlayer(string PlayerName, int PlayerId)  //÷ей метод видал€Ї гравц€ ≥з списку за допомогою ≥м'€ або id
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
		bool exist = false;     //якщо гравц€ з таким ≥м'€м не ≥снуЇ, метод повертаЇ exist = false
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
		bool exist = false;       //якщо гравц€ з таким id не ≥снуЇ, метод повертаЇ exist = false
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

	auto return_size()
	{
		return PlayerList.size();
	}

	auto make_a_copy(Player player1, Player copy)      //ћетод робить коп≥ю елемента ј ≥ вертаЇ њњ
	{
		copy.add_name(player1.return_name());
		copy.add_id(player1.return_id());
		copy.add_rank(player1.return_rank());
		return copy;
	}

	auto return_player(int numb)    //n - випадке число; метод знаходить елемент за номером, робить його коп≥ю	  
	{                            //та ставить елемент в к≥нець(таким чином цей елемент не буде повторюватис€)
		int count = 1;
		for (auto i : PlayerList)
		{
			if (numb == count)
			{
				copy = make_a_copy(i, copy);
				PlayerList.remove(i);
				PlayerList.push_back(copy);
				break;
			}
			count++;
		}
		return copy;

	}

	auto bot()
	{
		Player bot;
		bot.add_name("PlayerBot");
		bot.add_id(0);
		bot.add_rank(0);
		return bot;
	}

	auto update_rank(Player player1, int update_rank)
	{
		for (auto i : PlayerList)
		{
			if (player1.return_id() == i.return_id())
			{
				make_a_copy(i, player1);
				PlayerList.remove(i);
				player1.add_rank(25);
				PlayerList.push_back(player1);
			}
		}

	}
};