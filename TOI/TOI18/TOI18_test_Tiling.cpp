#include<bits/stdc++.h>

using namespace std;

bool dp[1000][1000] ;
int n ;

bool solve(int x , int y){
    if(x < 0 || y < 0)return false ;
    if(x == 0 && y == 0)return true ;
    if(dp[x][y])return dp[x][y];
    else return dp[x][y] = solve(x - 1 , y - 1) || solve(x - 2 , y - 1) || solve(x - 1 , y - 2) || solve(x - 2 , y) || solve(x , y - 2) ;
}

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    cout << solve(n , n) ;

    int cnt = 0 ;

    for(int i = 2 ;  i <= n ; i ++ ){
        for(int j = 2 ;  j <= n ; j ++ ){
            if(dp[i][j])cnt ++ ;
        }
    }
    cout << cnt ;
    return 0 ;
}