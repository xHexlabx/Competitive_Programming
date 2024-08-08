#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e5 + 1 ;
int n , m , u , v ;

vector<int>adj[2][Size] ;

bool visited[2][Size] ;

void dfs(int node , bool reverse){

    for(int next : adj[reverse][node]){
        if(!visited[reverse][next]){
            visited[reverse][next] = true ;
            dfs(next , reverse) ;
        }
    }

    return ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v ;
        adj[0][u].push_back(v) ;
        adj[1][v].push_back(u) ;
    }

    visited[0][1] = true;
    dfs(1 , 0) ;

    for(int i = 2 ; i <= n ; i ++ ){
        if(!visited[0][i]){
            cout << "NO" << '\n' ;
            cout << 1 << ' ' << i ;
            return 0 ;
        }
    }

    visited[1][1] = true ;
    dfs(1 , 1) ;

    for(int i = 2 ; i <= n ; i ++ ){
        if(!visited[1][i]){
            cout << "NO" << '\n' ;
            cout << i << ' ' << 1 ;
            return 0 ;
        }
    }

    cout << "YES" ;

    return 0 ;
}