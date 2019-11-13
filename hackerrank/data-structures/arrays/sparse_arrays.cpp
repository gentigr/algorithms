// https://www.hackerrank.com/challenges/sparse-arrays/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the matchingStrings function below.
static vector<int> matchingStrings(vector<string> strings,
                                   vector<string> queries)
{
    std::unordered_map<std::string, int> stats;
    for (const auto& str : strings) {
        stats[str] = stats[str] + 1;
    }
    std::vector<int> out;
    for (const auto& query : queries) {
        out.push_back(stats[query]);
    }
    return out;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    size_t strings_count;
    cin >> strings_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> strings(strings_count);

    for (size_t i = 0; i < strings_count; i++) {
        string strings_item;
        getline(cin, strings_item);

        strings[i] = strings_item;
    }

    size_t queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> queries(queries_count);

    for (size_t i = 0; i < queries_count; i++) {
        string queries_item;
        getline(cin, queries_item);

        queries[i] = queries_item;
    }

    vector<int> res = matchingStrings(strings, queries);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

#else

#include "gtest/gtest.h"

TEST (MatchingStrings, MatchingStringsTestCase0)
{
    std::vector<std::string> strs = {"aba", "baba", "aba", "xzxb"};
    std::vector<std::string> queries = {"aba", "xzxb", "ab"};
    std::vector<int> out = {2, 1, 0};
    ASSERT_EQ(matchingStrings(strs, queries), out);
}

TEST (MatchingStrings, MatchingStringsTestCase1)
{
    std::vector<std::string> strs = {"def", "de", "fgh"};
    std::vector<std::string> queries = {"de", "lmn", "fgh"};
    std::vector<int> out = {1, 0, 1};
    ASSERT_EQ(matchingStrings(strs, queries), out);
}

TEST (MatchingStrings, MatchingStringsTestCase2)
{
    std::vector<std::string> strs = {
        "abcde", "sdaklfj", "asdjf", "na",
        "basdn", "sdaklfj", "asdjf", "na",
        "asdjf", "na", "basdn", "sdaklfj",
        "asdjf"
    };
    std::vector<std::string> queries = {
        "abcde", "sdaklfj", "asdjf", "na", "basdn"
    };
    std::vector<int> out = {1, 3, 4, 3, 2};
    ASSERT_EQ(matchingStrings(strs, queries), out);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
