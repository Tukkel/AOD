#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> counting_sort(const std::vector<int>& vec);

int main()
{
    std::vector<int> input = { 4, 2, 6, 7, 3, 6, 10, 1, 2, 6, 2 };

    std::vector<int> sorted = counting_sort(input);

    for (const int &num : sorted) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

std::vector<int> counting_sort(const std::vector<int>& vec)
{
    int k = *std::max_element(vec.begin(), vec.end());
    std::vector<int> count(k + 1, 0);
    std::vector<int> output(vec.size());

    for (int j : vec) {
        count[j]++;
    }

    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    for (auto it = vec.rbegin(); it != vec.rend(); it++) {
        int j = *it;
        output[count[j] - 1] = j;
        count[j]--;
    }
    return output;
}