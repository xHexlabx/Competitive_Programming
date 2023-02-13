#include<bits/stdc++.h>
using namespace std;
struct coor {
    int x , y , t ;
};
string graph[2001] ;
bitset<2001>visited[2001] ;
int m , n , dis = 0 , cnt = 0 ; 
bool is_valid(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= n)return false;
    return true;
}
int dir[] = {0 , 0 , -1,  1};
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> m >> n ;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> graph[i] ;
    }
    
    queue<coor>q ;
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j  < n ; j ++ ){
            if(graph[i][j] == 'X'){
                visited[i][j] = true ;
                q.push({i , j , 0});
            }
        }
    }
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; i ++ ){
            int nowx = temp.x + dir[i] , nowy = temp.y + dir[3 - i] ;
            if(!is_valid(nowx , nowy))continue ;
            if(visited[nowx][nowy] || graph[nowx][nowy] == 'W')continue ;
            if(graph[nowx][nowy] == 'A'){
                visited[nowx][nowy] = true ;
                cnt ++ ;
                dis += (temp.t + 1) * 2 ;
                q.push({nowx , nowy , temp.t + 1});
            }
            else {
                visited[nowx][nowy] = true ;
                q.push({nowx , nowy , temp.t + 1});
            }
        }
    }
    cout << cnt << ' ' << dis ;
    return 0 ;
}