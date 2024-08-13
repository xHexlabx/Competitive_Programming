#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;
const int Size = 1e3 + 1 ;
char grid [Size][Size] ;

long long dp[Size][Size] ;
int n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> grid[i][j] ;
        }
    }

    dp[1][1] = 1 ;

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            if(grid[i][j] != '*')dp[i][j] += dp[i - 1][j] + dp[i][j - 1] ;
            else dp[i][j] = 0 ;
            dp[i][j] %= mod ;
        }
    }

    cout << dp[n][n] ;

    return 0 ;
}