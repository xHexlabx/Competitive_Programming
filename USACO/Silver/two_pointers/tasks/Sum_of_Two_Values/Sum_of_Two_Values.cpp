#include<bits/stdc++.h>

using namespace std ;

struct object {
    
    int val , pos ;

    friend bool operator < (const object &lhs , const object &rhs){

        if(lhs.val != rhs.val){
            return lhs.val < rhs.val ;
        }
        
        return lhs.pos < rhs.pos ;
        
    }

};

int n , target , val , pos  , res ;

vector<object>objects ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> target ;

    for(int i = 0 ; i < n ; i ++ ){

        cin >> val ;
        pos = i + 1 ;

        objects.push_back({val , pos}) ;
    }

    sort(objects.begin() , objects.end()) ;

    int l = 0 , r = n - 1 ;

    while(l < r){

        res = objects[l].val + objects[r].val ;
        
        if(res == target){
            
            cout << min(objects[l].pos , objects[r].pos) << ' ' << max(objects[l].pos , objects[r].pos) ;
            return 0 ;
        }

        else if (res > target) r -- ;
        
        else l ++ ;

    }

    cout << "IMPOSSIBLE" ;

    return 0 ;
}