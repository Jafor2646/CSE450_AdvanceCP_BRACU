#include<bits/stdc++.h>
using namespace std;
int a[16][16];
int dp[16][1<<16];
int n;
int bitmask(int i,int mask)
{
    if(mask==(1<<n)-1) //base case
        return 0;
    int &ans=dp[i][mask];
    if(ans!=-1)
        return dp[i][mask];
    for(int j=0; j<n; j++)
    {
        if((mask&(1<<j))==0)
        {
            ans=max(ans,a[i][j]+bitmask(i+1,mask|(1<<j)));
        }
    }
    return ans;
}

main()
{
    int t;
    cin>>t;
    for(int k=1; k<=t; k++)
    {
        cin>>n;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>a[i][j];
            }
        }
        memset(dp,-1,sizeof dp);
        cout<<"Case "<<k<<": "<<bitmask(0,0)<<endl;
    }
}