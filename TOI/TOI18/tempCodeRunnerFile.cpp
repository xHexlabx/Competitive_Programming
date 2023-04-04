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

vector<edge>adj[20001] ;
vector<long long>adj2[20001] ;

map<pair<int , int>, int>dis_node;

long long n , m , k , p , x , y , w , cnt = 0 ;

long long gecko[20001] , dis[20001] ;

priority_queue<state>pq ;

vector<pair<int , int>>node_pair ;

bool visited[20001] ;

int main(){

    ios_base :: sync_with_stdio(0) ,  cin.tie(0) ;

    cin >> n >> m >> k >> p ;

    cnt = m ;

    for(int i = 0 ; i < k ; i ++ ){
        cin >> gecko[i] ;
    }

    for(int i = 0 ; i < m ; i ++ ){

        cin >> x >> y >> w ;

        adj[x].push_back({y , w}) ;
        adj[y].push_back({x , w}) ;

        node_pair.push_back({x , y}) ;
        dis_node[{x , y}] = w ;
        dis_node[{y , x}] = w ;
    }

    for(int i = 0 ; i <= 20000 ; i ++ ){
        dis[i] = LLONG_MAX ;
    }

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
                dis[now_node] = now_weight ;
                pq.push({now_node , now_weight}) ;
            } 

        }
    }

    for(int i = 0 ; i < k ; i ++ ){
        cout << dis[gecko[i]] << ' ' ;
    }
                                                      
    for(auto i : node_pair){
        int x = i.first , y = i.second ;
        if( (dis_node[{x , y}] == abs(dis[x] - dis[y])) || dis[x] == INT_MAX || dis[y] == INT_MAX ){
            cnt ++ ;
        }
    }

    cout << '\n' << cnt << '\n';

    for(auto i : node_pair){
        int x = i.first , y = i.second ;
        if( (dis_node[{x , y}] == abs(dis[x] - dis[y])) || dis[x] == INT_MAX || dis[y] == INT_MAX ){
            cout << min(x,y) << ' ' << max(x,y) << '\n' ;
        }
    }
    return  0 ;
}