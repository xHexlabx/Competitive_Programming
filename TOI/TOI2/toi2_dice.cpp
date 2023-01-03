#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n' 
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string cmd ; cin >> cmd ;
		umap<char, int >roll;
		vec<int>dice = { 1,2,3,4,6,5 };
		for (auto i : cmd) {
			if (i == 'F') {
				vec<int>newdice = dice;
				newdice[0] = dice[5];
				newdice[1] = dice[0];
				newdice[4] = dice[1];
				newdice[5] = dice[4];
				dice = newdice;
			}
			if (i == 'B') {
				vec<int>newdice = dice;
				newdice[5] = dice[0];
				newdice[0] = dice[1];
				newdice[1] = dice[4];
				newdice[4] = dice[5];
				dice = newdice;
			}
			if (i == 'L') {
				vec<int>newdice = dice;
				newdice[2] = dice[0];
				newdice[0] = dice[3];
				newdice[3] = dice[4];
				newdice[4] = dice[2];
				dice = newdice;
			}
			if (i == 'R') {
				vec<int>newdice = dice;
				newdice[0] = dice[2];
				newdice[3] = dice[0];
				newdice[4] = dice[3];
				newdice[2] = dice[4];
				dice = newdice;
			}
			if (i == 'C') {
				vec<int>newdice = dice;
				newdice[1] = dice[3];
				newdice[3] = dice[5];
				newdice[5] = dice[2];
				newdice[2] = dice[1];
				dice = newdice;
			}
			if (i == 'D') {
				vec<int>newdice = dice;
				newdice[3] = dice[1];
				newdice[5] = dice[3];
				newdice[2] = dice[5];
				newdice[1] = dice[2];
				dice = newdice;
			}
		}
		cout << dice[1] << ' ';
	}
	return 0;
}