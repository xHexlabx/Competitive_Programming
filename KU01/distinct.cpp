#include<bits/stdc++.h>

using namespace std;

long long qs[101] ;
map<int , bool>mpp ;
int cnt = 0 ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    int n ; cin >> n ;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> qs[i] ;
        qs[i] += qs[i - 1] ;
    }

    for(int i = 1 ; i <= n ; i ++ ){
        for(int j = i - 1 ; j >= 0; j -- ){
            if(mpp[qs[i] - qs[j]] == false)cnt ++ ;
            mpp[qs[i] - qs[j]] = true;
        }
    }

    cout << cnt ;
    
    return 0 ;
}