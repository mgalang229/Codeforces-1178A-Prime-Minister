#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	int total_seats = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		// get the total number of seats
		total_seats += v[i];
	}
	vector<int> parties;
	// add the index of alice's party in the vector
	parties.emplace_back(1);
	// initialize the number of seats with alice's party
	int alice_party = v[0];
	for (int i = 1; i < n; i++) {
		// check if alice's part is still less than the half of the total seats
		// add a coalition party if and only alice's party (v[0]) is greater than twice number
		// of the coalition's party
		if (alice_party <= total_seats / 2 && v[0] >= v[i] * 2) {
			alice_party += v[i];
			parties.emplace_back(i + 1);
		}
	}
	// check if alice's party is strictly more than half of the total seats
	if (alice_party > total_seats / 2) {
		cout << (int) parties.size() << '\n';
		for (auto x : parties) {
			cout << x << " ";
		}
	} else {
		cout << 0;
	}
	cout << '\n';
	return 0; 
}
