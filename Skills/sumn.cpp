#include <cstdio>
#include <iostream>

using namespace std;

int N, K, r[10001], A[10001];

int main() {
	cin >> N >> K;
   	for (int i = 1; i <= N; i++) cin >> A[i], A[i] += A[i-1], r[i] = A[i] % K;     	   
	int i = 1, j = N;	
	while (i <= j && r[i] != r[j]) i++, j--;
	for (int it = i + 1; it <= j; it++) cout << A[it] - A[it-1] << " ";
	cout << endl << A[j] - A[i] << endl;
}
