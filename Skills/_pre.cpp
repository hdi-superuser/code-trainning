#include <bits/stdc++.h>

using namespace std;

bool fr[5];
int x[5];

void print() {
    int s = 0;
    for (int k = 1; k <= 4; k++) s = s*10 + x[k];
    if (s % 7) return;
    for (int k = 1; k <= 4; k++) printf("%d ", x[k]);
    printf("\n");
}

void backtrack(int i) {
    for (int j = 1; j <= 4; j++) {
        if (fr[j]) continue;
        x[i] = j;
        if (i == 4) print();
        else {
            fr[j] = true;
            backtrack(i+1);
            fr[j] = false;
        }
    }
}

int main() {
    backtrack(1); 
}
