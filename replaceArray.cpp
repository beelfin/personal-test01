#include <stdio.h>

template<size_t rows, size_t cols, size_t rows2, size_t cols2>
void replace(int (&ori)[rows][cols], int (&part)[rows2][cols2], int strow, int stcol) {
	printf("%s\n", __FUNCTION__);
	for (int i = strow; i < strow+rows2; ++i) {
		for (int j = stcol; j < stcol+rows2; ++j) {
			ori[i][j] = part[i-strow][j-stcol];
		}
	}
}

template<size_t rows, size_t cols, size_t rows2, size_t cols2>
void replace_2(int (&ori)[rows][cols], int (&part)[rows2][cols2], int strow, int stcol) {
	printf("%s\n", __FUNCTION__);
	int str = strow - rows2+1;
	int stc = stcol - cols2+1;
	int edr = strow + rows2*2-1;
	int edc = stcol + cols2*2-1;

	// boundary check
	if (str < 0) str = 0;
	if (stc < 0) stc = 0;
	if (edr >= rows) edr = rows-1;
	if (edc >= cols) edc = cols-1;

	for (int i = str; i < edr; ++i) {
		for (int j = stc; j < edc; ++j) {
			if (i >= strow && i < strow + rows2
				 && j >= stcol && j < stcol + cols2) {
				ori[i][j] = 11;//part[i-str][j-stc];
			} else {
				ori[i][j] = -1;
			}
		}
	}
}

#define N 25
int main(void) {
	printf("Hello world\n");
	int arr[N][N];
	int alt[5][5];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			arr[i][j] = i*j;
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	int temp = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			alt[i][j] = temp;
		}
		temp++;
	}

	replace_2(arr, alt, 10, 10);

	printf("after func1\n");
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}

