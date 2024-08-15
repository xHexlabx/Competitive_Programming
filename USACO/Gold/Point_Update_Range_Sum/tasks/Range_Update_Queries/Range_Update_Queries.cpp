#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;

int n , q , mode , a , b , u , k , val ;
struct Fenwick {

    long long fw[Size] ;

    void set (int idx , long long val){

        for(; idx < Size ; idx += (idx & -idx)){
            fw[idx] += val ;
        }
        return ;
    }

    long long get (int idx){

        long long res = 0 ;

        for(; idx > 0 ; idx -= (idx & -idx)){
            res += fw[idx] ;
        }

        return res ;
    }

}fw ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> q ;

    for(int i = 1 ; i <= n ; i ++ ){
        cin >> val ;
        fw.set(i , val) ;
        fw.set(i + 1 , -val) ;
    }

    while(q -- ){
        cin >> mode ;
        if(mode == 1){
            cin >> a >> b >> u ;
            fw.set(a , u) ;
            fw.set(b + 1 , -u) ;
        }
        else {
            cin >> k ;
            cout << fw.get(k) << '\n';
        }
    }

    return 0 ;
}