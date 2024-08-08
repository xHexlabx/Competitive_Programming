#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n , par ;
int dp[Size];
bool visited[Size] ;

vector<int>adj[Size] ;

void dfs(int node){

    for(int next : adj[node]){

        if(!visited[next]){
            visited[next] = true ;
            dfs(next) ;
            dp[node] += dp[next] + 1 ;
        }
    }
    return ; 
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int child = 2 ; child <= n ; child ++ ){    
        cin >> par ;
        adj[par].push_back(child) ;
    }

    dfs(1) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cout << dp[i] << ' ' ;
    }

    return 0 ;
}