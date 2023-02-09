#include<bits/stdc++.h>
using namespace std;
int distance(int a,int b){
    return abs(a-b);
}
int main() {
    int n ; cin >> n;
    vector<int>t1(n);
    vector<int>t2(n);
    int sum = 0;
    for(int i = 0;i<n;i++){
        cin >> t1[i];
    }
    for(int i = 0;i<n;i++){
        cin >> t2[i];
    }
    sort(t1.begin(),t1.end());
    sort(t2.begin(),t2.end());
    for(int i = 0;i<n;i++){
        sum += distance(t1[i],t2[i]);
    }
    cout << sum;
    return 0;
}