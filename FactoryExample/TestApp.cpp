// FactoryExample.cpp : Defines the entry point for the application.
//

#include "BoardFactory.h"

int main()
{
	std::unique_ptr<BaseBoardFactory> baseBoardFactory = std::make_unique<BaseBoardFactory>();
	BaseBoard* baseBoard;

	baseBoard = baseBoardFactory->createBoard("Arduino");
	baseBoard->create();
	return 0;
}
