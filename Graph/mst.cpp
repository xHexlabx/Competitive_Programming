#include<bits/stdc++.h>

using namespace std;

const int N = 1e4 ;

struct coordinate {

    long long x , y ;

    coordinate(){}

};

long long dis[N] , res = 0 ;
bool visited[N] ;

coordinate nodes[N] ;

long long distance(coordinate a , coordinate b){
    return abs(a.x - b.x) + abs(a.y - b.y) ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    int n ; cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        dis[i] = LLONG_MAX ;
        cin >> nodes[i].x >> nodes[i].y ;
    }

    dis[0] = 0 ;

    int currentNode = 0 , nextNode ;
    long long MIN ;
    visited[0] = true ;

    for(int i = 1 ; i <= n - 1 ; i ++ ){

        MIN = LLONG_MAX ;

        for(int j = 0 ; j < n ; j ++ ){

            if(visited[j])continue ;
            dis[j] = min(dis[j], distance(nodes[j], nodes[currentNode])) ;
            if(MIN > dis[j]){
                MIN = dis[j];
                nextNode = j ;
            }
        }

        visited[nextNode] = true ;
        res += MIN ;
        currentNode = nextNode ;
    }

    cout << res ;

    return 0 ;
}