#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

class Board {
public:
	~Board();
	void setDim(const int dim);
	void initializeBoard();
	void showBoard() const;
	void botTurn();
	void playerTurn();
	int gameEnd() const;

private:
	vector<vector<int>> m_board;
	int m_dim;
};