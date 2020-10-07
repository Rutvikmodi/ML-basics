#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        bool flag = 0;
        if(x == y)
            flag = 1;
        int temp = (x + k)%n;
        while(temp != x) {
            if(temp == y) {
                flag = 1;
                break;
            }
            temp = (temp + k)%n;
        }
        if(flag) {
            cout<<"YES\n";
        } else {
            cout<<"NO\n";
        }
    }
}