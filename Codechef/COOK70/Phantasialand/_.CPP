// [May 22 2016] Codechef COOK70 - Phantasialand
#include <iostream>
#include <cstdio>

using namespace std;

int N, a;
long long tmp;

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> a, tmp+= a;
    int res = N;
    while (tmp > N*2) {
        res++;
        tmp-=2;
    }
    cout << res;
    return 0;
}
