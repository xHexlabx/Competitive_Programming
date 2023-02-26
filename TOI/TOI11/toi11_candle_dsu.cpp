#include<bits/stdc++.h>

using namespace std;

struct coor {
    int x , y ;
};

int pa[4000001] , m , n ;
bitset<2001>graph[2001] ;

int fp(int x){
    if(pa[x] == x)return x ;
    return pa[x] = fp(pa[x]) ;
}

int coor_to_num(int x , int y){
    return x * n + y + 1;
}

coor dir[] = { {- 1 , 0} , {-1 , 1} , {0 , 1} , {1 , 1} , {1 , 0} , {1 , -1} , {0 , -1} , {-1 , -1} } ;

unordered_map<int , int>cnt ;

int ans = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> m >> n ;

    for(int i = 1 ; i <= 4000000 ; i ++ )pa[i] = i ;

    for(int i = 0 ; i < m ; i ++ ){
        cin >> graph[i] ;
    }

    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            if( graph[i][j] ){
                for(int k = 0 ; k < 8 ; k ++ ){
                    int nowx = i + dir[k].x , nowy = j + dir[k].y ;
                    if(nowx < 0 || nowy < 0 || nowx >= m || nowy >= n || graph[nowx][nowy] == 0)continue ;
                    int rootx = fp(coor_to_num(i , j)) ;
                    int rooty = fp(coor_to_num(nowx , nowy)) ;
                    pa[rootx] = rooty ;
                }
            }
        }
    }

    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            // cout << coor_to_num(i , j) << ' ' ;
            if(graph[i][j] == 0)continue ;
            int root = fp(coor_to_num(i , j)) ;
            // cout << coor_to_num(i , j) << ' ' << root << ' ' << i << ' ' << j << '\n';
            if(cnt[root])continue ;
            else {
                cnt[root] = 1 ;
                ans ++ ;
            }
        }
    }
    cout << ans ;
    return 0 ;
}