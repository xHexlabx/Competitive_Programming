#include<bits/stdc++.h>

using namespace std;

struct event {
    int time , type ;
};

int timeline [1000002] , s , p , n ;

vector<event>events ;
vector<int>v ;

void coordinate_compress(){
    sort(v.begin() , v.end());
    v.erase( unique(v.begin() , v.end()), v.end()) ;
}

int get_idx (int val) {
    return lower_bound(v.begin() , v.end() , val) - v.begin() ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    
    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> s >> p ;
        v.push_back(s) ;
        v.push_back(p) ;
        events.push_back({s , 1}) ;
        events.push_back({p , 0}) ;
    }

    coordinate_compress() ;

    for(auto temp : events){

        int idx = get_idx(temp.time) ;
        int type = temp.type ;

        if(type == 0){
            timeline[idx] -- ;
        }
        else {
            timeline[idx] ++ ;
        }
    }

    int MAX = 0 ;

    for(int i = 1 ; i <= 1000000 ; i ++ ){
        timeline[i] += timeline[i - 1] ;
        MAX = max(MAX , timeline[i]) ;
    } 

    cout << MAX ;

    return 0 ;
}