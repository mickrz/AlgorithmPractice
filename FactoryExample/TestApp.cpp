// FactoryExample.cpp : Defines the entry point for the application.
//

#include "BoardFactory.h"

int main()
{
	BaseBoardFactory* baseBoardFactory = new BaseBoardFactory;
	BaseBoard* baseBoard;

	baseBoard = baseBoardFactory->createBoard("Arduino");
	baseBoard->create();
	return 0;
}
