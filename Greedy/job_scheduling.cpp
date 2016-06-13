#include <bits/stdc++.h>

#define MAX 5000

using namespace std;

typedef struct {
    int id, d, p;
} job;

job A[MAX];
int X[MAX];

bool cmp(job a, job b) {
    return a.p != b.p ? a.p > b.p : a.d < a.d;
}

void greedy(int n) {
    sort(A, A + n, cmp);
    memset(X, -1, sizeof X);
    for (int i = 0; i < n; i++) {
        int j = A[i].d;
        while ((X[j] != -1) && (j < 0)) j--;
        if (j > 0) X[j] = i;
    }
}

int main() {
    // Enter data
    // Greedy(n)
}
