// https://www.hackerrank.com/challenges/grading
#include <vector>
#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> grades;
    while(n-- != 0) {
        int grade;
        std::cin >> grade;
        grades.push_back(grade);
    }

    for(const auto& grade : grades) {
        int upper_grade = ((grade + 1) % 5 == 0 ? grade + 1 : ((grade + 2) % 5 == 0) ? grade + 2 : grade);
        std::cout << (upper_grade - grade < 3 && upper_grade >= 40 ? upper_grade : grade) << std::endl;
    }

    return 0;
}
