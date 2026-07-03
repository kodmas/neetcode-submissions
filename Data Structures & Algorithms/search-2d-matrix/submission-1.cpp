class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int l = 0;
        int r = m-1;
        int mid;
        int correct_row = -1;
        while(l <= r){
            mid = (l+r)/2;
            // cout << matrix[mid][0] << " " << matrix[mid][n-1]<< endl;
            if(target <= matrix[mid][n-1] && target >= matrix[mid][0]){
                correct_row = mid;
                break;
            }
            else if(target > matrix[mid][n-1]) l = mid+1;
            else r = mid-1;
        }
        // cout << correct_row << endl;
        if(correct_row == -1) return false;

        l = 0;
        r = n-1;

        while(l <= r){
            mid = (l+r)/2;
            if(target == matrix[correct_row][mid]) return true;
            else if(target > matrix[correct_row][mid]) l = mid+1;
            else r = mid-1;
        }

        return false;

    }
};
