#include<bits/stdc++.h>

using namespace std;

vector<int>vec ;

long long arr[26][26] ;
long long MIN = LLONG_MAX ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    long long n ; cin >> n ;

    for(int i = 0 ; i < n ; i ++ ){
        vec.push_back(i) ;
    }

    for(int i = 0 ; i < n ; i ++ ){
        for(int j = 0 ;  j < n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }

    do {   
        long long sum = 0 ;
        for(int i = 0 ; i < n ; i ++ ){
            sum += arr[i][vec[i]] ;
        }
        MIN = min(MIN , sum) ;
    }while(next_permutation(vec.begin(),vec.end())) ;

    cout << MIN ;

    return 0 ;
}