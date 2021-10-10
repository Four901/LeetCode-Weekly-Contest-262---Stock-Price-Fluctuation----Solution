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
        vector<vector<int> >vec(n,vector<int>(5,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<5;j++)
            {
                cin>>vec[i][j];
            }
        }
        bool  ans=false;
        for(int j=0;j<4;j++)
        {
            
            for(int k=j+1;k<5;k++)
            {
               
                bool check=true;
                int one=0;
                int two=0;
                int rem=0;
                for(int i=0;i<n;i++)
                {
                    if(vec[i][j]==0&&vec[i][k]==0)
                    {
                        check=false;
                        break;
                    }
                    else if(vec[i][j]==0)
                    {
                        two++;
                    }
                    else if(vec[i][k]==0)
                    {
                        one++;
                    }
                    else
                    {
                        rem++;
                    }
                }
                if(check&&(abs(one-two)<=rem))
                {
                    ans=true;
                    j=5;
                    break;
                }
            }
        }
        if(ans)
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
