/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: Knight Tour 
*********************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int canPath[8][2] = { { -2, -1 },{ -2,1 },{ -1,-2 },{ -1,2 },{ 1,-2 },{ 1,2 },{ 2,-1 },{ 2,1 } };
class path {
public:
	int pastPath[8][8];
	int count;
	//int canPath[8][2] ;
	//int canPath[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}, {-1,2} };
	//int canPath[8][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },	{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };
	int row, col;


	path(int col, int row,int x,int y) {
		//pastPath = new int*[col];
		//for (int j = 0; j < row; j++)
		//	pastPath[j] = new int[row];
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++)
				pastPath[i][j] = 0;
		}
		this->col = col;
		this->row = row;
		count = 2;
		pastPath[x][y] = 1;
	}
	


	int knightTourRecur(int x,int y) {
		int nextX, nextY;
		
		if (count>col*row) {
			return 1;
		}
		else {

			for (int i = 0; i < 8; i++) {

				nextX = canPath[i][0] + x;
				nextY = canPath[i][1] + y;

				if ( nextX >= 0 && nextX < col && nextY >= 0 && nextY < row && pastPath[nextX][nextY] == 0 ) {
					pastPath[nextX][nextY] = count++;

					if (knightTourRecur(nextX, nextY))
						return 1;
					else {
						pastPath[nextX][nextY] = 0;
						count--;
					}
					
				}

				
			}
			return 0;
		}
	}
	void printPath() {
		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++)
				cout << pastPath[i][j] << " ";
			cout << endl;
		}
	}
};


int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	while (numCases--) {
		int col, row;
		int x, y;
		file >> col >> row >> x >> y;

		path *P = new path(col,row,x-1,y-1);
		
		if (P->knightTourRecur(x-1, y-1)) {
			cout << "1" << endl;
			P->printPath();
		}
		else
			cout << "0" << endl;
		delete P;

	}
	return 0;
}