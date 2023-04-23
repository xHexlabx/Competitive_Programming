#include<bits/stdc++.h>

using namespace std;

struct edge {
    int v , w ;
};

struct state {
    int u , w ;
    bool operator < (const state & rhs)const { 
        return rhs.w < w ;
    }
};

vector<edge>adj[20001] ;
vector<int>adj2[20001] ;

int n , m , k , p , x , y , w , cnt = 0 ;

int gecko[20001] , dis[20001] ;

priority_queue<state>pq ;

vector<pair<int , int>>node_pair ;

bool visited[20001] ;
bool visited2[20001] ;

void dfs(int node){

    for(auto i : adj[node]){
        
        int now_node = i.v ;
        int now_weight = dis[node] - i.w ;

        if(now_weight == dis[now_node]){
            

            if(visited[now_node]){
                cnt ++ ;
                node_pair.push_back({node , now_node}) ;
            }
            else {
                
                cnt ++ ;
                visited[now_node] = true ;
                node_pair.push_back({node , now_node}) ;
                dfs(now_node) ;

            }
        }
    }

}

void topological(int current){

    sort(adj2[current].begin() , adj2[current].end()) ;
    
    for(auto i : adj2[current]){

        if(visited2[i])continue;
        visited2[i] = true ;
        topological(i) ;
        cout << min(current , i) << ' ' << max(current , i) << '\n' ;

    }
}

int main(){

    ios_base :: sync_with_stdio(0) ,  cin.tie(0) ;

    cin >> n >> m >> k >> p ;

    for(int i = 0 ; i < k ; i ++ )cin >> gecko[i] ;

    for(int i = 0 ; i < m ; i ++ ){

        cin >> x >> y >> w ;

        adj[x].push_back({y , w}) ;
        adj[y].push_back({x , w}) ;

    }

    for(int i = 0 ; i <= 20000 ; i ++ ){
        dis[i] = INT_MAX ;
    }

    dis[p] = 0 ;
    pq.push({p , 0}) ;

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        int node = temp.u ;
        int weight = temp.w ;

        for(auto i : adj[node]){

            int now_node = i.v , now_weight = weight + i.w ;

            if(now_weight < dis[now_node]){
                dis[now_node] = now_weight ;
                pq.push({now_node , now_weight}) ;
            } 

        }
    }

    for(int i = 0 ; i < k ; i ++ ){
        cout << dis[gecko[i]] << ' ' ;
    }

    for(int i = 0 ; i < k ; i ++ ){
        int node = gecko[i] ;
        if(visited[node])continue ;
        visited[node] = true ;
        dfs(node) ;
    }

    cout << '\n' << cnt << '\n';


    for(auto i : node_pair){
        int x = i.first , y = i.second ;
        // cout << x << ' ' << y << '\n' ;
        adj2[x].push_back(y) ;
        adj2[y].push_back(x) ;

    }

    visited2[p] = true ;
    topological(p) ;
    
    return  0 ;
}