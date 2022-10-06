#include <iostream>
#include <omp.h>
using namespace std;

double** mul(double** a, double** b, int rowX, int colX, int rowY, int colY) {
	int _N = rowX, _M = colY;
	double** answer = new double* [_N];
	for (int i = 0; i < _N; i++) {
		answer[i] = new double[_M];
	}

	double tmp;
	int row, col, iter;

#pragma omp parallel for private(tmp, row, col, iter)
	for (row = 0; row < _N; row++) {
		for (col = 0; col < _M;col++) {
			tmp = 0.0;
			for (iter = 0; iter < colX; iter++) {
				tmp += a[row][iter] * b[iter][col];
			}
			answer[row][col] = tmp;
		}
	}

	return answer;

}

int main() {


	int rowX, colX, rowY, colY;
	cin >> rowX >> colX;
	cin >> rowY >> colY;
	if (colX != rowY) {
		cout << "Can't multiple 2 matrix";
		return 0;
	}
	double** a, ** b;


	a = new double* [rowX];
	b = new double* [rowY];

	for (int i = 0;i < rowX;i++) {
		a[i] = new double[colX];
	}
	for (int i = 0;i < rowY;i++) {
		b[i] = new double[colY];
	}

	cout << "INPUT MATRIX A\n";
	for (int i = 0;i < rowX;i++) {
		for (int j = 0;j < colX;j++) {
			cin >> a[i][j];
		}
	}
	cout << "INPUT MATRIX B\n";
	for (int i = 0;i < rowY;i++) {
		for (int j = 0;j < colY;j++) {
			cin >> b[i][j];
		}
	}
	
	double ** c = mul(a, b, rowX, colX, rowY, colY);

	for (int i = 0;i < rowX;i++) {
		for (int j = 0;j < colY;j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

}