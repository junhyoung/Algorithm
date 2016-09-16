/*********************************************************
* Name: 최 준 형
* Student ID : 20123425
* Program ID : 문제 1 피타고라스의 기대값
* Description: 
* Algorithm : 
* Variables:
**********************************************************/
#include<iostream>
#include<fstream>
#define square(x) (x)*(x)
using namespace std;

int main() {
	ifstream f;
	f.open("input.txt");
	int numCase;
	f >> numCase;
	while (numCase--) {
		int numTeam;
		int numGame;
		f >> numTeam;
		f >> numGame;

		int *tmGScr = new int[numTeam+1]; // 획득점수
		int *tmLScr = new int[numTeam+1]; // 잃은점수

		for (int i = 1; i <= numTeam; i++) { // 초기화
			tmGScr[i] = 0;
			tmLScr[i] = 0;
		}
		for (int i = 0; i < numGame; i++) { //각팀의 획득점수, 잃은점수 게산
			int teamA, teamB;
			int getA, getB;
			f >> teamA >> teamB >> getA >> getB;
			tmGScr[teamA] += getA;
			tmGScr[teamB] += getB;
			tmLScr[teamA] += getB;
			tmLScr[teamB] += getA;

		}

		float* team = new float[numTeam+1];//피타고라스의 기대값

		int max;
		int min;

		for (int i = 1; i <= numTeam; i++) {
			if (tmGScr[i] == 0 && tmLScr[i] == 0) {
				team[i] = 0;
			}
			else
			team[i] = 1000 * square(tmGScr[i]) / (square(tmGScr[i]) + square(tmLScr[i]));

			if (i == 1) {
				max = team[i];
				min = team[i];
			}
			max = max < team[i] ? team[i] : max;
			min = min > team[i] ? team[i] : min;
		}

		cout << max << endl << min << endl;


	}

	return 0;
}
