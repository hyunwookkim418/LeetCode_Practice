#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    int nums_size = nums.size();

    for (int i = 0; i < nums_size; i++)
    {
        s.insert(nums[i]);
    }

    int answer = 0;
    int set_size = s.size();

    if ((nums_size / 2) <= set_size)
    {
        answer = (nums_size / 2);
    }
    else
    {
        answer = set_size;
    }
    return answer;
}
