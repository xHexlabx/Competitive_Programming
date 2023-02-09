#include<bits/stdc++.h>
using namespace std;
bool dp[256][256][3] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n,t = 20 ;
    string s ;
    while(t -- ){
        
        memset(dp , false , sizeof(dp));
        cin >> n >> s ;
        for(int i = 0 ; i < n ; i ++ )dp[i][i][s[i] - '0'] = true ;
        for(int i = n - 1 ; i >= 0 ; i -- ){
            for(int j = i + 1 ; j < n ; j ++ ){
                for(int k = i ; k < j ; k ++ ){
                    if(dp[i][k][0] && dp[k + 1][j][0])dp[i][j][2] = true ;
					if(dp[i][k][0] && dp[k + 1][j][1])dp[i][j][1] = true ;
					if(dp[i][k][0] && dp[k + 1][j][2])dp[i][j][0] = true ;
					
					if(dp[i][k][1] && dp[k + 1][j][0])dp[i][j][2] = true ;
					if(dp[i][k][1] && dp[k + 1][j][1])dp[i][j][1] = true ;
					if(dp[i][k][1] && dp[k + 1][j][2])dp[i][j][1] = true ;
					
					if(dp[i][k][2] && dp[k + 1][j][0])dp[i][j][1] = true ;
					if(dp[i][k][2] && dp[k + 1][j][1])dp[i][j][2] = true ;
					if(dp[i][k][2] && dp[k + 1][j][2])dp[i][j][1] = true ;
					
					if(dp[i][j][0] && dp[i][j][1] && dp[i][j][2])break;
                    
                }
            }
        }
        (dp[0][n - 1][0]) ? cout << "yes\n" : cout << "no\n" ;
    }
    return 0 ;
}