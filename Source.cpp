#include<iostream>
#include<stdlib.h>
using std::cout;
using std::cin;
float a[4], b[4], c[4], d[4], e[4], f[4], g[4] = { 0 }; int z;
int main()
{
	system("cls");
	float w[8] = { 0 }; int n, i;
	int x = 0, u, r, m = 0, y = 0;
	int t;
	cout << "\n" << "Enter the highest degree entered  = "; cin >> i;
	cout << "Enter the coefficient of the characteristic equation upto degree 7\n";
	for (n = 0; n < i+1; n++)/*input the coefficient values*/
	{
		cin >> w[n];
	}
	cout << "The characteristic equation is: " << w[7] << "s^7+ " << w[6] << "s^6+ " << w[5] << "s^5+ " << w[4] << "s^4+ " << w[3] << "s^3+ " << w[2] << "s^2+ " << w[1] << "s^1+ "
		<< w[0] << "s^0 =0";
	t = i; z = i;
	if (i == 7) { r = 4; u = 4; }
	if (i == 6) { r = 4; u = 3; }
	if (i == 5) { r = 3; u = 3; }
	if (i == 4) { r = 3; u = 2; }
	if (i == 3) { r = 2; u = 2; }/*variables declaration*/
	for (n = 0; n < r; n++)/*for loop for first row calculation*/
	{
		a[n] = w[i - (2 * n)];
	}
	for (n = 0; n < u; n++)/*for loop for second row calculation*/
	{
		b[n] = w[i - 1 - (2 * n)];
	}
	if (b[0] != 0)
	{
		for (n = 0; n < 3; n++)/*for loop for third row calculation*/
		{
			if (b[n] != 0)
			{
				c[n] = ((b[0] * a[n + 1]) - (a[0] * b[n + 1])) / b[0];
			}
		}
	}
	if (c[0] == 0) {/*if the values of thrid row is zero,calculate using derivative of previous row*/
		m++; y = 1;
		if (i == 6)
		{
			for (n = 0; n < 3; n++)
			{
				i--; c[n] = i * b[n]; i--;
			}
		}
		if (i == 5)
		{
			for (n = 0; n < 2; n++)
			{
				i--; c[n] = i * b[n]; i--;
			}
		}
		if (i == 7)
		{
			for (n = 0; n < 3; n++)
			{
				i--; c[n] = i * b[n]; i--;
			}
		}
		if (i == 4)
		{
			for (n = 0; n < 3; n++)
			{
				i--; c[n] = i * b[n]; i--;
			}
		}
	}
	if (z >= 3) {
		if (c[0] != 0)/*for loop for fourth row calculation*/
		{
			for (n = 0; n < 3; n++)
			{
				d[n] = ((c[0] * b[n + 1]) - (b[0] * c[n + 1])) / c[0];
			}
		}
		if (d[0] == 0)/*if the values of fourth row is zero , calculate using derivative of previous row*/
		{
			m++; y = 2;
			if (i == 4)
			{
				for (n = 0; n < 2; n++)
				{
					i = i - 2; d[n] = i * c[n];
				}
			}
			if (i == 5)
			{
				for (n = 0; n < 2; n++)
				{
					i = i - 2; d[n] = i * c[n];
				}
			}
			if (i == 6)
			{
				for (n = 0; n < 3; n++)
				{
					i = i - 2; d[n] = i * c[n];
				}
			}
			if (i == 7)
			{
				for (n = 0; n < 3; n++)
				{
					i = i - 2; d[n] = i * c[n];
				}
			}
		}
	}
	if (z >= 4) {
		if (d[0] != 0)/*for loop for fifth row calculation*/
		{
			for (n = 0; n < 3; n++) {

				e[n] = ((d[0] * c[n + 1]) - (c[0] * d[n + 1])) / d[0];
			}
		}
		if (e[0] == 0)/*if the values of fifth row is zero , calculate using derivative of previous row*/
		{
			m++; y = 3;
			if (i == 4)
			{
				for (n = 0; n < 2; n++)
				{
					i = i - 3; e[n] = i * d[n];
				}
			}
			if (i == 5)
			{
				for (n = 0; n < 2; n++)
				{
					i = i - 3; e[n] = i * d[n];
				}
			}
			if (i == 6)
			{
				for (n = 0; n < 3; n++)
				{
					i = i - 3; e[n] = i * d[n];
				}
			}
			if (i == 7)
			{
				for (n = 0; n < 3; n++)
				{
					i = i - 3; e[n] = i * d[n];
				}
			}
		}
	}
	if (z >= 5) {
		if (e[0] != 0)/*for loop for sixth row calculation*/
		{
			for (n = 0; n < 2; n++)
			{
				f[n] = ((e[0] * d[n + 1]) - (d[0] * e[n + 1])) / e[0];
			}
		}
	}
	if (z >= 6) {
		if (f[0] != 0)/*for loop for seventh row calculation*/
		{
			for (n = 0; n < 2; n++)
			{
				g[n] = ((f[0] * e[n + 1]) - (e[0] * f[n + 1])) / f[0];
			}
		}
	}
	cout << "\n\n*********THE ROUTHS ARRAY IS************\n";
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < r; n++)/*print the routh array values using for loop*/
	{
		cout << a[n];
		cout << "\t";
	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << b[n];
		cout << "\t";
	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << c[n]; cout << "\t";

	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << d[n]; cout << "\t";
	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << e[n]; cout << "\t";
	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << f[n]; cout << "\t";
	}
	cout << "\ns^" << z-- << " :  ";
	for (n = 0; n < u; n++)
	{
		cout << g[n]; cout << "\t";
	}
	if (a[0] < 0) { x++; }/*variables used for calculation*/
	if (b[0] < 0) { x++; }
	if (c[0] < 0) { x++; }
	if (d[0] < 0) { x++; }
	if (e[0] < 0) { x++; }
	if (f[0] < 0) { x++; }
	if (g[0] < 0) { x++; }

	if (x >= 1)/*Print whether the system is stable, unstable or marginally stable*/
	{
		cout << "\n\nThe system is unstable\n";
	}
	else
	{
		if (m >= 1) {
			if (y == 1)
			{
				cout << "\n\nHere derivative fuction is used to convert zero into values in s^" << t - 2;
			}
			if (y == 2)
			{
				cout << "\n\nHere derivative fuction is used to convert zero into values in s^" << t - 3;
			}
			if (y == 3)
			{
				cout << "\n\nHere derivative fuction is used to convert zero into values in s^" << t - 4;
			}
			cout << "\n\nThe system is marginally stable\n\n";
		}
		else
			cout << "\n\nThe system is stable\n\n";
	}
}