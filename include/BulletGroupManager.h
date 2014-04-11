/*
* The Artificial Intelligence Using Randomness (AIUR) is an AI for StarCraft: Broodwar, 
* aiming to be unpredictable thanks to some stochastic behaviors. 
* Please visit http://code.google.com/p/aiurproject/ for further information.
* 
* Copyright (C) 2011 - 2014 Florian Richoux
*
* This file is part of AIUR.
* AIUR is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.

* AIUR is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.

* You should have received a copy of the GNU General Public License
* along with AIUR.  If not, see http://www.gnu.org/licenses/.
*/

#pragma once
#include <BWAPI.h>
#include <BulletGroup.h>
class BulletGroupManager
{
public:
	static BulletGroupManager* create();
	static void destroy();
	void update();
private:
	BulletGroupManager();
	~BulletGroupManager();
};
extern BulletGroupManager* TheBulletGroupManager;
BulletGroup AllBullets();
BulletGroup SelectAllBullet();
BulletGroup SelectAllBullet(BWAPI::BulletType type);
BulletGroup SelectAllEnemyBullet();
BulletGroup SelectAllEnemyBullet(BWAPI::BulletType type);
BulletGroup SelectAllBullet(BWAPI::Player* player, BWAPI::BulletType type);