#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

vector<int>adj[Size] ;
int dis[2][Size] , maxDis[2] , maxDisNode[2] ;
bool visited[2][Size] ;

int src , dest ; 

void dfs(int node , int parent , int round){

    for(int next : adj[node]){

        if(!visited[round][next] && next != parent){

            visited[round][next] = true ;
            dis[round][next] = dis[round][node] + 1 ;
            
            if(dis[round][next] > maxDis[round]){
                maxDis[round] = dis[round][next] ;
                maxDisNode[round] = next ;
            }

            dfs(next , node , round) ;
        }

    }

    return ;
}

int n ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n - 1; i ++ ){
        cin >> src >> dest ;
        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;
    }

    visited[0][1] = true ;
    dfs(1 , -1 , 0) ;

    visited[1][maxDisNode[0]] = true ;
    dfs(maxDisNode[0] , -1 , 1) ;

    cout << maxDis[1] ;

    return 0 ;
}