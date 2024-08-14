#include<bits/stdc++.h>

using namespace std ;

int n , x ;

vector<int>dp ;

int main (){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n; i ++ ){
        cin >> x ;

        auto it = upper_bound(dp.begin() , dp.end() , x) ;

        if(it == dp.end()){
            dp.push_back(x) ;
        }
        else {
            *it = x ;
        }

    }

    cout << dp.size() ;
    
    return 0 ;
}