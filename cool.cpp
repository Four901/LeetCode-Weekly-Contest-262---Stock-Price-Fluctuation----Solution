#include <bits/stdc++.h> // header file includes every Standard library
#define ll long long 
using namespace std;

int main() {

	//kghvgu Your code here klj
    ll N;
    cin>>N;
    vector<pair<ll,ll> >vec;
    ll x,y;
    for(ll i=0;i<N;i++)
    {
        cin>>x>>y;
        vec.push_back({x,y});
    }
    unordered_map<double,vector<pair<ll,ll> > >mp;
    for(ll i=0;i<N-1;i++)
    {
        for(ll j=i+1;j<N;j++)
        {
           if(vec[j].first-vec[i].first==0)
           {
              mp[INT_MIN].push_back({i,j});
           }
           else
           {
           mp[double((vec[j].second-vec[i].second)/(vec[j].first-vec[i].first))].push_back({i,j});
           }
        }
    }
    ll ans=0;
    for(auto slope:mp)
    {
        vector<ll>vc=slope.second;
        for(int i=0;i<vc.size()-1;i++)
        {
            for(ll j=i+1;j<vc.size();j++)
            {
                ll x1,y1,x2,y2,x3,y3,x4,y4;
                x1=vec[vc[i].first].first;
                y1=vec[vc[i].first].second;
                x2=vec[vc[i].second].first;
                y2=vec[vc[i].second].second;
                x3=vec[vc[j].first].first;
                y3=vec[vc[j].first].second;
                x4=vec[vc[j].second].first;
                y4=vec[vc[j].second].second;
               // 1&3 == 2&4
               int slope1,slope2;
               if(x3-x1==0)
               {
                   slope1=INT_MIN;
               }
               else{
                   slope1=double((y3-y1)/(x3-x1));
               }
               if(x4-x2==0)
               {
                   slope2=INT_MIN;
               }
               else
               {
                   slope2=double((y4-y2)/(x4-x2));
               }
               
               if(slope1==slope2)
               {
                   //1&2 3&4
                   //1 &3  2&4
     if(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)==(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4))&&((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1)==(x2-x4)*(x2-x4)+(y2-y4)*(y2-y4)))
     {

ans=max(ans,(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1))));

     }



               }


               //1%4= 2&3

              if(x4-x1==0)
               {
                   slope1=INT_MIN;
               }
               else{
                   slope1=double((y4-y1)/(x4-x1));
               }
               if(x3-x2==0)
               {
                   slope2=INT_MIN;
               }
               else
               {
                   slope2=double((y3-y2)/(x3-x2));
               }
               
               if(slope1==slope2)
               {
                   //1&2 3&4
                   //1 &3  2&4
     if(((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1)==(x3-x2)*(x3-x2)+(y3-y2)*(y3-y2))&&((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)==(x3-x4)*(x3-x4)+(y3-y4)*(y3-y4)))
     {

ans=max(ans,(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1))*((x4-x1)*(x4-x1)+(y4-y1)*(y4-y1))));

     }
            }
        }
    }
    cout<<ans;
	return 0;
}