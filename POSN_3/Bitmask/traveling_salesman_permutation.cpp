#include<bits/stdc++.h>

using namespace std;

const int N = 6 ;
const int INF = 1000000;
 
int dist [N + 1][N + 1] = { 
   { 0 , 0 , 0 , 0 , 0 , 0 , 0} ,
   { 0 , 0   , 5  , 6   , INF , INF , INF } ,
   { 0 , 5   , 0  , 9   , 10  , 4   , 7} ,
   { 0 , 6   , 9  , 0   , 4   , 2   , INF} , 
   { 0 , INF , 10 , 4   , 0   , 7   , 3} ,
   { 0 , INF , 4  , 2   , 7   , 0   , INF} , 
   { 0 , INF , 7  , INF , 3   , INF , 0}

};

bool visited [N + 1] ; 

int ans = INF;

void solve(int node , int sum , int cnt){

    if(cnt == N){
        ans = min(ans , sum + dist[node][1]) ;
    }
    else {

        for(int i = 2 ; i <= N ; i ++ ){
            if(visited[i])continue ;

            visited[i] = true ;
            solve(i , sum + dist[node][i] , cnt + 1) ;
            visited[i] = false ;

        }
    }
}

int main(){

    solve(1 , 0 , 1) ;

    printf("The cost of most efficient tour = %d", ans);

    return 0 ;
}