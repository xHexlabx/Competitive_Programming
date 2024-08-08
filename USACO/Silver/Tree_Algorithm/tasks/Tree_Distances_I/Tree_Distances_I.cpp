#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n , src , dest ;

vector<int>adj[Size] ;

int maxDis [2][Size] , maxDisNode[2][Size] ;

void dfs_1 (int node , int parent) {

    for(int next : adj[node]){
        
        if(next == parent)continue ;

        dfs_1(next , node) ;

        if(maxDis[0][next] + 1 >= maxDis[0][node]){

            maxDisNode[1][node] = maxDisNode[0][node] ;
            maxDis[1][node] = maxDis[0][node] ;

            maxDisNode[0][node] = next ;
            maxDis[0][node] = maxDis[0][next] + 1 ;
        }

        else if (maxDis[0][next] + 1 >= maxDis[1][node]){

            maxDisNode[1][node] = next ;
            maxDis[1][node] = maxDis[0][next] + 1 ;

        }

    }

    return ;
}

void dfs_2(int node , int parent){

    for(int next : adj[node]){

        if(next == parent)continue ;

        if(maxDisNode[0][node] != next){

            int dis = maxDis[0][node] + 1 ;

            if(dis >= maxDis[0][next]){

                maxDis[1][next] = maxDis[0][next] ;
                maxDisNode[1][next] = maxDisNode[0][next] ;

                maxDis[0][next] = dis ;
                maxDisNode[0][next] = node ;

            }

            else if(dis >= maxDis[1][next]){

                maxDis[1][next] = dis ;
                maxDisNode[1][next] = node ;

            }

        }
        else if (maxDisNode[1][node] != next){

            int dis = maxDis[1][node] + 1 ;

            if(dis >= maxDis[0][next]){

                maxDis[1][next] = maxDis[0][next] ;
                maxDisNode[1][next] = maxDisNode[0][next] ;

                maxDis[0][next] = dis ;
                maxDisNode[0][next] = node ;

            }

            else if(dis >= maxDis[1][next]){

                maxDis[1][next] = dis ;
                maxDisNode[1][next] = node ;

            }

        }

        dfs_2(next , node) ;
    }

    return ;

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n - 1 ; i ++ ){

        cin >> src >> dest ;

        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;

    }

    dfs_1(1 , -1) ;

    dfs_2(1 , -1) ;

    for(int i = 1; i <= n ; i ++ ){
        cout << maxDis[0][i] << ' ' ; ;
    }

    return 0 ;
}