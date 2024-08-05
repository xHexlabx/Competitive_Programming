#include<bits/stdc++.h>

using namespace std ;

struct event {

    int time , state ;

    event (int Time , int State) {
        time = Time ;
        state = State ;
    }

    friend bool operator < (const event &lhs , const event &rhs) {
        
        if (lhs.time != rhs.time){
            return lhs.time < rhs.time ;
        }
        else {
            return lhs.state < rhs.state ;
        }

    }
};

int n  , currentPerson = 0 , maxPerson = 0 , x , y ;

vector<event> events ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        
        cin >> x >> y ;

        events.push_back({x , 1}) ;
        events.push_back({y + 1 , -1}) ;

    }

    sort(events.begin() , events.end()) ;

    for(auto e : events){

        if (e.state == -1) currentPerson -- ;
        else currentPerson ++ ;

        maxPerson = max(maxPerson , currentPerson) ; 

    }

    cout << maxPerson ;

    return 0 ;
}