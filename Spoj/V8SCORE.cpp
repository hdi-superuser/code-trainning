#include <cstdio>
#include <iostream>

using namespace std;

const int maxN = 21;

int A[maxN][maxN], memo[maxN];
int S, K, N, sum;
bool ok;

void Backtrack(int x) {
        for (int i = 1; i <= N; i++)
                if (A[i][x] >= memo[x-1]) {
                        if (A[i][x] <= (S - sum) / (K-x+1)) {
                                memo[x] = A[i][x];
                                sum += memo[x];
                                if (x == K) {
                                        if (sum == S) ok = true;
                                }
                                else Backtrack(x + 1);
                                sum -= memo[x];
                        }
                        if (ok) return;
                }
}

void Print() {
        if (ok) {
                cout << "YES" << endl;
                for (int i = 1; i <= K; i++) cout << memo[i] << " ";
        } else cout << "NO" << endl;
}

int main() {
        //freopen("debug.txt","r", stdin);
        cin >> S >> K >> N;
        for (int i = 1; i <= N; i++)
                for (int j = 1; j <= K; j++) cin >> A[i][j];

        Backtrack(1);
        Print();
}
