#include<bits/stdc++.h>

using namespace std ;

string graph[101] ;
int arr[101][101] ;
int m , n ;

bool out(int x , int y){
    if(x < 0 || x >= m || y < 0 || y >= n)return true ;
    return false ;
}

void gotop(int x , int y){
    if(out(x, y))return ;
    if(graph[x][y] == 'X')return ;
    arr[x][y] ++ ;
    gotop(x - 1 , y);
}

void goleft(int x , int y){
    if(out(x, y ))return ;
    if(graph[x][y] == 'X')return ;
    arr[x][y] ++ ;
    goleft(x, y - 1);
}

void goright(int x , int y){
    if(out(x, y))return ;
    if(graph[x][y] == 'X')return ;
    arr[x][y] ++ ;
    goright(x, y + 1);
}
void gobottom(int x , int y){
    
    if(out(x , y))return ;
    if(graph[x][y] == 'X')return ;
    arr[x][y] ++ ;
    gobottom(x + 1 , y);

}

void sprinker(int x , int y){
    arr[x][y] ++ ;
    gotop(x - 1 , y);
    goleft(x , y - 1);
    goright(x , y + 1);
    gobottom(x + 1, y);
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> m >> n ;
    for(int i = 0 ; i < m ; i ++ )cin >> graph[i] ;

    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            
            if(graph[i][j] == 'S'){
                sprinker(i , j) ;
            }

        }
    }
    for(int i = 0 ; i < m ; i ++ ){
        for(int j = 0 ; j < n ; j ++ ){
            cout << arr[i][j] << ' ';
        }
        cout << '\n' ;
    }

    return 0 ;
}