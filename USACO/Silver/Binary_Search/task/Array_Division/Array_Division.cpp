#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

long long n , k , res , sum , MAX = 0 ;
long long arr[Size] ;

int main (){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arr[i] ;
        MAX = max(MAX , arr[i]) ;
    }

    long long l = MAX , r = 1e18 ;

    while(l < r){

        long long mid = (l + r) >> 1 ;

        res = 1 ;
        sum = 0 ;

        for(int i = 0 ; i < n ; i ++ ){
            
            if (sum + arr[i] > mid){
                res ++ ;
                sum = arr[i] ;
            }
            else sum += arr[i] ;

            if (res > k) break ;
        }

        if (res <= k) r = mid ;
        else l = mid + 1 ;

    }

    cout << l ;

    return 0 ;
}