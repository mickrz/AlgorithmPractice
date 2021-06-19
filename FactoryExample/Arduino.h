#include "BaseBoard.h"

class Arduino : public BaseBoard {
public:
	void create() {
		std::cout << "Arduino board created!" << std::endl;
	}
};