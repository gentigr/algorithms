// https://www.hackerrank.com/challenges/password-cracker
#include <tuple>
#include <vector>
#include <iostream>
#include <unordered_set>

static std::pair<std::string, bool> do_attempt(const std::unordered_set<std::string>& passwords,
        const std::string& login,
        size_t position,
        std::vector<int>& memoization)
{
    if (memoization[position] != 0) {
        return std::make_pair("", false);
    }

    for(const auto& k : passwords) {
        if (login.compare(position, k.size(), k) == 0) {
            if (position + k.size() == login.size()) {
                return std::make_pair(k, true);
            }
            std::pair<std::string, bool> result = do_attempt(passwords, login, position + k.size(), memoization);
            if (result.second) {
                return std::make_pair(k + " " + result.first, true);
            }
        }
    }
    memoization[position] = -1;

    return std::make_pair("", false);
}

int main()
{
    int t;
    std::cin >> t;

    for(int n; t-- > 0 && std::cin >> n;) {
        std::unordered_set<std::string> passwords {};
        for(std::string p; n-- > 0 && std::cin >> p;) {
            passwords.insert(p);
        }
        std::string login;
        std::cin >> login;

        std::vector<int> memoization (login.size(), 0);
        std::pair<std::string, bool> result = do_attempt(passwords, login, 0, memoization);
        std::cout << (result.second ? result.first : "WRONG PASSWORD") << std::endl;
    }

    return 0;
}
