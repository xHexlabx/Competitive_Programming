#include<bits/stdc++.h>
#define vec vector 
#define endll '\n'
using namespace std ;
int main(){
	ios_base :: sync_with_stdio(0),cin.tie(0);
	
	int k , n ; cin >> k >> n;
	int a[n],b[n];
	
	for(int i = 0  ; i < n ;i ++ )cin >> a[i];
	for(int i = 0  ; i < n ;i ++ )cin >> b[i];
	
	vec<vec<pair<int,int>>>dp(n + 1, vec<pair<int,int>>(n + 1 , {1,0}));
	
	for(int j = 1 ; j <= n ; j ++ ){
		if(a[j - 1] + dp[0][j - 1].second > k )dp[0][j] = {dp[0][j - 1].first + 1 , a[j - 1] };
		else dp[0][j] = {dp[0][j - 1].first , dp[0][j - 1].second + a[j - 1]};
	}
	
	for(int i = 1 ; i <= n ; i ++ ){
		if(b[i - 1] + dp[i - 1][0].second > k )dp[i][0] = {dp[i - 1][0].first + 1 , b[i - 1] };
		else dp[i][0] = {dp[i - 1][0].first , dp[i - 1][0].second + b[i - 1]};
	}
	
	for(int i = 1 ; i <= n ; i ++ ){
		for(int j = 1 ; j <= n ; j ++){
			pair<int ,int>temp_a = dp[i - 1][j];
			pair<int ,int>temp_b = dp[i][j - 1];
			
			if(temp_a.second + b[i - 1] > k)temp_a = {temp_a.first + 1 , b[i - 1]};
			else temp_a = {temp_a.first , temp_a.second + b[i - 1]};
			
			if(temp_b.second + a[j - 1] > k)temp_b = {temp_b.first + 1 , a[j - 1]};
			else temp_b = {temp_b.first , temp_b.second + a[j - 1]};
			
			if(temp_a.first == temp_b.first){
				if(temp_a.second < temp_b.second)dp[i][j] = temp_a;
				else dp[i][j] = temp_b;
			}
			else if(temp_a.first < temp_b.first )dp[i][j] = temp_a;
			else dp[i][j] = temp_b ;
			
			}
		}
	
	cout << dp[n][n].first  << endll << dp[n][n].second ;
	
	return 0 ;
}
