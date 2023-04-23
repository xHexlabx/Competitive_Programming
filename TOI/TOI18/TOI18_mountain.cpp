#include<bits/stdc++.h>

using namespace std;

struct coor {
    long long x , y ;
    coor (){} 
};

long long dp[501][501] ;
coor node[501] ;

int n , m ;

long long dis(coor a , coor b){
    return abs(a.x - b.x) + abs(a.y - b.y) ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> node[i].x >> node[i].y ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            dp[i][j] = LLONG_MAX ;
        }
    }

    for(int i = 1 ; i <= n ; i ++ ){
        dp[1][i] = dis(node[1] , node[i]) ;
    }
    
    long long MAX ;

    for(int step = 2 ; step <= n ; step ++ ){

        for(int i = 1 ; i <= n ; i ++ ){
            
            dp[step][i] = dp[step - 1][i] ;

            for(int j = 1 ; j <= n ; j ++ ){
                MAX = max(dp[step - 1][j] , dis(node[i] , node[j])) ;
                dp[step][i] = min(dp[step][i] , MAX) ;
            }

        }

    }

    long long res = 0 ;

    while(m -- ){

        long long range ; cin >> range ; 

        int l = 1 , r = n ;

        while(l < r){

            int mid = (l + r) >> 1 ;
            if(dp[mid][n] <= range)r = mid ;
            else l = mid + 1 ;
        }

        res += l ;
    }

    cout << res ;

    return 0 ;
}