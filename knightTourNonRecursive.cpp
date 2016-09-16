/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: Knight Tour Non recursive Version
*********************************************************/
#include<iostream>
#include<fstream>
using namespace std;

int canPath[8][2] = { { -2, -1 },{ -2,1 },{ -1,-2 },{ -1,2 },{ 1,-2 },{ 1,2 },{ 2,-1 },{ 2,1 } };
//int canPath[8][2] = { {1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1},{-2,1}, {-1,2} };
//int canPath[8][2] = { { 1, -2 },{ 2, -1 },{ 2, 1 },{ 1, 2 },	{ -1, 2 },{ -2, 1 },{ -2, -1 },{ -1, -2 } };

class node {
public:
	int x, y;
	int pX, pY;
	node(int x, int y) {
		this->x = x;
		this->y = y;
		pX = -1;
		pY = -1;
	}
	node(int x, int y, int pX, int pY) {
		this->x = x;
		this->y = y;
		this->pX = pX;
		this->pY = pY;
	}
	node() {
		x = -1;
		y = -1;
		pX = -1;
		pY = -1;
	}
};
class stack {
public:
	node* S;
	int last;

	stack() {
		last = -1;
		S = new node[1000];
	}
	~stack() {
		delete S;
		S = NULL;
	}
	void push(node temp) {
		if (last >= 1000)
			cout << "Stack is FULL" << endl;
		else {
			S[++last] = temp;
		}
	}
	node pop() {
		if (last >= 0)
			return S[last--];
		else {
			return node(-1,-1);
		}
	}
};

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;

	while(numCases--) {
		int col, row, x, y;
		int count = 1;
		int pastPath[8][8];
		int countCanPath[8][8];
		file >> col >> row >> x >> y;

		for (int i = 0; i < col; i++) {
			for (int j = 0; j < row; j++) {
				pastPath[i][j] = 0;
				countCanPath[i][j] = 0;
			}
			
		}

		stack S; // 갈수있는 길을 담는 스택
		stack path;  //지나온길을 담는 스택
		node temp(x-1,y-1);
		node curr;
		node fail;
		
		S.push(temp);

		
		int pushCount = 0;
	
		while (1) {
			if (count > row*col)
				break;

			temp = S.pop();
			if ((pastPath[curr.pX][curr.pY] > pastPath[temp.pX][temp.pY]) &&  count != 1) {
				
				int save = pastPath[temp.pX][temp.pY];
				while(count > save+1) {
					fail = path.pop();
					pastPath[fail.x][fail.y] = 0;
					count--;

				}
			}
			if (temp.x == -1)
				break;

			curr = temp;

			pushCount = 0;

			for (int i = 7; i >= 0; i--) {
				int nextX = curr.x + canPath[i][0];
				int nextY = curr.y + canPath[i][1];
				if (nextX >= 0 && nextX < col && nextY >= 0 && nextY < row && pastPath[nextX][nextY] == 0) {
					temp = node(nextX, nextY,curr.x,curr.y);
					S.push(temp);
					pushCount++;
				}
			}

			if (pushCount != 0 || count == row*col) {
				pastPath[curr.x][curr.y] = count++;
				path.push(curr);
			}
			
		}

		if (count > row* col) {
			cout << "1" << endl;
			for (int i = 0; i < col; i++) {
				for (int j = 0; j < row; j++)
					cout << pastPath[i][j] << " ";
				cout << endl;
			}
		}
		else
			cout << "0" << endl;

	}

	return 0;
}