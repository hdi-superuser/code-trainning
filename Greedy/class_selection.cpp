#include <bits/stdc++.h>

#define MAX 1000000

using namespace std;

typedef struct {
    int id, s, f;
} course;
int X[MAX];
course A[MAX];

bool cmp(course a, course b) {
    return a.f != b.f ? a.f < b.f : a.s < b.s;
}

int greedy(int n) {
    sort(A + 1, A + n + 1, cmp);
    int count = 0;
    X[0] = 0;
    for (int i = 1; i < n; i++)
        if (A[X[count]].f <= A[i].s)
            X[++count] = i;
    return count + 1;
}

int main() {
    // Enter data
    // printf("%d\n", greedy(N));
}
