#include<iostream>
#include<stdlib.h>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
#define ff(q,l,v) for(int q=l;q<v;q++) 

// i,t,z= degree
// w[] = coefficient matrix
// r = size of a[] row
// u = size of b[] row
// m = marginal stability check
// y = derivative row finder
// n = temporary for variable
// x = to check unstability

class rh_stability_crieteria {
private:
	float a[4] = { 0.0000 }, b[4] = { 0.0000 }, c[4] = { 0.0000 }, d[4] = { 0.0000 }, e[4] = { 0.0000 }, f[4] = { 0.0000 }, g[4] = { 0.0000 };
	int z, t, n, i;
	float w[8] = { 0.0000 };
	int  u, r, m = 0, y = 0;
	bool x = false;
public:
	// taking input of degree, coeffcients of characterstics equation and initializing size of rh array 
	void take_input() {
	    first:  cout << "Enter the highest degree of characteristic equation(less than or equal to 7):";
		cin >> i;
		if (i > 7 or i < 3) {
		cout << "CAUTION ::  please enter degree within in range 3 to 7 !!!" << endl;
			goto first;
		}
		cout << "Enter the coefficient of the characteristic equation upto degree " << i << endl;
		ff(n,0,i+1) {
				cout << "s^" << n << ": ";
				cin >> w[n];
		}
		t = i; z = i;
		if (i == 7) { r = 4; u = 4; }
		if (i == 6) { r = 4; u = 3; }
		if (i == 5) { r = 3; u = 3; }
		if (i == 4) { r = 3; u = 2; }
		if (i == 3) { r = 2; u = 2; }
	}
	// first and second row of rh matrix (row ,rowsize, odd or even)
	void first_second_row_filling(float h[],int hh,int hhh) {
		ff(n, 0, hh) {
			h[n] = w[i - hhh - (2 * n)];
		}
	}
	//row calculation (previous previous row ,previous row, current row ,row size)
	void row_calculation(float h[], float hh[], float hhh[], int hhhh) {
		if (hh[0] != 0) {
			ff(n, 0, hhhh) {
				hhh[n] = ((hh[0] * h[n + 1]) - (h[0] * hh[n + 1])) / hh[0]; 
			}
		}
	}
	//derivation from previous row (row, previous row, starting decrementor,ending decrementor
	void derivation_from_previous_row(float h[], float hh[], int hhh, int hhhh) {
		int temp = 3;
		if (i == 4 or i == 5) {
			temp = 2;
		}
		ff(n, 0, temp) {
			i = i - hhh;
			h[n] = i * hh[n];
			i = i - hhhh;
		}

	}
	// checking for zero value at starting of row (row, previous row, derivative row finder ,starting decrementor,ending decrementor)
	void zero_check_row_start_element(float h[], float hh[], int hhh, int hhhh, int hhhhh) {
		if (h[0] == 0) {
			m++;
			y = hhh;
			derivation_from_previous_row(h, hh, hhhh, hhhhh);
		}
	}
	// row display (row, row size)
	void row_display(float h[], int hh) {
		cout <<"s^"<<z-- << " : ";
		ff(n, 0, hh) {
			printf("%.4f", h[n]); 
			cout <<"     "<< "\t";
		}
		cout << endl;
	}
	// marginal stability display  (derivative row finder)
	void marginal_stability_display(int h) {
	cout << "Here derivative fuction is used to convert zero into values in s^" <<( t - h + 1) ;
	}
	// check for stability and display
	void stability_display() {
		if (a[0] < 0 or b[0] < 0 or c[0] < 0 or d[0] < 0 or e[0] < 0 or f[0] < 0 or g[0] < 0) { x = true; }
		if (x >= 1) {
			cout << "The system is unstable\n";
		}
		else if (m >= 1) {
			marginal_stability_display(y);
			cout << "\nThe system is marginally stable\n";
		}
		else
			cout << "The system is stable" << endl;
	}
	//final main display function
	void routh_array_display() {
		cout << "THE ROUTH'S ARRAY IS" << endl;
		cout << "-------------------------------------------------------------" << endl;
		row_display(a, r);
		row_display(b, u);
		row_display(c, u);
		row_display(d, u);
		row_display(e, u);
		row_display(f, u);
		row_display(g ,u);
		cout << "-------------------------------------------------------------" << endl;
		stability_display();
	}
	void rh_calculator() {
		take_input();
		first_second_row_filling(a, r, 0);
		first_second_row_filling(b, u, 1);
		row_calculation(a, b, c, 3);
		zero_check_row_start_element(c, b, 1, 1, 1);
		if (z >= 3) {
			row_calculation(b, c, d, 3);
			zero_check_row_start_element(d, c, 2, 2, 0);
		}
		if (z >= 4) {
			row_calculation(c, d, e, 3);
			zero_check_row_start_element(e, d, 3, 3, 0);
		}
		if (z >= 5) {
			row_calculation(d, e, f, 2);
		}
		if (z >= 6) {
			row_calculation(e, f, g,  2);
		}
		routh_array_display();
	}
};

int main() {
	rh_stability_crieteria r1;
	r1.rh_calculator();
	return 0;
}
