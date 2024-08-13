#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;
const int Size = 1e6 + 1 ;
long long n , x ;
long long dp[Size] ;
long long coins [101] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> x ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> coins[i] ;
    }

    dp[0] = 1 ;

    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 1 ; j <= x ; j ++ ){
            if(j - coins[i] >= 0 ){
                dp[j] += dp[j - coins[i]] ; 
                dp[j] %= mod ;
            }
        }
    }

    cout << dp[x] ;

    return 0 ;
}