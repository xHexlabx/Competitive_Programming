#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

struct event {
    
    int arrive , departure , idx ;

    friend bool operator < (const event &lhs , const event &rhs){
        if (lhs.arrive != rhs.arrive)return lhs.arrive < rhs.arrive ;
        return lhs.departure < rhs.departure ;
    }

};

struct heap_event {

    int arrive , departure , room , idx ;

    friend bool operator < (const heap_event &bot , const heap_event &top){
        if (bot.departure != top.departure)return top.departure < bot.departure ;
        return top.arrive < bot.arrive ;
    }

};

vector<event>events ;
priority_queue<heap_event> pq ;
queue<heap_event> q ;

int n , arrive , departure , cnt_room = 0 , ans [Size];

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        cin >> arrive >> departure ;
        events.push_back({arrive , departure , i}) ;
    }

    sort(events.begin() , events.end()) ;

    for(int i = 0 ; i < n ; i ++ ){

        event current = events[i] ;

        while(!pq.empty() && pq.top().departure < current.arrive){
            q.push(pq.top()) ;
            pq.pop() ;
        }

        if (q.empty()){
            cnt_room ++ ;
            pq.push({current.arrive , current.departure , cnt_room , current.idx}) ;
            ans[current.idx] = cnt_room ;
        }

        else {
            pq.push({current.arrive , current.departure , q.front().room , current.idx}) ;
            ans[current.idx] = q.front().room ;
            q.pop() ;
        }

    }

    cout << cnt_room << '\n' ;

    for(int i = 0 ; i < n ; i ++ ){
        cout << ans[i] << ' ' ;
    }

    return 0 ;
}