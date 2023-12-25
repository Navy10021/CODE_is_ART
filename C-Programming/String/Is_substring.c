#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSubstring(const char * str, const char * substr){
    return strstr(str, substr) != NULL;     // if is NOT substring return NULL 
}

// strstr() 없이 구현
int isSubstring2(const char* str, const char* substr){
    while(*str){
        const char * a = str;
        const char * b = substr;

        while (*a && *b && (*a == *b)){
            a++;
            b++;
        }

        if (!*b){
            return 1;
        }
        str++;
    }
    return 0;
}


int main(){
    const char * substr = "BC";
    const char * fullstr = "ABCDE";

    if (isSubstring(fullstr, substr)){
        printf("%s is substring.", substr);
    }
		return 0;
}
