#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 2e5 + 1 ;

array <long long , MAX_N> arr ;

class Node {

    public :

        long long sum , prefix ;

        Node* l ;
        Node* r ;

        Node (long long Sum , long long Prefix) {
            sum = Sum ;
            prefix = Prefix ;

            l = nullptr ;
            r = nullptr ;
        }
};


class Segment {

    public :
        
        void build (int l , int r , Node* node) {

            if(l == r){
                node -> sum = arr[l] ;
                node -> prefix = arr[l] ;

                
                return ;
            }

            int mid = (l + r) >> 1 ;

            node -> l = new Node(0 , 0) ;
            node -> r = new Node(0 , 0) ;

            build(l , mid , node -> l) ;
            build(mid + 1 , r , node -> r) ;

            node -> sum = node -> l -> sum + node -> r -> sum ;
            node -> prefix = max(node -> l -> prefix , node -> l -> sum + node -> r -> prefix ) ;
        }

        void update(int l , int r , int idx , int val , Node* node){

            if(l > idx || r < idx)return ;

            if(l == r){
                node -> sum = arr[idx] ;
                node -> prefix = arr[idx] ;
                return ;
            }

            int mid = (l + r) >> 1 ;

            update(l , mid , idx , val , node -> l) ;
            update(mid + 1 , r , idx , val , node -> r) ;

            node -> sum = node -> l -> sum + node -> r -> sum ;
            node -> prefix = max(node -> l -> prefix , node -> l -> sum + node -> r -> prefix ) ;
        }

        Node query(int l , int r , int curr_l , int curr_r , Node* node){

            if(curr_r < l || curr_l > r)return Node(0 , 0) ;

            if(l <= curr_l && curr_r <= r)return * node ;

            int mid = (curr_l + curr_r) >> 1 ;

            Node cl = query(l , r , curr_l , mid , node->l) ;
            Node cr = query(l , r , mid + 1 , curr_r , node->r) ;

            return Node(cl.sum + cr.sum , max(cl.prefix , cl.sum + cr.prefix)) ;
        }

} Seg ;

int n , q , cmd , k , a , b ;
long long u ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ;  i <= n ; i ++ )cin >> arr[i] ;

    Node* root = new Node(0 , 0) ;

    Seg.build(1 , n , root) ;


    while(q -- ){

        cin >> cmd ;

        if(cmd == 1){
            
            cin >> k >> u ;
            arr[k] = u ;
            Seg.update(1 , n , k , u , root) ;

        }

        if(cmd == 2){

            cin >> a >> b ;
            cout << Seg.query(1 , n , a , b , root).prefix << '\n' ;

        }
    }

    return 0 ;
}