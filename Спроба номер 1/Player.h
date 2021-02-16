#pragma once
#include <iostream>
#include <string>
#include <math.h>
using namespace std;
class Player
{
private:
	string name;
	int id, rank;
public:

	auto add_name(string PlayerName)
	{
		this->name = PlayerName;
	}
	auto return_name()
	{
		return name;
	}

	auto add_id(int PlayerId)
	{
		this->id = PlayerId;
	}
	auto return_id()
	{
		return id;
	}

	auto add_rank(int PlayerRank)
	{
		this->rank = PlayerRank;
	}
	auto return_rank()
	{
		return rank;
	}

	friend bool operator == (const Player& A, const Player& B)
	{
		if ((A.name == B.name) && (A.id == B.id))
			return true;
		return false;
	};
};
