#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e5 + 1 ;

int n , m , u , v , grp = 0 ;

int group[Size];

bool visited[Size] ;

vector<int>adj[Size] ;

void dfs(int node){

    visited[node] = true ;

    for(int next : adj[node]){
        if (!visited[next]){
            dfs(next) ;
        }
    }

    return ;
}

int main () {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    for(int i = 1 ; i <= n ; i ++ ){

        if(!visited[i]){
            group[grp ++] = i ;
            dfs(i) ;
        }
    }

    cout << grp - 1 << '\n' ;

    for(int i = 0 ; i < grp - 1; i ++ ){
        cout << group[i] << ' ' << group[i + 1] << '\n' ;
    }

    return 0 ;
}