#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;
const int Size = 1e6 + 1 ;
int n ;

long long dp[Size] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    dp[0] = 1; 

    for(int i = 1 ; i <= n ; i ++ ){

        for(int j = 1 ; j <= 6 ; j ++ ){
            if(i - j >= 0){
                dp[i] = dp[i] + dp[i - j] ;
                dp[i] %= mod ;
            }
        }
    }
    
    cout << dp[n] ;

    return 0 ;
}