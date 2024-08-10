#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e6 + 1 ;

int n , k ;
int coins [101] , dp[Size] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> k >> n ;

    for(int i = 0 ; i < k ; i ++ ){
        cin >> coins[i] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){

        dp[i] = 1e9 ;

        for(int j = 0 ; j < k ; j ++ ){

            if(i - coins[j] >= 0 && dp[i - coins[j]] != 1e9){
                dp[i] = min(dp[i] , 1 + dp[i - coins[j]]) ;
            }

        }
    }

    if(dp[n] != 1e9){
        cout << dp[n] ;
    }
    else cout << -1 ;

    return 0 ;  
}