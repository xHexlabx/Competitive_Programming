#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int arr[Size] ;
int n , q , mode , k , u , a , b ;

struct Node {

    int val ;

    Node* l ;
    Node* r ;

    Node (int Val){
        val = Val ;
        l = nullptr ;
        r = nullptr ;
    }

};

struct SegmentTree {

    Node* root = new Node(INT_MAX) ;

    void build (int l , int r , Node* node) {

        if(l == r){
            node->val = arr[l] ;
            return ;
        }

        node->l = new Node(INT_MAX) ;
        node->r = new Node(INT_MAX) ;

        int mid = (l + r) >> 1 ;

        build(l , mid , node->l) ;
        build(mid + 1 , r , node->r) ;

        node->val = min(node->l->val , node->r->val) ;
    }

    void set (int l , int r , int idx , int val , Node* node) {

        if (idx < l || idx > r)return ;

        if(l == r){
            node->val = val ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        set(l , mid , idx , val , node->l) ;
        set(mid + 1 , r , idx , val , node->r) ;

        node->val = min(node->l->val , node->r->val);
    }

    int get (int ql , int qr , int l , int r , Node* node) {

        if(r < ql || l > qr)return INT_MAX ;
        if(l >= ql && r <= qr)return node->val ;

        int mid = (l + r) >> 1 ;

        return min(get(ql , qr , l , mid , node->l) , get(ql , qr, mid + 1 , r , node->r));
    }

}seg;



int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

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