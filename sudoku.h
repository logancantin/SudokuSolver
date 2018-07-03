#ifndef H_GUARD_SUDOKU
#define H_GUARD_SUDOKU

#include <vector>

bool search(int, vector<int>*);

class Sudoku {
	private:
		vector<vector<int>> board;
	public:
		Sudoku();
		Sudoku(vector<vector<int>>);
		void print();
};

class Box{
	public:
		Box(int, int, int);
		int getNum();
		int getRow();
		int getCol();
		void printPossible();
	private:
		int num;
		int x, y;
		vector<int> possible;
};

