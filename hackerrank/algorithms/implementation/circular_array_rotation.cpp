// https://www.hackerrank.com/challenges/circular-array-rotation/problem
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the circularArrayRotation function below.
static vector<size_t> circular_array_rotation(const vector<size_t>& a,
        size_t k,
        const vector<size_t>& queries)
{
    vector<size_t> result(queries.size(), 0);
    vector<size_t> rotated(a.size(), 0);

    k %= a.size();
    for(size_t i = 0; i < a.size(); ++i) {
        rotated[(i + k) % a.size()] = a[i];
    }

    for(size_t i = 0; i < queries.size(); ++i) {
        result[i] = rotated[queries[i]];
    }

    return result;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nkq_temp;
    getline(cin, nkq_temp);

    vector<string> nkq = split_string(nkq_temp);

    size_t n = stoul(nkq[0]);

    size_t k = stoul(nkq[1]);

    size_t q = stoul(nkq[2]);

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split_string(a_temp_temp);

    vector<size_t> a(n);

    for (size_t i = 0; i < n; i++) {
        size_t a_item = stoul(a_temp[i]);

        a[i] = a_item;
    }

    vector<size_t> queries(q);

    for (size_t i = 0; i < q; i++) {
        size_t queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<size_t> result = circular_array_rotation(a, k, queries);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
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

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

#else

#include "gtest/gtest.h"

TEST (CircularArrayRotation, HackerRankTestCase0)
{
    vector<size_t> a = {1, 2, 3};
    size_t k = 2;
    vector<size_t> queries = {0, 1, 2};
    vector<size_t> result = {2, 3, 1};
    ASSERT_EQ(circular_array_rotation(a, k, queries), result);
}

TEST (CircularArrayRotation, MoveFurtherThanLength)
{
    vector<size_t> a = {1, 2, 3};
    size_t k = 4;
    vector<size_t> queries = {0, 1, 2};
    vector<size_t> result = {3, 1, 2};
    ASSERT_EQ(circular_array_rotation(a, k, queries), result);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
