#include<bits/stdc++.h>

using namespace std;

struct transport_vehicle {
    int node , cost , fuel ;
    bool ticket ; //ticket = 1 -> used

    bool operator < (const transport_vehicle & rhs) const {
        return rhs.cost < cost ;
    }
};

struct path {
    int dest , w ;
};

int n , m , s , d , f , a , b , w ;

int visited[101][101][2] ;
int fuel_cost[101] ;
vector<path>adj[101] ;
priority_queue<transport_vehicle>pq ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    for(int i = 0 ; i <= 100 ; i ++ ){
        for(int j = 0 ; j <= 100 ; j ++ ){
            for(int k = 0 ; k <= 1 ; k ++ ){
                visited[i][j][k] = INT_MAX ;
            }
        }
    }
    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> fuel_cost[i] ;
    }

    cin >> s >> d >> f ;

    cin >> m ;

    for(int i = 1 ; i <= m ; i ++ ){
        cin >> a >> b >> w ;

        adj[a].push_back({b , w});
        adj[b].push_back({a , w});

    }

    visited[s][0][0] = 0 ;
    pq.push({s , 0 , 0 , 0}) ;

    while(!pq.empty()){

        auto temp = pq.top() ;
        pq.pop() ;

        if(temp.node == d && temp.fuel == f){
            cout << temp.cost ;
            return 0 ;
        }

        if(temp.ticket == false && temp.cost < visited[temp.node][f][1]){
            visited[temp.node][f][1] = temp.cost ;
            pq.push({temp.node , temp.cost , f  , 1}) ;
        }

        for(int i = 1 ; temp.fuel + i <= f ; i ++ ){
            if(temp.cost + i * fuel_cost[temp.node] < visited[temp.node][temp.fuel + i][temp.ticket]){
                visited[temp.node][temp.fuel + i][temp.ticket] = temp.cost + i * fuel_cost[temp.node] ;
                pq.push({temp.node , temp.cost + i * fuel_cost[temp.node], temp.fuel + i , temp.ticket}) ;
            }
        }

        for(auto i : adj[temp.node]){
            if(temp.fuel - i.w >= 0 && temp.cost < visited[i.dest][temp.fuel - i.w][temp.ticket]){
                visited[i.dest][temp.fuel - i.w][temp.ticket] = temp.cost ;
                pq.push({i.dest , temp.cost , temp.fuel - i.w , temp.ticket}) ;
            }
        }

    }


    return 0 ;
}