#include<bits/stdc++.h>

using namespace std;

struct node {

    int x , y ;
    coor () {}

    bool operator < (const node & rhs)const { 
        if(x != rhs.x)return x < rhs.x ;
        return y < rhs.y ;
    }

};

node node_list [501] , src , dest ;

int n , q , compressed_index[501] ;

long long dp[501][501] , ans[501] ;

vector<long long>col_list ;

void coordinate_compression(){

    sort(col_list.begin() , col_list.end()) ;
    col_list.erase(unique(col_list.begin() , col_list.end()) , col_list.end()) ;

    for(int i = 1 ; i <= n - 2 ; i ++ ){
        compressed_index[i] = lower_bound(col_list.begin() , col_list.end() , node_list[i].y ) - col_list.begin() + 1 ; 
    }
}

void setstate1(){

    for(int i = 1 ; i <= n - 2 ; i ++ ){
        dp[1][]
    }
}
int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){

        if(i == 1){
            cin >> src.x >> src.y ;
        }
        if(i == n){
            cin >> dest.x >> dest.y ;
        }
        else {
            cin >> node_list[i - 1].x >> node_list[i - 1].y ;
            col_list.push_back(node_list[i - 1].y) ;
        }

    }

    sort(node_list + 1 , node_list + 1 + n - 2) ;

    coordinate_compression() ;

    setstate1() ;

    return 0 ;
}