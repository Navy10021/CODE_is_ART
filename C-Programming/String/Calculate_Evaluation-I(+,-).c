#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// String +, -, = 계산결과 리턴

double evaluate(const char *expression){
    double res = 0;
    double currNum = 0;
    char lastOp = '+';  // Start with '+' to handle the first number : 0 + first number

    for (int i = 0; expression[i] != '\0'; i++){
        char c = expression[i];

        if (isdigit(c)){
            // Build the current number digit by digit 
            currNum = currNum * 10 + (c - '0');
        }
        else if (c == '+' || c == '-'){
            // Process the current number with the last operaor
            if (lastOp == '+'){
                res += currNum;
            }
            else if (lastOp == '-'){
                res -= currNum;
            }

            // reset for next number
            currNum = 0;
            lastOp = c;
        }

        // Add additional condition '*', '/'
    }

    // Process the last number in expression
    if (lastOp == '+'){
        res += currNum;
    }
    else if (lastOp == '-'){
        res -= currNum;
    }
    // add addition condition '*', '/'

    return res;
}

int main(void){
    char expression[50];
    scanf("%s", expression);
    double result = evaluate(expression);
    printf("%s = %.2f\n", expression, result);
    return 0;
}
