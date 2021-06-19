#pragma once
#include "BaseBoardFactory.h"


class BoardFactory : public BaseBoardFactory {
	BaseBoard* create(char* type) {
		if (strcmp(type, "RaspberryPi") == 0) {
			return new RaspberryPi;
		}
		else if (strcmp(type, "DragonBoard410c") == 0) {
			return new DragonBoard410c;
		}
	}
};
