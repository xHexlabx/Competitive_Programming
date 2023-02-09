#include<bits/stdc++.h>
using namespace std;
int dp[25][3] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    int n ;
    dp[0][0] = 1 ;
    dp[0][1] = 1 ;
    for(int i = 1 ; i <= 24 ; i ++ ){
        dp[i][0] = dp[i - 1][0] ;
        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] ;
        dp[i][2] = dp[i - 1][1] ;
    }
    cin >> n ;
    while(n != -1){
        cout << dp[n][1] << ' ' << dp[n][0] + dp[n][1] + dp[n][2] << '\n';
        cin >> n;
    } 
    return 0 ;
}