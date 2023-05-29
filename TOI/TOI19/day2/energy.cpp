#include<bits/stdc++.h>

using namespace std;

int n , level , d ; 
int qs[301] ;

const long long mod = 1e9 + 7 ;

long long dp[2][301][301] ;

int pre = 0 , now = 1 ;

int get(int l , int r){
    return qs[r] - qs[l - 1] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> level >> d ; 

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> qs[i] ;
        qs[i] += qs[i - 1];
    }

    for(int i = 1 ; i <= n ; i ++){
        for(int j = i ; j <= n ; j ++ ){
            dp[pre][i][j] = 1 ;
        }
    }

    for(int l = level - 1 ; l >= 1 ; l -- ){

        for(int i = n ; i >= 1 ; i -- ){

            for(int j = i ; j <= n ; j ++ ){
                
                dp[now][i][j] = 0 ;

                for(int k = i ; k <= j ; k ++){
            
                    if(abs(get(i , k) - get(k + 1 , j)) <= d){
                        dp[now][i][j] += (dp[pre][i][k] * dp[pre][k + 1][j]) % mod ;
                        dp[now][i][j] %= mod ;
                    }

                }
            }
        }

        if(l != 1)swap(pre , now) ;
    }

    cout << dp[now][1][n] ;

    return 0 ;
}