/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: ICPC I Q-index
*********************************************************/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	int numcases;
	ifstream file("input.txt");
	file >> numcases;
	while (numcases--) {
		int numdata;
		file >> numdata;
		int *data;
		data = new int[numdata];
		for (int i = 0; i < numdata; i++)
			file >> data[i];
		int res=0;
		sort(data, data + numdata,cmp);
		//12 10 9 8 7 6
		for (int i = 1; i <= numdata; i++) {
			int big = 0, small = 0;
			for (int j = 0; j < numdata; j++) {
				if (data[j] >= i && big < i)
					big++;
				else if (data[j] <= i && big == i)
					small++;
				else
					break;
			}
			if (big + small == numdata) {
				res = i;
				break;
			}
		}
		cout << res << endl;

	}

	return 0;
}
