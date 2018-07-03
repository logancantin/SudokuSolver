#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
using namespace std;

vector<vector<int>> v = {
	{1,2,3,4,5,6,7,8,9},
	{2,3,4,5,6,7,8,9,1},
	{3,4,5,6,7,8,9,1,2},
	{4,5,6,7,8,9,1,2,3},
	{5,6,7,8,9,1,2,3,4},
	{6,7,8,9,1,2,3,4,5},
	{7,8,9,1,2,3,4,5,6},
	{8,9,1,2,3,4,5,6,7},
	{9,1,2,3,4,5,6,7,8}};

bool search(int num, vector<int> *vec){
	bool inside = false;
	for (vector<int>::iterator iter = vec->begin(); iter != vec->end(); iter++) {
		if (*iter == num) {
			inside = true;
			break;
		}
	}
	return inside;
}

class Sudoku {
	private:
		vector<vector<int>> board;
	public:
		Sudoku(){
			for (int x = 0; x < 9; x++) {
				vector<int> row;
				for (int y = 0; y < 9; y++) {
					int a;
					cin >> a;
					row.push_back(a);
				}
				board.push_back(row);
			}
		}
		Sudoku(vector<vector<int>> b)
			:board(b)
		{
		}
		void print(){
			string div = "+-------+-------+-------+";
			cout << div << endl;
			vector<vector<int>>::iterator iter = board.begin();
			for (int x = 0; x < 3; x++){
				printf("| %i %i %i | %i %i %i | %i %i %i |\n", 
					iter->at(0), iter->at(1), iter->at(2), 
					iter->at(3), iter->at(4), iter->at(5), 
					iter->at(6), iter->at(7), iter->at(8));
				iter++;
			}
			cout << div << endl;
			for (int x = 0; x < 3; x++){
				printf("| %i %i %i | %i %i %i | %i %i %i |\n", 
					iter->at(0), iter->at(1), iter->at(2), 
					iter->at(3), iter->at(4), iter->at(5), 
					iter->at(6), iter->at(7), iter->at(8));
				iter++;
			}
			cout << div << endl;
			for (int x = 0; x < 3; x++){
				printf("| %i %i %i | %i %i %i | %i %i %i |\n", 
					iter->at(0), iter->at(1), iter->at(2), 
					iter->at(3), iter->at(4), iter->at(5), 
					iter->at(6), iter->at(7), iter->at(8));
				iter++;
			}
			cout << div << endl;
		}
};

class Box {
	public:
		Box(int n, int r, int c) 
		: num(n), row(r), col(c)
		{
		}
		void updatePossible(vector<int> *other) {
			vector<int>::iterator iter = possible.begin();
			while (iter != possible.end()) {
				if (!search(*iter, other))
					iter = possible.erase(iter);
				else
					iter++;
			}
		}
		int getNum(){
			return num;
		}
		int getRow(){
			return row;
		}
		int getCol(){
			return col;
		}
		void printPossible(){
			for (vector<int>::iterator iter = possible.begin();
					iter != possible.end(); iter++) {
				cout << *iter << " ";
			}
			cout << endl;
		}
		vector<int> getPossible(){
			return possible;
		}
	private:
		int num;
		int row, col;
		vector<int> possible = {1, 2, 3, 4, 5, 6, 7, 8, 9};

};

int main() {
	Sudoku s(v);
	s.print();
	return 0;
}
