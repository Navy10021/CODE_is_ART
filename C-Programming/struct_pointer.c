#include <stdio.h>
#include <string.h>

struct point{
    int xpos;
    int ypos;
};

int main(void){
    struct point pos1 = {1,2};
    struct point pos2 = {100, 200};
    struct point *pptr = &pos1; // 포인터 변수 초기화(Pos1 구조체 주소값)
    
    pptr->xpos += 4;
    pptr->ypos += 8;
    
    printf("[%d %d]\n", pptr->xpos, pptr->ypos);
    printf("[%d %d]\n", (*pptr).xpos, (*pptr).ypos);
    
    pptr = &pos2;   // 포인터 변수에 새로운 구조체 주소값 저장
    pptr->xpos +=40;
    pptr->ypos +=80;
    printf("[%d %d] \n", pptr->xpos, pptr->ypos);
}
