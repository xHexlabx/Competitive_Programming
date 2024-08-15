#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int arr[Size] , n , idx ;

struct Fenwick {

    int fw[Size] ;

    void set(int idx , int val){
        for(; idx < Size ; idx += (idx & -idx))fw[idx] += val ;
        return ;
    }

    int get(int idx){
        int res = 0 ;
        for(; idx > 0 ; idx -= (idx & -idx)) res += fw[idx] ;
        return res ;
    }

    int get_idx (int idx){

        int l = 1 , r = n ;

        while(l < r){
            int mid = (l + r) >> 1 ;
            if(get(mid) >= idx) r = mid ;
            else l = mid + 1 ;
        }

        return l ;
    }

}fw;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> arr[i] ;
        fw.set(i , 1) ;
    }


    for(int i = 1 ; i <= n ; i ++ ){

        cin >> idx ;
        cout << arr[fw.get_idx(idx)] << ' ' ;

        fw.set(fw.get_idx(idx) , - 1) ;

    }
    return 0 ;
}