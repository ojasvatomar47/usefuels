#include <bits/std+>
using namespace std;

int maxSubArray(const vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int max_sum = nums[0];
    int current_sum = nums[0];

    for (int i = 1; i < nums.size(); ++i)
    {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSubArray(nums);

    cout << "The maximum sum of a contiguous subarray is: " << result << endl;

    return 0;
}
