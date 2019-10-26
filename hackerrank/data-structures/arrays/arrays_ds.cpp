// https://www.hackerrank.com/challenges/arrays-ds/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the reverseArray function below.
static vector<int> reverseArray(vector<int> a)
{
    // note 1: interface has copy of initial array
    // note 2: explicitly std::reverse can be used
    auto start = a.begin();
    auto end = a.end();
    for (--end; start < end; ++start, --end) {
        int tmp = *start;
        *start = *end;
        *end = tmp;
    }
    return a;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    size_t arr_count;
    cin >> arr_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(arr_count);

    for (size_t i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> res = reverseArray(arr);

    for (size_t i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

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

TEST (ReverseArray, ReverseArrayTestCase0)
{
    std::vector<int> in = {1, 4, 3, 2};
    std::vector<int> out = {2, 3, 4, 1};
    ASSERT_EQ(reverseArray(in), out);
}

TEST (ReverseArray, ReverseArrayTestCase1)
{
    std::vector<int> in = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> out = {7, 6, 5, 4, 3, 2, 1};
    ASSERT_EQ(reverseArray(in), out);
}

TEST (ReverseArray, ReverseArrayTestCase2)
{
    std::vector<int> in = {1, 2};
    std::vector<int> out = {2, 1};
    ASSERT_EQ(reverseArray(in), out);
}

TEST (ReverseArray, ReverseArrayTestCase3)
{
    std::vector<int> in = {};
    std::vector<int> out = {};
    ASSERT_EQ(reverseArray(in), out);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
