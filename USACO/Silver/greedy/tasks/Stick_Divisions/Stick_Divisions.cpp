#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;
long long x , n , sum , res = 0 ;
long long arr[Size] ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> x >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    sort(arr , arr + n) ;

    sum = x ;

    for(int i = n - 1 ; i >= 1 ; i -- ){
        res += sum ;
        sum -= arr[i] ;
    }
    
    cout << res ;
    
    return 0 ;
}