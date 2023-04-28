#include<bits/stdc++.h>

using namespace std;

struct node {
    int x , y , type ;

    bool operator < (const node & rhs)const {
        if(x != rhs.x)return x < rhs.x;
        if(y != rhs.y)return y < rhs.y;
        return type < rhs.type;
    }
};

map<node , node>mpp ;

node arr[12] ;

int main(){

    mpp[{1 , 2 ,3}] = {1 , 2 , 3} ;
    return 0 ;
}