class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        // 1. Initialize matrix correctly with m rows and n columns
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        
        // 2. Set the correct boundaries based on m and n
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        // Loop runs until we run out of matrix space OR the linked list ends
        while(top <= bottom && left <= right && head != nullptr)
        {
            // Traverse right
            for(int i = left; i <= right && head != nullptr; i++)
            {
                matrix[top][i] = head->val;
                head = head->next;
            }
            top++;

            // Traverse down
            for(int i = top; i <= bottom && head != nullptr; i++)
            {
                matrix[i][right] = head->val;
                head = head->next;
            }
            right--;

            // Traverse left
            if(top <= bottom)
            {
                for(int i = right; i >= left && head != nullptr; i--)
                {
                    matrix[bottom][i] = head->val;
                    head = head->next;
                }
                bottom--;
            }

            // Traverse up
            if(left <= right)
            {
                for(int i = bottom; i >= top && head != nullptr; i--)
                {
                    matrix[i][left] = head->val;
                    head = head->next;
                }
                left++;
            }
        }

        return matrix;
    }
};

