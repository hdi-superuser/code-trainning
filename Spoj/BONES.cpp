#include <stdio.h>
#include <iostream>

#define file "SPOJ"
#define maxN 100000

using namespace std;

int s1, s2, s3, Count[maxN];

int main() {

    #ifndef ONLINE_JUDGE
        freopen(file".INP", "r", stdin);
        freopen(file".OUT", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> s1 >> s2 >> s3;

    for (int i = 1; i <= s1; i++)
        for (int j = 1; j <= s2; j++)
            for (int k = 1; k <= s3; k++)
                Count[i+j+k]++;

    int t = 0, ans = 0;
    for (int i = 1; i <= s1 + s2 + s3; i++)
        if (Count[i] > t) ans = i, t = Count[i];

    cout << ans;

    return 0;
}
