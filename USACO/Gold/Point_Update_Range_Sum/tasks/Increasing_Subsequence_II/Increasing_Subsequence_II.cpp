#include<bits/stdc++.h>

using namespace std ;

const long long mod = 1e9 + 7 ;
const int Size = 2e5 + 1 ;

long long arr[Size] , res = 0;
vector<long long>vec ;

int get_idx(long long val){
    return (lower_bound(vec.begin() , vec.end() , val) - vec.begin()) + 1 ;
}

struct Fenwick {

    long long fw[2][Size] ; // fw[0] -> count inversion fw[1] -> count dp

    void set (int idx , long long val , int mode) {
        for(; idx < Size ; idx += (idx & -idx))fw[mode][idx] += val ;
    }

    long long get(int idx , int mode) {

        long long res = 0 ;

        for(; idx > 0 ; idx -= (idx & -idx)){
            res += fw[mode][idx] ;
            res %= mod ;
        }

        return res ;
    }

}fw ;

int n ;

int main(){

    ios_base :: sync_with_stdio(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){

        cin >> arr[i];
        vec.push_back(arr[i]) ;

    }

    sort(vec.begin() , vec.end()) ;
    vec.erase(unique(vec.begin() , vec.end()) , vec.end()) ;

    for(int i = 1 ; i <= n ; i ++ ){

        res ++ ;

        int idx = get_idx(arr[i]) ;

        long long sum = fw.get(idx - 1 , 0) + fw.get(idx - 1 , 1) ;

        fw.set(idx , 1 , 0) ;
        fw.set(idx , sum , 1) ;

        res += sum ;
        res %= mod ;
    }

    cout << res ;

    return 0 ;
}