#pragma once
#include <string>
using namespace std;
class Hero
{
private:
	string name;
	int damage, hp, id;
public:

	auto add_name(string HeroName)
	{
		this->name = HeroName;
	}
	auto return_name()
	{
		return name;
	}

	auto add_damage(int HeroDamage)
	{
		this->damage = HeroDamage;
	}
	auto return_damage()
	{
		return damage;
	}

	auto add_hp(int HeroHp)
	{
		this->hp = HeroHp;
	}
	auto return_hp()
	{
		return hp;
	}

	auto add_id(int HeroId)
	{
		this->id = HeroId;
	}
	auto return_id()
	{
		return id;
	}

	friend bool operator == (const Hero& A, const Hero& B)
	{
		if ((A.name == B.name) && (A.id == B.id))
			return true;
		return false;
	};
};