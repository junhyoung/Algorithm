/*********************************************************
���δ��б� ��ǻ�Ͱ��а� 20123425 ������
����: ����ī (Ʈ���̾ޱ� �ѹ��� ������ �̷���� ���� ���ϱ�)
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

int triNum(int num) { //Ʈ���̾ޱ� ���ڸ� ã�� �Լ�
	return num*(num + 1) / 2;
}
int findMaxN(int num) { // ���ں��� ���� ����ū Ʈ���̾ޱ� ������ �ε����� ã�� �Լ�
	int i;
	for (i = 1; triNum(i) <= num; i++) {}
	return i - 1;
}