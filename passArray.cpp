#include <stdio.h>

template<size_t rows, size_t cols>
void func1(int (&arr)[rows][cols]) {
	printf("%s\n", __FUNCTION__);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			printf("%d\t", arr[i][j]);
			arr[i][j]++;
		}
		printf("\n");
	}
}

int main(void) {
	printf("Hello world\n");
	int arr[5][10];

	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 10; ++j) {
			arr[i][j] = i*j;
		}
	}

	func1(arr);

	printf("after func1\n");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 10; ++j) {
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
