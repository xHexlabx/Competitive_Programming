#include<bits/stdc++.h>

using namespace std;

struct edge {
    int v , w ;
};

struct state {
    
    int v , w ;

    bool operator < (const state & top)const {
        return top.w < w ;
    }
};

vector<edge>adj[(1 << 19) + 90001] ;

int dis[(1 << 19) + 90001] ;

int n , s , MAX = 0;

int main (){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> s ;

    for(int i = 0 ; i < (1 << 19) + n ; i ++ ){
        dis[i] = INT_MAX ;
    }

    for(int mask = 0 ; mask < (1 << 19) ; mask ++ ){

        for(int i = 0 ; i < s ; i ++ ){

            int bit = (1 << i) ;
            
            if(mask & bit){
                adj[mask + n].push_back({(mask ^ bit) + n , 0}) ;
            }

        }

    }

    priority_queue<state>pq ;

    for(int i = 0 ; i < n ; i ++ ){

        int weight , src = 0 , dest = 0 , bit ;

        cin >> weight ;

        for(int j = 0 ; j < s ; j ++ ){

            cin >> bit ;

            if(bit == -1){
                src |= (1 << j) ;
            }

            if(bit == 1){
                dest |= (1 << j) ;
            }

        }

        adj[src + n].push_back({dest + n , weight}) ;
        adj[src + n].push_back({i , 0}) ;

    }

    dis[n] = 0 ;

    pq.push({n , 0}) ;

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        int v = temp.v ;
        int w = temp.w ;

        for(auto i : adj[v]){

            int curr_v = i.v ;
            int curr_w = w + i.w ;

            if(curr_w < dis[curr_v]){
                
                dis[curr_v] = curr_w ;
                pq.push({curr_v , curr_w}) ;

            }
        }
    }

    for(int i = 0 ; i < n ; i ++ ){
        if(dis[i] != INT_MAX)MAX = max(MAX , dis[i]);
    }

    cout << MAX ;

    return 0 ;
}