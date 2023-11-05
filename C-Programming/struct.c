#include <stdio.h>
#include <string.h>

struct employee{
    char name[10];
    char ip[15];
    int payment;
};

int main()
{
    struct employee emp;
    //printf("Name : "); scanf("%s", emp.name);
    //printf("IP : "); scanf("%s", emp.ip);
    //printf("Pay : "); scanf("%d", &emp.payment);
    strcpy(emp.name, "Lee");
    strcpy(emp.ip, "870830");
    emp.payment = 3000;
    
    printf("-----------------------\n");
    printf("Name : %s\n", emp.name);
    printf("IP : %s\n", emp.ip);
    printf("Pay : %d", emp.payment);

    return 0;
}
