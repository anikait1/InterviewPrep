#include <vector>

int longestOnes(vector<int> &A, int K)
{
    int count = 0;
    int start = 0;
    int ans = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        if (A[i] == 0)
            count += 1;

        while (count > K)
        {
            if (A[start] == 0)
                count -= 1;

            start += 1;
        }

        ans = std::max(ans, i - start + 1);
    }

    return ans;
}

int main()
{
    return 0;
}