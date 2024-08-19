#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;
int n , q , src , dest , x , y ;

int levels[Size] ;
int distances[Size] ;
int parents[Size][20] ;

vector<int>adj[Size] ;

void dfs(int node , int par){

    levels[node] = levels[par] + 1 ;
    distances[node] = distances[par] + 1 ;
    parents[node][0] = par ;

    for(int i = 1 ; i <= 18 ; i ++){
        parents[node][i] = parents[parents[node][i - 1]][i - 1] ;
    }

    for(int next : adj[node]){
        if(next == par)continue ;
        dfs(next , node) ;
    }

    return ;
}

int lca(int x , int y){

    if(levels[x] < levels[y])swap(x , y) ;

    int diff_level = levels[x] - levels[y] ;

    int stride = (1 << 18) ;

    for(int i = 18 ; i >= 0 ; i -- ){

        if(stride <= diff_level){
            x = parents[x][i] ;
            diff_level -= stride ;
        }

        stride >>= 1 ;
    }

    if(x == y)return x ;

    for(int i = 18 ; i >= 0 ; i -- ){
        if(parents[x][i] != parents[y][i]){
            x = parents[x][i] ;
            y = parents[y][i] ;
        }
    }

    return parents[x][0] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n - 1 ; i ++ ){
        cin >> src >> dest ;
        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;
    }

    distances[0] = -1 ;

    dfs(1 , 0) ;
    
    while(q -- ){
        cin >> x >> y ;
        cout << distances[x] + distances[y] - 2 * distances[lca(x , y)] << '\n' ;
    }

    return 0 ;
}