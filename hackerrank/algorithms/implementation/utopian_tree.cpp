// https://www.hackerrank.com/challenges/utopian-tree/problem
#include <bits/stdc++.h>

using namespace std;

// Complete the utopianTree function below.
static int utopian_tree(int n)
{
    int height = 1;
    for (int cycle = 1; cycle <= n; ++cycle) {
        height += (cycle % 2 == 1 ? height : 1);
    }

    return height;
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

        int result = utopian_tree(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

#else

#include <gtest/gtest.h>

TEST (UtopianTree, HackerRankTestCase0)
{
    ASSERT_EQ(utopian_tree(0), 1);
}

TEST (UtopianTree, HackerRankTestCase1)
{
    ASSERT_EQ(utopian_tree(1), 2);
}

TEST (UtopianTree, HackerRankTestCase2)
{
    ASSERT_EQ(utopian_tree(4), 7);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
