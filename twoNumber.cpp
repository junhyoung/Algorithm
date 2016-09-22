/*********************************************************
���δ��б� ��ǻ�Ͱ��а� 20123425 ������
����: Two Number ������ ������ �־��� ���� �ٻ��� �ΰ��� ���� �������ϱ�
*********************************************************/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
int abs(int n);

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;

	while (numCases--) {
		int *set;
		int size;
		int goal;
		file >> size >> goal;
		set = new int[size];
		int count = 0;
		int nearIndex;
		for (int i = 0; i < size; i++) {
			file >> set[i];
		}
		sort(set, set + size);

		nearIndex = size - 1;
		int near = abs(set[0] + set[nearIndex] - goal);

		for (int i = 0; i < nearIndex; ) {
			if (set[i] + set[nearIndex] - goal == 0) {
				if (near != 0)
					count = 1;
				else
					count++;
				i++;
				nearIndex--;
				near = 0;
			}
			else if (set[i] + set[nearIndex] - goal>0) {
				if (abs(set[i] + set[nearIndex] - goal) == near)
					count++;
				else if (abs(set[i] + set[nearIndex] - goal)<near) {
					count = 1;
					near = abs(set[i] + set[nearIndex] - goal);
				}
				nearIndex--;
			}
			else {
				if (abs(set[i] + set[nearIndex] - goal) < near) {
					count = 1;
					near = abs(set[i] + set[nearIndex] - goal);
				}
				else if (abs(set[i] + set[nearIndex] - goal) == near)
					count++;
				i++;

			}

		}
		cout << count << endl;
	}

	return 0;
}

int abs(int n) {
	if (n >= 0)
		return n;
	else
		return -n;
}