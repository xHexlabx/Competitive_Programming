#include<bits/stdc++.h>
using namespace std;
int start ;
struct path {
    int v , w ;
};
vector<path>graph[80001] ;
bitset<80001>visited ;
long long dis[80001] ;
int idx = 0 ;
int n , x , y , w ;
void dfs(int now){
    visited[now] = true ;
    for(auto i : graph[now]){
        if(!visited[i.v]){
            dis[++idx] = i.w;
            dfs(i.v) ;
        }
    }
    return ;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> x >> y >> w ;
        graph[x].push_back({y , w}) ;
        graph[y].push_back({x , w}) ; 
    }
    for(int i = 0 ; i < n ; i ++ ){
        if(graph[i].size() == 1){
            start = i ;
            break ;
        }
    }
    dfs(start) ;
    
    long long l = 0 , r = 2e9 , mid ;
    long long sum , cnt ;
    while(l < r){
        cnt = 0 ;
        sum = 0 ;
        mid = (l + r + 1) >> 1 ;
        for(int i = 1 ; i <= n ; i ++ ){
            sum += dis[i] ;
            if(sum >= mid){
                cnt ++ ;
                sum = 0 ;
            }
        }
        if(cnt >= 3)l = mid ;
        else r = mid - 1 ;
    }
    cout << l ;
    return 0 ;
}