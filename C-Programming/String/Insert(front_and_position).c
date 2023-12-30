void InsertFront(char *str, char target) {
    int len = strlen(str);

    // str -> str + 1에 (len + 1) 메모리 만큼 복사
    memmove(str + 1, str, len + 1); // Use memmove to handle overlapping regions
    str[0] = target;
}

void InsertPostion(char *str, char target, int position){
    int len = strlen(str);

    if (position < 0 || position > len){
        printf("Invalid.\n");
        return;
    }
    memmove(str + position + 1, str + position, len - position + 1);
    str[position] = target;
}
