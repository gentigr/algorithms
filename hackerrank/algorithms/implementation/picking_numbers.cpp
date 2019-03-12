// https://www.hackerrank.com/challenges/picking-numbers/problem

#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'pickingNumbers' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY a as parameter.
 */
static size_t picking_numbers(const vector<int>& a)
{
    map<int, size_t> counter;

    for(const auto& item : a) {
        ++counter[item];
    }
    int prev_key = 0;
    size_t prev_value = 0;
    size_t max_length = 0;
    for(const auto& item : counter) {
        size_t cur_value = item.second;
        if (abs(item.first - prev_key) <= 1) {
            cur_value += prev_value;
        }
        max_length = (max_length < cur_value ? cur_value : max_length);
        prev_key = item.first;
        prev_value = item.second;
    }

    return max_length;
}

#ifndef TEST_BUILD
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    size_t n = stoul(ltrim(rtrim(n_temp)));

    string a_temp_temp;
    getline(cin, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (size_t i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    size_t result = picking_numbers(a);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}

#else

#include <gtest/gtest.h>

TEST (PickingNumbersTest, HackerRankTestCase0)
{
    size_t n = 6;
    std::vector<int> numbers = {4, 6, 5, 3, 3, 1};
    ASSERT_EQ(picking_numbers(numbers), 3);
}

TEST (PickingNumbersTest, HackerRankTestCase1)
{
    size_t n = 6;
    std::vector<int> numbers = {1, 2, 2, 3, 1, 2};
    ASSERT_EQ(picking_numbers(numbers), 5);
}

TEST (PickingNumbersTest, AllZeros)
{
    size_t n = 3;
    std::vector<int> numbers = {0, 0, 0};
    ASSERT_EQ(picking_numbers(numbers), 3);
}

TEST (PickingNumbersTest, GaussDistribution)
{
    size_t n = 7;
    std::vector<int> numbers = {0, 1, 1, 2, 1, 1, 0};
    ASSERT_EQ(picking_numbers(numbers), 6);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

#endif
