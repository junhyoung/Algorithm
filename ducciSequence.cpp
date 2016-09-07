#include<iostream>
#include<fstream>
using namespace std;
int abs(int a, int b);

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;

	while (numCases--) {
		int length;
		file >> length;
		int *temp = new int[length];
		int *data = new int[length];
		int count = 0;

		for (int i = 0; i < length; i++) {
			file >> data[i];
			temp[i] = data[i];
		}

		int *history[1000];
		for (int i = 0; i < 1000; i++)
			history[i] = new int[length];
		while (1) {
			
			int j;
			bool isLoop = true;

			for (j = 0; j < length; j++) {
				if (data[j] != 0)
					break;
			}
			if (j >= length) {
				cout << "ZERO" << endl;
				break;
			}
			else {
				for (int i = 0; i < count; i++) {
					isLoop = true;
					for (j = 0; j < length; j++) {
						if (data[j] != history[i][j]) {
							isLoop = false;
							break;
						}
					}
					if (isLoop) {
						cout << "LOOP" << endl;
						break;
					}
					
				}
				if (count == 0)
					isLoop = false;
				if (isLoop)
					break;
				else {

					for (int i = 0; i < length; i++) {
						history[count][i] = data[i];
						if (i == length - 1)
							data[i] = abs(temp[i], temp[0]);
						else
							data[i] = abs(temp[i], temp[i + 1]);
					}
					for (int i = 0; i < length; i++)
						temp[i] = data[i];
					count++;
				}
			}

		}
		for (int i = 0; i < 1000; i++)
			delete history[i];
	}
	return 0;
}
int abs(int a, int b) {
	int takeOff = a - b;
	if (takeOff >= 0)
		return takeOff;
	else
		return -takeOff;
}