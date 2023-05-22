#include<bits/stdc++.h>

using namespace std;

const int N = 4 ;

int arr[N + 1][N + 1] = { {0 , 0 , 0 , 0 , 0} , 
                          {0 , 5 , 6 , 3 , 4} ,
                          {0 , 7 , 3 , 4 , 2} , 
                          {0 , 3 , 8 , 4 , 6} ,
                          {0 , 2 , 1 , 9 , 8}
                        };

int ans = INT_MAX ;

bool visited[N + 1] ;

void solve(int cnt , int cost){

    if(cnt == N){
        ans = min(ans , cost) ;
    }

    else {

        for(int i = 1 ; i <= N ; i ++ ){
            
            if(visited[i])continue;

            visited[i] = true ;
            solve(cnt + 1 , cost + arr[i][cnt + 1]) ;
            visited[i] = false ;
            
        }

    }
}


int main(){

    ios_base ::sync_with_stdio(0) , cin.tie(0) ;

    solve(0 , 0) ;

    cout << ans ;

    return 0 ;
}