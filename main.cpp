#include<bits/stdc++.h>
#include<algorithm>

using namespace std;

int t,m;
vector<int> a(133),p;

int main(){
    //freopen("balls.in","r",stdin);
    //freopen("balls.out","w",stdout);
    cin>>t;
    a[1]=1;
    p.push_back(1);
    for(int i=2;i<126;i++)
        a[i]=a[i-1]+i;
    int dp[400009];
    for(int i=1;i<=300000;i++)
        dp[i]=222;
    dp[1]=1;
    for(int i=1;i<125;i++){
        p.push_back(p[i-1]+a[i+1]);
        dp[p[i]]=1;
    }
    for(int i=1;i<=300000;i++)
        if(!binary_search(p.begin(),p.end(),i)){
            int pos=lower_bound(p.begin(),p.end(),i)-p.begin();
            pos--;
            for(int j=0;j<=pos;j++)
                dp[i]=min(dp[i],dp[i-p[j]]+dp[p[j]]);
        }
        else
            dp[i]=1;
    for(int i=1;i<=t;i++){
        int x;
        cin>>x;
        cout<<dp[x]<<endl;
    }
    return 0;
}
