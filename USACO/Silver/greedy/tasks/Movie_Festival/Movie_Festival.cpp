#include<bits/stdc++.h>

using namespace std ;

struct event {

    int start , stop ;

    friend bool operator < (const event &lhs , const event &rhs){
        return lhs.stop < rhs.stop ;
    }

};

int n , start , stop , last , res = 0 ;

vector<event>events ;

int main () {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++){

        cin >> start >> stop ;

        events.push_back({start , stop}) ;

    }

    sort(events.begin() , events.end()) ;

    for(int i = 0 ; i < n ; i ++ ){

        start = events[i].start ;
        stop = events[i].stop ;

        if (start >= last){
            last = stop ;
            res ++ ;
        }

    }

    cout << res ;

    return 0 ;
}