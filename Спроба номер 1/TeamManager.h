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
				random = rand() % numb_of_players + 1;            //���������� ��������� ����� �� 1 �� ������� �������
				a = playerManager.return_player(random);  //��������� ��� � , ������� �� ������� ���� �������� ���������
				numb_of_players--;               //������� � ����� return_player ������ ������� ��������������� � �����           
			}                                                        //numb_of_players-- ��� �� ����� ��� ������� ��������
			else
				a = playerManager.bot();                                //���� ������� ���������, � ������� �������� ����

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
			T.add_to_team(PlayerHero);   //��������� ���� � ����������� � ���� team
		}
	}

	auto GetTeamInfo(PlayerManager& playerManager, HeroManager& heroManager)
	{
		cout << endl;
		cout << "((((((����� �������))))))" << endl;               //������� �� ������ ���� ��������� � ���� ����,
		cout << endl;                                       //�������� ���������� ������ �� 1 �� 5, �� � ����������
		for (int i = 1; i <= 5; i++)           //����� �������, � ���� ������ �� 6 �� 10, �� � ���������� �����.
		{
			cout << "" << i << ")";
			playerManager.ShowPlayerInfo(T.return_pair(i).first);
			heroManager.ShowHeroInfo(T.return_pair(i).second);
			cout << endl;
		}
		cout << "((((((����� �������))))))" << endl;
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
