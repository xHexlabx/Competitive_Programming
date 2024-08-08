#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

long long n , k ;
long long arr[Size] ;
long long cmp = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
    }

    sort(arr , arr + n) ;

    long long l = arr[n / 2] , r = 2e9 ;

    while(l < r){

        long long mid = (l + r + 1) >> 1 ;

        long long res = 0 ;

        for (int i = n / 2 ; i < n ; i ++ ){
            res += max(cmp , mid - arr[i]) ;
        }

        if (res <= k) l = mid ;
        else r = mid - 1;
    }

    cout << l ;

    return 0 ;
}