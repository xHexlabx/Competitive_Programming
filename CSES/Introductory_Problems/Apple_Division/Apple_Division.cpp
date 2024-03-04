#include<bits/stdc++.h>

using namespace std;

const int Size = 20 ;
long long arr[Size] , MIN = LLONG_MAX ;
int n ;

void solve(int idx , long long sum_l , long long sum_r){

    if(idx == n){
        MIN = min(MIN , abs(sum_l - sum_r) ) ;
    }
    else {
        solve(idx + 1 , sum_l + arr[idx] , sum_r) ;
        solve(idx + 1 , sum_l , sum_r + arr[idx] ) ;
    }

    return ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    solve(0 , 0 , 0) ;

    cout << MIN ;

    return 0 ;
}