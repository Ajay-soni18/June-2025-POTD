/* 2929. Distribute Candies Among Children II :- 
You are given two positive integers n and limit.
Return the total number of ways to distribute n candies among 3 children such that no child gets more than limit candies.
*/

// Method 1 (Brute Force) :- 

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for(int i=0;i<limit+1;i++){
            for(int j=0;j<limit+1;j++){
                for(int k=0;k<limit+1;k++){
                    if(i+j+k==n) cnt++;
                }
            }
        }
        return cnt;
    }
};

// Time Complexity :- O(limit ^ 3);


// Method 2 :-

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long cnt = 0;
        for(int i=0;i<limit+1;i++){
            for(int j=0;j<limit+1;j++){
                int k = n-i-j;
                if(k>=0 && k<=limit) cnt++;
            }
        }
        return cnt;
    }
};

// Time Complexity :- O(limit ^ 2)


// Method 3 (Optimal Approach) :-

class Solution {
public:
    long long distributeCandies(int n, int limit) {
       long long ways = 0;
       // child1 
       int minch1 = max(0,n-2*limit);
       int maxch1 = min(n,limit);

       for(int i=minch1;i<=maxch1;i++){ // fixing for child 1 
            int N = n - i;
            int minch2 = max(0,N-limit);
            int maxch2 = min(N,limit);
            ways += (maxch2-minch2+1);
       }
       return ways;
    }
};

// Time Complexity :- O(maxch1-minch1)