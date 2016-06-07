#include <cstdio>
#include <iostream>
#include <stack>

#define x first
#define y second

using namespace std;

typedef pair<int, int> ii;
const int N = 1000001;

int a[N], L[N], R[N], n;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i], L[i] = R[i] = i;
	stack<ii> st;	st.push(ii(0, 0));	
	for (int i = 1; i <= n; i++) {
		while (st.size() && st.top().x >= a[i]) st.pop();
		L[i] = st.top().y + 1;	st.push(ii(a[i], i));
	}	 
	while (st.size()) st.pop();
	st.push(ii(0, n+1));
	for (int i = n; i >= 1; i--) {
		while (st.size() && st.top().x > a[i]) st.pop();
		R[i] = st.top().y - 1;	st.push(ii(a[i], i));
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
		if (R[i] - L[i] + 1 >= a[i]) ans = max(ans, a[i]);
	cout << ans << endl;
}
