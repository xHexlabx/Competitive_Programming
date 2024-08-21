#include<bits/stdc++.h>

using namespace std ;

struct Node {

    long long sum , prefix ;

    Node* l = nullptr ;
    Node* r = nullptr ;

    Node (int Val) {
        sum = Val ;
        prefix = 0 ;
    }
};

void merge(Node* node){

    node->sum = node->l->sum + node->r->sum ;
    node->prefix = max(node->l->sum + node->r->prefix , node->l->prefix) ;

    return ;
};

void setNode(Node* node , long long val){
    node->sum = val ;
    long long x = 0 ;
    node->prefix = max(x , val) ;
    return ;
}

const int Size = 2e5 + 1 ;
long long arr[Size] ;

struct SegmentTree {

    Node* root = new Node(0);

    void build(int l , int r , Node* node){

        if(l == r){
            setNode(node , arr[l]) ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        node->l = new Node(0) ;
        node->r = new Node(0) ;

        build(l , mid , node->l) ;
        build(mid + 1 , r , node->r) ;

        merge(node) ;

    }

    void set(int l , int r , int idx , long long val , Node* node){

        if(r < idx || l > idx)return ;

        if(l == r){
            setNode(node , val) ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        set(l , mid , idx , val , node->l) ;
        set(mid + 1 , r , idx , val , node->r) ;

        merge(node);

    }

    long long get(int ql , int qr , int l , int r , Node* node){
        
        if(r < ql || l > qr)return 0 ;
        if(l >= ql && r <= qr)return node->prefix ;

        int mid = (l + r) >> 1 ;
        return get(ql , qr , l , mid , node->l) + get(ql , qr , mid + 1 , r , node->r) ;
    }

}seg;

int n , q , mode , k , u , a , b;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    seg.build(1 , n , seg.root) ;

    while(q -- ){

        cin >> mode ;

        if(mode == 1){
            cin >> k >> u ;
            seg.set(1 , n , k , u , seg.root) ;
        }
        else {
            cin >> a >> b ;
            cout << seg.get(a , b , 1 , n , seg.root) << '\n' ;
        }
    }

    return 0 ;
}