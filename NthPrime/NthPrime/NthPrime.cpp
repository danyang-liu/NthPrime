#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int getnthprime(int n)
{
	int upper = 1.2 * n*log(n);
	vector<int>primes;
	for (int i = 0; i <= upper; ++i)
	{
		primes.push_back(1);   //向量元素值若为1，则元素序数为质数；向量元素若为0，则元素序数不是质数。初始时假设所有数皆为质数。
	}
	primes[0] = 0;
	primes[1] = 0;      ////0,1都不是质数
	for (int i = 2; i <= sqrt(upper); ++i)
	{
		if (primes[i] == 1)
		{
			for (int multiple = 2; i*multiple <= upper; ++multiple)
				primes[i*multiple] = 0;
		}
	}
	int index = 0;
	int k = 0;
	while (index<n)
	{
		if (primes[k] == 1)
		{
			index++;
			k++;
		}
		else
		{
			k++;
		}
	}
	k--;
	return k;
}

int main(int argc, const char * argv[]) {
	ofstream fout;
	fout.open("result.txt", ios::out);

	int n1 = 10000;
	int n2 = 100000;
	int n3 = 1000000;

	fout << getnthprime(n1) << endl;
	fout << getnthprime(n2) << endl;
	fout << getnthprime(n3) << endl;

	fout.close();
	return 0;
}
