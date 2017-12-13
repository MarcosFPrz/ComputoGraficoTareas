#include "Player.h"



Player::Player()
{
}


Player::~Player()
{
}

Player::Player(int i, int j)
{
	x = i;
	y = j;
}

void Player::setUp(std::vector<std::vector<int>> map)
{
	for (int i = 0; i < map.size(); ++i)
	{
		for (int j = 0; j < map[i].size(); ++j)
		{
			if (map[i].at(j) == 3)
			{
				x = i;
				y = j;
			}
		}
	}
}
