#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char c[10][10];
int n, m;
int ans = 0;
bool elim(int x, int y){
	bool flag = false;
	char ct = c[x][y];
	c[x][y] = '-';
	ans += 5;
	if(y + 1 < m && ct == c[x][y + 1]){
		elim(x, y + 1);
		flag = true;
	}
	if(y - 1 >= 0 && ct == c[x][y - 1]){
		elim(x, y - 1);
		flag = true;
	}
	if(x + 1 < n && ct == c[x + 1][y]){
		elim(x + 1, y);
		flag = true;
	}
	if(x - 1 >= 0 && ct == c[x - 1][y]){
		elim(x - 1, y);
		flag = true;
	}
	return flag;
}
void fall(int x, int y){
	if(x < 0 || x >= n - 1)return;
	if(c[x][y] == '-' || c[x][y] == '#')return;
	while(x + 1 < n && c[x + 1][y] == '-'){
		swap(c[x + 1][y], c[x][y]);
		x++;
	}
}
void fc(){
	for(int i = n;i >= 0;i--){
		for(int j = 0;j < m;j++){
			fall(i, j);
		}
	}
	for(int i = 1;i < n - 1;i++){
		for(int j = 1;j < m - 1;j++){
			if(c[i][j] == c[i][j + 1] || c[i][j] == c[i][j - 1]
			|| c[i][j] == c[i - 1][j] || c[i][j] == c[i + 1][j]){
				if(c[i][j] != '-' && c[i][j] != '#'){
					if(elim(i, j))fc();
				}
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cin >> c[i][j];
		}
	}
	int op;cin >> op;
	for(int i = 0;i < op;i++){
		int x, y;cin >> x >> y;
		char cop;cin >> cop;
		if(cop == 'R'){
			if(y + 1 < m && c[x][y + 1] == '-' && c[x][y] != '-'
			&& c[x][y] != '#'){
				swap(c[x][y], c[x][y + 1]);
				fc();
			}
			else ans -= 5;
		}
		else{
			if(y - 1 >= 0 && c[x][y - 1] == '-' && c[x][y] != '-'
			&& c[x][y] != '#'){
				swap(c[x][y], c[x][y - 1]);
				fc();
			}
			else ans -= 5;
		}
	}
	cout << ans << endl;
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}