#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        vector<vector<int> >vec(2,vector<int>(n+1,0));
        char ch;
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            if(ch=='1')
            {
                vec[0][i]=1;
            }
        }
        for(int i=0;i<n;i++)
        {
            cin>>ch;
            if(ch=='1')
            {
                vec[1][i]=1;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(vec[0][i]==0&&(vec[0][i-1]==0||vec[1][i-1]==0))
            {
                vec[0][i]=0;
            }
            else
            {
                vec[0][i]=1;
            }
             if(vec[1][i]==0&&(vec[0][i-1]==0||vec[1][i-1]==0))
            {
                vec[1][i]=0;
            }
            else
            {
                vec[1][i]=1;
            }
        }
        if(vec[1][n-1]==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
