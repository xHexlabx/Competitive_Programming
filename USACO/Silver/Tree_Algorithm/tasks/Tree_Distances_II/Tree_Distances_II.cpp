#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

vector<int>adj[Size] ;

int n , src , dest ;

long long dis [Size] , child [Size] ;

void dfs_1 (int node , int parent) {

    child[node] ++ ;

    for(int next : adj[node]){

        if(next == parent) continue ; 

        dfs_1(next , node) ;

        child[node] += child[next] ;
        dis[node] += child[next] + dis[next] ;
    }

    return ;
}

void dfs_2(int node , int parent){

    for(int next : adj[node]){

        if(next == parent)continue ;

        dis[next] = dis[node] + child[1] - 2 * child[next] ;

        dfs_2(next , node) ; 
    }

    return ;
}
int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n - 1 ;  i ++ ){

        cin >> src >> dest ;

        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;

    }

    dfs_1(1 , -1) ;
    dfs_2(1, - 1) ;

    for(int i = 1 ; i <= n ; i ++ ){
        cout << dis[i] << ' ' ;
    }

    return 0 ;
}