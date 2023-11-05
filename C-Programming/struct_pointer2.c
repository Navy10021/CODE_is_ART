#include <stdio.h>

struct point{
    int xpos;
    int ypos;
};

struct cycle{
    double radius;
    struct point *center;  // 포인터 변수(center)를 구조체 멤버(point)로 선언.
};

int main(void){
    struct point cen = {3, 5};
    double rad = 3.3;
    
    struct cycle myRing = {rad, &cen};  // cen 구조체의 주소값 전달
    printf("Cycle's radius : %f \n", myRing.radius);
    printf("Center of Cycle : [%d, %d]\n", myRing.center->xpos, myRing.center->ypos);
    
    return 0;
}
