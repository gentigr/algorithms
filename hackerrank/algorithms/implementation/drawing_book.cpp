// https://www.hackerrank.com/challenges/drawing-book/problem
#include <iostream>
#include <bits/stdc++.h>

static int page_count(int n, int p)
{
    int a = n / 2;
    int b = p / 2;
    return (a - b < b) ? a - b : b;
}

#ifndef TEST_BUILD

// this part was taken from hackerrank, codestyle is preserved
int main()
{
    std::ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int p;
    std::cin >> p;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int result = page_count(n, p);

    fout << result << "\n";

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (PageCountTest, OneOne)
{
    ASSERT_EQ(page_count(1, 1), 0);
}

TEST (PageCountTest, TwoOne)
{
    ASSERT_EQ(page_count(2, 1), 0);
}

TEST (PageCountTest, TwoTwo)
{
    ASSERT_EQ(page_count(2, 2), 0);
}

TEST (PageCountTest, ThreeOne)
{
    ASSERT_EQ(page_count(3, 1), 0);
}

TEST (PageCountTest, ThreeTwo)
{
    ASSERT_EQ(page_count(3, 2), 0);
}

TEST (PageCountTest, ThreeThree)
{
    ASSERT_EQ(page_count(3, 3), 0);
}

TEST (PageCountTest, FourOne)
{
    ASSERT_EQ(page_count(4, 1), 0);
}

TEST (PageCountTest, FourTwo)
{
    ASSERT_EQ(page_count(4, 2), 1);
}

TEST (PageCountTest, FourThree)
{
    ASSERT_EQ(page_count(4, 3), 1);
}

TEST (PageCountTest, FourFour)
{
    ASSERT_EQ(page_count(4, 4), 0);
}

TEST (PageCountTest, FiveOne)
{
    ASSERT_EQ(page_count(5, 1), 0);
}

TEST (PageCountTest, FiveTwo)
{
    ASSERT_EQ(page_count(5, 2), 1);
}

TEST (PageCountTest, FiveThree)
{
    ASSERT_EQ(page_count(5, 3), 1);
}

TEST (PageCountTest, FiveFour)
{
    ASSERT_EQ(page_count(5, 4), 0);
}

TEST (PageCountTest, FiveFive)
{
    ASSERT_EQ(page_count(5, 5), 0);
}

TEST (PageCountTest, SixOne)
{
    ASSERT_EQ(page_count(6, 1), 0);
}

TEST (PageCountTest, SixTwo)
{
    ASSERT_EQ(page_count(6, 2), 1);
}

TEST (PageCountTest, SixThree)
{
    ASSERT_EQ(page_count(6, 3), 1);
}

TEST (PageCountTest, SixFour)
{
    ASSERT_EQ(page_count(6, 4), 1);
}

TEST (PageCountTest, SixFive)
{
    ASSERT_EQ(page_count(6, 5), 1);
}

TEST (PageCountTest, SixSix)
{
    ASSERT_EQ(page_count(6, 6), 0);
}

TEST (PageCountTest, SevenOne)
{
    ASSERT_EQ(page_count(7, 1), 0);
}

TEST (PageCountTest, SevenTwo)
{
    ASSERT_EQ(page_count(7, 2), 1);
}

TEST (PageCountTest, SevenThree)
{
    ASSERT_EQ(page_count(7, 3), 1);
}

TEST (PageCountTest, SevenFour)
{
    ASSERT_EQ(page_count(7, 4), 1);
}

TEST (PageCountTest, SevenFive)
{
    ASSERT_EQ(page_count(7, 5), 1);
}

TEST (PageCountTest, SevenSix)
{
    ASSERT_EQ(page_count(7, 6), 0);
}

TEST (PageCountTest, SevenSeven)
{
    ASSERT_EQ(page_count(7, 7), 0);
}

TEST (PageCountTest, EightOne)
{
    ASSERT_EQ(page_count(8, 1), 0);
}

TEST (PageCountTest, EightTwo)
{
    ASSERT_EQ(page_count(8, 2), 1);
}

TEST (PageCountTest, EightThree)
{
    ASSERT_EQ(page_count(8, 3), 1);
}

TEST (PageCountTest, EightFour)
{
    ASSERT_EQ(page_count(8, 4), 2);
}

TEST (PageCountTest, EightFive)
{
    ASSERT_EQ(page_count(8, 5), 2);
}

TEST (PageCountTest, EightSix)
{
    ASSERT_EQ(page_count(8, 6), 1);
}

TEST (PageCountTest, EightSeven)
{
    ASSERT_EQ(page_count(8, 7), 1);
}

TEST (PageCountTest, EightEight)
{
    ASSERT_EQ(page_count(8, 8), 0);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
