#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n ;

long long minSubArray = 0 , maxSubarray = LLONG_MIN ;

array<long long , Size> qs ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        
        cin >> qs[i] ;
        qs[i] += qs[i - 1] ;

        maxSubarray = max(maxSubarray , qs[i] - minSubArray) ;
        minSubArray = min(minSubArray , qs[i]) ;

    }

    cout << maxSubarray ;

    return 0 ;

}