#include<bits/stdc++.h>
using namespace std;
int lowest_cost[16] ;
void preprocess(){
    for(int i = 1 ; i <= 15 ; i ++ ){
        lowest_cost[i] = INT_MAX;
    }
    lowest_cost[0] = 0 ;
    lowest_cost[1] = 500 ;
    lowest_cost[2] = 800 ;
    lowest_cost[5] = 1500 ;
    lowest_cost[15] = 3000 ;
    for(int i = 1 ; i <= 15 ; i ++ ){
        
        for(int j = 1 ; j <= 15 ; j ++ ){
            if(j < i){
                lowest_cost[i] = min(lowest_cost[i],lowest_cost[j] + lowest_cost[i - j]);
            }
            else {
                lowest_cost[i] = min(lowest_cost[i] , lowest_cost[j]);
            }
        }
    }
}
int solve(int guests){
    int res = 0 ;
    res += (lowest_cost[15] * (guests / 15) ) + lowest_cost[guests % 15] ;
    return res ;
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    int n ; cin >> n ;
    preprocess() ;
    cout << solve(n) ;
    return 0 ;
}