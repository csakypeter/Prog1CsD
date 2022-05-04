#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <complex>

#include "Matrix.h"
#include "MatrixIO.h"

using namespace Numeric_lib;

/*
1. Print the size of a char , a short , an int , a long , a float , a double , an int* ,
and a double* (use sizeof , not <limits> ).
2. Print out the size as reported by sizeof of Matrix<int> a(10) , Matrix<int>
b(100) , Matrix<double> c(10) , Matrix<int,2> d(10,10) , Matrix<int,3>
e(10,10,10) .
3. Print out the number of elements of each of the Matrix es from 2.
4. Write a program that takes int s from cin and outputs the sqrt() of each
int , or “no square root” if sqrt(x) is illegal for some x (i.e., check your
sqrt() return values).
5. Read ten floating-point values from input and put them into a Matrix-
<double> . Matrix has no push_back() so be careful to handle an attempt
to enter a wrong number of double s. Print out the Matrix .
6. Compute a multiplication table for [0,n)*[0,m) and represent it as a 2D
Matrix . Take n and m from cin and print out the table nicely (assume that
m is small enough that the results fit on a line).
7. Read ten complex<double> s from cin (yes, cin supports >> for complex )
and put them into a Matrix . Calculate and output the sum of the ten com-
plex numbers.
8. Read six int s into a Matrix<int,2> m(2,3) and print them out.
*/

void readSqrt()
{
	int a;

	std::cin >> a;
	
	if(a < 0)
	{
		std::cout << "no square root" << '\n';
	}
	
	else
	{
		std::cout << "square root: " << std::sqrt(a) << '\n';
	}
}

int main()
{
	char a;
	short b;
	int c;
	long d;
	float e;
	double f;
	int* g;
	double* h;
	
	std::cout << sizeof(a) << '\n';
	std::cout << sizeof(b) << '\n';
	std::cout << sizeof(d) << '\n';
	std::cout << sizeof(d) << '\n';
	std::cout << sizeof(e) << '\n';
	std::cout << sizeof(f) << '\n';
	std::cout << sizeof(g) << '\n';
	std::cout << sizeof(h) << "\n\n";
	
	Matrix<int, 1> ma(10);
	Matrix<int, 1> mb(100);
	Matrix<double, 1> mc(10);
	Matrix<int,2> md(10,10);
	Matrix<int,3> me(10,10,10);
	
	std::cout << sizeof(ma) << '\n';
	std::cout << sizeof(mb) << '\n';
	std::cout << sizeof(mc) << '\n';
	std::cout << sizeof(md) << '\n';
	std::cout << sizeof(me) << "\n\n";
	
	std::cout << ma.size() << '\n';
	std::cout << mb.size() << '\n';
	std::cout << mc.size() << '\n';
	std::cout << md.size() << '\n';
	std::cout << me.size() << "\n\n";
	
	std::cout << "Enter a number: " << '\n';
	readSqrt();
	
	std::cout << '\n' << "Enter 10 doubles" << '\n';
	Matrix<double> ten(10);
		for (int i = 0; i < 10; i++)
	std::cin >> ten[i];
	std::cout << "Matrix: " << ten << "\n\n";
	
	
	std::cout << "Enter 2 dimensions for a multiplication table:" << '\n';
	int n;
	int m;
	std::cin >> n >> m;
	Matrix<int, 2> table(n+1, m+1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			table[i][j] = i * j;
			std::cout << table(i, j) << " ";
		}
		
		std::cout << std::endl;
	}


	std::cout << '\n' << "Enter 10 complex numbers:" << '\n';	
	Matrix<std::complex<double>> complexM(10);
	std::complex<double> comp;
	std::complex<double> sum;

	for (int i = 0; i < complexM.size(); i++)
	{
		std::cin >> comp;
		complexM[i] = comp;
		sum = sum + comp;
	}

	std::cout << "Sum of complex numbers: " << sum << "\n\n";

	std::cout << "Enter 6 integers:" << '\n';
	Matrix<int, 2> m2(2, 3);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)
			std::cin >> m2[i][j];
	std::cout << "Matrix: \n" << m2 << '\n';

	return 0;
}












