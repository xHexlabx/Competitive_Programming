#include<bits/stdc++.h>  

using namespace std ; 

struct point{
    int s , h , o ;
    bool operator < (const point & rhs)const{
        if(s != rhs.s)return s < rhs.s ;
        return o < rhs.o ;
    }
};
const int N = 1000001 ;
int n , t , s , h , w , o , mul , ans = 0; 
vector<point>vec ;
class Fenwick {
    public :
        int fw[N] ;
        
        void update(int idx , int val){
            for(; idx < N ; idx += (idx & -idx)){
                fw[idx] += val ;
            }
            return ;
        }
        int query(int idx){
            int res = 0 ;
            for(; idx > 0 ;idx -= (idx & -idx)){
                res += fw[idx] ;
            }
            return res ;
        }
        int upper(){
            int l = 1 , r = N ;
            while(l < r){
                int mid = (l + r) >> 1 ;
                if(query(mid) <= t)r = mid ;
                else l = mid + 1 ;
            }
            return l ;
        }
        int lower(){
            int l = 1 , r = N ;
            while(l < r){
                int mid = (l + r) >> 1 ;
                if(query(mid) < t)r = mid ;
                else l = mid + 1 ;
            }
            return l ;
        }
}fw;
int main () {
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    cin >> n >> t ;
    for(int i = 0 ; i < n ; i ++ ){
        cin >> s >> h >> w >> o ;
        vec.push_back({s , h , o});
        vec.push_back({s + w , h , -o});
    }
    sort(vec.begin(), vec.end());
    for(int i = 0 ; i < 2 * n - 1 ; i ++ ){
        h = vec[i].h , o = vec[i].o ;
        fw.update(1 , o) ;
        fw.update(h + 1 , -o);
        mul = vec[i + 1].s - vec[i].s ;
        ans += mul * (fw.lower() - fw.upper()) ;
    }
    cout << ans ;
    return 0 ;
}