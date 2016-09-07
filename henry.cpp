#include<iostream>
#include<fstream>
using namespace std;

int gcd(int a, int b);

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	
	while (numCases--) {
		unsigned int mother;		//�и�
		unsigned int son;			//����
		file >> son >> mother;

		double data;			// (���� / �и�)
		double compare;		//data���� ���� �м�
		double compareM = 2;		//data���� ���� �м��� �и�
		int num = 0;
		double temp = compareM;
		while (son > 1) {
		
			while (compareM*son < mother)  // a/b<1/x   =>   x*a<b
				compareM++;
			son = (compareM*son - mother);
			mother = compareM*mother;
			int Gcd = gcd(son, mother);
			son /= Gcd;
			mother /= Gcd;
		}
		cout << mother << endl;
	}


	return 0;
}
int gcd(int a, int b) {
	if (b == 0)
		return a;
	gcd(b, a%b);
}