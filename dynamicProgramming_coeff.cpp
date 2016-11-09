/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: 동적계획법으로 nCk구하기
*********************************************************/
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases; 
	int **arr;
	
	while (numCases--) {
		int N, K;
		file >> N >> K;
		arr = new int *[N + 1];
		for (int i = 0; i <= N ; i++)
			arr[i] = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0 || j == i)
					arr[i][j] = 1;
				else {
					arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
					arr[i][j] %= 10007;
				}
			}
		}
		cout << arr[N][K] << endl;
		for (int i = 0; i <= N; i++)
			delete[]arr[i];
		delete[]arr;
	}
	return 1;
}
