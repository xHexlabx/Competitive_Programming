#include<bits/stdc++.h>

using namespace std ;

int prio(char op){
    if(op == '3')return 3 ;
    if(op == '2')return 2 ;
    if(op == '1')return 1 ;
    return 0 ;
}
bool is_operator(char op){
    if(op == '1' || op == '2' || op == '3' || op == '[' || op == ']')return true ;
    return false ;
}
int cal(int a, int b , char op){
	
	if(op == '1')return (a + b) + (a + b) * 4 / 100 ;
	if(op == '2')return (a + b) + (a + b) * 8 / 100 ;
	if(op == '3')return (a + b) + (a + b) * 16 / 100 ;
	return 0 ;
}
stack<int>st;

int main(){

    ios_base::sync_with_stdio(0) , cin.tie(0);

    string expression , postfix ; cin >> expression ;
    for(char i : expression){
        if(!is_operator(i)){
            postfix += i ;
        }
        else if(i == '[')st.push(i) ;
        else if(i == ']'){
            while(st.top() != '['){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && prio(i) <= prio(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    for(char i : postfix){
        if(!is_operator(i)){
            st.push(20);
        }
        else {
            int x , y ;
            x = st.top() ; st.pop() ;
            y = st.top() ; st.pop() ;
            st.push(cal(x , y , i)) ;
        }
    }
    cout << st.top();
    return 0 ;
}