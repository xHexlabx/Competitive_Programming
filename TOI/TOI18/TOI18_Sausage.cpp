#include<bits/stdc++.h>

using namespace std;

long long dp[5001][5001] ;
long long dp2[5001] ;
long long arr[5001] ;
int n ;

long long solve(int l , int r){
    if(l == r){
        return dp[l][r] = arr[l];
    }
    else if(dp[l][r])return dp[l][r];
    else {
        return dp[l][r] = max(arr[l] + abs(arr[r] - arr[l]) + solve(l + 1 , r) , arr[r] + abs(arr[r] - arr[l]) + solve(l , r - 1)) ;
    }
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n ;

    for(int i = 1 ; i <= n  ; i++){
        cin >> arr[i] ;
    }

    solve(1 , n) ;

    for(int i = 1 ; i <= n ; i ++ ){

        dp2[i] = dp[1][i] ;

        for(int j = 1 ; j < i ; j ++ ){
            dp2[i] = max(dp2[i] , dp2[j] + dp[j + 1][i]) ;
        }
    }

    cout << dp2[n] ;

    return 0 ;
}