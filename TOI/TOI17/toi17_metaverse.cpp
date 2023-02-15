#include<bits/stdc++.h>

using namespace std ;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int now = 0 , pre = 1 ; 
int dp[2][20001] ;

struct coordinate {
    int x , y ;
};

int m , n , k , p ;

coordinate in[20001] , out[20001] ;

int cal(coordinate a , coordinate b){
    return abs(a.x - b.x) + abs(a.y - b.y) ;
}

int dis = INT_MAX ;
int ticket = INT_MAX ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> m >> n >> k >> p ;

    for(int i = 0 ; i < k ; i ++ ){
        cin >> in[i].x >> in[i].y >> out[i].x >> out[i].y ;
    }
    for(int i = 0 ; i <= p ; i ++ ){
        if(i == 0){
            for(int dest = 0 ; dest < k ; dest ++ ){
                dp[now][dest] = cal({1 , 1} , out[dest]) ;
            }
            dp[now][k] = cal({1 , 1} , {m , n}) ;
        }
        else if(i == 1){
            
            for(int dest = 0 ; dest <= k ; dest ++ ){
                dp[now][dest] = dp[pre][dest] ;
            }
            for(int dest = 0 ; dest < k ; dest ++ ){
                dp[now][dest] = min(dp[now][dest] , cal({1 , 1} , in[dest])) ;
                dp[now][k] = min(dp[now][k] , dp[now][dest] + cal(out[dest] , {m , n})) ;
            }
            
        }
        else {
            for(int dest = 0 ; dest <= k ; dest ++ ){
                dp[now][dest] = dp[pre][dest] ;
            }
            for(int src = 0 ; src < k ; src ++ ){
                for(int dest = 0 ; dest < k ; dest ++ ){
                    dp[now][dest] = min(dp[now][dest] , dp[pre][src] + cal(out[src] , in[dest])) ;
                }
            }
            for(int src = 0 ; src < k ; src ++ ){
                dp[now][k] = min(dp[now][k] , dp[now][src] + cal(out[src] , {m , n})) ;
            }
        }
        if(dp[now][k] < dis){
            dis = dp[now][k] ;
            ticket = i ;
        }
        swap(pre , now) ;
    }
    cout << dis << ' ' << ticket ;
    
    return 0 ;
}