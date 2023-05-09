#include<bits/stdc++.h>

using namespace std;

const int INF = 2000000001 ;

class Segment {

    vector<int>seg ;

    public :

        void init () {
            seg = vector<int>(4 * 40001 , INF) ;
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

//Seg[0] previous col < current col 
//Seg[1] previous col > current col 

struct node {
    int x , y , t ; // 0 --> in 1 --> out 
    
    node(){}
    
    node(int X , int Y , int TYPE){
        x = X ;
        y = Y ;
        t = TYPE ;
    }

    bool operator < (const node & rhs)const {
        if(x != rhs.x)return x < rhs.x;
        if(y != rhs.y)return y < rhs.y;
        return t < rhs.t;
    }
    
};

map<node , node>mpp ;
map<node , int>get_idx_out ;
map<node , int>get_idx_in ;

node node_list[40001] ;
node out[20001] ;
node in[20001] ;

int m , n , k , p , sx , sy , dx , dy , dp[18][20001] , idx , size_col , compressed_index[40001] , ans_dis = INF , ans_ticket , lower_col , upper_col ; 
vector<int>col_list ;

void init(){

    for(int i = 0 ;  i <= 17 ; i ++ ){
        for(int j = 1 ; j <= 20000 ; j ++ ){
            dp[i][j] = INF;
        }
    }

}

void coordinate_compression(){

    sort(col_list.begin(), col_list.end()) ;
    col_list.erase( unique(col_list.begin() , col_list.end()) , col_list.end());
    size_col = col_list.size();

    for(int i = 1 ; i <= 2 * k ; i ++ ){
        compressed_index[i] = lower_bound(col_list.begin() , col_list.end() , node_list[i].y ) - col_list.begin() + 1 ;
    }
}

void setnode(){

    int idx = 1 ; 

    for(int i = 1 ; i <= 2 * k ; i ++ ){
        if(node_list[i].t == 0){
            in[idx] = node_list[i] ;
            out[idx] = mpp[node_list[i]] ;
            get_idx_in[node_list[i]] = idx ;
            get_idx_out[mpp[node_list[i]]] = idx ;
            idx ++ ;
        }
    }

}

void setstate0 () {

    for(int i = 1 ; i <= k ; i ++ ){
        dp[0][i] = out[i].x + out[i].y - 2 ;
    }

}

void setstate1 () {

    for(int i = 1 ; i <= k ; i ++ ){
        dp[1][i] = min(dp[0][i] , in[i].x + in[i].y - 2) ;
        if(m + n - out[i].x - out[i].y + dp[1][i] < ans_dis){
            ans_dis = m + n - out[i].x - out[i].y + dp[1][i];
            ans_ticket = 1 ;
        }
    }

}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n >> k >> p ;

    for(int i = 1 ; i <= k ; i ++ ){

        cin >> sx >> sy >> dx >> dy ;

        node_list[i * 2 - 1] = node(sx , sy , 0) ;
        node_list[i * 2] = node(dx , dy , 1) ;

        mpp[{sx , sy , 0}] = node(dx , dy , 1) ;
        mpp[{dx , dy , 1}] = node(sx , sy , 0) ;

        col_list.push_back(sy) ;
        col_list.push_back(dy) ;
    }

    ans_dis = m + n - 2 ;
    ans_ticket = 0 ;

    init() ;
    sort(node_list + 1  , node_list + 2 * k + 1) ;
    coordinate_compression() ;
    setnode() ;
    setstate0() ;
    setstate1() ;

    for(int ticket = 2 ; ticket <= p ; ticket ++){
        
        for(int i = 1 ; i <= k ; i ++ ){
            dp[ticket][i] = dp[ticket - 1][i] ;
        }

        Seg[0].init() ;
        Seg[1].init() ;

        for(int i = 1 ; i <= 2 * k ; i ++ ){
            
            if(node_list[i].t == 0){

                lower_col = Seg[0].query(1 , compressed_index[i] , 1 , size_col , 1 ) + node_list[i].x + node_list[i].y ;
                upper_col = Seg[1].query(compressed_index[i] , size_col , 1 , size_col , 1 ) + node_list[i].x - node_list[i].y ;
                dp[ticket][get_idx_out[mpp[node_list[i]]]] = min({dp[ticket][get_idx_out[mpp[node_list[i]]]] , lower_col , upper_col}) ;
            }

            if(node_list[i].t == 1){

                Seg[0].update(1 , size_col , compressed_index[i] , 
                              dp[ticket - 1][get_idx_out[node_list[i]]] - node_list[i].x - node_list[i].y , 1) ;
                Seg[1].update(1 , size_col , compressed_index[i] , 
                              dp[ticket - 1][get_idx_out[node_list[i]]] - node_list[i].x + node_list[i].y , 1) ;

            }

        }


        Seg[0].init() ;
        Seg[1].init() ;

        for(int i = 2 * k ; i >= 1 ; i -- ){
            
            if(node_list[i].t == 0){

                lower_col = Seg[0].query(1 , compressed_index[i] , 1 , size_col , 1 ) 
                            - node_list[i].x + node_list[i].y ;
                upper_col = Seg[1].query(compressed_index[i] , size_col , 1 , size_col , 1 ) 
                            - node_list[i].x - node_list[i].y ;
                dp[ticket][get_idx_out[mpp[node_list[i]]]] = min({dp[ticket][get_idx_out[mpp[node_list[i]]]] , 
                            lower_col , upper_col}) ;

            }

            if(node_list[i].t == 1){

                Seg[0].update(1 , size_col , compressed_index[i] , 
                              dp[ticket - 1][get_idx_out[node_list[i]]] + node_list[i].x - node_list[i].y , 1) ;
                Seg[1].update(1 , size_col , compressed_index[i] , 
                              dp[ticket - 1][get_idx_out[node_list[i]]] + node_list[i].x + node_list[i].y , 1) ;
                
            }

        }
        
        for(int i = 1 ; i <= k ; i ++ ){

            if( m + n - out[i].x - out[i].y + dp[ticket][i] < ans_dis){
                ans_dis = m + n - out[i].x - out[i].y + dp[ticket][i] ;
                ans_ticket = ticket ;
            }
        }

    }

    cout << ans_dis << ' ' << ans_ticket  ;

    return 0 ;
} 