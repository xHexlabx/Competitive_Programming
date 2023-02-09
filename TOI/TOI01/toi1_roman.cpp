#include<bits/stdc++.h>
#define vec vector
using namespace std;
int main() {
	
	ios_base::sync_with_stdio(0) , cin.tie(0) ;
	vec<int>ans = { 0,0,0,0,0,0};
	vec<vec<int>> numSet{ {0},{1,0} , {2,0} , {3,0}, {1,1} , {0,1} , {1,1}, {2,1},{3,1},{1,0,1} };
	int num; cin >> num;
	int first, second, third;
	for (int i = 1; i <= num; i++) {
		first = i % 10;
		second = i % 100 - first;
		third = i - second - first;
		second /= 10;
		third /= 100;
		if (first != 0) {
			for (int j = 0; j < numSet[first].size() ; j++) {
				ans[j] += numSet[first][j];
			}
		}
		if (second != 0) {
			for (int j = 0; j < numSet[second].size(); j++) {
				ans[j + 2] += numSet[second][j];
			}
		}
		if (third != 0) {
			for (int j = 0; j < numSet[third].size(); j++) {
				ans[j + 4] += numSet[third][j];
			}
		}
	}
	for (int i = 0; i <= 4; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}