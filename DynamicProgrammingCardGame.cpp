#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int numCases;
	ifstream infile("input.txt");
	infile >> numCases;
	//cin >> numCases;
	while (numCases--) {
		int numCard;
		infile >> numCard;
		//cin >> numCard;
		int* card = new int[numCard + 1];
		int** table = new int*[numCard + 1];
		int ** sum = new int*[numCard + 1];
		for (int i = 1; i <= numCard; i++) {
			infile >> card[i];
			//cin >> card[i];
			table[i] = new int[numCard+1];
			sum[i] = new int[numCard + 1];
			table[i][i] = card[i];
			sum[i][i] = card[i];
		}
		for (int i = 1; i <= numCard; i++) {
			for (int j = 1; j <= numCard - i; j++) {
				sum[j][i + j] = sum[j][j] + sum[j + 1][i + j];
			}
		}
		
		for (int i = 1; i <= numCard; i++) {
			for (int j = 1; j <= numCard-i; j++) {
				int min = 0;
				min = table[j + 1][i + j] > table[j][i + j - 1] ? table[j][i + j - 1] : table[j + 1][i + j];
				table[j][i + j] = sum[j][i+j] - min;
			}
		}
		cout << table[1][numCard] << endl;
	}
	return 0;
}
