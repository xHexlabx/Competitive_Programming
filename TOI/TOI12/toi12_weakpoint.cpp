#include<bits/stdc++.h>
using namespace std;
int m , k , x , y , cnt_ans , node_ans , ti = 1 ;
int visited[500001] , low[500001] , cnt[500001];
vector<int>graph[500001] ;
void dfs(int now , int pa){
    
    visited[now] = low[now] = ti ++ ;
    for(auto i : graph[now]){
        if(!visited[i]){
            dfs(i , now) ;
            low[now] = min(low[now] , low[i]) ;
            if(low[i] != 1){
                cnt[now] += cnt[i] + 1 ;
            }
        }
        else if(i != pa){
            low[now] = min(low[now] , low[i]) ;
        }
    }
    if(now != k ){
        if(cnt[now] > cnt_ans){
            node_ans = now ;
            cnt_ans = cnt[now] ;
        }
        if(cnt[now] == cnt_ans && now < node_ans){
            node_ans = now ;
        }
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> m >> k ;
    
    for(int i = 0 ; i < m ; i ++ ){
        cin >> x >> y ;
        graph[x].push_back(y) ;
        graph[y].push_back(x) ;
    }
    dfs(k , -1);
    cout << node_ans << '\n' << cnt_ans ;
    return 0 ;
}