#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	while (numCases--) {

		char data[50];
		int numL = 0;		// ���� ��ȣ�̸� ++ ������ ��ȣ�̸� --
		bool isYes = true; // ��� üũ�� ����

		file >> data;

		for (int i = 0; data[i]; i++) {
			if (data[i] == '(') //���ʰ�ȣ�̸� numL++
				numL++;
			else {				//������ ��ȣ�̸� numL--
				numL--;			
				if (numL < 0) {	//���� ��ȣ�� �� ������ FALSE
					isYes = false;
					break;
				}
			}
		}
		if (isYes && numL == 0)	//numL ���ʰ�ȣ�� �����ʰ�ȣ�� ������ ��ġ�ϸ鼭 ��Ī�ϰ��
			cout << "YES" << endl;
		else					//���ʰ�ȣ�� �����ų� ������ ��ȣ�� ���������
			cout << "NO" << endl;

		numL = 0;
		isYes = true;
	}


	return 0;
}