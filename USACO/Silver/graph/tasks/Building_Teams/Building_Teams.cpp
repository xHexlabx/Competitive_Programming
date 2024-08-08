#include<bits/stdc++.h>

using namespace std ;

const int Size = 1e5 + 1 ;

int n , m , u , v ;

vector<int>adj[Size] ;
int visited[Size] ;
bool check = true ;

bool is_possible(){
    return check ;
}

void dfs(int node , int currentTeam){

    if(!is_possible())return ;

    if(!visited[node])visited[node] = currentTeam ;

    for(int next : adj[node]){

        if (visited[next] && visited[next] == currentTeam){
            check = false ;
            break ;
        }
        else if (visited[next]){
            continue ;
        }
        else {

            int nextTeam ;

            if(currentTeam == 1){
                nextTeam = 2 ;
            }
            else {
                nextTeam = 1 ;
            }

            dfs(next , nextTeam) ;
        }
    }

    return ;

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> u >> v ;
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }

    for(int i = 1 ; i <= n ; i ++ ){

        if (!visited[i]) dfs(i , 1) ;

        if (!is_possible()){
            cout << "IMPOSSIBLE" ;
            return 0 ;
        }

    }

    for(int i = 1 ; i <= n ; i ++ ){
        cout << visited[i] << ' ' ;
    }

    return 0 ;

}