#include<bits/stdc++.h>

using namespace std ;

int n ;

multiset<long long>mts ;
long long t , left_time , res = 0 ;

int main (){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> t ;
        mts.insert(t) ;
    }

    auto it = mts.end() ;
    --it ;
    res += *it * 2 ;
    mts.erase(it) ;
    left_time = *it ;
    

    while(!mts.empty()){

        auto it = mts.upper_bound(left_time) ;
        
        if(it == mts.begin()){
            
            it = mts.end() ;
            --it ;
            res += *it * 2 ;
            mts.erase(it) ;
            left_time = *it ;

        }
        else {
            --it ;
            left_time -= *it ;
            mts.erase(it) ;
        }
    }

    cout << res ;

    return 0 ;
}