// https://www.hackerrank.com/challenges/sock-merchant/problem
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
static size_t sock_merchant(size_t n, vector<size_t> ar)
{
    unordered_map<size_t, size_t> socks;

    for (const auto& sock : ar) {
        ++socks[sock];
    }

    size_t number_of_pairs = 0;
    for (const auto& num : socks) {
        number_of_pairs += num.second / 2;
    }

    return number_of_pairs;
}

#ifndef TEST_BUILD

// this part was taken from hackerrank, codestyle is preserved
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    size_t n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<size_t> ar(n);

    for (size_t i = 0; i < n; i++) {
        size_t ar_item = stoul(ar_temp[i]);

        ar[i] = ar_item;
    }

    size_t result = sock_merchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(),
    [] (const char& x, const char& y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos,
                                                input_string.length()) - i + 1));

    return splits;
}

#else

#include "gtest/gtest.h"

TEST (SockMerchantTest, HackerRankTestCase0)
{
    size_t n = 9;
    vector<size_t> ar = {10, 20, 20, 10, 10, 30, 50, 10, 20};
    ASSERT_EQ(sock_merchant(n, ar), 3);
}

TEST (SockMerchantTest, HackerRankTestCase1)
{
    size_t n = 10;
    vector<size_t> ar = {1, 1, 3, 1, 2, 1, 3, 3, 3, 3};
    ASSERT_EQ(sock_merchant(n, ar), 4);
}

TEST (SockMerchantTest, ZeroLength)
{
    size_t n = 0;
    vector<size_t> ar = {};
    ASSERT_EQ(sock_merchant(n, ar), 0);
}

TEST (SockMerchantTest, MaxLength)
{
    size_t n = 100;
    vector<size_t> ar = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
                         0, 1, 2, 3, 4, 5, 6, 7, 8, 9
                        };
    ASSERT_EQ(sock_merchant(n, ar), 50);
}

TEST (SockMerchantTest, ZeroPairs)
{
    size_t n = 9;
    vector<size_t> ar = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    ASSERT_EQ(sock_merchant(n, ar), 0);
}

TEST (SockMerchantTest, AllPairs)
{
    size_t n = 8;
    vector<size_t> ar = {1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(sock_merchant(n, ar), 4);
}

TEST (SockMerchantTest, AllPairsAndOne)
{
    size_t n = 9;
    vector<size_t> ar = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    ASSERT_EQ(sock_merchant(n, ar), 4);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
#endif
