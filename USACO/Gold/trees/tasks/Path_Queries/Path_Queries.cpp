#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 2 ;
int n , q , src , dest , idx = 0 , mode , s  ;

long long arr[Size] , x ;

int childs[Size] ;
int indexs[Size] ;

vector<int>adj[Size] ;

void dfs(int node , int par){

    childs[node] = 1 ;
    indexs[node] = ++ idx ;

    for(int next : adj[node]){
        if(next == par)continue; 
        dfs(next , node) ;
        childs[node] += childs[next] ;
    }
    return ; 
}

struct Fenwick {

    long long fw[Size] ;

    void set (int idx , long long val) {
        for(; idx < Size ; idx += (idx & -idx))fw[idx] += val ;
    }

    long long get(int idx){
        long long res = 0 ;
        for(; idx > 0 ; idx -= (idx & -idx))res += fw[idx] ;
        return res ;
    }

}fw;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    for(int i = 1 ; i <= n - 1 ; i ++ ){
        cin >> src >> dest ;
        adj[src].push_back(dest) ;
        adj[dest].push_back(src) ;
    }

    dfs(1 , 0) ;

    for(int i = 1 ; i <= n ;i ++ ){
        fw.set(indexs[i] , arr[i]) ;
        fw.set(indexs[i] + childs[i] , -arr[i]) ;
    }

    while(q -- ){
        cin >> mode ;
        if(mode == 1){
            cin >> s >> x ;

            long long previous_val = arr[s] ;
            arr[s] = x ;

            fw.set(indexs[s] , x - previous_val) ;
            fw.set(indexs[s] + childs[s] , - (x - previous_val)) ;
        }   
        else {
            cin >> s ;
            cout << fw.get(indexs[s]) << '\n' ;
        }
    }

    return 0 ;
}