/*

Given a 6x6 2D Array arr:

1 1 1 0 0 0
0 1 0 0 0 0
1 1 1 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0

An hourglass in A is a subset of values with indices falling in this pattern in arr's graphical representation:

a b c
  d
e f g

There are 16 hourglasses in arr. An hourglass sum is the sum of an hourglass' values.
Calculate the hourglass sum for every hourglass in arr, then print the maximum hourglass sum. 
The array will always be 6x6.

*/

#include<stdio.h>

int hourglass(int arr[6][6]) {
    int max = arr[0][0] + arr[0][1] + arr[0][2] + arr[1][1] + arr[2][0] + arr[2][1] + arr[2][2], sum = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            sum = arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];

            if (max < sum) {
                max = sum;
            }
        }
    }

    return max;
}

void main() {
    int i, j, a[6][6];

    for (int i = 0; i < 6; i++) 
        for (int j = 0; j < 6; j++)
            scanf("%d", &a[i][j]);
    
    int res = hourglass(a);
    printf("%d", res);
}
