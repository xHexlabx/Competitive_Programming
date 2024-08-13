#include<bits/stdc++.h>

using namespace std ;

const int Size_X = 1e5 + 1 ;
const int Size_N = 1e3 + 1 ;

int n , x , pre = 0 , curr = 1 ;
int dp[2][Size_X] ;
int h[Size_N] , s[Size_N];

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> x ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> h[i] ;
    }

    for(int i = 0 ; i < n ; i ++ ){
        cin >> s[i] ;
    }

    for(int i = 0 ; i < n ; i ++ ){

        for(int j = 1; j <= x ; j ++ ){
            
            dp[curr][j] = dp[pre][j] ;

            if(j - h[i] >= 0) dp[curr][j] = max(dp[curr][j] , dp[pre][j - h[i]] + s[i]) ;

        }

        swap(pre , curr) ;
    }

    swap(pre , curr) ;

    cout << dp[curr][x] ;

    return 0 ;
}