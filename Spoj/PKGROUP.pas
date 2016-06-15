/***@authr Huynh Duy Idol
	@lang C++
   */

#include <iostream> // this is a line comment
#include <stdio.h>
#include <cmath>

#define task "GROUP"
#define maxN 101
#define BASE 1000000007

using namespace std;

int N, A[maxN][maxN], Part[maxN], LT[maxN], M, Ok, X[3][maxN], Lat[maxN], T[3], Delta;

void Enter() {
    cin >> N;
    int k;
    for (int i = 1; i <= N; i++)
    do {
        cin >> k;
        if (k) A[k][i] = 1;
    } while (k);
    for (int i = 1; i <= N; i++) A[i][i] = 1;
}

void DFS(int u, int value) {
    LT[u] = M;
    Part[u] = value;
    X[value][M]++;
    for (int v = 1; v <= N; v++)
    if (!A[u][v] || !A[v][u]) {
        if (LT[v] && Part[v] == value) {
            Ok = 0;
            return;
        }
        if (!LT[v]) {
            DFS(v, 3 - value);
            if (!Ok) return;
        }
    }
}

void Devide() {
    for (int i = 1; i <= N; i++) Part[i] = 0;
    for (int i = 1; i <= N; i++) LT[i] = 0;
    Ok = 1;
    M = 0;
    for (int i = 1; i <= N; i++)
    if (!LT[i]) {
        M++;
        X[1][M] = 0;
        X[2][M] = 0;
        DFS(i, 1);
    }
}

void Search(int &u) {
    for (int i = 1; i <= M; i++)
    if (abs(T[1] - T[2] - 2*X[1][i] + 2*X[2][i]) < Delta) {
        u = i;
        return;
    }
    u = 0;
}

void Optimize() {
    for (int i = 1; i <= M; i++) Lat[i] = 0;
    for (int i = 1; i <= 2; i++) T[i] = 0;
    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= 2; j++) T[j] = T[j] + X[j][i];
    Delta = abs(T[1] - T[2]);
    int i;
    do {
        Search(i);
        if (i > 0) {
            Lat[i] = !Lat[i];
            T[1] = T[1] - X[1][i] + X[2][i];
            T[2] = T[2] - X[2][i] + X[1][i];
            Delta = abs(T[1] - T[2]);
            swap(X[1][i], X[2][i]);
        }
    } while (i);
}

void Print() {
    if (!Ok) cout << "-1";
    else {
        cout << T[1] << " " << T[2] << endl;
        for (int i = 1; i <= N; i++) {
            int u = LT[i];
            int k = Part[i];
            if (((!Lat[u]) && (k == 1)) || ((Lat[u]) && (k == 2))) cout << i << " ";
        }
        cout << endl;
        for (int i = 1; i <= N; i++) {
            int u = LT[i];
            int k = Part[i];
            if ((!Lat[u] && k == 2) || (Lat[u] && k == 1)) cout << i << " ";
        }
    }
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	Enter();
    Devide();
    Optimize();
    Print();
    return 0;
}
