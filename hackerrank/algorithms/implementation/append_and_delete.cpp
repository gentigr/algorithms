// https://www.hackerrank.com/challenges/append-and-delete/problem
#include <bits/stdc++.h>

using namespace std;

static size_t find_index_of_first_different_character(const string& a,
                                                      const string& b)
{
    size_t i = 0;
    for (; i < a.size() && a[i] == b[i]; ++i);
    return i;
}

// Complete the append_and_delete function below.
static string append_and_delete(const string& s, const string& t, size_t k)
{
    size_t i = find_index_of_first_different_character(s, t);

    if (k < (s.size() - i) + (t.size() - i)) {
        return "No";
    }
    k -= (s.size() - i) + (t.size() - i);

    return (k == 0 || k % 2 == 0 || k > (i * 2)) ? "Yes" : "No";
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    size_t k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = append_and_delete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (AppendAndDelete, HackerRankTestCase0)
{
    ASSERT_EQ(append_and_delete("hackerhappy", "hackerrank", 9), "Yes");
}

TEST (AppendAndDelete, HackerRankTestCase1)
{
    ASSERT_EQ(append_and_delete("aba", "aba", 7), "Yes");
}

TEST (AppendAndDelete, HackerRankTestCase2)
{
    ASSERT_EQ(append_and_delete("ashley", "ash", 2), "No");
}

TEST (AppendAndDelete, LocalTestCase0)
{
    ASSERT_EQ(append_and_delete("ashley", "ashp", 5), "No");
}

TEST (AppendAndDelete, CommentsTestCaseA)
{
    ASSERT_EQ(append_and_delete("123456789", "1", 5), "No");
}

TEST (AppendAndDelete, CommentsTestCaseB1)
{
    ASSERT_EQ(append_and_delete("010101", "01010", 1), "Yes");
}

TEST (AppendAndDelete, CommentsTestCaseB2)
{
    ASSERT_EQ(append_and_delete("010101", "010101", 1), "No");
}

TEST (AppendAndDelete, CommentsTestCaseB3)
{
    ASSERT_EQ(append_and_delete("010101", "010101", 13), "Yes");
}

TEST (AppendAndDelete, CommentsTestCaseC)
{
    ASSERT_EQ(append_and_delete("1", "101", 5), "Yes");
}

TEST (AppendAndDelete, HackerRankTestCase10)
{
    ASSERT_EQ(append_and_delete("abcd", "abcdert", 10), "No");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
