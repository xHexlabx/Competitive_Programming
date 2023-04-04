#include <bits/stdc++.h>
using namespace std;

double n  ;
double x ;

double dp[301][301][301] ;

double solve(int c1 , int c2 , int c3){

    if(dp[c1][c2][c3])return dp[c1][c2][c3];
    
    if(c1 == 0 && c2 == 0 && c3 == 0)return 0 ;

    double sum = 0 ;
    double zero = double(n) - double(c1) - double(c2) - double(c3) ;

    if(c1 > 0){;
        sum += c1 * (solve(c1 - 1 , c2 , c3) + n / (n - zero)) ;
    }
    if(c2 > 0){
        sum += c2 * (solve(c1 + 1, c2 - 1, c3) + n / (n - zero)) ;
    }
    if(c3 > 0){
        sum += c3 * (solve(c1  , c2 + 1, c3 - 1) + n / (n - zero)) ;
    }
        
    return dp[c1][c2][c3] = double(sum / (n - zero)) ;

}



int main (){
    
    array<double , 4>arr ;
    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> x ;
        arr[x] += double(1) ;
    }

    cout << fixed << setprecision(9) << solve(arr[1] , arr[2] , arr[3]);


}