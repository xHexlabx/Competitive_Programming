#include<bits/stdc++.h>
using namespace std;
int arr[2002][2002] , qs[2002][2002] , rqs[2002][2002] , tri[2002][2002] , rtri[2002][2002] ;
int MAX = INT_MIN , m , n , k;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0);
    cin >> m >> n >> k ;
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            cin >> arr[i][j] ;
        }
    }
    for(int i = 1 ; i <= m ; i ++ ){
        for(int j = 1 ; j <= n ; j ++ ){
            qs[i][j] = arr[i][j] + qs[i][j - 1] + qs[i - 1][j] - qs[i - 1][j - 1];
            tri[i][j] = qs[i][j] - qs[i - 1][j] + tri[i - 1][j - 1] ;
        }
        for(int j = n ; j >= 1 ; j -- ){
            rqs[i][j] = arr[i][j] + rqs[i][j + 1] + rqs[i - 1][j] - rqs[i - 1][j + 1];
            rtri[i][j] = rqs[i][j] - rqs[i - 1][j] + rtri[i - 1][j + 1] ;
        }
    }
    for(int i = k ; i <= m ; i ++ ){
        for(int j = k ; j <= n ; j ++ ){
            MAX = max(MAX , tri[i][j] - qs[i][j - k] + qs[i - k][j - k] - tri[i - k][j - k]);
        }
        for(int j = n - k + 1 ; j >= 1 ; j -- ){
            MAX = max(MAX , rtri[i][j] - rqs[i][j + k] + rqs[i - k][j + k] - rtri[i - k][j + k]);
        }
    }
    cout << MAX ;
    return 0 ;
}