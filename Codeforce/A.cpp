#include<bits/stdc++.h>

using namespace std;

map<int , int>mpp ;


int arr[50] ;
int t ;

int main(){

    ios_base :: sync_with_stdio(0) , cin.tie(0);

    cin >> t ;

    while(t -- ){

        int n ; cin >> n ;
        mpp.clear() ;

        for(int i = 0 ; i < 2 * n - 2 ; i ++ ){
            cin >> arr[i] ;
            for(auto j : arr[i]){
                mpp[int(j)] ++ ;
            }
        }

        string s = "";

        int sz = 0 ;
        for(int i = int('a') ; i <= int('z') ; i ++ ){
            if(mpp[i]){
                sz ++ ;
                arr[sz] = int(mpp[i]);
            }
        }  

        cout << s << endl ;
    }

    return 0 ;
}n