#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) {
		cin >> x;
	}
	// insert alice's part in the vector
	vector<int> p{1};
	int rest = 0;
	// store alice's party seats in 'cur'
	int cur = a[0];
	for (int i= 1; i < n; i++) {
		// check if the coalition is stricly less than or equal
		// to the half of alice's party seats
		// ignore the others and add them in another variable
		if (a[i] <= a[0] / 2) {
			cur += a[i];
			p.push_back(i + 1);
		} else {
			rest += a[i];
		}
	}
	// check if alice's party seats are strictly greater than 
	// the total number seats of other parties
	if (cur > rest) {
		cout << (int) p.size() << '\n';
		for (int i = 0; i < (int) p.size(); i++) {
			// [i == (int) p.size() - 1], means that the newline will only print in the last iteration
			cout << p[i] << " \n" [i == (int) p.size() - 1];
		}
	} else {
		cout << 0 << '\n';
	}
	return 0; 
}
