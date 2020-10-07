#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++) {
            cin>>v[i];
        }
        ll carry = 0, sum = 0, ans = 0;
        for(int i=1;i<=n;i++) {
            sum += v[i] + carry;
            if(sum < k) {
                ans = i;
                break;
            }
            sum -= k;
        }
        if(ans == 0) {
            ans = n + 1 + sum/k;
        }
        cout<<ans<<"\n";
    }
}