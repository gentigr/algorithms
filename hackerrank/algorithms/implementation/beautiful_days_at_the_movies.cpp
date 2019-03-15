// https://www.hackerrank.com/challenges/beautiful-days-at-the-movies/problem

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the beautifulDays function below.
static int beautiful_days(int i, int j, int k)
{
    int count = 0;
    for(int m = i; m <= j; ++m) {
        int inv_value = 0;
        for(int v = m; v > 0; v /= 10) {
            inv_value = inv_value * 10 + v % 10;
        }

        count += (abs((m - inv_value) % k) == 0);
    }

    return count;
}

#ifndef TEST_BUILD

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string ijk_temp;
    getline(cin, ijk_temp);

    vector<string> ijk = split_string(ijk_temp);

    int i = stoi(ijk[0]);

    int j = stoi(ijk[1]);

    int k = stoi(ijk[2]);

    int result = beautiful_days(i, j, k);

    fout << result << "\n";

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

TEST (BeautifulDaysAtTheMovies, HackerRankTestCase0)
{
    ASSERT_EQ(beautiful_days(20, 23, 6), 2);
}

TEST (BeautifulDaysAtTheMovies, HackerRankTestCase1)
{
    ASSERT_EQ(beautiful_days(13, 45, 3), 33);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
