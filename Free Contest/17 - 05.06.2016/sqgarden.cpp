#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
const int N = 1000001;
int n;
int x[N];
int y[N];
map<pair<int, int>, int> mm;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
		mm[make_pair(x[i], y[i])] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) if (x[i] < x[j] && y[i] < y[j] && x[i] - x[j] == y[i] - y[j]) {
			if (mm.count(make_pair(x[i], y[j])) == 1 && mm.count(make_pair(x[j], y[i])) == 1 ) cnt++;
		}
	}
	cout << cnt << endl;

}
