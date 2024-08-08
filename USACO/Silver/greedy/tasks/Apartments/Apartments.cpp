#include<bits/stdc++.h>

using namespace std ;

const int Size = 2e5 + 1 ;
int n , m , k , i = 0 , j = 0 , res = 0;
int reqs [Size] , apartments [Size] ;

int main() {

    ios_base :: sync_with_stdio(0) , cin.tie(0) ;

    cin >> n >> m >> k ;

    for(int i = 0 ; i < n ; i ++ )cin >> reqs[i] ;
    for(int j = 0 ; j < m ; j ++ )cin >> apartments[j] ;
    
    sort(reqs , reqs + n) ;
    sort(apartments , apartments + m) ;

    while(i < n && j < m){

        if(reqs[i] >= apartments[j] - k && reqs[i] <= apartments[j] + k){
            res ++ ;
            i ++ ;
            j ++ ;
        }
        else if (reqs[i] > apartments[j] + k){
            j ++ ;
        }
        else {
            i ++ ;
        }
    }

    cout << res ;

    return 0 ;
}