#include <cstdio>
#include <iostream>
#include <stack>
#include <cstring>
#include <cmath>

using namespace std;

const int MAX = 10;
const int inf = 30000;

string cmd[6] = {"*", "ADD", "DIV", "DUP", "MUL", "SUB"};
int n, d, best;
int a[MAX+1], b[MAX+1], x[MAX+1], y[MAX+1];
int st[MAX+1][MAX+1];

int enter_data() {
	d++;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	return n;
}

void backtrack(int i, int top) {
	int j, k, s[MAX+1], t[MAX+1], z[MAX+1];
	if (i >= best) return;
	if (top == 1) {
		j = 1;
		while (j <= n && b[j] == st[top][j]) j++;
		if (j > n) {
			best = i - 1;
			memcpy(y, x, sizeof x);
			return;
		}
	}	
	if (i > MAX) return;
	for (j = 1; j <= 5; j++) {
		if (j != 3 && top < 2) continue;
		if (j == 3 && top == MAX) continue;
		x[i] = j;
		if (j == 1) {
			for (k = 1; k <= n; k++)
				s[k] = st[top-1][k] + st[top][k]; 
		}
		if (j == 2) {
			k = 1;
			while (k <= n && st[top][k] != 0) {
				s[k] = st[top-1][k] / st[top][k];
				k++;
			} 
			if (k <= n) continue;
		}
		if (j == 3) {
			for (k = 1; k <= n; k++) 
				st[top+1][k] = st[top][k];
			backtrack(i+1, top+1);	continue;
		}
		if (j == 4) {
			for (k = 1; k <= n; k++) 
				s[k] = st[top-1][k] * st[top][k];
		}
		if (j == 5) {
			for (k = 1; k <= n; k++)
				s[k] = st[top-1][k] - st[top][k];
		}
		k = 1;
		while (k <= n && abs(s[k]) <= inf) k++;
		if (k <= n) continue;
		memcpy(t, st[top-1], sizeof st[top-1]);
		memcpy(z, st[top], sizeof st[top]);
		memcpy(st[top-1], s, sizeof s);
		backtrack(i+1, top-1);
		memcpy(st[top-1], t, sizeof t);
		memcpy(st[top], z, sizeof z);
	}
}

void process() {
	best = inf;
	for (int i = 1; i <= n; i++) st[1][i] = a[i];
	backtrack(1, 1);
}

void print() {
	cout << "Program " << d << endl;
	if (best > MAX) cout << "Impossible" << endl;
	else {
		if (best = 0) cout << "Empty sequence" << endl;
		else {
			for (int i = 1; i <= best; i++) cout << cmd[y[i]] << " ";
			cout << endl;
		}
	}
	cout << endl;
}
int main() {
	freopen("in.txt", "r", stdin);
	d = 0;
	do {
		if (enter_data() == 0) break;
		process();	print();
	} while (1);
	return 0;
}
