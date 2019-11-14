// https://www.hackerrank.com/challenges/crush/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the arrayManipulation function below.
static long arrayManipulation(size_t n, vector<vector<int>> queries)
{
    std::vector<long> out(n + 1);
    for (const auto& query : queries) {
        out[static_cast<size_t>(query[0]) - 1] += query[2];
        out[static_cast<size_t>(query[1])] -= query[2];
    }
    long max = out[0], slider = 0;
    for (size_t i = 0; i < out.size(); ++i) {
        slider += out[i];
        max = (slider > max ? slider : max);
    }
    return max;
}

#ifndef TEST_BUILD

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    size_t n = stoul(nm[0]);

    size_t m = stoul(nm[1]);

    vector<vector<int>> queries(m);
    for (size_t i = 0; i < m; i++) {
        queries[i].resize(3);

        for (size_t j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

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

TEST (ArrayManipulation, ArrayManipulationTestCase0)
{
    std::vector<std::vector<int>> queries = {
        {1, 5, 3},
        {4, 8, 7},
        {6, 9, 1}
    };
    ASSERT_EQ(arrayManipulation(10, queries), 10);
}

TEST (ArrayManipulation, ArrayManipulationTestCase1)
{
    std::vector<std::vector<int>> queries = {
        {1, 2, 100},
        {2, 5, 100},
        {3, 4, 100}
    };
    ASSERT_EQ(arrayManipulation(5, queries), 200);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif

