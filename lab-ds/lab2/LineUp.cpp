#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    std::vector<std::vector<int>> rows;
    
    int temp;
    std::cin >> temp;
    
    int rowIdx = 0;
    std::vector<int> newRow = {temp};
    rows.push_back(newRow);
    
    for (int i = 1; i < N; i++) {
        std::cin >> temp;
        if (temp > rows[rowIdx].back())
            rows[rowIdx].push_back(temp);
        else if (temp < rows[rowIdx].front())
            rows[rowIdx].insert(rows[rowIdx].begin(), temp);
        else {
            newRow = {temp};
            rows.push_back(newRow);
            rowIdx++;
        }
    }
    
    for (const auto& row : rows) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
