#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 1000001;

int N;
int A[MAX], D[MAX], L[MAX], R[MAX];

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];

    int top;
    L[1] = D[top = 1] = 1;
    for (int i = 2; i <= N; i++) {
        while (top > 0 && A[D[top]] >= A[i]) top--;
        D[++top] = i;   L[i] = D[top-1] + 1;
    }
    top = 0;
    R[N] = D[top = 1] = N;
    for (int i = N - 1; i; i--) {
        while (top > 0 && A[D[top]] >= A[i]) top--;
        D[++top] = i;   R[i] = D[top-1] - 1;
    }

    for (int i = 1; i <= N; i++) cout << L[i] << " ";
    cout << endl;
    for (int i = 1; i <= N; i++) cout << R[i] << " ";

    return 0;
}
