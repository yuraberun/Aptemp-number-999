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
		for (auto i : HeroList)     //Check if the entered name is free
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
		cout << "Ім'я героя: " << Hero1.return_name() << endl;
		cout << "id: " << Hero1.return_id() << "  ";
		cout << "Damage: " << Hero1.return_damage() << "  " << "Hp: " << Hero1.return_hp() << endl;
	}

	auto GetHeroByName(string HeroName)
	{
		bool exist = false;    //If a hero with that name does not exist, the method returns exist = false
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
		bool exist = false;     //If the hero with such id does not exist, the method returns exist = false
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

	auto return_size()
	{
		return HeroList.size();
	}

	auto make_a_copy(Hero hero1, Hero copy)    //This method makes a copy of the hero and returns it
	{
		copy.add_name(hero1.return_name());
		copy.add_id(hero1.return_id());
		copy.add_damage(hero1.return_damage());
		copy.add_hp(hero1.return_hp());
		return copy;
	}

	auto bot()
	{
		Hero bot;
		bot.add_name("HeroBot");
		bot.add_id(0);
		bot.add_damage(rand() % 20 + 10);
		bot.add_hp(rand() % 50 + 25);
		return bot;
	}

	auto return_hero(int numb)   //n - random number; the method finds the element by number, makes a copy                    
	{                         //and puts an element at the end (so this element will not be repeated)
		int count = 1;
		for (auto i : HeroList)
		{
			if (numb == count)
			{
				copy = make_a_copy(i, copy);
				HeroList.remove(i);
				HeroList.push_back(copy);
				break;
			}
			count++;
		}
		return copy;
	}
};