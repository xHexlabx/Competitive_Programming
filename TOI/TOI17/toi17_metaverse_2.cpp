#include<bits/stdc++.h>

using namespace std;

class Segment {
    
    vector<int>seg ;

    public : 

        void init(){
            seg = vector<int>(4 * 40001 , INT_MAX) ;
            return ;
        }

        void update(int l , int r , int idx , int val , int node){

            if(l > idx || r < idx)return ;
            if(l == r){
                seg[node] = min(seg[node] , val) ;
                return ;
            }

            int mid = (l + r) >> 1 ;

            update(l , mid , idx , val , node * 2) ;
            update(mid + 1  , r , idx , val , node * 2 + 1) ;

            seg[node] = min(seg[node * 2] , seg[node * 2 + 1]) ;
        }

        int query(int ql  , int qr , int l , int r , int node){
            
            if(r < ql || l > qr)return INT_MAX ;
            if(ql <= l && r <= qr)return seg[node] ;

            int mid = (l + r) >> 1 ;
            return min(query(ql , qr , l , mid , node * 2) , query(ql , qr , mid + 1 , r , node * 2 + 1)) ;
        }
}Seg[2];

//seg[0] --> query (previous col < current col) 
//seg[1] --> query (previous col > current col)

struct node {
    
    int x , y ; 

    bool operator < (const node & rhs) const {
        if(x != rhs.x)return x < rhs.x;
        return y < rhs.y;
    }

};

int m , n , k , p , size_col , lower_col , upper_col;

int sx[40001] , sy[40001] , dx[40001] , dy[40001] , compressed_idx[40001] , dp[18][40001] , ans_dis = INT_MAX , ans_ticket ;

node node_list [40001] ;

vector<int>col_list ;

map<node , node> mpp ;

void init(){

    for(int i = 0 ; i <= 17 ; i ++ ){
        for(int j = 1 ; j <= 40000 ; j ++ ){
            dp[i][j] = INT_MAX ;
        }
    }

}

void coordinate_compression(){

    sort(col_list.begin() , col_list.end()) ;
    col_list.erase(unique(col_list.begin() , col_list.end()) , col_list.end()) ;    

    size_col = col_list.size() ;

    for(int i = 1 ; i <= 2 * k ; i ++ ){
        compressed_idx[i] = lower_bound(col_list.begin() , col_list.end() , node_list[i].y ) - col_list.begin() + 1 ;
    }    

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n >> k >> p ;

    init() ;

    for(int i = 1 ; i <= k ; i ++ ){

        cin >> sx[i * 2 - 1] >> sy[i * 2 - 1] >> sx[i * 2] >> sy[i * 2] ;

        col_list.push_back(sy[i * 2]) ;
        col_list.push_back(sy[i * 2 - 1]) ;

        node_list[i * 2 - 1] = {sx[i * 2 - 1] , sy[i * 2 - 1]} ;
        node_list[i * 2] = {sx[i * 2] , sy[i * 2]} ;

        mpp[{sx[i * 2 - 1] , sy[i * 2 - 1]}] = {sx[i * 2], sy[i * 2]} ;
        mpp[{sx[i * 2] , sy[i * 2]}] = {sx[i * 2 - 1] , sy[i * 2 - 1]} ;
    }

    ans_dis = (m - 1) + (n - 1) ;
    ans_ticket = 0 ;

    sort(node_list + 1 , node_list + 2 * k + 1) ;

    for(int i = 1 ; i <= 2 * k ; i ++ ){
         dp[0][i] = (node_list[i].x - 1) + (node_list[i].y - 1) ;
    }

    coordinate_compression() ;

    for(int ticket = 1 ; ticket <= p ; ticket ++ ){

        Seg[0].init() ;
        Seg[1].init() ;

        for(int i = 1 ; i <= 2 * k ; i ++ ){

            Seg[0].update(1 , size_col , compressed_idx[i] , dp[ticket - 1][i] - mpp[node_list[i]].x - mpp[node_list[i]].y , 1) ;
            Seg[1].update(1 , size_col , compressed_idx[i] , dp[ticket - 1][i] - mpp[node_list[i]].x + mpp[node_list[i]].y , 1) ;

            lower_col = Seg[0].query(1 , compressed_idx[i] , 1 , size_col , 1) + node_list[i].x + node_list[i].y ;
            upper_col = Seg[1].query(compressed_idx[i] , size_col , 1 , size_col , 1) + node_list[i].x - node_list[i].y ;

            dp[ticket][i] = min({dp[ticket][i] , lower_col , upper_col}) ;            
        }

        Seg[0].init() ;
        Seg[1].init() ;

        for(int i = 2 * k ; i >= 1 ; i -- ){

            Seg[0].update(1 , size_col , compressed_idx[i] , dp[ticket - 1][i] + mpp[node_list[i]].x - mpp[node_list[i]].y , 1) ;
            Seg[1].update(1 , size_col , compressed_idx[i] , dp[ticket - 1][i] + mpp[node_list[i]].x + mpp[node_list[i]].y , 1) ;

            lower_col = Seg[0].query(1 , compressed_idx[i] , 1 , size_col , 1) - node_list[i].x + node_list[i].y ;
            upper_col = Seg[1].query(compressed_idx[i] , size_col , 1 , size_col , 1) - node_list[i].x - node_list[i].y ;

            dp[ticket][i] = min({dp[ticket][i] , lower_col , upper_col}) ;            
        }

        for(int i = 1 ; i <= 2 * k ; i ++ ){
            cout << dp[ticket][i] << ' ' ;
            if(m + n - node_list[i].x - node_list[i].y + dp[ticket][i] < ans_dis){
                ans_dis = m + n - node_list[i].x - node_list[i].y + dp[ticket][i] ;
                ans_ticket = ticket ;
                
            }
        }
        
        cout << '\n' ;
    }
    cout << ans_dis << ' ' << ans_ticket << ' ' ;
    
    

    return 0 ;
}