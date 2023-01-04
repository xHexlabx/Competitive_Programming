#include<bits/stdc++.h>
using namespace std ;
int arr[20][20] , n ;
bitset<20>visited[20] ;
struct till {
    int x , y ;
};
int dir[] = {0 , 0 , -1 , 1} ;
bool is_valid(int x , int y){
    if(x < 0 || x >= n || y < 0 || y >= n)return false ;
    return true ;
}
int main(){
    ios_base::sync_with_stdio(0) , cin.tie(0);
    int res = 0 ; cin >> n ;
    
    queue<till>q ;
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }
    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            
            if(visited[i][j] || arr[i][j] == 0 )continue ;
            int cnt = 1 ;
            visited[i][j] = true ;
            q.push({i , j});
            int mx = i, my = j ;
            int Mx = i, My = j ;
            while(!q.empty()){
                
                auto temp = q.front() ;
                q.pop() ;
                for(int k = 0 ; k < 4 ; k ++ ){
                    int now_x = temp.x + dir[k] , now_y = temp.y + dir[3 - k] ;
                    if(is_valid(now_x , now_y)){
                        if(visited[now_x][now_y] || arr[now_x][now_y] != arr[i][j])continue ;
                        visited[now_x][now_y] = true ;
                        cnt ++ ;
                        mx = min(mx , now_x) , my = min(my , now_y) ;
                        Mx = max(Mx , now_x) , My = max(My , now_y) ;
                        q.push({now_x , now_y});
                    }
                }
            }
            if(cnt == 3 && Mx - mx == 1 && My - my == 1)res ++ ;
        }
    }
    cout << res ;
    return 0 ;
}