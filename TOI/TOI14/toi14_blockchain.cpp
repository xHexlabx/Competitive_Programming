#include<bits/stdc++.h> 
using namespace std ;
map<vector<pair<int,int>> , int>mpp ;
vector<pair<int,int>> blockchain(){
    
    int x , y , sz ; cin >> sz ;
    vector<pair<int,int>>vec ;
    for(int i = 0 ; i < sz - 1; i ++ ){
        cin >> x >> y ;
        vec.push_back({min(x , y) , max(x , y)});
    }
    sort(vec.begin(),vec.end());
    return vec ;
}
int main (){
    ios_base :: sync_with_stdio(0),cin.tie(0);
    
    int n , q ; cin >> n >> q ;
    while(n -- )mpp[blockchain()]++ ;
    while(q -- )cout << mpp[blockchain()] << '\n';
    return 0 ;
}