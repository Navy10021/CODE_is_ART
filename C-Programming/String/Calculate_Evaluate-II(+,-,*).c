#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // For isdigit

double evaluate(const char *expression) {
    double result = 0; // Accumulate addition and subtraction here
    double currentNumber = 0; // Current number being processed
    double tempResult = 1; // Accumulate multiplication and division here
    char lastOp = '+'; // Assume '+' to start correctly with the first number

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isdigit(c)) {
            // Build the current number digit by digit
            currentNumber = currentNumber * 10 + (c - '0');
        } else {
            // Apply the last high-precedence operation (* or /)
            if (lastOp == '*') {
                tempResult *= currentNumber;
            } else if (lastOp == '/') {
                tempResult /= currentNumber;
            } else {
                // For + or -, apply tempResult to result and reset tempResult
                if (lastOp == '+') result += tempResult;
                else if (lastOp == '-') result -= tempResult;
                tempResult = currentNumber; // Reset tempResult for next number
            }

            // Reset currentNumber for the next number
            currentNumber = 0;
            lastOp = c; // Update last operation
        }
    }

    // Apply the last number and operation
    if (lastOp == '*') {
        tempResult *= currentNumber;
    } else if (lastOp == '/') {
        tempResult /= currentNumber;
    } else {
        // Apply the last tempResult to result
        if (lastOp == '+') result += tempResult;
        else if (lastOp == '-') result -= tempResult;
        tempResult = currentNumber; // Not strictly necessary
    }

    // If the last operation was * or /, need to add or subtract tempResult
    if (lastOp == '*' || lastOp == '/') {
        if (lastOp == '+') result += tempResult;
        else if (lastOp == '-') result -= tempResult;
    } else {
        result += tempResult; // This accounts for the very last number
    }

    return result;
}

int main() {
    char expression[] = "2+3*4-8/2"; // Example expression without spaces
    double result = evaluate(expression);
    printf("%s = %.2f\n", expression, result);
    return 0;
}
