#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int arr[Size] , val , n , m ;

struct Node {

    int val ;

    Node* l ;
    Node* r ;

    Node () {

    }

    Node (int Val){
        val = Val ;
        l = nullptr ;
        r = nullptr ;
    }
} ;

struct SegmentTree {

    Node* root = new Node(INT_MIN);

    void build (int l , int r , Node* node) {

        if(l == r){
            node->val = arr[l] ;
            return ;
        }

        node->l = new Node(INT_MIN) ;
        node->r = new Node(INT_MIN) ;

        int mid = (l + r) >> 1 ;

        build(l ,  mid , node->l) ;
        build(mid + 1 , r , node->r) ;

        node->val = max(node->l->val , node->r->val) ;
    }

    void setAndGet (int l , int r , int val , Node* node) {

        if(l == r){
            node->val -= val ;
            cout << l << ' ' ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        if(node->l->val >= val){
            setAndGet(l , mid , val , node->l) ;
        }
        else {
            setAndGet(mid + 1 , r , val , node->r) ;
        }

        node->val = max(node->l->val , node->r->val) ;

    } 

}seg ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    seg.build(1 , n , seg.root) ;

    for(int i = 1 ; i <= m ; i ++ ){
        cin >> val ;
        if(seg.root->val < val)cout << 0 << ' ' ;
        else seg.setAndGet(1 , n , val , seg.root) ;
    }

    return 0 ;
}