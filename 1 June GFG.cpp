/*  Count pairs Sum in matrices

Given two matrices mat1[][] and mat2[][] of size n x n, where the elements in each matrix are arranged in strictly ascending order. Specifically, each row is sorted from left to right, and the last element of a row is smaller than the first element of the next row.
You're given a target value x, your task is to find and count all pairs {a, b} such that a is from mat1 and b is from mat2 where the sum of a + b is equal to x.
*/

// Brute Force :- 

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        unordered_set<int>s;
        for(int i=0;i<mat2.size();i++){
            for(int j=0;j<mat2[0].size();j++){
                s.insert(mat2[i][j]);
            }
        }
        int count = 0;
        for(int i=0;i<mat1.size();i++){
            for(int j=0;j<mat1[0].size();j++){
                int target = x - mat1[i][j];
                if(s.find(target)!=s.end()){
                    count++;
                    s.erase(target);
                }
            }
        }
        return count;
        
    }
};


// Time Complexity :- O(n^2) + O(n^2)
// Space Complexity :- O(n^2)


// Optimal Approach :- 

class Solution {
  public:
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int n = mat1.size();
        int i =0;
        int j = n*n-1;
        int count =0;
        while(i<n*n && j>=0){
            int r1 = i/n , c1 = i%n;
            int r2 = j/n , c2 = j%n;
            int val = mat1[r1][c1]+mat2[r2][c2];
            if(val==x){
                count++;
                i++;
                j--;
            }
            else if(val<x){
                i++;
            }
            else{
                j--;
            }
        }
        return count;
        
    }
};

// Time Complexity :- O(n^2)
// Space Complexity :- O(1);
