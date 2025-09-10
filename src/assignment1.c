#include <stdio.h>

int main() {
    int num = 10;       
    int *ptr = &num;       

    printf("Address of num: %p\n", (void*)&num);
    printf("Address stored in ptr: %p\n", (void*)ptr);

    *ptr = 20;
    printf("New value of num: %d\n", num);

    return 0;
};
