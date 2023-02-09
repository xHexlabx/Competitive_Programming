#include<bits/stdc++.h>
#define vec vector
#define endll '\n'
using namespace std;
int main() {
	int m, n; cin >> m >> n;
	vec<vec<char>>map(m, vec<char>(n, ' '));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	
	for (int j = 0; j < n; j++) {
		int block; cin >> block; 
		for (int k = 0; k < block; k++) {
			for (int i = 0; i < m; i++) {
				if (i == m - 1 && map[i][j] == '.') {
					map[i][j] = '#';
					break;
				}
				else if (map[i][j] == 'O' || map[i][j] == '#') {
					if (i != 0) {
						map[i - 1][j] = '#';
						break;
					}
					else {
						break;
					}
				}
			}
		}
		
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
    return 0 ;
}