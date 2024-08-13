#include<bits/stdc++.h>

using namespace std ;

const int Size_N = 1e4 + 1 ;
const int Size_DP = 1e6 + 1 ;

int n , pre = 0 , curr = 1 , sum = 0 ;
int coins [Size_N] ;

bool dp[2][Size_DP] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> coins[i] ;
        sum += coins[i] ;
    }

    for(int i = 0 ; i < n ; i ++ ) {

        dp[pre][0] = true ;

        for(int j = 1 ; j <= sum ; j ++ ){

            if(j - coins[i] >= 0){
                if(dp[pre][j - coins[i]])dp[curr][j] = dp[pre][j - coins[i]] ;
            }

            if(dp[pre][j])dp[curr][j] = dp[pre][j];

        }

        swap(pre , curr) ;
    }

    swap(pre , curr) ;

    int res = 0 ;

    for(int i = 1 ; i <= sum ; i ++ ){

        if(dp[curr][i])res ++ ;

    }

    cout << res << '\n' ;

    for(int i = 1 ; i <= sum ; i ++ ){

        if(dp[curr][i])cout << i << ' ' ;

    }

    return 0 ;
}