// https://www.hackerrank.com/challenges/strange-advertising/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the viral_advertising function below.
static int viral_advertising(int n)
{
    int cumulative = 0;
    int count = 5;
    for(int i = n; i > 0; --i) {
        cumulative += count / 2;
        count = (count / 2 * 3);
    }
    return cumulative;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = viral_advertising(n);

    fout << result << "\n";

    fout.close();

    return 0;
}

#else

#include <gtest/gtest.h>

TEST (ViralAdvertising, HackerRankTestCase0)
{
    ASSERT_EQ(viral_advertising(1), 2);
}

TEST (ViralAdvertising, HackerRankTestCase1)
{
    ASSERT_EQ(viral_advertising(2), 5);
}

TEST (ViralAdvertising, HackerRankTestCase2)
{
    ASSERT_EQ(viral_advertising(3), 9);
}

TEST (ViralAdvertising, HackerRankTestCase3)
{
    ASSERT_EQ(viral_advertising(4), 15);
}

TEST (ViralAdvertising, HackerRankTestCase4)
{
    ASSERT_EQ(viral_advertising(5), 24);
}

TEST (ViralAdvertising, ZeroCase)
{
    ASSERT_EQ(viral_advertising(0), 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
