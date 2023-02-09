#include<bits/stdc++.h>
using namespace std;
const int N = 200001 ;
vector<int>graph[N] ;
int visited[N] , low[N] , forb[N] , ti = 1 ;
pair<int ,int>gems[N] ;
bool instack[N] ;
stack<int>st ;
void dfs(int now){
    visited[now] = low[now] = ti ++ ;
    st.push(now);
    instack[now] = true ;
    for(auto i : graph[now]){
        if(!visited[i]){
            dfs(i) ;
            low[now] = min(low[now] , low[i]);
        }
        else if(instack[i]){
            low[now] = min(low[now] , low[i]);
        }
    }
    if(visited[now] == low[now]){
        while(st.top() != now){
            instack[st.top()] = false ;
            st.pop();
        }
        instack[st.top()] = false;
        st.pop() ;
    }
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n , m , t = 5 ;
    
    while(t -- ){
        memset(visited,0,sizeof(visited)) ;
        for(int i = 1 ; i <= 200000 ; i ++ ){
            graph[i].clear();
        }
        cin >> n >> m ; 
        
        for(int i = 1 ; i <= n ; i ++ ){
            cin >> gems[i].first >> gems[i].second ;
        }
        for(int i = 0 ; i < m / 2 ; i ++ ){
            int a , b ; cin >> a >> b ;
            forb[a] = b ; 
            forb[b] = a ;
        }
        for(int i = 1 ; i <= n ; i ++ ){
            graph[forb [gems[i].first ] ].emplace_back(gems[i].second) ;
            graph[forb [gems[i].second] ].emplace_back(gems[i].first) ;
        }
        bool is_valid = true ;
        for(int i = 1 ; i <= m ; i ++ ){
            if(!visited[i])dfs(i) ;
        }
        for(int i = 1 ; i <= m ; i ++ ){
            if(low[i] == low[forb[i]]){
                is_valid = false ;
                break ;
            }
        }
        (is_valid) ? cout << "Y" : cout << "N" ;
    }
    return 0 ;
}