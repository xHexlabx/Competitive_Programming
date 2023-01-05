#include<bits/stdc++.h>
using namespace std ;
struct coor {
    int x , y ;
};
int arr[21][21] , dir[] = {0 , 0 , -1 , 1}, m , x , y , MAX = INT_MIN ;
bool is_valid(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= m)return false ;
    return true ;
}
bitset<21>visited[21] ;
queue<coor>q ;
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);
    
    cin >> m >> y >> x ;
    y -- , x -- ;
    
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> arr[i][j] ;
        }
    }
    q.push({x , y});
    visited[x][y] = true ;
    while(!q.empty()){
        auto temp = q.front();
        q.pop(); 
        MAX = max(MAX , arr[temp.x][temp.y]) ;
        for(int i = 0 ; i < 4 ; i ++ ){
            int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i];
            if(!is_valid(nowx , nowy))continue ;
            if(arr[nowx][nowy] == 100 || visited[nowx][nowy] || arr[temp.x][temp.y] >= arr[nowx][nowy] )continue ;
            visited[nowx][nowy] = true ;
            q.push({nowx , nowy});
        }
    }
    cout << MAX ;
    return 0 ;
}