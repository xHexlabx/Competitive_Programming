#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

long long arr[Size] ;
struct Node {
    
    long long sum , prefix ;

    Node () {

    }

    Node (long long Sum , long long Prefix) {
        sum = Sum ;
        prefix = max(0LL , Prefix) ;
    } 

    Node operator + (Node rhs) {
        return Node(sum + rhs.sum , max(prefix , sum + rhs.prefix)) ;
    }
};

struct SegmentTree {

    Node seg[4 * Size] ;

    void build (int l , int r , int node){
        
        if(l == r){
            seg[node] = Node(arr[l] , arr[l]) ;
            return ;
        }
        
        int mid = (l + r) >> 1 ;

        build(l , mid , node * 2) ;
        build(mid + 1 , r , node * 2 + 1) ;

        seg[node] = seg[node * 2] + seg[node * 2 + 1] ;

        return ; 
    }

    void set (int l , int r , int idx , long long val , int node){

        if(r < idx || l > idx)return ;

        if(l == r){
            seg[node] = Node(val , val) ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        set(l , mid , idx , val , node * 2) ;
        set(mid + 1 , r , idx , val , node * 2 + 1) ;

        seg[node] = seg[node * 2] + seg[node * 2 + 1] ;

        return ;
    }

    Node get (int ql , int qr , int l , int r , int node){

        if(r < ql || l > qr)return Node(0 , 0) ;
        if(ql <= l && r <= qr)return seg[node] ;

        int mid = (l + r) >> 1 ;
        return get(ql , qr , l , mid , node * 2) + get(ql , qr , mid + 1 , r , node * 2 + 1) ;
    }
}seg;

int n , q , mode , k , a , b ;
long long u ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ )cin >> arr[i] ;

    seg.build(1 , n , 1) ;

    while (q --)
    {
        cin >> mode ;

        if(mode == 1){
            cin >> k >> u ;
            arr[k] = u ;
            seg.set(1 , n , k , u , 1) ;
        }
        else {
            cin >> a >> b ;
            cout << seg.get(a , b , 1 , n , 1).prefix << '\n' ;
        }
    }
    
    return 0 ;
}