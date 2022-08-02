#include <iostream>
#include <cstring>
using namespace std;
#define ROW 2
#define COLUMN 10

int** init_second_rank_pointer(int row, int column) {
	int** b = new int*[row];
	for (int i = 0; i < row; ++i) {
		*(b + i) = new int[column];
		memset(*(b + i), 0, sizeof(int) * column);
	}
	return b;
}

void print_second_rank_pointer(int** x, int row, int column) {
	for (int i = 0;i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			cout << x[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	// x[i] <=> x + i then * <=> &x[0] to char* then move (i * sizeof(x[0])) B
	x[1][7] = 6;
	cout << "x[1][7] val:\t" << x[1][7] << endl;
	cout << "x[1][7] val:\t" << *(*(x + 1) + 7) << endl;
	cout << "x[1][7] val:\t" << (x[1] + 4)[3] << endl;
	cout << "x[1][7] val:\t" << (*(x + 1) + 4)[3] << endl;
	cout << "x[1][7] val:\t" << *(int*)((char*)&x[1][0] + 7 * sizeof(int)) << endl; // sizeof(x[1][0]) is sizeof(int)
	cout << endl;

	// x + 1, *x + 1, &x + 1
	cout << "x + 1:\t" << x + 1 << endl; // heap: => &*(x + 1) => &x[1]
	cout << "&x[1]:\t" << &x[1] << endl;
	cout << "*x + 1:  \t" << *x + 1 << endl; // heap: => (*(x + 0) + 1) => &*(*(x + 0) + 1) => &x[0][1]
	cout << "&x[0][1]:\t" << &x[0][1] << endl;
	cout << "&x + 1                  :\t" << &x + 1 << endl; // stack: => int** + 1 => char* + 8
	cout << "(int**)((char*)(&x) + 8):\t" << (int**)((char*)(&x) + 1 * sizeof(x)) << endl;
}

void uninit_second_rank_pointer(int** b, int row) {
	for (int i = 0; i < row; ++i) {
		delete[] *(b + i);
		*(b + i) = NULL;
	}
	delete[] b;
	b = NULL;
}

int main() {
	auto b = init_second_rank_pointer(ROW, COLUMN);
	print_second_rank_pointer(b, ROW, COLUMN);
	uninit_second_rank_pointer(b, ROW);
	return 0;
}