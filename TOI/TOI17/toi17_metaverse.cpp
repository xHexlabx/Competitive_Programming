#include<bits/stdc++.h>

using namespace std;

struct node {

    int w_r , w_c , o_r , o_c ; 

    node(){}

    node (int a , int b , int c , int d) { 
        w_r = a , w_c = b , o_r = c , o_c = d ;
    }

};

int dis(node j , node i){

    return abs(j.o_r - i.w_r) + abs(j.o_c - i.w_c) ;

}

int dp[20][20001] , mindis , minticket , m , n , k , p ;

node node_list[20001] ;
node s , e ;

void solve(){

    for(int i = 1 ; i <= k ; i ++ ){

        dp[1][i] = dis(s , node_list[i]) ;

        if(dp[1][i] + dis(node_list[i] , e) < mindis){
            mindis = dp[1][i] + dis(node_list[i] , e) ;
            minticket = 1 ; 
        }

    }

    for(int t = 2 ; t <= p ; t ++ ){

        for(int i = 1 ; i <= k ; i ++ ){

            dp[t][i] = INT_MAX ;

            for(int j = 1 ; j <= k ; j ++ ){
                dp[t][i] = min(dp[t][i] , dp[t - 1][j] + dis(node_list[j] , node_list[i])) ;
            }

            if(dp[t][i] + dis(node_list[i] , e) < mindis){
                mindis = dp[t][i] + dis(node_list[i] , e) ;
                minticket = t ; 
            }
        }
        
    }

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n >> k >> p ;

    for(int i = 1 ; i <= k ; i ++ ){
        
        int w_r , w_c , o_r , o_c ;
        
        cin >> w_r >> w_c >> o_r >> o_c ;

        node_list[i] = node(w_r , w_c , o_r , o_c) ;

    }
    
    s = node(1 , 1 , 1 , 1) ;
    e = node(m , n , m , n) ;

    mindis = (m + n - 2) ;
    minticket = 0 ;

    solve() ;

    cout << mindis << ' ' << minticket ;

    return 0 ;
}