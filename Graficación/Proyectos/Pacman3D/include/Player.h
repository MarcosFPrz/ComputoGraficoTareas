#pragma once
#include <vector>


class Player
{
public:
	Player();
	~Player();
	Player(int i, int j);

	void setUp(std::vector<std::vector<int> > map);
	int x, y;
};

