int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1; // Palindrome
    }
    if (str[start] != str[end]) {
        return 0; // Not a palindrome
    }
    return isPalindrome(str, start + 1, end - 1);
}
