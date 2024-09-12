#include <vector>
#include <iostream>
using namespace std;

// Function to compute the prefix sum matrix
vector<vector<int>> computePrefixSum(const vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> prefixSum(n, vector<int>(m, 0));

    // Compute prefix sum matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            prefixSum[i][j] = matrix[i][j];
            if (i > 0)
                prefixSum[i][j] += prefixSum[i - 1][j];
            if (j > 0)
                prefixSum[i][j] += prefixSum[i][j - 1];
            if (i > 0 && j > 0)
                prefixSum[i][j] -= prefixSum[i - 1][j - 1];
        }
    }

    return prefixSum;
}

// Function to query the sum of the submatrix from (a, b) to (c, d)
int querySubmatrixSum(const vector<vector<int>> &prefixSum, int x1, int y1, int x2, int y2)
{
    int sum = prefixSum[x2][y2];

    if (x1 > 0)
        sum -= prefixSum[x1 - 1][y2];
    if (y1 > 0)
        sum -= prefixSum[x2][y1 - 1];
    if (x1 > 0 && y1 > 0)
        sum += prefixSum[x1 - 1][y1 - 1];

    return sum;
}

int main()
{
    // Example usage
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Compute the prefix sum matrix
    vector<vector<int>> prefixSum = computePrefixSum(matrix);

    // Query the sum of submatrix from (1, 1) to (2, 2)
    int result = querySubmatrixSum(prefixSum, 1, 1, 2, 2);
    cout << "Sum of submatrix from (1, 1) to (2, 2) is: " << result << endl; // Output should be 28

    return 0;
}
