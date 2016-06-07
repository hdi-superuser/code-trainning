#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const long long inf = 2000000000000000000;

int N, D1[1 << 16], D2[1 << 16];
long long S, A[33], C[1 << 16], x[1 << 16];

int main() {
	freopen("in.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i], S += A[i];
	for (int i = 0; i <= (1 << N/2) - 1; i++) 
		for (int j = 1; j <= N/2; j++) C[i] += (i >> (j-1)) & 1 ? A[j] : 0;
	sort(C, C + (1 << (N/2)));
	vector <long long> d1;	int nd1 = 0;
	d1.push_back(0);	D1[0] = 1;
	for (int i = 1; i <= (1 << N/2) - 1; i++) 
		if (C[i] != C[i-1]) {
			d1.push_back(C[i]);
			D1[++nd1] = 1;
		} else  D1[nd1]++;
	long long t[18];	int nt = 0;
	for (int i = N/2 + 1; i <= N; i++) t[++nt] = A[i];
	for (int i = 1; i <= (1 << nt) - 1; i++) 
		for (int j = 1; j <= nt; j++) x[i] += (i >> (j-1)) & 1 ? t[j] : 0; 
	vector <long long> d2;	int nd2 = 0;
	d2.push_back(0);	D2[0] = 1;
	for (int i = 1; i <= (1 << nt) - 1; i++) {
		if (x[i] != x[i-1]) {
			d2.push_back(x[i]);
			D2[++nd2] = 1;
		} else D2[nd2]++;
	}

	for (int i = 1; i <= nd1; i++) cout << d1[i] << " " << D1[i] << endl;
	cout << endl;
	for (int i = 1; i <= nd2; i++) cout << d2[i] << " " << D2[i] << endl;	
	cout << endl;
	long long minAnswer = inf, ways = 0;
	for (int i = 0; i <= nd2; i++)
		for (int j = 0; j <= nd1; j++) {
			long long temp = abs(S - 2*(d1[j] + d2[i]));
			if (temp < minAnswer) { minAnswer = temp, ways = D1[j]*D2[i], cout << "optimize: " << minAnswer << " " << j << " " << i << endl; continue; }
			if (temp == minAnswer) ways += D1[j]*D2[i], cout << "+: " << minAnswer << " " << j << " " << i << endl;
		}		
	cout << minAnswer << " " << ways/2 << endl;
}
