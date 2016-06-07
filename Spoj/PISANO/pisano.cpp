/*
 * D - Pisano
 * ICPC 2013 Greater NY Regional
 * Solution by Adam Florence
 * Problem by Adam Florence
 */

#include <cstdio>
#include <iostream>

using namespace std;

int k(int m) {
	/*
	 * int's are fine since max remainder is (x%1000000) <= 999999
	 */
	int nSeq, f1, f2;

	/* Special case is easy */
	if(m == 2){
		return(3);
	}
	nSeq = 2;
	/* Prime Fibonacci pump */
	f1 = 1;
	f2 = 1;
	for(;; nSeq += 2){
		/*
		 * we do 2 values at a time, since if m > 2, k(m) is even
		 */
		/* Next value in sequence remainder */
		f1 = (f1 + f2) % m;
		/* Value after that remainder */
		f2 = (f2 + f1) % m;
		/* Sequence repeats when next 2 values match first 2 which
		 * are always 1
		 */
		if(f1 == 1 && f2 == 1){
			break;
		}
	}
	return(nSeq);
}

int main() {
    freopen("in.txt", "r", stdin);

	int T, m;
	cin >> T;
    while (T--) {
        cin >> m;
        cout << k(m) << endl;
    }

	return(0);
}
