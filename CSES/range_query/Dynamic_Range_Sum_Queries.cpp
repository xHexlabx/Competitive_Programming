#include<bits/stdc++.h>
 
using namespace std;
 
const int N = 200001 ;
 
int n , q , k , a , b , x , cmd ;
 
long long arr[N] , seg[4 * N], u ;
 
void build(int l , int r , int node){
 
    if(l == r){
        int idx = l ;
        seg[node] = arr[idx] ;
        return ;
    }
 
    int mid = (l + r) / 2 ;
 
    build(l , mid , node * 2) ; build(mid + 1 , r , node * 2 + 1) ;
    seg[node] = seg[node * 2] + seg[node * 2 + 1] ;
}
 
void update(int l , int r , int idx , long long val , int node){
 
    if(l > idx || r < idx)return ;
 
    if(l == r){
        arr[idx] = val ;
        seg[node] = val ;
        return ;
    }
 
    int mid = (l + r) / 2 ;
 
    update(l , mid , idx , val , node * 2) ; 
    update(mid + 1 , r , idx , val , node * 2 + 1) ;
    seg[node] = seg[node * 2] + seg[node * 2 + 1] ;  
}
 
long long query(int l , int r , int curr_l , int curr_r , int node){
 
    if(curr_r < l || curr_l > r)return 0 ;
    if(l <= curr_l && curr_r <= r)return seg[node] ;
 
    int mid = (curr_l + curr_r) / 2 ;
 
    return query(l , r , curr_l , mid , node * 2) + query(l , r , mid + 1 , curr_r , node * 2 + 1) ;
}
 
 
int main(){
 
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
 
    cin >> n >> q ;
    
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }
 
    build(1 , n , 1) ;
 
    while(q -- ){
 
        cin >> cmd ;
 
        if(cmd == 1){
            cin >> k >> u ;
            update(1 , n , k , u , 1) ;
        }
 
        if(cmd == 2){
            cin >> a >> b ;
            cout << query(a , b , 1 , n , 1) << '\n';
        }
    }
 
    return 0 ;
}