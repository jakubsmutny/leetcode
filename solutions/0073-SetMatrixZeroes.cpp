class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = m ? matrix[0].size() : 0;
        bool firstColZero = false;
        bool firstRowZero = false;
        for(int i = 0; i < m; ++i)
            if(!matrix[i][0])
                firstColZero = true;
        for(int j = 0; j < n; ++j)
            if(!matrix[0][j])
                firstRowZero = true;
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        for(int i = 1; i < m; ++i)
            if(!matrix[i][0])
                for(int j = 1; j < n; ++j)
                    matrix[i][j] = 0;
        for(int j = 1; j < n; ++j)
            if(!matrix[0][j])
                for(int i = 1; i < m; ++i)
                    matrix[i][j] = 0;
        if(firstColZero)
            for(int i = 0; i < m; ++i)
                matrix[i][0] = 0;
        if(firstRowZero)
            for(int j = 0; j < n; ++j)
                matrix[0][j] = 0;
    }
};
