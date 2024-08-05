#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n ;

long long arr[Size] ;
long long qs[Size] ;

long long minCost = LLONG_MAX , current , currentCost ;

long long getSum(int l , int r){

    if(l > r) return 0 ;
    return qs[r] - qs[l - 1] ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ )cin >> arr[i] ;

    sort(arr + 1 , arr + n + 1) ;

    for(int i = 1 ; i <= n ; i ++ )qs[i] += qs[i - 1] + arr[i] ;

    for(int i = 1 ; i <= n ; i ++ ){

        current = arr[i] ;
        currentCost = (i - 1) * current - getSum(1 , i - 1) + getSum(i + 1 , n) - (n - i) * current ;
        minCost = min(minCost  , currentCost) ;

    }

    cout << minCost ;

    return 0 ;
}