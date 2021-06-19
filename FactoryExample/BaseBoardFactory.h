#pragma once
#include <iostream>
#include "RaspberryPi.h"
#include "DragonBoard410c.h"
#include "Arduino.h"
#include "BaseBoard.h"

class BaseBoardFactory
{
public:
	BaseBoardFactory() = default;
	virtual ~BaseBoardFactory() = default;

	virtual BaseBoard* createBoard(char* type) {
		if (strcmp(type, "RaspberryPi") == 0) {
			return new RaspberryPi;
		}
		else if (strcmp(type, "DragonBoard410c") == 0) {
			return new DragonBoard410c;
		}
		else if (strcmp(type, "Arduino") == 0) {
			return new Arduino;
		}
		return NULL;
	}
};