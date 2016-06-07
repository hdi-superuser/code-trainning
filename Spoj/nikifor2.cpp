#include <iostream>

using namespace std;

int main() {
	int x, y, ans = 0;
	cin >> x >> y;
	for (int base = 2; base <= x+1; base++) {
		int Y = y, X = x;
		bool match = true;
		while (Y) {
			while (X % base != Y % base) {
				X /= base;
				if (X == 0) { match = false; break; }
			}
			if (!match) break;
			match = true;
			X /= base;	Y /= base;
		}
		if (match) { ans = base; break; }
	}
	if (ans) cout << ans << endl;
	else cout << "No Solutioin" << endl;
	return 0;
}
