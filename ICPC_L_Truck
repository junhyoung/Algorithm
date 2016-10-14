/*********************************************************
국민대학교 컴퓨터공학과 20123425 최준형
문제: ICPC L번 TRUCK
*********************************************************/

#include<iostream>
#include<fstream>
#include<queue>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numcases;

	file >> numcases;
	while (numcases--) {
		int numTruck, length, weight;
		file >> numTruck >> length >> weight;
		int *truck = new int[numTruck];
		queue<int> Q;
		for (int i = 0; i < numTruck; i++)
			file >> truck[i];
		int time = 0;
		int leftWeight = weight;
		int onBridge = 0;
		for (int i = 0; i < numTruck; i++) { 
			while (1) { //각 트럭이 지나가는데 소요되는 시간
				time++;
				if (onBridge == length) {  //다리가 가득찼을때
					onBridge--;
					int temp = Q.front();
					Q.pop();
					leftWeight += temp;
				}
				if (leftWeight >= truck[i]) { // 남은 하중이 트럭의 무게보다 클떄
					onBridge++;
					leftWeight -= truck[i];
					Q.push(truck[i]);
					break;
				}
				else {						//남은 하중이 트럭보다 작을때
					onBridge++;
					Q.push(0);
				}

			}
		}
		time += length; //마지막 트럭
		cout << time << endl;
		delete[]truck;
	}

}
