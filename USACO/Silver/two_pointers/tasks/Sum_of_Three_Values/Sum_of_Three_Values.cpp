#include<bits/stdc++.h>

using namespace std ;

struct object {

    long long val , pos ;

    friend bool operator < (const object &lhs , const object &rhs){
        if(lhs.val != rhs.val){
            return lhs.val < rhs.val ;
        }
        else {
            return lhs.pos < rhs.pos ;
        }
    }
};

int n ;

long long target , sum = 0 , val ;
long long ans [3] ;
vector<object>objects ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> target ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> val ;
        objects.push_back({val , i}) ;
    }

    sort(objects.begin() , objects.end()) ;

    for(int i = 0 ; i < n - 2 ; i ++ ){

        int l = i + 1 , r = n - 1 ;

        while (l < r) {
            
            sum = objects[i].val + objects[l].val + objects[r].val ;

            if(sum == target){

                ans[0] = objects[i].pos ;
                ans[1] = objects[l].pos ;
                ans[2] = objects[r].pos ;

                sort(ans , ans + 3) ;

                for(int i = 0 ; i < 3 ; i ++ ){
                    cout << ans[i] << ' ' ;
                }

                return 0 ;
            }

            else if(sum > target ) r -- ;
            
            else l ++ ;
        }
        
    }

    cout << "IMPOSSIBLE" ;
    
    return 0 ;
}