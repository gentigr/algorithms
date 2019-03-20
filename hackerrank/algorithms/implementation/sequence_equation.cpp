// https://www.hackerrank.com/challenges/permutation-equation/problem

#include <bits/stdc++.h>

using namespace std;

// Complete the permutationEquation function below.
static vector<size_t> permutation_equation(const vector<size_t>& p)
{
    vector<size_t> result(p.size(), 0);

    for(size_t i = 0; i < p.size(); ++i) {
        size_t pos = p[p[i] - 1];
        result[pos - 1] = i + 1;
    }

    return result;
}

#ifndef TEST_BUILD

vector<string> split_string(string);

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    size_t n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string p_temp_temp;
    getline(cin, p_temp_temp);

    vector<string> p_temp = split_string(p_temp_temp);

    vector<size_t> p(n);

    for (size_t i = 0; i < n; i++) {
        size_t p_item = stoul(p_temp[i]);

        p[i] = p_item;
    }

    vector<size_t> result = permutation_equation(p);

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

#include <gtest/gtest.h>

TEST (PermutationEquation, HackerRankTestCase0)
{
    vector<size_t> val = {2, 3, 1};
    vector<size_t> res = {2, 3, 1};
    ASSERT_EQ(permutation_equation(val), res);
}

TEST (PermutationEquation, HackerRankTestCase1)
{
    vector<size_t> val = {4, 3, 5, 1, 2};
    vector<size_t> res = {1, 3, 5, 4, 2};
    ASSERT_EQ(permutation_equation(val), res);
}

TEST (PermutationEquation, HackerRankTestCaseDesc)
{
    vector<size_t> val = {5, 2, 1, 3, 4};
    vector<size_t> res = {4, 2, 5, 1, 3};
    ASSERT_EQ(permutation_equation(val), res);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
