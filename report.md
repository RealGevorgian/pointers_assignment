Pointers Assignment Report
   This report provides an analysis of the five C programs implemented for the Pointers assignment. Each program focuses on a specific aspect of pointer usage in C, including basic pointer operations, pointer arithmetic, passing pointers to functions, double pointers, and string manipulation. Below is a detailed explanation of each program, how it works, observations about pointer behavior, and the GitHub repository link.
GitHub Repository
   The source code for all assignments is available at: https://github.com/username/pointers-assignment   Note: Replace the above link with the actual repository link after pushing the code.
Assignment 1: Basics of Pointers
Code
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;
    
    printf("Address of num: %p\n", (void*)&num);
    printf("Address stored in ptr: %p\n", (void*)ptr);
    
    *ptr = 100;
    printf("New value of num: %d\n", num);
    
    return 0;
}

Explanation

Objective: Understand basic pointer operations, including the address-of operator (&) and dereferencing (*).
How It Works:
An integer num is initialized to 42.
A pointer ptr is declared and set to the address of num using &num.
The program prints the address of num directly (&num) and via the pointer (ptr), which are identical.
The value of num is modified to 100 by dereferencing ptr (*ptr = 100).
The new value of num is printed to confirm the change.


Output (example, as addresses vary):Address of num: 0x7ffee4a0c4ac
Address stored in ptr: 0x7ffee4a0c4ac
New value of num: 100


Observations:
Pointers store memory addresses, allowing direct manipulation of a variable's value via dereferencing.
The address-of operator (&) retrieves the memory location, and the dereference operator (*) accesses or modifies the value at that location.
This demonstrates the power of pointers in accessing and altering memory directly, but care must be taken to avoid invalid memory access.



Assignment 2: Pointer Arithmetic
Code
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *ptr = arr;
    
    printf("Original array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = *(ptr + i) * 2;
    }
    
    printf("Modified array (using pointer): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    printf("Modified array (using array name): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

Explanation

Objective: Learn pointer arithmetic to traverse and modify an array.
How It Works:
An array arr is initialized with {1, 2, 3, 4, 5}.
A pointer ptr is set to the base address of arr.
The original array is printed using pointer arithmetic (*(ptr + i)).
Each element is doubled using pointer arithmetic (*(ptr + i) = *(ptr + i) * 2).
The modified array is printed twice: once using the pointer and once using the array name (arr[i]).


Output:Original array: 1 2 3 4 5
Modified array (using pointer): 2 4 6 8 10
Modified array (using array name): 2 4 6 8 10


Observations:
Pointer arithmetic (ptr + i) automatically accounts for the size of the data type (e.g., int is typically 4 bytes), so ptr + 1 moves to the next integer.
The array name arr acts like a pointer to the first element, making arr[i] equivalent to *(arr + i) or *(ptr + i).
Modifying the array via pointers directly affects the original array, as pointers reference the same memory.



Assignment 3: Pointers and Functions
Code
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10, y = 20;
    
    printf("Before swap: x = %d, y = %d\n", x, y);
    
    swap(&x, &y);
    
    printf("After swap: x = %d, y = %d\n", x, y);
    
    return 0;
}

Explanation

Objective: Learn to pass pointers to functions for modifying variables.
How It Works:
A function swap takes two integer pointers (int *a, int *b) and swaps the values they point to using a temporary variable.
In main, two integers x = 10 and y = 20 are declared.
The addresses of x and y (&x, &y) are passed to swap.
The values are printed before and after the swap to show the effect.


Output:Before swap: x = 10, y = 20
After swap: x = 20, y = 10


Observations:
Passing pointers to a function allows modification of the original variables (pass-by-reference), unlike pass-by-value, which only modifies copies.
The swap function uses dereferencing (*a, *b) to access and modify the values at the memory addresses.
This demonstrates how pointers enable functions to have side effects on variables outside their scope.



Assignment 4: Pointers to Pointers
Code
#include <stdio.h>

int main() {
    int num = 42;
    int *ptr = &num;
    int **dptr = &ptr;
    
    printf("Value of integer using pointer: %d\n", *ptr);
    printf("Value of integer using double-pointer: %d\n", **dptr);
    
    return 0;
}

Explanation

Objective: Work with double pointers to access a variable indirectly.
How It Works:
An integer num is initialized to 42.
A pointer ptr is set to the address of num (&num).
A double pointer dptr is set to the address of ptr (&ptr).
The value of num is printed using the pointer (*ptr) and the double pointer (**dptr).


Output:Value of integer using pointer: 42
Value of integer using double-pointer: 42


Observations:
A double pointer (**dptr) stores the address of a pointer, allowing indirect access to the original variable.
Dereferencing dptr once (*dptr) yields ptr, and dereferencing again (**dptr) yields num's value.
Double pointers are useful in scenarios like modifying a pointer's address in a function (e.g., dynamic memory allocation).



Assignment 5: Strings and Character Pointers
Code
#include <stdio.h>

int main() {
    char str[] = "Hello";
    char *ptr = str;
    
    printf("String: ");
    while (*ptr != '\0') {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n");
    
    ptr = str;
    
    int count = 0;
    while (*ptr != '\0') {
        count++;
        ptr++;
    }
    
    printf("Number of characters: %d\n", count);
    
    return 0;
}

Explanation

Objective: Manipulate strings using character pointers and pointer arithmetic.
How It Works:
A string str is initialized as a character array with "Hello".
A pointer ptr is set to the first character of str.
The string is printed character by character using a loop and pointer dereferencing (*ptr) until the null terminator (\0) is reached.
The pointer is reset to the start of str, and the number of characters is counted by incrementing ptr until \0.


Output:String: Hello
Number of characters: 5


Observations:
Strings in C are null-terminated arrays of characters, and a pointer to the first character can traverse the string.
Pointer arithmetic on char* increments by 1 byte (size of char), allowing precise character-by-character navigation.
The null terminator (\0) is critical for determining the string's end, preventing out-of-bounds access.



General Observations on Pointer Behavior

Memory Access: Pointers provide direct access to memory, enabling efficient manipulation of variables and data structures but requiring careful handling to avoid errors like dereferencing null or invalid pointers.
Flexibility: Pointers allow pass-by-reference in functions (Assignment 3), dynamic memory access (Assignment 4), and array/string traversal (Assignments 2 and 5).
Arithmetic: Pointer arithmetic (Assignments 2 and 5) scales with the data type size, making it type-safe but requiring understanding of memory layout.
Indirection: Double pointers (Assignment 4) add a layer of indirection, useful for modifying pointers themselves, as seen in dynamic memory allocation scenarios.
Risks: Incorrect pointer usage (e.g., accessing unallocated memory) can cause segmentation faults, emphasizing the need for proper initialization and bounds checking.

These assignments demonstrate the power and versatility of pointers in C programming. From basic dereferencing to advanced double-pointer usage, pointers enable efficient memory management and data manipulation. The programs were implemented carefully to avoid common pitfalls, and their behavior aligns with expected pointer mechanics.
