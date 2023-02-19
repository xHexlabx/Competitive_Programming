#include<bits/stdc++.h>
using namespace std;
bitset<1001>visited[1001] ;
bitset<1001>visited2[1001] ;
int m , n , MAX = 0;
string graph[1001] ;
bool is_valid(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= n)return false;
    return true ;
}
struct coor {
    int x , y ;
};
queue<coor>q ;
int dir[] = {0 , 0 , -1 , 1} ;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> m >> n ;
    for(int i = 0 ; i < m ; i++)cin >> graph[i] ;
    
    visited[0][0] = true ;
    graph[0][0] = '#' ;
    q.push({0 , 0});
    
    while(!q.empty()){
        auto temp = q.front() ;
        q.pop() ;
        for(int i = 0 ; i < 4 ; i ++ ){
            int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i] ;
            if(!is_valid(nowx,nowy))continue ;
            if(visited[nowx][nowy])continue ;
            if(graph[nowx][nowy] == '.'){
                visited[nowx][nowy] = true ;
                graph[nowx][nowy] = '#' ;
                q.push({nowx , nowy});
            }
        }
    }
    for(int i = 1 ; i < m - 1 ; i ++ ){
        for(int j = 1 ; j < n - 1 ; j ++ ){
            
            if(visited2[i][j] || graph[i][j] != 'X')continue ;
                
            int cnt = 0 ;
            visited2[i][j] = true ;
            q.push({i , j});
            while(!q.empty()){
                auto temp = q.front() ;
                q.pop() ;
                for(int i = 0 ; i < 4 ; i ++ ){
                    int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i] ;
                    if(visited2[nowx][nowy])continue ;
                    if(graph[nowx][nowy] == '#')cnt ++ ;
                    if(graph[nowx][nowy] == 'X'){
                        visited2[nowx][nowy] = true ;
                        q.push({nowx , nowy});
                    }
                }
            }
            MAX = max(MAX , cnt) ;
            
        }
    }
    cout << MAX ;
    return 0 ;
}