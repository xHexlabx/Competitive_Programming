#include<bits/stdc++.h>

using namespace std;

const int INF = 2000000001 ;

class Segment {

    vector<int>seg ;

    public :

        void init () {
            seg = vector<int>(4 * 11 , INF) ;
        }

        void update(int l , int r , int idx , int val , int node){
            if(r < idx || l > idx) return ;
            if(l == r){
                seg[node] = min(seg[node], val) ;
                return ;
            }
            int mid = (l + r) >> 1 ;
            update(l , mid , idx , val , node * 2) ;
            update(mid + 1 , r , idx , val , node * 2 + 1) ;
            seg[node] = min(seg[node * 2] , seg[node * 2 + 1]) ;
        }

        int query(int ql , int qr , int l , int r , int node){
            if(r < ql || l > qr)return INF ;
            if(ql <= l && r <= qr)return seg[node] ;
            int mid = (l + r) >> 1 ;
            return min(query(ql , qr , l , mid ,node * 2) , query(ql , qr , mid + 1 , r , node * 2 + 1)) ;
        }

}Seg[2];

struct node {
    
    int r , c ;

    node(){}

    node(int R , int C){
        r = R ; c = C ;
    }

    bool operator < (const node & rhs)const{
        if(r != rhs.r)return r < rhs.r ;
        return c < rhs.c ;
    }

};

node node_list[7] = { node(1 , 2) , node(3 , 3) , node(4 , 8) , node(6 , 2) , node(6 , 6) , node(8 , 5) , node(9 , 9) } ;

int closest1[7] ;
int closest2[7] ;
int closest[7] ;

int main(){

    for(int i = 0 ; i < 7 ; i ++ ){
        closest1[i] = INF ;
        closest2[i] = INF ;
        closest[i] = INF ;
    }

    Seg[0].init() ;
    Seg[1].init() ;

    for(int i = 0 ; i < 7 ; i ++ ){

        int r = node_list[i].r  , c = node_list[i].c ;

        int lower = Seg[0].query(1 , c , 1 , 10 , 1) + r + c ;
        int upper = Seg[1].query(c , 10 , 1 , 10 , 1) + r - c  ;
        closest1[i] = min(lower, upper) ;

        Seg[0].update(1 , 10 , c , -r - c , 1) ;
        Seg[1].update(1 , 10 , c , -r + c , 1) ;
    }

    Seg[0].init() ;
    Seg[1].init() ;

    for(int i = 6 ; i >= 0 ; i -- ){

        int r = node_list[i].r  , c = node_list[i].c ;

        int lower = Seg[0].query(1 , c , 1 , 10 , 1) - r + c ;
        int upper = Seg[1].query(c , 10 , 1 , 10 , 1) - r - c  ;
        closest2[i] = min(lower, upper) ;

        Seg[0].update(1 , 10 , c , +r - c , 1) ;
        Seg[1].update(1 , 10 , c , +r + c , 1) ;

    }

    for(int i = 0 ; i < 7 ; i ++ ){
        closest[i] = min(closest1[i] , closest2[i]) ;
        cout << closest[i] << ' ' ;
    }

    return 0 ;
}