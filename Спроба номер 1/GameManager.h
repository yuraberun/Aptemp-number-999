#pragma once
#include <iostream>
#include <string>
#include <list>
using namespace std;
class GameManager
{
private:
	list <string> list_of_fights;
public:

	auto add_fight_to_list(string rezult)
	{
		list_of_fights.push_back(rezult);
	}

	auto show_list_of_fights()
	{
		int n = 1;
		system("cls");
		for (auto i : list_of_fights)
		{
			cout << n << "." << i << endl;
			n++;
		}
	}
};