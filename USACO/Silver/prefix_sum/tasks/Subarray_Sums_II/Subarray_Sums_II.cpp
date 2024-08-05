#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n ; 
long long x , current , res = 0 ;

array<long long , Size> arr ;
array<long long , Size> qs ;

map<long long , int>mpp ;

int main() {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> x ;

    mpp[0] = 1 ;

    for (int i = 1 ; i <= n ; i ++ ){

        cin >> arr[i] ;
        qs[i] += arr[i] + qs[i - 1]  ;

        current = qs[i] ;
        res += mpp[current - x] ;

        mpp[qs[i]] ++ ;

    }
    
    cout << res ;

    return 0 ;
}