#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

const vector<int> FULL_SET = {1, 2, 3, 4, 5, 6, 7, 8, 9};

vector<vector<int>> v = {
	{0,7,0,2,0,6,0,5,0},
	{5,0,0,0,0,0,0,0,3},
	{0,4,0,0,0,0,0,9,0},
	{0,0,2,0,1,0,8,0,0},
	{0,1,0,0,0,0,0,2,0},
	{0,0,6,0,4,0,5,0,0},
	{0,9,0,0,0,0,0,7,0},
	{2,0,0,0,0,0,0,0,9},
	{0,5,0,4,0,7,0,1,0}};

bool search(const int num, const vector<int> *vec){
	bool inside = false;
	for (vector<int>::const_iterator iter = vec->begin(); iter != vec->end(); iter++) {
		if (*iter == num) {
			inside = true;
			break;
		}
	}
	return inside;
}

void both(vector<int> *first, const vector<int> *other){
	vector<int>::iterator iter = first->begin();
	while (iter != first->end()) {
		if (!search(*iter, other))
			iter = first->erase(iter);
		else
			iter++;
	}
}

void invert(vector<int> *vec){
	vector<int> copy = FULL_SET;
	vector<int>::iterator iter = copy.begin();
	while (iter != copy.end()){
		if (search(*iter, vec))
			iter = copy.erase(iter);
		else
			iter++;
	}
	*vec = copy;
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
		vector<int> horizontal(int row){
			vector<int> notPossible;
			vector<int> r = board.at(row);
			vector<int>::iterator iter = r.begin();
			while (iter != r.end()){
				if (*iter)
					notPossible.push_back(*iter);
				iter++;
			}
			invert(&notPossible);
			return notPossible;
		}
		vector<int> vertical(int col){
			vector<int> notPossible;
			vector<vector<int>>::iterator iter = board.begin();
			while (iter != board.end()){
				vector<int> row = *iter;
				int x = row.at(col);
				if (x)
					notPossible.push_back(x);
				iter++;
			}
			invert(&notPossible);
			return notPossible;
		}
		vector<int> section(int sec){
			vector<int> notPossible;
			for (int i = sec / 3; i < (sec / 3 + 3); i++){
				vector<int> row = board.at(i);
				for (int j = sec % 3 * 3; j < (sec % 3 * 3 + 3); j++){
					int col = row.at(j);
					if (col) {
						notPossible.push_back(col);
					}
				}
			}
			invert(&notPossible);
			return notPossible;
		}
			
};

class Box {
	public:
		Box(int n, int r, int c) 
		: num(n), row(r), col(c)
		{
		}
		//BASICALLY both() SO CHANGE THAT LATER
		//Also, if only one possibility left, set it to the solution.
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
		vector<int> possible = FULL_SET;
};

int main() {
	Sudoku s(v);
	s.print();
	vector<int> h = s.section(2);

	vector<int>::iterator iter = h.begin();
	while (iter != h.end()) {
		cout << *iter << " ";
		iter++;
	}
	cout << endl;
/*
	for (int i = 0; i < 9; i++) {
		cout << i << " " << i / 3 * 3 << " " << i % 3 * 3 << endl;
	}
*/	
	return 0;
}
