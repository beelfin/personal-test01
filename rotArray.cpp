#include <stdio.h>

template<size_t rows, size_t cols>
void rotate90(int (&src)[rows][cols], int (&dst)[rows][cols]) {
	int loopcnt = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			dst[i][j] = src[cols-1-j][i];
			loopcnt++;
		}
	}
	printf("%s, loopcnt = %d\n", __FUNCTION__, loopcnt);
}

/* 270도까지 회전해도 가장 유리 */
template<size_t rows, size_t cols>
void rotate90_2(int (&src)[rows][cols]) {
	static int loopcnt = 0;
	for (int i = 0; i < rows/2; ++i) {
		for (int j = i; j < cols-1-i; ++j) {
			int k = src[i][j];
			src[i][j] = src[cols-1-j][i];
			src[cols-1-j][i] = src[cols-1-i][rows-1-j];
			src[cols-1-i][rows-1-j] = src[j][rows-1-i];
			src[j][rows-1-i] = k;
			loopcnt++;
		}
	}
	printf("%s, loopcnt = %d\n", __FUNCTION__, loopcnt);
}

template<size_t rows, size_t cols>
void rotate2(int deg, int (&src)[rows][cols], int (&dst)[rows][cols]) {
	int loopcnt = 0;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			switch(deg) {
			case 90:
				dst[i][j] = src[cols-1-j][i];
				break;
			case 180:
				dst[i][j] = src[cols-1-j][rows-1-i];
				break;
			case 270:
				dst[i][j] = src[rows-1-i][j];
				break;
			}
			loopcnt++;
		}
	}
	printf("%s, loopcnt = %d\n", __FUNCTION__, loopcnt);
}

int main(void) {
	printf("Hello world\n");
	int deg[3] = {90, 180, 270};
	int arr[5][5];
	int arr2[5][5];
	int rot[5][5];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			arr[i][j] = i*j;
			arr2[i][j] = i*j;
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	rotate90(arr, rot);

	for (int d = 0; d < 3; d++) {
		rotate2(deg[d], arr, rot);

		printf("after %d rotate\n", deg[d]);
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				printf("%d\t", rot[i][j]);
			}
			printf("\n");
		}

		rotate90_2(arr2);

		printf("after rotate\n");
		for (int i = 0; i < 5; ++i) {
			for (int j = 0; j < 5; ++j) {
				printf("%d\t", arr2[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}

