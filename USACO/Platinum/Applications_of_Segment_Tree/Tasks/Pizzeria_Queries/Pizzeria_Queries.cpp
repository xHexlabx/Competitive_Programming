#include<bits/stdc++.h>

using namespace std ;

int n , q , k , mode ;

const int Size = 2e5 + 1 ;

long long arr[Size] , x ;

struct Node {

    long long val ;

    Node* l ;
    Node* r ;

    Node () {

    }

    Node(int Val){
        val = Val ;
        l = nullptr ;
        r = nullptr ;
    }
};


struct SegmentTree {

    Node* root = new Node(INT_MAX);

    void build (int l , int r , Node* node){

        if(l == r){
            node->val = arr[l] ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        node->l = new Node(INT_MAX) ;
        node->r = new Node(INT_MAX) ;

        build(l , mid , node->l) ;
        build(mid + 1 , r , node->r) ;

        node->val = min(node->l->val , node->r->val) ;
        return ;
    }

    void set(int l , int r , int idx , long long val , Node* node){
        
        if(l > idx || r < idx)return ;

        if(l == r){
            node->val = val ;
            return ;
        }

        int mid = (l + r) >> 1 ;

        set(l , mid , idx , val , node->l) ;
        set(mid + 1 , r , idx , val , node->r) ;

        node->val = min(node->l->val , node->r->val) ;
        return ;
    }

    long long get(int ql , int qr , int l , int r , Node* node){
        
        if(l > qr || r < ql)return INT_MAX ;
        if(l >= ql && r <= qr)return node->val ;

        int mid = (l + r) >> 1 ;
        return min(get(ql , qr , l , mid , node->l) , get(ql , qr , mid + 1 , r , node->r)) ;
    }

}leftSeg , rightSeg;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ )cin >> arr[i] ;
    
    leftSeg.build(1 , n , leftSeg.root) ;
    rightSeg.build(1 , n , rightSeg.root) ;

    for(int i = 1 ; i <= n ; i ++ ){
        leftSeg.set(1 , n , i , arr[i] - i , leftSeg.root) ;
        rightSeg.set(1 , n , i , arr[i] + i , rightSeg.root) ;
    }

    while(q -- ){
        
        cin >> mode ; 

        if(mode == 1){
            cin >> k >> x ;
            arr[k] = x ;
            leftSeg.set(1 , n , k , arr[k] - k , leftSeg.root) ;
            rightSeg.set(1 , n , k , arr[k] + k , rightSeg.root) ;
        }
        else {
            cin >> k ;
            cout << min(leftSeg.get(1 , k , 1 , n , leftSeg.root) + k , rightSeg.get(k + 1 , n , 1 , n , rightSeg.root) - k) << '\n' ;
        }

    }

    return 0 ;
}