// * You are transporting some boxes through a tunnel, where each box is a parallelepiped, 
// * and is characterized by its length, width and height.
// * The height of the tunnel is 41 feet and the width can be assumed to be infinite. 
// * A box can be carried through the tunnel only if its height is strictly less than the tunnel's
// * height. Find the volume of each box that can be successfully transported to the other end 
// * of the tunnel. 
// ! Note:  Boxes cannot be rotated.

#include<stdio.h>
#include<stdlib.h>
#define MAX_HEIGHT 41

struct box {
    int length, height, width;
};

typedef struct box box;

int is_lower_than_max_height(box x) {
    if(x.height < MAX_HEIGHT) return 1;
    else return 0;
}

int get_volume(box x) {
    return (x.height * x.length * x.width);
}

void main() {
    int n;
    scanf("%d", &n);

    box boxes[100];

    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
    }

    for (int i = 0; i < n; i++) {
        if(is_lower_than_max_height(boxes[i])) printf("%d", get_volume(boxes[i]));
        printf("\n");
    }
}