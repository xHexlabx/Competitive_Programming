#include<bits/stdc++.h>
using namespace std ;
bitset<2001>visited[2001] ;
struct coor {
    int x , y ;
};
int m , n , cnt = 0 ;
bool is_valid(int x , int y) { 
    if(x < 0 || x >= m || y < 0 || y >= n)return false;
    return true ;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    cin >> m >> n ;
    for(int i = 0 ; i < m ; i ++ )cin >> visited[i] ;
    
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            if(visited[i][j]){
                
                cnt ++ ;
                visited[i][j] = 0 ;
                queue<coor>q ;
                q.push({i , j});
                while(!q.empty()){
                    
                    auto temp = q.front();
                    q.pop() ;
                    for(int x = -1 ; x <= 1 ; x ++  ){
                        for(int y = -1 ; y <= 1 ; y ++ ){
                            int nowx = temp.x + x , nowy = temp.y + y ;
                            if(is_valid(nowx , nowy)){
                                if(visited[nowx][nowy]){
                                    visited[nowx][nowy] = 0 ;
                                    q.push({nowx , nowy}) ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << cnt ;
    return 0 ;
}