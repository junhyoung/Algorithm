/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: Dynamic Program Change1
*********************************************************/
#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	while (numCases --) {
		int numOfKind; // 잔돈 종류의 갯수
		file >> numOfKind;
		int *kindOfCoin; //잔돈의 종류 저장 배열
		kindOfCoin = new int[numOfKind];
		for (int i = 0; i < numOfKind; i++)
			file >> kindOfCoin[i];
		int change;
		file >> change;
		int *table = new int[change+1]; // 0~ 원하는잔돈까지 저장할 최소의 교환갯수 저장 테이블
		int *lastChangeTb = new int[change+1]; // 마지막에 사용한 잔돈의 종류 저장 테이블
		for (int i = 0; i <= change; i++) {
			if (i == 0) { //Base Case
				table[i] = 0;
				lastChangeTb[i] = 0;
			}
			else { //Recursive Step
				int min=9999;
				int minIndex = 9999;
				for (int j = 0; j < numOfKind; j++) {
					if (i-kindOfCoin[j]>=0 &&  min > table[i-kindOfCoin[j]]) {
						minIndex = j;
						min = table[i - kindOfCoin[j]];
					}
				}
				table[i] = min + 1;
				lastChangeTb[i] = minIndex;
			}


		}
		int * countOfCoin = new int[numOfKind]; // 잔돈종류별 사용갯수 저장 배열
		for (int i = 0; i < numOfKind; i++)
			countOfCoin[i] = 0; // 초기화
		cout << table[change]<<endl; //최소의 교환갯수
		while (change != 0) {
			countOfCoin[lastChangeTb[change]]++;
			change -= kindOfCoin[lastChangeTb[change]];       
		}
		for (int i = 0; i < numOfKind; i++) {
			cout << countOfCoin[i];
			if (i == numOfKind - 1)
				cout << endl;
			else
				cout << " ";
		}
		
	}
	
	return 0;
}
