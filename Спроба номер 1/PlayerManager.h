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
		for (auto i : PlayerList)   //Цикл перевіряє чи введене ім'я вільне
		{
			if (PlayerName == i.return_name())
				return used_name;
		}
		used_name = false;
		player.add_name(PlayerName);
		player.add_id(rand() % 899 + 100);     //id генерується від 100 до 999
		player.add_rank(0);
		PlayerList.push_back((player));
		return used_name;
	}

	auto DeletePlayer(string PlayerName, int PlayerId)  //This method removes a player from the list by name or id
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
		bool exist = false;     //If a player with that name does not exist, the method returns exist = false
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
		bool exist = false;       //If a player with this id does not exist, the method returns exist = false
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

	auto make_a_copy(Player player1, Player copy)      //The method makes a copy of element A and returns it
	{
		copy.add_name(player1.return_name());
		copy.add_id(player1.return_id());
		copy.add_rank(player1.return_rank());
		return copy;
	}

	auto return_player(int numb)    //n - random number; the method finds the element by number, makes a copy  
	{                            //and puts an element at the end (so this element will not be repeated)
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