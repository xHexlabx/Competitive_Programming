#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e5 + 1 ;
int arr[Size] , dp[Size];
int n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    dp[1] = 0 ;
    dp[2] = abs(arr[2] - arr[1]) ;
    
    for(int i = 3 ; i <= n ; i ++ ){
        dp[i] = min(dp[i - 1] + abs(arr[i] - arr[i - 1]) , dp[i - 2] + abs(arr[i] - arr[i - 2])) ;
    }

    cout << dp[n] ;
    
    return 0 ;
}