#include<bits/stdc++.h>
using namespace std;
int arr[2501] ;
int dp[2501] ;
void display(int idx){
    if(idx == 0)return ;
    if(dp[idx] < 0)return ;
    display(idx - 1) ;
    cout << arr[idx] << ' ' ; 
}
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    int n ; cin >> n ;
    int idx , MAX = INT_MIN ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }
    for(int i = 1 ; i <= n ; i ++ ){
        dp[i] = max(arr[i] , arr[i] + dp[i - 1]) ;
        if(dp[i] > MAX){
            MAX = dp[i] ;
            idx = i ;
        }
    }
    if(MAX <= 0){
        cout << "Empty sequence" ;
    }
    else {
        display(idx) ;
        cout << '\n' << MAX ;
    }
    return 0 ;
}