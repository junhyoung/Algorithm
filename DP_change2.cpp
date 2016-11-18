#include<iostream>
#include<fstream>
using namespace std;

int main() {
	int numcases,numOfCoins;
	ifstream file("input.txt");
	file >> numcases;
	while (numcases--) {
		file >> numOfCoins;
		int * kindOfCoin = new int[numOfCoins];
		for (int i = 0; i < numOfCoins; i++)
			file >> kindOfCoin[i];
		int change;
		file >> change;
		int **table = new int*[numOfCoins + 1];
		for (int i = 0; i <= numOfCoins; i++)
			table[i] = new int[change + 1];
		for (int i = 0; i <= numOfCoins; i++) {
			for (int j = 0; j <= change;j++){
				if (j == 0)
					table[i][j] = 1;
				else if (i == 0)
					table[i][j] = 0;
				else if (j - kindOfCoin[i-1] < 0)
					table[i][j] = table[i-1][j];
				else
					table[i][j] = table[i - 1][j]+table[i][j-kindOfCoin[i-1]];
			}
		}
		cout << table[numOfCoins][change] << endl;

	}


	return 0;
}
