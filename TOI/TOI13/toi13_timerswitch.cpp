#include<bits/stdc++.h>
using namespace std;
const long long hashcode = 3 ;
long long hashFuction(string s){
	int n = s.length();
	long long hashed = 0;
	for(int i=0;i<n;i++){
		hashed *= hashcode;
		hashed += s[i] - '0';
	}
	return hashed;
}
main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	long long maxMultiple = 1, currentHashed = hashFuction(s), target = currentHashed;
	for(int i=0;i<n-1;i++)
		maxMultiple *= hashcode;
	for(int i=0;i<n;i++){
		currentHashed -= (s[i]-'0') * maxMultiple;
		currentHashed *= hashcode;
		currentHashed += s[i] - '0';
		
		if(currentHashed == target){
			int same = true;
			string ss = s + s;
			for(int j=0;j<n;j++){
				if(ss[i+j+1] != s[j]){
					same = false;
					break;
				}
			}
			if(same){
				cout << i+1;
				break;
			}
		}
	}
}