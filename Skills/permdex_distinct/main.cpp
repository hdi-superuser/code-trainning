/* Combinatorics - Permutation index on distinct characters
   =================================================================
   Description: Given a string formed of distinct characters,
                returns the index of the permutation from 0..N!-1.

   Complexity:  O(N^2) where N is size of the string
   -----------------------------------------------------------------
   Author:      Gilbert Lee
   Date:        May 15, 2016
   References:
   -----------------------------------------------------------------
   Reliability: 0
   Notes:       This does not work when characters can be the same
                for example: "aaba"
*/
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int permdex(char *s) {
    int index = 0;
    for (int i = 1; i < strlen(s); i++) {
        for (int j = i; j < strlen(s); j++)
            if (s[i-1] > s[j]) index++;
        index *= strlen(s) - i;
    }
    return index;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    char s[100];
    while(scanf(" %s", s) == 1){
        printf("Index of %s = %d\n", s,  permdex(s));
    }

    return 0;
}
