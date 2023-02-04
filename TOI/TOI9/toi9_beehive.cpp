#include<bits/stdc++.h>
#define vec vector
#define umap unordered_map
#define endll '\n'
using namespace std ;
struct node {
	int w , t ;
};
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0); 
	int m , n ; cin >> m >> n ;
	vec<vec<node>>dp(m , vec<node>(n , {0 , 1})); for(int i = 0 ; i < m; i ++)for(int j = 0 ; j < n ; j ++){
		cin >> dp[i][j].w;
	}
	for(int i = 1 ; i < m ; i++){
		for(int j = 0; j < n ;j ++){
			if(i & 1){
				if(j == n - 1){
					dp[i][j].w += dp[i - 1][j].w ;
					dp[i][j].t = dp[i - 1][j].t ;
				}
				else {
					if(dp[i - 1][j].w > dp[i - 1][j + 1].w){
						dp[i][j].w += dp[i - 1][j].w ;
						dp[i][j].t = dp[i - 1][j].t ;
					}
					else if(dp[i - 1][j].w < dp[i - 1][j + 1].w){
						dp[i][j].w += dp[i - 1][j + 1].w ;
						dp[i][j].t = dp[i - 1][j + 1].t ;
					}
					else {
						dp[i][j].w += dp[i - 1][j].w ;
						dp[i][j].t = dp[i - 1][j].t + dp[i - 1][j + 1].t;
					}
				} 
			}
			else {
				if(j == 0){
					dp[i][j].w += dp[i - 1][j].w;
					dp[i][j].t = dp[i - 1][j].t; 
				}
				else{
						if(dp[i - 1][j].w > dp[i - 1][j - 1].w){
						dp[i][j].w += dp[i - 1][j].w ;
						dp[i][j].t = dp[i - 1][j].t ;
					}
					else if(dp[i - 1][j].w < dp[i - 1][j - 1].w){
						dp[i][j].w += dp[i - 1][j - 1].w ;
						dp[i][j].t = dp[i - 1][j - 1].t ;
					}
					else {
						dp[i][j].w += dp[i - 1][j].w ;
						dp[i][j].t = dp[i - 1][j].t + dp[i - 1][j - 1].t;
					}
				}
			}
		}
	}
	int MAX = INT_MIN ;
	for(int i = 0 ; i < n ; i ++){
		if(dp[m - 1][i].w > MAX){
			MAX = dp[m - 1][i].w ; 
		}
	}
	int cnt = 0 ;
	for(int i = 0 ; i < n ; i ++){
		if(dp[m - 1][i].w == MAX){
			cnt += dp[m - 1][i].t ;
		}
	}
	cout << MAX << ' ' << cnt ;
}