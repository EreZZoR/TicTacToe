#include "board.h"

Board::~Board()
{
	for (int i = 0; i < m_dim; i++) {
		m_board[i].clear();
	}
	m_board.clear();
}

void Board::setDim(const int dim) {
	m_dim = dim;
	m_board.resize(dim);
	for (int i = 0; i < dim; i++) {
		m_board[i].resize(dim);
	}
}

void Board::initializeBoard() {
	for (int i = 0; i < m_dim; i++) {
		for (int j = 0; j < m_dim; j++) {
			m_board[i][j] = 0;
		}
	}
}

/*
-1 -> Board not full.
0 -> Empty position / Game not Finished.
1 -> X (Player)
2 -> O (BOT)
3 -> Draw.
*/

void Board::showBoard() const {
	if (m_dim < 11) { // If > 11 then positions don't match with the numbers.
		printf_s("  ");
		for (int i = 0; i < m_dim; i++) {
			printf_s("%d ", i);
		}
		printf_s("\n");
	}
	
	for (int i = 0; i < m_dim; i++) {
		printf_s("%d ", i);
		for (int j = 0; j < m_dim; j++) {
			switch (m_board[i][j])
			{
			case 0: printf_s("%s- ", KWHT); break;
			case 1: printf_s("%sX %s", KYEL, KWHT); break;
			case 2: printf_s("%sO %s", KCYN, KWHT); break;
			}
		}
		printf_s("\n");
	}
	printf_s("\n");
}

void Board::botTurn() {
	int row, col;
	bool flag = false;

	while (!flag) {
		row = rand() % m_dim;
		col = rand() % m_dim;
		if (m_board[row][col] == 0) {
			m_board[row][col] = 2;
			flag = true;
		}
	}
}

void Board::playerTurn() {
	int row, col;
	bool flag = false;

	while (!flag) {
		printf_s("Introduce X coordinate: ");
		scanf_s("%d", &row);
		printf_s("Introduce Y coordinate: ");
		scanf_s("%d", &col);
		if (row < m_dim and col < m_dim) {
			if (m_board[row][col] == 0) {
				m_board[row][col] = 1;
				flag = true;
			}
		}
	}
}

int Board::gameEnd() const {
	
	// Rows

	int i, j, first;
	bool flag;

	for (i = 0; i < m_dim; i++) {
		j = 1;
		first = m_board[i][0];
		flag = false;
		if (first != 0) {
			while (!flag and j < m_dim) {
				if (first != m_board[i][j]) {
					flag = true;
				}
				j++;
			}
			if (flag == false) {
				return first;
			}
		}
		
	}


	// Columns

	for (i = 0; i < m_dim; i++) {
		j = 1;
		first = m_board[0][i];
		flag = false;
		if (first != 0) {
			while (!flag and j < m_dim) {
				if (first != m_board[j][i]) {
					flag = true;
				}
				j++;
			}
			if (flag == false) {
				return first;
			}
		}
	}


	// Diagonal (Top-Left to Bott-Right)
	flag = false;
	j = 1;
	first = m_board[0][0];
	if (first != 0) {
		while (!flag and j < m_dim) {
			if (first != m_board[j][j]) {
				flag = true;
			}
			j++;
		}
		if (flag == false) {
			return first;
		}
	}

	// Diagonal (Bott-Left to Top-Right)
	flag = false;
	j = 1;
	first = m_board[m_dim - 1][0];
	if (first != 0) {
		while (!flag and j < m_dim) {
			if (first != m_board[m_dim - 1 - j][j]) {
				flag = true;
			}
			j++;
		}
		if (flag == false) {
			return first;
		}
	}

	// Check if Empty

	i = 0, j;
	flag = false;
	while (!flag and i < m_dim){
		j = 0;
		while (!flag and j < m_dim) {
			if (0 == m_board[i][j]) {
				flag = true;
			}
			j++;
		}
		i++;
	}
	if (flag == true) {
		return -1;
	}
	else {
		return 3;
	}
}