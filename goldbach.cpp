// 20123425 ÃÖÁØÇü
// num 06 goldbach Conjecture

#include<iostream>
#include<fstream>
using namespace std;

bool checkPrim(int a, int b);

int main() {
	int numCases;
	ifstream file("input.txt");

	file >> numCases;
	while (numCases--) {

		int data;
		file >> data;

		int i;

		int a, b;
		if ((data / 2) % 2 == 0 && (data/2)!=2) {
			for (i = 1; i < data / 2; i += 2) {

				a = (data / 2 - i);
				b = (data / 2 + i);

				int j;

				for (j = 2; j <= b / 2 ; j++) {
					if (a%j == 0 && j <= a / 2 && a!=2)
						break;
					if (b%j == 0 && b!=2)
						break;
				}
				if (j > b / 2)
					break;
			}
		}
		else {
			for (i = 0; i < data / 2; i += 2) {

				a = (data / 2 - i);
				b = (data / 2 + i);

				int j;

				for (j = 2; j <= b / 2 ; j++) {
					if (a%j == 0 && j <= a / 2&& a!=2)
						break;
					if (b%j == 0 && b!=2)
						break;
				}
				if (j > b / 2)
					break;
			}
			
		}
		cout << data / 2 - i << " " << data / 2 + i << endl;
	}


	return 0;
}

bool checkPrim(int a, int b) {
	for (int i = 2; i <= b / 2 + 1; i++) {
		if (a%i == 0 && i <= a / 2)
			return false;
		if (b%i == 0)
			return false;
	}
	return true;
}