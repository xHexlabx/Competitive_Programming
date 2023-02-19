#include<bits/stdc++.h>
using namespace std;
struct item {
    long long price , amount ;
};
item dp[501][501] ;
item items[501];
int n , m , q , x , y ;
long long w ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> m >> q ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> items[i].price ;
        items[i].amount = 1 ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            dp[i][j].price = LLONG_MAX ;
            dp[i][j].amount = 0 ;
        }
    }
    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            dp[i][j].price = items[i].price + items[j].price ;
            dp[i][j].amount = 2 ;
        }
    }
    for(int i = 1 ; i <= m ; i ++ ){
        cin >> x >> y >> w ;
        dp[x][y].price = w ;
        dp[x][y].amount = 2 ;
        dp[y][x].price = w ;
        dp[y][x].amount = 2 ;
    }
    for(int k = 1 ; k <= n ; k ++ ){
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = 1 ; j <= n ; j ++ ){
                if(dp[i][k].price + dp[k][j].price < dp[i][j].price){
                    dp[i][j].price = dp[i][k].price + dp[k][j].price ;
                    dp[i][j].amount = dp[i][k].amount + dp[k][j].amount ;
                }
                else if(dp[i][k].price + dp[k][j].price == dp[i][j].price){
                    dp[i][j].amount = max(dp[i][j].amount , dp[i][k].amount + dp[k][j].amount );
                }
            }
        }
    }
    while(q -- ){
        cin >> x >> y ;
        cout << dp[x][y].price << ' ' << dp[x][y].amount << '\n' ;
    }
    return 0;
}