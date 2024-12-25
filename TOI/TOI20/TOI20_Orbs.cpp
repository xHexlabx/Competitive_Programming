#include<bits/stdc++.h>

using namespace std ;

const int Size_arr = 2e6 + 1 ;
int arr[Size_arr] ;
int mts_size[3] ;
multiset<int>mts[3] ;
int N , L , a , b , x , y ;

void balance() {

    while(mts[0].size() > mts_size[0]){
        int val = *mts[0].rbegin() ;
        mts[0].erase(mts[0].find(val)) ;
        mts[1].insert(val) ;
    }

    
    while(mts[1].size() > mts_size[1]){
        int val = *mts[1].rbegin() ;
        mts[1].erase(mts[1].find(val)) ;
        mts[2].insert(val) ;
    }

    return ;
}

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> N >> L >> a >> b ;

    a -- ;
    b -- ;

    for(int i = 0 ; i < N ; i ++ ){
        cin >> arr[i] ;
    }

    sort(arr , arr + N) ;

    for(int i = 0 ; i < a ; i ++ ){
        mts[0].insert(arr[i]) ;
    }
    for(int i = a ; i < b ; i ++ ){
        mts[1].insert(arr[i]) ;
    }
    for(int i = b ; i < N ; i ++ ){
        mts[2].insert(arr[i]) ;
    }

    mts_size[0] = a ;
    mts_size[1] = b - a ;
    mts_size[2] = N - b ;

    while(L -- ){
        
        auto iter_x = mts[1].begin() ;
        auto iter_y = mts[2].begin() ;

        x = *iter_x ;
        y = *iter_y ;

        mts[1].erase(iter_x) ;
        mts[2].erase(iter_y) ;

        mts[0].insert(y - x) ;
        mts[0].insert((x + y) >> 1) ;

        balance() ;
    }

    for(int i = 0 ; i < 3 ; i ++ ){
        for(int val : mts[i]){
            cout << val << ' ' ;
        }
    }

    return 0 ;
}