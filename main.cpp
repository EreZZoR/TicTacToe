#include "board.h"

int main(int argc, char* argv[]) {
	Board board;
	int dim;
	bool turn = false;
	int end = -1;

	do {
		printf_s("Introduce a size for the Game Board: ");
		scanf_s("%d", &dim);
		if (dim < 3) {
			system("CLS");
			printf_s("Introduce a number above 2. \n");
			
		}
	} while (dim < 3);
	board.setDim(dim);
	board.initializeBoard();
	board.showBoard();

	while (end == -1) {
		system("CLS");
		board.showBoard();

		if (turn == false) {
			board.playerTurn();
			turn = true;
		}
		else {
			board.botTurn();
			turn = false;
		}

		end = board.gameEnd();
	
	}

	board.showBoard();

	switch (end)
	{
	case 1: printf_s("\n Congrats, You WON! \n "); break;
	case 2: printf_s("\n The BOT destroyed YOU! \n "); break;
	case 3: printf_s("\n Draw! \n "); break;
	}



	system("PAUSE");
	return 0;
}