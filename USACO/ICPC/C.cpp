#include<bits/stdc++.h>

using namespace std ;

const int Size_P = 11 , Size_N = 3001 , Size_K = 3001 ;

long long dp[Size_P][Size_N][Size_K] ;
long long arr[Size_N][Size_P] ;
long long p[Size_N] ;

long long n , k , ans;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> n >> k ;

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> p[i] ;

        for(int j = 1 ; j <= p[i] ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= k ; j ++ ){
            for(int a = 0 ; a <= 10 ; a ++ ){
                    
                    if (a - p[i] >= 0){
                        dp[a][i][j] = max(dp[a][i][j] , dp[a - p[i]][i - 1][j - p[i]] + arr[i][p[i]]) ;
                    }
                    
                    if(j + a <= k) {
                        dp[a][i][j] = max(dp[a][i][j] , dp[a][i - 1][j - p[i]] + arr[i][p[i]]) ;
                    }
                    else {
                        dp[a][i][j] = max(dp[a][i][j] , dp[a][i - 1][j - p[i]] + arr[i][k - j]) ;
                    }  

                    dp[a][i][j] = max(dp[a][i][j] , dp[a][i - 1][j]);

                    ans = max(ans , dp[a][i][j]) ;
            }
        }
    }

    cout << ans ;

    return 0 ;
}