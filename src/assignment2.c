#include <stdio.h>

int main(){
	int arr[5] = {1,2,3,4,5};
	int *ptr = arr;

	printf("Our original array:\n");
	for(int i = 0; i < 5; i++){
		printf("%d ", *(ptr + i));
	}
	printf("\n");

	for(int i = 0; i < 5; i++){
		*(ptr + i) += 10;
	}

	printf("Our modified array (using pointer):\n");
	for(int i = 0; i < 5; i++){
		printf("%d ", *(ptr + i));
	}
	printf("\n");

        printf("Modified array (using array name):\n");
	for(int i = 0; i < 5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
