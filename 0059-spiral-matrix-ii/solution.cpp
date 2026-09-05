class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int row = n;
        int col = n;
        int top = 0, bottom = row - 1, left = 0, right = col - 1;
        // Implementation for spiral order traversal

        int cnt=1;
        // Implementation for spiral order traversal

        while(top <= bottom && left <= right)
        {
            // Traverse right
            for(int i = left; i <= right; i++)
            {
                matrix[top][i]=cnt;
                cnt++;
            }
            top++;

            // Traverse down
            for(int i = top; i <= bottom; i++)
            {
                matrix[i][right]=cnt;
                cnt++;
            }
            right--;

            // Traverse left
            if(top <= bottom)
            {
                for(int i = right; i >= left; i--)
                {
                    matrix[bottom][i]=cnt;
                cnt++;
                }
                bottom--;
            }

            // Traverse up
            if(left <= right)
            {
                for(int i = bottom; i >= top; i--)
                {
                    matrix[i][left]=cnt;
                cnt++;
                }
                left++;
            }
        }

        return matrix;
    }
};
