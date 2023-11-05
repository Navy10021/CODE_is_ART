#include <stdio.h>

typedef struct point{
    int xpos;
    int ypos;
} Point;

void showPosition(Point pos){
    printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

Point GetPosition(void){
    Point cen;
    printf("Input current position : ");
    scanf("%d %d", &cen.xpos, &cen.ypos);
    return cen;
}

int main(void){
    Point curPos = GetPosition();
    showPosition(curPos);
    return 0;
}
