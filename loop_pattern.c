// Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.

// 4 4 4 4 4 4 4  
// 4 3 3 3 3 3 4   
// 4 3 2 2 2 3 4   
// 4 3 2 1 2 3 4   
// 4 3 2 2 2 3 4   
// 4 3 3 3 3 3 4   
// 4 4 4 4 4 4 4

// n = 3
// 3 3 3 3 3
// 3 2 2 2 3
// 3 2 1 2 3
// 3 2 2 2 3
// 3 3 3 3 3

// min( i % 3, j % 3) 

#include<stdio.h>

void check(int i, int j, int first, int last, int n) {
    if(n >= 1) {
        if (i == first || i == last || j == first || j == last) {
            printf("%d ", n);
        } else {
            check(i, j, first + 1, last - 1, n - 1);
        }
    }
}

void main() {
    int n;
    scanf("%d", &n);
    int rows = 2 * n - 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            check(i, j, 0, rows - 1, n);
        }
        printf("\n");
    }
}