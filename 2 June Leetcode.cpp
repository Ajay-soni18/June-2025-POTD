/*  135. Candy 

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
 
*/


// Method 1 :-

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>L2R(n,1);
        vector<int>R2L(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]){
                L2R[i]=L2R[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i]){
                R2L[i]=R2L[i+1]+1;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            count += max(L2R[i],R2L[i]);
        }
        return count;
    }
};

// Time Complexity :-  O(n) + O(n) + O(n)
// Space Complexity :- O(2n) (You can solve this using only 1 extra array)

// Method 2 :-

