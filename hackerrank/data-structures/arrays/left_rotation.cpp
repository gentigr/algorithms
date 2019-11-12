// https://www.hackerrank.com/challenges/array-left-rotation/problem

#include <bits/stdc++.h>

using namespace std;

static std::vector<int> rotate_left(const std::vector<int>& in, size_t d)
{
    std::vector<int> out(in.size());
    for (size_t i = 0; i < in.size(); ++i) {
        out[i] = in[(i + d) % in.size()];
    }
    return out;
}

#ifndef TEST_BUILD

vector<string> split_string(string);

int main()
{
    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    size_t n = stoul(nd[0]);

    size_t d = stoul(nd[1]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<int> a(n);

    for (size_t i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    auto out = rotate_left(a, d);
    for (int i : out) {
        std::cout << i << " ";
    }

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(),
    input_string.end(), [] (const char& x, const char& y) {
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

TEST (RotateLeft, RotateLeftTestCase0)
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {5, 1, 2, 3, 4};
    ASSERT_EQ(rotate_left(a, 4), b);
}

TEST (RotateLeft, RotateLeftTestCase1)
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 2, 3, 4, 5};
    ASSERT_EQ(rotate_left(a, 0), b);
}

TEST (RotateLeft, RotateLeftTestCase2)
{
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::vector<int> b = {1, 2, 3, 4, 5};
    ASSERT_EQ(rotate_left(a, 5), b);
}

TEST (RotateLeft, RotateLeftTestCase3)
{
    std::vector<int> a = {};
    std::vector<int> b = {};
    ASSERT_EQ(rotate_left(a, 100), b);
}

TEST (RotateLeft, RotateLeftTestCase4)
{
    std::vector<int> a = {1};
    std::vector<int> b = {1};
    ASSERT_EQ(rotate_left(a, 100), b);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
