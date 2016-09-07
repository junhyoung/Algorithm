#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	while (numCases--) {

		char data[50];
		int numL = 0;		// 왼쪽 괄호이면 ++ 오른쪽 괄호이면 --
		bool isYes = true; // 결과 체크용 변수

		file >> data;

		for (int i = 0; data[i]; i++) {
			if (data[i] == '(') //왼쪽괄호이면 numL++
				numL++;
			else {				//오른쪽 괄호이면 numL--
				numL--;			
				if (numL < 0) {	//왼쪽 괄호가 더 많으면 FALSE
					isYes = false;
					break;
				}
			}
		}
		if (isYes && numL == 0)	//numL 왼쪽괄호와 오른쪽괄호의 갯수가 일치하면서 대칭일경우
			cout << "YES" << endl;
		else					//왼쪽괄호가 더많거나 오른쪽 괄호가 더많은경우
			cout << "NO" << endl;

		numL = 0;
		isYes = true;
	}


	return 0;
}