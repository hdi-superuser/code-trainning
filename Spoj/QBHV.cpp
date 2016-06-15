#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}
int cmp(const void *a, const void *b)
{
    return (*(char*)a - *(char*)b);
}
int main()
{
    char s[10];
    int i, n, k, a, b;
    gets(s);
    n = strlen(s);
    long R = 1;
    int A[26]={0};
    for(i=0; i<n; i++)
        R = R*(i+1)/++A[s[i]-'A'];
    printf("%ld\n", R);
    qsort(s, n, sizeof(char), cmp); 
    do {
        i = n-2;
        puts(s);
        while(i>=0 && s[i]>=s[i+1])
            i--;
        if(i>=0) {
            k = n-1;
            while(s[k]<=s[i])
                k--;
            swap(&s[k], &s[i]);
            a = i+1;
            b = n-1;
            while(a<b) {
                swap(&s[a], &s[b]);
                a++;
                b--;
            }
        }
    }
    while(i>=0);
    return 0;
}