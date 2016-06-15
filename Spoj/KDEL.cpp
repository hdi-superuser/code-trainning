/***@authr Huynh Duy Idol
	@lang C++
   */

#include <iostream> // this is a line comment
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>

#define task "DEL"
#define maxN 611953
#define BASE 1000000007

using namespace std;

vector<int> prime,a;
int n,k;
string s;

void Eratosthene() {
    a.resize(maxN+2);
    for(int i = 2; i*i <= maxN; i++)
        if (a[i]==0) {
            int j = i*i;
            while(j <= maxN) {
                a[j] = 1;
                j += i;
            }
        }
        for(int i = 2; i <= maxN; i++) {
            if(a[i] == 0) prime.push_back(i);
            if(prime.size() == n) break;
        }
}

void Add(int i) {
    string st2 = "";
    stack <char> st;
    while(i != 0) {
        st2.insert(0, 1, i % 10 + 48);
        i /= 10;
    }
    s += st2;
}

void Init() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) Add(prime[i]);
}

void Solve() {
    deque <char> dq;
    for(int i = 0; i < s.length(); i++) {
        while(k > 0 && dq.size() > 0 && dq.back() < s[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(s[i]);
    }
    while(dq.size() > k) {
        cout << dq.front();
        dq.pop_front();
    }
}

int main() {
	#ifndef ONLINE_JUDGE
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    #endif // ONLINE_JUDGE
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);
	Eratosthene();
    Init();
    Solve();
    return 0;
}
