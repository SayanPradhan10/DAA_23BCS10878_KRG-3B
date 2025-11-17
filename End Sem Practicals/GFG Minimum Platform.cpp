class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {

        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platforms = 1;     // current platforms needed
        int maxPlatforms = 1;  // result
        int i = 1, j = 0;      
        
        // Step 2: Two pointer comparison
        while (i < n && j < n) {
            
      // If train arrives before previous one departs, add a platform
            if (arr[i] <= dep[j]) {
                platforms++;
                i++;
            }
            // One train departed  free a platform
            else {
                platforms--;
                j++;
            }
            
            // Update max required platforms
            maxPlatforms = max(maxPlatforms, platforms);
        }
        
        return maxPlatforms;
    }
};




