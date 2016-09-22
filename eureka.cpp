/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: 유레카 (트라이앵글 넘버의 합으로 이루어진 숫자 구하기)
*********************************************************/

#include<iostream>
#include<fstream>
using namespace std;

int triNum(int num);
int findMaxN(int num);

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;

	while (numCases--) {
		int data;
		file >> data;
		int temp = data;
		bool isTrue = false;
		int i;
		for (int i = 1; data >= triNum(i); i++) {
			for (int j = 1; data >= triNum(i) + triNum(j); j++) {
				for (int k = 1; data >= triNum(i) + triNum(j) + triNum(k); k++) {
					if (data == triNum(i) + triNum(j) + triNum(k)) {
						isTrue = true;
						break;
					}
				}
				if (isTrue)
					break;
			}
			if (isTrue)
				break;
		}
		if (isTrue)
			cout << "1" << endl;
		else
			cout << "0" << endl;

	}

	return 0;
}

int triNum(int num) { //트라이앵글 숫자를 찾는 함수
	return num*(num + 1) / 2;
}
int findMaxN(int num) { // 숫자보다 작은 가장큰 트라이앵글 숫자의 인덱스를 찾는 함수
	int i;
	for (i = 1; triNum(i) <= num; i++) {}
	return i - 1;
}