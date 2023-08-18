#include <iostream>
#include <vector>
using namespace std ;
string countComparison(const vector<int>& numbers, int pivot) {
    int countGreater = 0;
    int countLess = 0;

    for (int num : numbers) {
        if (num > pivot) {
            countGreater++;
        } else if (num < pivot) {
            countLess++;
        }
    }

    if (countGreater > countLess) {
        return "greater";
    } else if (countGreater < countLess) {
        return "smaller";
    } else {
        return "tie";
    }
}

int main() {
    // Example usage:
    vector<int> numbers = {10, 5, 15, 8, 20};
    int pivot = 12;

    string result = countComparison(numbers, pivot);
    cout << "Result: " << result << endl;

    return 0;
}
