/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: ICPC A번 Binary Tree
*********************************************************/
#include<iostream>
#include<fstream>
using namespace std;
int max(int bt[], int index, int level);
int mkMinSum(int bt[], int index, int level,int MAX);
int sum(int bt[], int index, int level);
int pow(int a, int b);
int height;
int res = 0;
int main() {
	int numcases;
	ifstream file("input.txt");
	file >> numcases;
	while (numcases--) {
		res = 0;
		file >> height;
		int index = pow(2, height + 1);
		int *bT = new int[index];
		bT[0] = 0;
		for (int i = 1; i <index-1 ; i++) 
			file >> bT[i];

		int Max = max(bT, 0, 0);
		
		mkMinSum(bT, 0, 0, Max);
		cout << res << endl;
	}
	return 0;
}
int pow(int a, int b) { //제곱 구하는 함수
	if (b == 0)
		return 1;
	else
		return a*pow(a,b-1);
}
int sum(int bt[], int index, int level) {//합 구하는 함수
	if (level == height)
		return bt[index];
	else {
		int a = sum(bt, 2 * index + 1, level + 1), b = sum(bt, 2 * index + 2, level + 1);
		return bt[index] + a + b;
	}
}
int max(int bt[], int index, int level) { //최댓값 구하는 함수
	if (level == height)
		return bt[index];
	else {
		int a = max(bt, 2 * index + 1, level + 1), b = max(bt, 2 * index + 2, level + 1);
		return bt[index] + (a > b ? a : b);
	}
}
int mkMinSum(int bt[], int index, int level,int MAX) { // 최소의 증가를 만드는 함수
	if (level == height)
		return MAX - bt[index];
	else {
		int left = mkMinSum(bt, 2 * index + 1, level + 1, MAX-bt[index]), right= mkMinSum(bt, 2 * index + 2, level + 1, MAX-bt[index]);
		int min = left < right ? left : right;
		bt[2 * index + 1] += (left - min);
		bt[2 * index + 2] += (right - min);
		res += bt[2 * index + 2] + bt[2 * index + 1];
		return min;
	}

}
