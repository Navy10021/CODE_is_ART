#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// print with calculate results
double evaluate(char *expression){
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
    printf("%s = %.2f\n", expression, res);
    return res;
}

void generateCombinations(char* str, int l, int r, char* path, int path_idx){
    if (l == r){
        path[path_idx] = '\0';
        if(path[path_idx - 1] != '+' && path[path_idx - 1] != '-'){
            double eval = evaluate(path);
           //printf("%s\n", path);
        }
        return;
    }

    // Insert '+' between current digit and next digit
    path[path_idx] = str[l];
    path[path_idx + 1] = '+';
    generateCombinations(str, l + 1, r, path, path_idx + 2);
    path[path_idx + 1] = '-';
    generateCombinations(str, l + 1, r, path, path_idx + 2); 
    // Exclude current digit
    generateCombinations(str, l + 1, r, path, path_idx + 1);
}

void generateAllCombinations(char *str){
    int length = strlen(str);
    // Allocate memory for path which will store the combinations
    char * path = (char*)malloc((2 * length) * sizeof(char));

    generateCombinations(str, 0, length, path, 0);
    free(path);
}

int main(void){
    char input[100] = "123";
    //scanf("%s", input);

    generateAllCombinations(input);
    return 0;
}
