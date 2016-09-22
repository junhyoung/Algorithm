/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: 호텔
*********************************************************/
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	while (numCases--) {
		int w, h, n;
		file >> h >> w >> n;
		int N = 1 , H = 0;
		while (n--) {
			H++;
			if (H > h) {
				N++;
				H = 1;
			}
		}
		if(N<10)
			cout << H <<"0"<< N << endl;
		else
			cout << H << N << endl;
	}

	return 0;
}