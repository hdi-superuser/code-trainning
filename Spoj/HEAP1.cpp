#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int t;

int main()
{
    //freopen("HEAP1.INP", "r", stdin);
    //freopen("HEAP1.OUT", "w", stdout);
    scanf("%d", &t);
    for (int it = 1; it <= t; it++){
        priority_queue <long long, vector<long long>, greater<long long> > heap(0, 0);
        int n;
        long long res = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            long long u;
            scanf("%lli", &u);
            heap.push(u);
        }
        for (int i = 1; i < n; i++){
            long long temp1 = heap.top();
            heap.pop();
            long long temp2 = heap.top();
            heap.pop();
            res += temp1 + temp2;
            heap.push(temp1+temp2);
        }
        printf("%lli\n", res);
    }
    return 0;
}

