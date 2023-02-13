#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base :: sync_with_stdio(0) , cin.tie(0) ;
    vector<int>lnds ;
    int n , x ; cin >> n ;
    for(int i = 0 ; i < n ; i ++){
        cin >> x ;
        auto it = upper_bound(lnds.begin(), lnds.end() , x) ;
        if(it == lnds.end())lnds.push_back(x) ;
        else *it = x ;
    }
    cout << n - lnds.size() ; 
    return 0 ;
}