//
//  main.cpp
//  LeetCode54_SpiralMatrix
//
//  Created by Rui on 1/11/18.
//  Copyright © 2018 Rui. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.empty() || matrix[0].empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int c = m > n? (n + 1) / 2 : (m + 1) / 2;
        int p = m;
        int q = n;
        
        for(int i = 0; i < c; i++, p -= 2, q -= 2)
        {
            for(int col = i; col < i + q; col++)
            {
                res.push_back(matrix[i][col]);
            }
            
            for(int row = i + 1; row < i + p; row++)
                res.push_back(matrix[row][i + q - 1]);
            
            if(p == 1 || q == 1) break;
            
            for(int col = i + q - 2; col >= i; col--)
            {
                res.push_back(matrix[i + p - 1][col]);
            }
            
            for(int row = i + p - 2; row > i; row--)
            {
                res.push_back(matrix[row][i]);
            }
        }
        
        return res;
    }
};
