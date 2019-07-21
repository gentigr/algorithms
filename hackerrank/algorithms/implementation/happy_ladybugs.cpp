// https://www.hackerrank.com/challenges/happy-ladybugs/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
static string happy_ladybugs(const string& b)
{
    bool is_happy = false;

    vector<pair<char, int>> stats;
    stats.push_back(make_pair(' ', 0));
    for_each(b.cbegin(), b.cend(), [&stats](char a) {
        auto& last = stats.back();
        if (last.first == a) {
            ++last.second;
        } else {
            stats.push_back(make_pair(a, 1));
        }
    });

    bool has_alone = any_of(stats.cbegin(), stats.cend(),
    [](const pair<char, int>& kv) {
        return kv.second == 1 && kv.first != '_';
    });
    if (has_alone) {
        bool has_underscore = any_of(stats.cbegin(),
        stats.cend(), [](const pair<char, int>& kv) {
            return kv.first == '_';
        });
        if (has_underscore) {
            unordered_map<char, int> s;
            for_each(b.cbegin(), b.cend(), [&s](char a) {
                ++s[a];
            });
            s.erase('_');
            is_happy = !any_of(s.cbegin(), s.cend(),
            [](const pair<char, int>& kv) {
                return kv.second == 1;
            });
        }
    } else {
        is_happy = true;
    }

    return is_happy ? "YES" : "NO";
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happy_ladybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (HappyLadybugs, HackerRankTestCase0)
{
    ASSERT_EQ(happy_ladybugs("RBY_YBR"), "YES");
    ASSERT_EQ(happy_ladybugs("X_Y__X"), "NO");
    ASSERT_EQ(happy_ladybugs("__"), "YES");
    ASSERT_EQ(happy_ladybugs("B_RRBR"), "YES");
}

TEST (HappyLadybugs, HackerRankTestCase1)
{
    ASSERT_EQ(happy_ladybugs("AABBC"), "NO");
    ASSERT_EQ(happy_ladybugs("AABBC_C"), "YES");
    ASSERT_EQ(happy_ladybugs("_"), "YES");
    ASSERT_EQ(happy_ladybugs("DD__FQ_QQF"), "YES");
    ASSERT_EQ(happy_ladybugs("AABCBC"), "NO");
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
