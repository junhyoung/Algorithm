#include<iostream>
#include<fstream>
using namespace std;
int main() {
	int numCases;
	ifstream infile("input.txt");
	infile >> numCases;

	while (numCases--) {
		int numFile;
		int **DP;
		infile >> numFile;
		int *fileSize = new int[numFile+1];
		DP = new int*[numFile + 1];
		for (int i = 1; i <= numFile; i++) {
			DP[i] = new int[numFile+1];
			infile >> fileSize[i];
			DP[i][i] = 0;
		}
		for (int i = 1; i <= numFile; i++) {
			for (int j = 1; j <= numFile-i; j++) {
				int sum = 0;
				for (int q = j; q <= j + i; q++)
					sum += fileSize[q];
				int min = (DP[j][j] + DP[j + 1][i + j] + sum);
				for (int k = j+1; k < i + j; k++) {
					min = min > (DP[j][k] + DP[k + 1][i + j] + sum) ? (DP[j][k] + DP[k + 1][i + j] + sum) : min;
				}
				DP[j][i + j] = min;
			}
		}
		cout << DP[1][numFile] << endl;
	}
	return 0;   
}
