#pragma once
#include <iostream>
#include "TeamManager.h"
#include <string>

using namespace std;
class Session
{
private:
	int hp_t1, hp_t2, damage_t1, damage_t2;
public:

	auto CalculateWinner(string winner, TeamManager& teammanager, PlayerManager& playermanager)
	{
		int rank = 1;
		if (winner == "1")
			rank = 25;
		if (winner == "2")
			rank = -25;
		for (int i = 1; i <= 5; i++)
		{
			playermanager.update_rank(teammanager.return_player(i), rank);
		}
		for (int i = 6; i <= 10; i++)
		{
			playermanager.update_rank(teammanager.return_player(i), -rank);
		}
	}

	auto Winner()
	{
		string winner;
		if (hp_t1 == 0 || hp_t2 == 0)
		{
			winner = "-1";
			return winner;
		}
		while (hp_t2 < 0 || hp_t1 < 0)
		{
			hp_t2 -= damage_t1;
			hp_t1 -= damage_t2;
		}
		if (hp_t1 > hp_t2)
			winner = "1";
		if (hp_t2 > hp_t1)
			winner = "2";
		if (hp_t1 == hp_t2)
			winner = "0";
		return winner;
	}

	auto TeamTwo(TeamManager& teammanager)
	{
		hp_t2 = 0;
		damage_t2 = 0;
		for (int i = 6; i <= 10; i++)
		{
			hp_t2 += teammanager.return_hero(i).return_hp();
			damage_t2 += teammanager.return_hero(i).return_damage();
		}
	}

	auto TeamOne(TeamManager& teammanager)
	{
		hp_t1 = 0;
		damage_t1 = 0;
		for (int i = 1; i <= 5; i++)
		{
			hp_t1 += teammanager.return_hero(i).return_hp();
			damage_t1 += teammanager.return_hero(i).return_damage();
		}
	}
};