#include <bits/stdc++.h>

using namespace std;

int F[1000001];

void constructFSM(string P){
	int m = P.size()-1; // the first char of P is empty
	F[0] = -1;
	int i = 1, j = 0;
	for(; i < m; i++){
		j = F[i-1];
		while(P[j+1] != P[i]&& j >= 0){
			j = F[j];
		}
		F[i] = j +1;
	}
}

// since string in C is indexed from 0, to be consistent with the pseudocode, I put
// a space character in T[0] and P[0] and the real strings are  T[1,...,n] and P[1,....,m]
void  kmp_as_fsm(string T, string P){
	int n = T.size()-1; // the first character of T is empty
	int m = P.size()-1; // the first character of P is empty
	constructFSM(P);
	int i = 1, j = 0;
	for(; i <= n; i++){
		while(T[i] != P[j+1] && j >= 0){
			j = F[j];
		}
		j++;
		if(j == m){
			printf("%d ", i - m + 1);
		}
	}
}

int main() {
    freopen("in.txt", "r", stdin);
    string T, P;
    cin >> T >> P;
    T = " " + T;    P = " " + P;
    kmp_as_fsm(T, P);
    return 0;
}

