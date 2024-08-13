#include<bits/stdc++.h>

using namespace std ;

const int Size = 5001 ;

string a , b ;

int dp[Size][Size] , n , m ;

int min(int a , int b , int c){
    return min(a , min(b , c)) ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> a >> b ;

    n = a.size() ;
    m = b.size() ;

    for(int i = 0 ; i <= n ; i ++ ){
        dp[i][0] = i ;
    }

    for(int j = 0 ; j <= m ; j ++ ){
        dp[0][j] = j ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){

            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] ;
            }

            else dp[i][j] = 1 + min(dp[i - 1][j] , dp[i][j - 1] , dp[i - 1][j - 1]) ;
        }
    }

    cout << dp[n][m] ;

    return 0 ;
}