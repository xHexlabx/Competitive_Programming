#include<bits/stdc++.h>

using namespace std ;

struct event {
    int start , stop ; 

    friend bool operator < (const event &lhs , const event &rhs){
        if (lhs.stop != rhs.stop)return lhs.stop < rhs.stop ;
        return lhs.start < rhs.start ;
    }
};

int n , k , start , stop , res = 0 ;

vector<event>events ;
multiset<int>mts ;

int main () {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> k ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> start >> stop ;
        events.push_back({start , stop}) ;
    }

    for(int i = 0 ; i < k ; i ++ ){
        mts.insert(0) ;
    }

    sort(events.begin() , events.end()) ;

    for(int i = 0 ; i < n ; i ++ ){

        start = events[i].start ;
        stop = events[i].stop ;

        auto it = mts.lower_bound(-start) ;

        if (it == mts.end())continue ;

        res ++ ;
        mts.erase(it) ;
        mts.insert(-stop) ;
    }

    cout << res ;

    return 0 ;
}