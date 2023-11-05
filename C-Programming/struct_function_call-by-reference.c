#include <stdio.h>
// struct call-by-reference
typedef struct point{
    int xpos;
    int ypos;
} Point;

void OrgSymTrans(Point *ptr){       // Call-By-Refence(원점대칭)
    ptr->xpos = (ptr->xpos) * -1;
    ptr->ypos = (ptr->ypos) * -1;
    printf("Translation.\n");
}

void showPosition(Point pos){
    printf("[%d, %d]\n", pos.xpos, pos.ypos);
}

int main(void){
    Point pos = {3, 5};
    OrgSymTrans(&pos);
    showPosition(pos);
    OrgSymTrans(&pos);
    showPosition(pos);
    return 0;
}
