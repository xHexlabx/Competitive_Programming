#include<bits/stdc++.h>
using namespace std;
char arr[1001] ;
int dp[1001][1001] ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n ; cin >> n ;
    
    for(int i = 0 ; i < n ; i ++ )cin >> arr[i] ;
    for(int i = n - 1 ; i >= 0 ; i -- ){
        for(int j = i + 1 ; j < n ; j ++ ){
            if(arr[i] == arr[j])dp[i][j] = 1 + dp[i + 1][j - 1] ;
            else {
                for(int k = i ; k < j ; k ++ ){
                    dp[i][j] = max(dp[i][j] , dp[i][k] + dp[k + 1][j]) ;
                }
            }
        }
    }
    cout << dp[0][n - 1] ;
    
    return 0 ;
}