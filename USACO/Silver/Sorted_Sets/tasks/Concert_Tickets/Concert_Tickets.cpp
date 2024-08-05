#include<bits/stdc++.h>

using namespace std ;

multiset<int>mts ;

int n , q , val ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> val ;
        mts.insert(val) ;
    }

    while(q -- ){

        cin >> val ;

        auto it = mts.upper_bound(val) ;

        if (!mts.empty() && it != mts.begin()){
            --it ;
            cout << *(it) << '\n' ;
            mts.erase(it) ;
        } 

        else {
            cout << -1 << '\n';
        }
    }

    return 0 ;
}