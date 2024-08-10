#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e6 + 1 ;
const long long mod = 1e9 + 7 ;
long long dp[Size] ;

int k , n ;
int coins[101] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> k >> n ;

    for(int i = 0 ; i < k ; i ++ ){
        cin >> coins[i] ;
    }

    dp[0] = 1 ;

    for(int i = 1 ; i <= n ; i ++ ){

        for(int j = 0 ; j < k ; j ++ ){
            if(i - coins[j] >= 0){

                dp[i] = dp[i] + dp[i - coins[j]] ; 
                dp[i] %= mod ;
            }
        }
    }

    cout << dp[n] ;

    return 0 ;
}