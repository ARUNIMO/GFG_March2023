/*

The task is to find the second smallest number with a given sum of digits as S and the number of digits as D.
Example 1:

Input:
S = 9 
D = 2
Output:
27
Explanation:
18 is the smallest number possible with sum = 9
and total digits = 2, Whereas the second
smallest is 27.
Example 2:

Input:
S = 16
D = 3
Output:
178
Explanation:
169 is the smallest number possible with sum is
16 and total digits = 3, Whereas the second
smallest is 178.

Your Task:
You don't need to read input or print anything. Your task is to complete the function secondSmallest() which takes the two integers S and D respectively and returns a string which is the second smallest number if possible, else return "-1".

Expected Time Complexity: O(D)
Expected Space Complexity: O(1)

Constraints:
1 ≤ S ≤ 105
1 ≤ D ≤ 105


*/

//CODE
//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        // code here 
          if(S>=D*9)
        return "-1";
        
        vector<int> num(D,0);
        
        num[0] = 1;
        
        S--;
        
        for(int i=D-1;i>=0;i--)
        {
            if(S>=9)
            {
                num[i] += 9;
                S-=9;
            }
            else
            {
                num[i] += S;
                S = 0;
            }
            
            if(num[i]>9)
            return "-1";
        }
        
        int idx = D-2;
        while(idx>=0 && num[idx]==9) idx--;
        
        num[idx]++;
        num[idx+1]--;
        
        string ans = "";
        for(int i=0;i<D;i++)
        {
            ans+=('0'+num[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends
