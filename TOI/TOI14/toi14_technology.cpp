#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001] ;
vector<int>level[10001] ;
int visited[100001] ;
int n , k , t , e , node_level , v , nowt = 0 , ans = -1 ;
void dfs(int now){
    visited[now] = 1 ;
    for(auto i : graph[now]){
        if(visited[i] == 1){
            nowt = t + 1 ;
            return ;
        }
        if(visited[i] == 0){
            dfs(i) ;
        }
    }
    visited[now] = 2 ;
    nowt ++ ;
    if(nowt > t)return ;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> k >> t ;
    for(int i = 1 ; i <= n ; i ++ ){
        
        cin >> node_level >> e ;
        level[node_level].push_back(i) ;
        while(e -- ){
            cin >> v ;
            graph[i].push_back(v) ;
        }
    }
    for(int i = 1 ; i <= k ; i ++ ){
        for(auto j : level[i]){
            if(!visited[j]){
                dfs(j) ;
            }
        }
        if(nowt > t)break ;
        ans = i ;
    }
    cout << ans ;
    return 0 ;
}