#include<bits/stdc++.h>

using namespace std;

int n ;
long long arr[3001] , dp[3001][3001];
long long solve(int l , int r){
    if(dp[l][r])return dp[l][r];
    if(l == r)return arr[l] ;
    else return dp[l][r] = max(arr[l] - solve(l + 1 , r) , arr[r] - solve(l , r - 1));
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
    }

    cout << solve(1 , n) ;

    return 0 ;
}