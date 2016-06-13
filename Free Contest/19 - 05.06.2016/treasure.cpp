#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;

const int N = 2003;
int n, b[N][N], res[N][N];
int MAX, d[N];
vector<ii> List;

bool check(int x, int y) {
	MAX++;
	for(vector<ii>::iterator it = List.begin(); it != List.end(); it++) {
		int L = abs(x-it->first) + abs(y-it->second);
		if (d[L]==MAX) return true;
		else d[L]=MAX;
	}
	return false;
}

void process() {
    for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		if (List.size() >= max(i-1, n-i) + max(j-1, n-j) + 2) res[i][j] = 1;
		else res[i][j] = check(i, j);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++) {
		scanf("%d", &b[i][j]);
		if (b[i][j]) List.push_back(ii(i, j));
	}
	process();
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) printf("%d ", res[i][j]);
        printf("\n");
	}
}
