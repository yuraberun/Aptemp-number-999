#pragma once
#include <iostream>
#include <string>
#include "Hero.h"
#include <list>
using namespace std;
class HeroManager
{
private:
	list <Hero> HeroList;
public:
	Hero hero, copy;
	auto CreateHero(string HeroName, int HeroDamage, int HeroHp)
	{
		bool used_name = true;
		for (auto i : HeroList)     //ѕерев≥рка на те, чи введене ≥м'€ в≥льне
		{
			if (HeroName == i.return_name())
				return used_name;
		}
		used_name = false;
		hero.add_name(HeroName);
		hero.add_hp(HeroHp);
		hero.add_damage(HeroDamage);
		hero.add_id(rand() % 899 + 100);
		HeroList.push_back(hero);
		return used_name;
	}

	auto DeletePlayer(string HeroName, int HeroId)
	{
		for (auto i : HeroList)
		{
			if ((HeroId == i.return_id()) || (HeroName == i.return_name()))
			{
				HeroList.remove(i);
				break;
			}
		}
	}

	auto ShowHeroInfo(Hero Hero1)
	{
		cout << "≤м'€ геро€: " << Hero1.return_name() << endl;
		cout << "id: " << Hero1.return_id() << "  ";
		cout << "Damage: " << Hero1.return_damage() << "  " << "Hp: " << Hero1.return_hp() << endl;
	}

	auto GetHeroByName(string HeroName)
	{
		bool exist = false;    //якщо геро€ з таким ≥м'€м не ≥снуЇ, метод повертаЇ exist = false
		for (auto i : HeroList)
		{
			if (HeroName == i.return_name())
			{
				Hero& link = i;
				ShowHeroInfo(link);
				exist = true;
				break;
			}
		}
		return exist;
	}

	auto GetHeroById(int HeroId)
	{
		bool exist = false;     //якщо геро€ з таким id не ≥снуЇ, метод повертаЇ exist = false
		for (auto i : HeroList)
		{
			if (HeroId == i.return_id())
			{
				Hero& link = i;
				ShowHeroInfo(link);
				exist = true;
				break;
			}
		}
		return exist;
	}
};