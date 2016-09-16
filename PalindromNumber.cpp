//20123425 ÃÖÁØÇü
//Num02 Palindrom number
#include<iostream>
#include<fstream>
using namespace std;


int main() {
	ifstream f;
	f.open("input.txt");

	int numCase = 0;
	f >> numCase;

	while (numCase--){
		int data;
		f >> data;
		int chData[20];
		bool isEnd = false;

		for (int i = 2; i <= 64; i++) {
		//int i = 10;{
			int index = 0;
			int cpData = data;

			while (cpData) {
				chData[index++] = cpData%i;
				cpData /= i;
			}
			//cout << "index" << index;

			if (index % 2) {
				for (int j = 0; j <= (index / 2) - 1; j++) {
					if (chData[j] != chData[index - j -1]) {
						isEnd = false;
						break;
					}
					isEnd = true;
				}
				
			}
			else {
				for (int j = 0; j < (index / 2); j++) {
					if (chData[j] != chData[index - j - 1]) {
						isEnd = false;
						break;
					}
					isEnd = true;
				}
			}
			if (isEnd)
				break;

		}

		if (isEnd)
			cout << "1";
		else
			cout << "0";
		cout << endl;

	}
	return 0;
}
