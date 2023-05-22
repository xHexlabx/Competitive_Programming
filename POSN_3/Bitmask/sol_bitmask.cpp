#include<bits/stdc++.h>

using namespace std;

const int N = 4 ;

int dp[1 << N] , ans ;

int arr[N + 1][N + 1] = { {0 , 0 , 0 , 0 , 0} , 
                          {0 , 5 , 6 , 3 , 4} ,
                          {0 , 7 , 3 , 4 , 2} , 
                          {0 , 3 , 8 , 4 , 6} ,
                          {0 , 2 , 1 , 9 , 8}
                        };

void init(){
    for(int i = 1 ; i < (1 << N) ; i ++ ){
        dp[i] = INT_MAX ;
    }
}

void solve(){

    for(int i = 1 ; i < (1 << N) ; i ++ ){

        int state_bit = __builtin_popcount(i) ;

        for(int j = 1 ; j <= N ; j ++ ){
            int bit = (1 << (j - 1)) ;
            if(i & bit)dp[i] = min(dp[i] , dp[i ^ bit] + arr[j][state_bit]);
        }

    }

    ans = dp[(1 << N) - 1] ;

}

int main(){

    ios_base :: sync_with_stdio(0) ,cin.tie(0) ;

    init() ;
    solve() ;

    cout << ans ;

    return 0 ;
}