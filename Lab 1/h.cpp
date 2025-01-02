#include<bits/stdc++.h>
using namespace std;
int main(){
    double t,mid,low,high,d,big,small;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>d;
        if(d>0 && d<4){
            cout<<"N\n";
            continue;
        }
        if(d==4){
            cout<<"Y 2.000000000 2.000000000\n";
            continue;
        }
        low=0.0,high=d;
        int cnt=100;
        while(cnt--){
            mid=low+(high-low)/2.0;
            big=mid;
            small=(d-big);
            if(big*small>big+small){
                low=mid;
            }else{
                high=mid;
            }
        }
        printf("Y %.9f %.9f\n",big,small); 
    }
    return 0;
}