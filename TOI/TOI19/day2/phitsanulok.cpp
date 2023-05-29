#include<bits/stdc++.h>

using namespace std;

struct apple {
    int w ;
    array<int , 19>poisons ;
};

struct state {
    
    int w ;
    array<int , 19>poisons ;

    bool operator < (const state & top){
        return top.w < w ;
    };

};

vector<apple>adj[19] ;
vector<apple>apples ;

bool end_node[(1 << 19)] ;
int dis[(1 << 19)] ;

int n , s ;

int main (){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> s ;

    for(int i = 0 ; i < (1 << 19) ; i ++ ){
        dis[i] = INT_MAX ;
    }

    for(int i = 0 ; i < n ; i ++ ){
        
        apple temp ;

        cin >> temp.w ;

        for(int i = 0 ; i < s ; i ++ ){
            cin >> temp.poisons[i] ;
        }

        apples.push_back(temp) ;

        for(int i = 0 ; i < s ; i ++ ){
            if(temp.poisons[i] == 1){
                adj[i].push_back(temp) ;
            }
        }

    }

    
    return 0 ;
}