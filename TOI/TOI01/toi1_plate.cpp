#include<bits/stdc++.h>
#include<unordered_map>
#define vec vector
#define umap unordered_map
#define endll endl
#define x first 
#define y second 
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	umap<int, int>findclass;
	vec<pair<int,int>>q;
	int n, t; cin >> n >> t;
	int Class, Number;
	while (t--) {
		cin >> Class >> Number; 
		findclass[Number] = Class; 
	}
	char cmd; cin >> cmd;
	while (cmd != 'X') {
		if (cmd == 'E') {
			cin >> Number;
			if (q.empty()) {
				q.push_back({ findclass[Number] , Number });
			}
			else {
				int cnt = 0;
				for (int i = q.size() - 1; i >= 0; i--) {
					if (findclass[Number] == q[i].first) {
						q.insert(q.begin() + i + 1, {findclass[Number] , Number});
						cnt++;
						break;
					}
					
				}
				if(cnt == 0)q.push_back({ findclass[Number] , Number });
			}
		}
		if (cmd == 'D') {
			if (q.empty()) {
				cout << "empty\n";
			}
			if(!q.empty()){
				cout << q[0].second << '\n';
				q.erase(q.begin());
			}
		}
		if (cmd == 'X')cout << 0;
		cin >> cmd; 
	}
	cout << 0;
	return 0;
}