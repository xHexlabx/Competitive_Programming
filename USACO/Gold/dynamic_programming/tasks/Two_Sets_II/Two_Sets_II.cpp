#include<bits/stdc++.h>

using namespace std ;

const int Size = 150001 ;
const long long mod = 1e9 + 7 ;
int n , pre = 0 , curr = 1 , sum = 0 ; 
long long dp[2][Size] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    sum = (n) * (n + 1) / 2 ;
    
    if(sum & 1){
        cout << 0 ;
        return 0 ;
    }

    sum /= 2 ;

    for(int i = 1 ; i <= n ; i ++ ){
        
        dp[pre][0] = 1 ;
        
        for(int j = 1 ; j <= sum ; j ++ ){
            
            dp[curr][j] = dp[pre][j] ;
            
            if(j - i >= 0)dp[curr][j] += dp[pre][j - i] ;

            dp[curr][j] %= mod ;
            // cout << dp[curr][j] << ' ' ;
        }
        // cout << '\n' ;
        swap(pre , curr) ;
    }

    swap(pre , curr) ;

    cout << dp[pre][sum];

    return 0 ;
}