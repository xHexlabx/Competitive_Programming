#include<bits/stdc++.h>

using namespace std ;

struct coordinate {

    int x , y ;

    coordinate(int X , int Y){
        x = X ;
        y = Y ;
    }

};

const int Size = 1e3 + 1 ;

int n , m , next_x , next_y , res = 0 ;

char maze[Size][Size] ;
bool visited[Size][Size] ;
int dirs[4] = {0 , 0 , -1 , 1} ;

queue<coordinate> q ;

bool is_valid(coordinate coor){

    if(coor.x < 0 || coor.x > n - 1 || coor.y < 0 || coor.y > m - 1)return false ;
    if(maze[coor.x][coor.y] == '#')return false ;
    if(visited[coor.x][coor.y])return false ;

    return true ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> maze[i][j] ;
        }
    }

    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ; j < m  ; j ++ ){
            
            if(!visited[i][j] && maze[i][j] != '#'){

                res ++ ;
                visited[i][j] = true ;
                q.push({i , j}) ;

                while(!q.empty()){

                    coordinate coor = q.front() ;

                    q.pop() ;

                    for(int dir = 0 ; dir < 4 ; dir ++ ){

                        next_x = coor.x + dirs[dir] ;
                        next_y = coor.y + dirs[3 - dir] ;

                        if(!is_valid(coordinate(next_x , next_y)))continue ;

                        visited[next_x][next_y] = true ;
                        q.push({next_x , next_y}) ;
                    }

                }
            }

        }
    }

    cout << res ;

    return 0 ;
}