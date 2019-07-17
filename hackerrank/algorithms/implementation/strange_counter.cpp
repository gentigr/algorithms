// https://www.hackerrank.com/challenges/strange-code/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
static long strange_counter(long t)
{
    long time = 1;
    long value = 3;
    for (; time <= t; time += value, value *= 2);
    if (time != 1) {
        value /= 2;
        time -= value;
    }
    return value - (t - time);
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    long t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = strange_counter(t);

    fout << result << "\n";

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (StrangeCounter, HackerRankTestCase0)
{
    ASSERT_EQ(strange_counter(4), 6);
}

TEST (StrangeCounter, HackerRankTestCase11)
{
    ASSERT_EQ(strange_counter(17), 5);
}

TEST (StrangeCounter, LocalTestCase0)
{
    ASSERT_EQ(strange_counter(1000000000000000), 688849860263934);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
