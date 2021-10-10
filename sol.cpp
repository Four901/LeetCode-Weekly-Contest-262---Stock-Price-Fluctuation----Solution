class Solution {
public:

    int minOperations(vector<vector<int>>& vec, int x) {
        
        
        
        int n=vec.size();
        int m=vec[0].size();
        vector<int> arr(n * m, 0);
 
       for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i * m + j] = vec[i][j];
            if (vec[i][j] % x != vec[0][0]%x) {
                return -1;
              }
           }
        }
 
  
    sort(arr.begin(), arr.end());
 
    int mid = arr[(n * m) / 2];
 

    int ans = 0;
    for (int i = 0; i < n * m; ++i)
        ans += abs(arr[i] - mid) / x;
 
    if((n*m)%2!=0)
    {
        int ans1;
        if((n*m)/2-1>=0)
        {
              mid = arr[( (n * m) / 2) - 1];
        ans1 = 0;
       for (int i = 0; i < n * m; ++i)
          ans1 += abs(arr[i] - mid) / x;
 
       ans = min(ans, ans1);
        }
       
        if((n*m)/2+1<n*m)
        {
             mid = arr[( (n * m) / 2) + 1];
            ans1 = 0;
           for (int i = 0; i < n * m; ++i)
            ans1 += abs(arr[i] - mid) / x;
        }
      
 
       ans = min(ans, ans1);
    }
      
    
 

    return ans;
    }
};