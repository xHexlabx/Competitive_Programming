#include<bits/stdc++.h>

using namespace std ;

const int Size = 21 ;
const long long mod = 1e9 + 7 ;
int n , m , src , dest ;
vector<int> adj[Size];
long long dp[1 << Size][Size] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> src >> dest ;
        adj[dest].push_back(src) ;
    }

    dp[1][1] = 1 ;
    
    for(int state = 2 ; state < (1 << n) ; state ++ ){

        if(!(state & 1))continue ;
        
        int dest_bit = 1 ;

        for(int dest = 2 ; dest <= n ; dest ++ ){

            dest_bit <<= 1 ;

            if(state & dest_bit){
                
                int previous_state = state ^ dest_bit ;

                for(int src :  adj[dest]){
                    
                    int src_bit = (1 << (src - 1)) ;

                    if(src_bit & previous_state){
                        dp[state][dest] += dp[previous_state][src] ;
                        dp[state][dest] %= mod ;
                    }
                }
            }

        }
    }

    cout << dp[(1 << n) - 1][n] ;

    return 0 ;
}