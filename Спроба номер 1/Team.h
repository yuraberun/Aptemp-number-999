#pragma once
#include <string>
#include <list>
#include "Player.h"
#include "Hero.h"
#include "PlayerManager.h"
#include "HeroManager.h"
class Team
{
private:
	list<pair <Player, Hero>> TeamList;
public:

	auto add_to_team(pair <Player, Hero> PlayerHero)   //Дві команди записуються в один лист
	{
		TeamList.push_back(PlayerHero);
	}

	auto clear_team()
	{
		TeamList.clear();
	}

	auto return_pair(int numb)
	{
		int count = 1;
		pair <Player, Hero> PlayerHero;
		for (auto i : TeamList)
		{
			if (count == numb)
				PlayerHero = i;
			count++;
		}
		return PlayerHero;
	}
};