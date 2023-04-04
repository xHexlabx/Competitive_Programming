#include<bits/stdc++.h>

using namespace std;

struct edge {
    long long v , w ;
};

struct state {
    long long u , w ;
    bool operator < (const state & rhs)const { 
        return rhs.w < w ;
    }
};

struct pairnodelevel{
    int x , y , level ;
    bool operator < (const pairnodelevel & rhs)const {
        return level  < rhs.level ;
    }
};

vector<edge>adj[20001] ;
vector<int>adj2[20001] ;

map<pair<int , int>, int>edge_level ;

long long n , m , k , p , x , y , w , cnt = 0 ;

long long dis[20001] ;

priority_queue<state>pq ;

vector<pairnodelevel>node_pair ;

int gecko[20001] , parent[20001] ;

int main(){

    ios_base :: sync_with_stdio(0) ,  cin.tie(0) ;

    //input
    cin >> n >> m >> k >> p ;

    for(int i = 0 ; i < k ; i ++ ){
        cin >> gecko[i] ;
    }

    for(int i = 0 ; i < m ; i ++ ){

        cin >> x >> y >> w ;

        adj[x].push_back({y , w}) ;
        adj[y].push_back({x , w}) ;

    }
    //INF set
    for(int i = 0 ; i <= 20000 ; i ++ ){
        dis[i] = LLONG_MAX ;
    }

    //sssp

    dis[p] = 0 ;
    pq.push({p , 0}) ;

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        long long node = temp.u ;
        long long weight = temp.w ;

        for(auto i : adj[node]){

            long long now_node = i.v , now_weight = weight + i.w ;

            if(now_weight < dis[now_node]){
                parent[now_node] = node ;
                dis[now_node] = now_weight ;
                pq.push({now_node , now_weight}) ;
            } 

        }
    }

    for(int i = 0 ; i < k ; i ++ ){

        int node = gecko[i] ;
        int level = 1 ;

        while(node != p){

            if(level > edge_level[{node , parent[node]}]){
                edge_level[{node , parent[node]}] = level ++ ;
            }
            else {
                break ;
            }

            node = parent[node] ;
        }

    }
                                                      
    for(auto i : edge_level){
        node_pair.push_back({i.first.first , i.first.second , i.second}) ;
    }

    sort(node_pair.begin() , node_pair.end()) ;

    for(int i = 0 ; i < k ; i ++ ){
        cout << dis[gecko[i]] << ' ' ;
    }

    cout << '\n' << node_pair.size() << '\n' ;

    for(auto i : node_pair){
        cout << min(i.x  , i.y) << ' ' << max(i.x , i.y) << '\n' ;
    }

    return  0 ;
}