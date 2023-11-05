#include <stdio.h>

typedef int INT;
typedef int * PTR_INT;
typedef unsigned char UCHAR;
typedef unsigned char * PTR_UCHAR;

int main(void){
    INT num = 65;
    PTR_INT pnum = &num;
    
    UCHAR ch = 'A';
    PTR_UCHAR pch= &ch;
    
    printf("%d | %c", *pnum, *pch);
    
    return 0;
}
