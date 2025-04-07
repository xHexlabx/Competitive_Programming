#include<bits/stdc++.h>
 
using namespace std;
 
struct event {
 
    int time , type ; // type = 0 -> out ; type = 1 -> in
    bool operator < (const event & rhs)const {
        if(time != rhs.time)return time < rhs.time;
        else return type < rhs.type;
    }
 
};
 
vector<event>events ;
 
int main(){
 
    ios_base :: sync_with_stdio(0) , cin.tie(0);
 
    int n , in , out , MAX = 0 , cnt = 0 ; cin >> n ; 
 
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> in >> out ;
        events.push_back({in , 1}) ;
        events.push_back({out , 0}) ;
    }
 
    sort(events.begin() , events.end()) ;
 
    for(auto temp : events ){
        
        int type = temp.type ;
 
        if(type == 0){
            cnt -- ;
        }
        else {
            cnt ++ ;
        }
        
        MAX = max(MAX , cnt) ;
    }
 
    cout << MAX ;
 
    return 0 ;
}