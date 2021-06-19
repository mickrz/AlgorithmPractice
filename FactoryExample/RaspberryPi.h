#include "BaseBoard.h"

class RaspberryPi : public BaseBoard {
public:
	void create() {
		std::cout << "Raspberry Pi board created!" << std::endl;
	}
};