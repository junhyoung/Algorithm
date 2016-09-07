#include<iostream>
#include<fstream>
using namespace std;

int gcd(int a, int b);

int main() {
	ifstream file("input.txt");
	int numCases;
	file >> numCases;
	
	while (numCases--) {
		unsigned int mother;		//분모
		unsigned int son;			//분자
		file >> son >> mother;

		double data;			// (분자 / 분모)
		double compare;		//data보다 작은 분수
		double compareM = 2;		//data보다 작은 분수의 분모
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