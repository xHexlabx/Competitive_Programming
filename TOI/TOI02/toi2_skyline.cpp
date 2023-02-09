#include<bits/stdc++.h>
using namespace std ;
struct building {
    int idx , h , type ;
    bool operator < (const building & rhs){
        if(idx != rhs.idx) return idx < rhs.idx ;
        else if(type != rhs.type) return type > rhs.type ;
        else if(type)return h > rhs.h ;
        else return h < rhs.h ;
    }
};
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    vector<building>skyline ;
    int n ; cin >> n ;
    for(int i = 0 ; i < n ; i ++ ){
        int l , r , h ;
        cin >> l >> h >> r ; 
        skyline.push_back({l , h , 1});
        skyline.push_back({r , h , 0});
    }
    sort(skyline.begin(),skyline.end());
    multiset<int>highset ;
    highset.insert(0) ;
    int maxh = 0 ;
    for(auto temp : skyline){
        if(temp.type){
            highset.insert(temp.h) ;
        }
        else {
            highset.erase(highset.find(temp.h)) ;
        }
        if(*highset.rbegin() != maxh){
            maxh = *highset.rbegin() ;
            cout << temp.idx << ' ' << maxh << ' ';
        }
    }
    return 0 ;
}