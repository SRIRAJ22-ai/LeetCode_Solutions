void reverseString(char* s, int sSize) {
    int temp;
    int i = 0;
    int j = sSize - 1;
    while(i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        ++i;
        --j;
    }
    return ;
}