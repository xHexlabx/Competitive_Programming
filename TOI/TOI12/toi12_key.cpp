#include<bits/stdc++.h>
#define endll '\n'
#define vec vector
#define umap unordered_map
#define ll long long 
using namespace std;
bool dp[1001][1001] ;
string a , b , s;
int main(){
	
	ios_base :: sync_with_stdio(0),cin.tie(0);
	 cin >> a >> b ;
	int m = b.size() , n = a.size();
	
	int q ; cin >> q ;
	
	while(q--){
		cin >> s ;
		memset(dp , false , sizeof(dp));
		dp[0][0] = true ;
		
		for(int j = 1 ; j < n + 1 ; j ++ ){
			if( dp[0][j - 1] && s[j - 1] == a[j - 1])dp[0][j] = true ;
		}
		for(int i = 1 ; i < m + 1 ; i ++ ){
			if(dp[i - 1][0] && s[i - 1] == b[i - 1])dp[i][0] = true ;
		}
		for(int i = 1 ; i < m + 1 ; i ++ ){
			for(int j = 1 ; j < n + 1 ; j ++ ){
				if((dp[i - 1][j] && s[j + i - 1] == b[i - 1] ) || ( dp[i][j - 1]&&s[i + j - 1] == a[j - 1] ))dp[i][j] = true ;
			}
		}
		if(dp[m][n]) cout << "Yes\n";
		else cout << "No\n";
	}
	return 0;
}