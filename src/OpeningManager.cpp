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

#include <OpeningManager.h>

OpeningManager::OpeningManager()
{
	enemyRace = BWAPI::Broodwar->enemy()->getRace();
}

void OpeningManager::initialize()
{
	MoodManager::MoodData::Mood mood = moodManager->getMood();
	switch(mood)
	{
	case MoodManager::MoodData::Cheese:
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Forge,90);
		break;
	case MoodManager::MoodData::Rush:
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Gateway,70);
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Zealot,75);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Gateway,70);
		break;
	case MoodManager::MoodData::Agressive: //like Rush before
		break;
	case MoodManager::MoodData::Defensive:
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Gateway,70);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Zealot,75);
		buildOrderManager->build(3,BWAPI::UnitTypes::Protoss_Gateway,70);
		break;
	case MoodManager::MoodData::FastExpo:
		if (BWAPI::Broodwar->mapHash() != hashMap.hash("Andromeda"))
			baseManager->expand(95);
		else
		{
			if (BWAPI::Broodwar->self()->getStartLocation().x() == 7 && BWAPI::Broodwar->self()->getStartLocation().y() == 6)
			{
				BWAPI::TilePosition tp(21, 21);
				baseManager->expand(BWTA::getNearestBaseLocation(tp), 95);
			}
			else if (BWAPI::Broodwar->self()->getStartLocation().x() == 7 && BWAPI::Broodwar->self()->getStartLocation().y() == 118)
			{
				BWAPI::TilePosition tp(21, 105);
				baseManager->expand(BWTA::getNearestBaseLocation(tp), 95);
			}
			else if (BWAPI::Broodwar->self()->getStartLocation().x() == 117 && BWAPI::Broodwar->self()->getStartLocation().y() == 119)
			{
				BWAPI::TilePosition tp(103, 105);
				baseManager->expand(BWTA::getNearestBaseLocation(tp), 95);
			}
			else if (BWAPI::Broodwar->self()->getStartLocation().x() == 117 && BWAPI::Broodwar->self()->getStartLocation().y() == 7)
			{
				BWAPI::TilePosition tp(103, 21);
				baseManager->expand(BWTA::getNearestBaseLocation(tp), 95);
			}
			// should never happen
			else
				baseManager->expand(95);
		}
		//buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Pylon,90);
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Gateway,85);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Zealot,85);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Gateway,80);
		buildOrderManager->build(4,BWAPI::UnitTypes::Protoss_Zealot,80);
		buildOrderManager->build(3,BWAPI::UnitTypes::Protoss_Gateway,75);
		buildOrderManager->build(6,BWAPI::UnitTypes::Protoss_Zealot,75);
		buildOrderManager->build(4,BWAPI::UnitTypes::Protoss_Dragoon,75);
		break;
	case MoodManager::MoodData::Macro:
		buildOrderManager->build(1,BWAPI::UnitTypes::Protoss_Gateway,70);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Zealot,75);
		buildOrderManager->build(2,BWAPI::UnitTypes::Protoss_Gateway,70);
		break;			
	}
}

void OpeningManager::setMoodManager(MoodManager *moodManager)
{
	this->moodManager = moodManager;
}

void OpeningManager::setBuildOrderManager(BuildOrderManager *buildOrderManager)
{
	this->buildOrderManager = buildOrderManager;
}

void OpeningManager::setBaseManager(BaseManager *baseManager)
{
	this->baseManager = baseManager;
}
