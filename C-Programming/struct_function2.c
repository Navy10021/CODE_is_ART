#include <stdio.h>
// struct call-by-reference
typedef struct point{
    int xpos;
    int ypos;
} Point;

void SwapPoint(Point *ptr1, Point *ptr2){       // Call-By-Refence
    // 대입연산이 가능함으로..
    Point temp;
    temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
    printf("Swaped.\n");
}

void showPosition(Point pos1, Point pos2){
    printf("Point 1 : [%d, %d]\n", pos1.xpos, pos1.ypos);
    printf("Point 2 : [%d, %d]\n", pos2.xpos, pos2.ypos);
}

int main(void){
    Point pos1 = {2, 4};
    Point pos2 = {5, 7};
    showPosition(pos1, pos2);
    SwapPoint(&pos1, &pos2);
    showPosition(pos1, pos2);
    return 0;
}
