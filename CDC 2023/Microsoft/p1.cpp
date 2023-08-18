#include <iostream>
#include <string>
using namespace std;

int longest_symmetric(string str) {
    int start = 0, mid = 0, last_gt = 0, end = 0;
    int best = 0;
    while (start < str.length()) {
        int current = min(mid - start, end - mid);
        if (best < current) {
            best = current;
        }
        if (end - mid == current && end < str.length()) {
            if (str[end] == '?') {
                end += 1;
            } else if (str[end] == '>') {
                end += 1;
                last_gt = end;
            } else {
                end += 1;
                mid = end;
                start = max(start, last_gt);
            }
        } else if (mid < str.length() && str[mid] == '?') {
            mid += 1;
        } else if (start < mid) {
            start += 1;
        } else {
            start = max(start, last_gt);
            mid = mid + 1;
            end = max(mid, end);
        }
    }
    return 2 * best;
}
