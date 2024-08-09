#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int ti = 0 , n ;

int disc[Size] , lengths[Size] , dest ;
bool on_stack[Size] ;
stack<int>st ;

int adj[Size] ;

void dfs(int node){

    disc[node] = ++ ti ;
    on_stack[node] = true ;
    st.push(node) ;

    int next = adj[node] ;

    if(next == 0){

    }
    
    else if (on_stack[next]){

        int length = disc[node] - disc[next] + 1;
        
        while(st.top() != next){
            lengths[st.top()] = length ;
            on_stack[st.top()] = false ;
            st.pop() ;
        }

        lengths[st.top()] = length ;
        on_stack[st.top()] = false ;
        st.pop() ;

        return ;

    }
    else if (disc[next]) {

        int length = lengths[next] + 1 ;
        lengths[node] = length ;

        on_stack[st.top()] = false ;
        st.pop() ;

        return ;
    }
    else {

        dfs(next) ;

    }

    int length = lengths[next] + 1 ;
    lengths[node] = length ;

    if(st.top() == node){
        on_stack[st.top()] = false ;
        st.pop() ;
    }

    return ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> dest ;
        adj[i] = dest ;

    }

    for(int i = 1 ; i <= n ; i ++ ){

        if(!disc[i]){
            dfs(i) ;
        }
    }

    for(int i = 1 ; i <= n ; i ++ ){
        cout << lengths[i] << ' ' ;
    }

    return 0 ;
}