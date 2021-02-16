#pragma once
#include "PlayerManager.h"
#include "HeroManager.h"
#include <string>
#include "Team.h"
#include "Player.h"
class TeamManager
{
private:
	Player a;
	Hero b;
	pair <Player, Hero> PlayerHero;
	Team T;
public:

	auto GenerateNewTeam(PlayerManager& playerManager, HeroManager& heroManager)
	{
		T.clear_team();
		int numb_of_players = playerManager.return_size();
		int numb_of_heroes = heroManager.return_size();
		int random;
		for (int numb = 0; numb < 10; numb++)
		{
			if (numb_of_players > 0)
			{
				random = rand() % numb_of_players + 1;            //A random number from 1 to the number of players is selected
				a = playerManager.return_player(random);  //Assignment for a, the element under number which was chosen casually
				numb_of_players--;               //Because in the return_player method the taken element is moved to the end           
			}                                                        //numb_of_players-- so as not to take that item again
			else
				a = playerManager.bot();                                //If there are not enough players, bots are added to the team

			if (numb_of_heroes > 0)
			{
				random = rand() % numb_of_heroes + 1;
				b = heroManager.return_hero(random);
				numb_of_heroes--;
			}
			else
				b = heroManager.bot();
			PlayerHero.first = a;
			PlayerHero.second = b;
			T.add_to_team(PlayerHero);   //Створення пари і відправлення в клас team
		}
	}

	auto GetTeamInfo(PlayerManager& playerManager, HeroManager& heroManager)
	{
		cout << endl;
		cout << "((((((Перша команда))))))" << endl;               //Since all players were added to one sheet,
		cout << endl;                                       //players 1 to 5 who are participants are displayed first
		for (int i = 1; i <= 5; i++)           //the first team, and then the players from 6 to 10 who are members of the second.
		{
			cout << "" << i << ")";
			playerManager.ShowPlayerInfo(T.return_pair(i).first);
			heroManager.ShowHeroInfo(T.return_pair(i).second);
			cout << endl;
		}
		cout << "((((((Друга команда))))))" << endl;
		cout << endl;
		for (int i = 6; i <= 10; i++)
		{
			cout << "" << i - 5 << ")";
			playerManager.ShowPlayerInfo(T.return_pair(i).first);
			heroManager.ShowHeroInfo(T.return_pair(i).second);
			cout << endl;
		}
	}

	auto return_player(int numb)
	{
		Player player;
		player = T.return_pair(numb).first;
		return player;
	}

	auto return_hero(int numb)
	{
		Hero hero;
		hero = T.return_pair(numb).second;
		return hero;
	}
};
