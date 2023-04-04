#include<bits/stdc++.h>

using namespace std;

int dp[100001][3] , arr[100001][3];
int n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);
    cin >> n ;

    for(int i = 1; i <= n ; i++){
        for(int j = 0 ; j < 3 ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    for(int i = 1 ; i <= n ; i++){
        dp[i][0] = arr[i][0] + max({dp[i - 1][1] , dp[i - 1][2]}) ;
        dp[i][1] = arr[i][1] + max({dp[i - 1][0] , dp[i - 1][2]}) ;
        dp[i][2] = arr[i][2] + max({dp[i - 1][0] , dp[i - 1][1]}) ;
    }

    cout << max({dp[n][0] , dp[n][1] , dp[n][2]}) ;

    return 0 ;
}