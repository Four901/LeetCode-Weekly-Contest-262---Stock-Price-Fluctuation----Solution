class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3)
    {
        set<int>s1,s2,s3;
        map<int,int>mp;
        for(auto v:nums1)
        {
            s1.insert(v);
        }
        for(auto v:nums2)
        {
            s2.insert(v);
        }
        for(auto v:nums3)
        {
            s3.insert(v);
        }
        for(auto v:s1)
        {
            mp[v]++;
        }
        for(auto v:s2)
        {
            mp[v]++;
        }
        for(auto v:s3)
        {
            mp[v]++;
        }
        vector<int>ans;
        for(auto v:mp)
        {
            if(v.second>=2)
            {
                ans.push_back(v.first);
            }
        }
        return ans;
    }
};