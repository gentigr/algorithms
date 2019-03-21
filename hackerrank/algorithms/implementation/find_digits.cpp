// https://www.hackerrank.com/challenges/find-digits/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the findDigits function below.
static int find_digits(int n)
{
    int count = 0;
    for(int i = n; i > 0; i /= 10) {
        int divider = i % 10;
        count += (divider != 0 && n % divider == 0);
    }
    return count;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int result = find_digits(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (FindDigits, HackerRankTestCase0)
{
    ASSERT_EQ(find_digits(12), 2);
}

TEST (FindDigits, HackerRankTestCase1)
{
    ASSERT_EQ(find_digits(2012), 3);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
