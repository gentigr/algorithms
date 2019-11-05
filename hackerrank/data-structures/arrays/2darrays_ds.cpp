// https://www.hackerrank.com/challenges/2d-array/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
static int hourglassSum(vector<vector<int>> arr)
{
    std::vector<int> results;
    for (size_t i = 0; i < arr.size() - 2; ++i) {
        for (size_t j = 0; j < arr[i].size() - 2; ++j) {
            int sum = arr[i][j] + arr[i][j + 1] + arr[i][j + 2];
            sum += arr[i + 1][j + 1];
            sum += arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2];
            results.push_back(sum);
        }
    }
    return *(std::max_element(results.begin(), results.end()));
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);
    for (size_t i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (size_t j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (hourglassSum, hourglassSumTestCase0)
{
    std::vector<std::vector<int>> a = {
        {1, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {0, 0, 2, 4, 4, 0},
        {0, 0, 0, 2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };
    ASSERT_EQ(hourglassSum(a), 19);
}

TEST (hourglassSum, hourglassSumTestCase1)
{
    std::vector<std::vector<int>> a = {
        {-9, -9, -9, 1, 1, 1},
        {0, -9, 0, 4, 3, 2},
        {-9, -9, -9, 1, 2, 3},
        {0, 0, 8, 6, 6, 0},
        {0, 0, 0, -2, 0, 0},
        {0, 0, 1, 2, 4, 0}
    };
    ASSERT_EQ(hourglassSum(a), 28);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
