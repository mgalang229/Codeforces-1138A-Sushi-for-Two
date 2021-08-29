#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	int cnt = 1;
	vector<int> vec;
	for (int i = 1; i < n; i++) {
		if (t[i] != t[i - 1]) {
			// if 't[i]' (current) is not equal to 't[i - 1]' (previous), then store the segment 
			// in the vector (it means before this particular element, there is a segment of size 'cnt')
			vec.push_back(cnt);
			// reset the value of 'cnt' to 1 (it means count the current element)
			cnt = 1;
		} else {
			// increment 'cnt' (same segment)
			cnt++;
		}
	}
	// store the last value of 'cnt' to the vector (last continuous segment)
	vec.push_back(cnt);
	int ans = 0;
	// check the continuous subsegments are greater than 1
	if ((int) vec.size() > 1) {
		// if yes, then find the maximum length of the a valid continuous segment
		for (int i = 0; i < (int) vec.size() - 1; i++) {
			ans = max(ans, min(vec[i], vec[i + 1]));
		}
	}
	// multiply it by 2 to count the other half of the segment
	cout << ans * 2 << '\n';
	return 0;
}
