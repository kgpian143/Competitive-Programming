#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std ;
int find_max_in_column(string S, string C) {
    vector<string> lines;
    stringstream ss(S);
    string line;
    while (getline(ss, line, '\n')) {
        lines.push_back(line);
    }
    
    vector<string> headers;
    stringstream header_ss(lines[0]);
    string header;
    while (getline(header_ss, header, ',')) {
        headers.push_back(header);
    }
    
    int column_index = -1;
    for (int i = 0; i < headers.size(); i++) {
        if (headers[i] == C) {
            column_index = i;
            break;
        }
    }
    
    if (column_index == -1) {
        return -1;
    }
    
    int max_val = -1;
    for (int i = 1; i < lines.size(); i++) {
        vector<string> values;
        stringstream value_ss(lines[i]);
        string value;
        while (getline(value_ss, value, ',')) {
            values.push_back(value);
        }
        
        try {
            int num = stoi(values[column_index]);
            if (max_val == -1 || num > max_val) {
                max_val = num;
            }
        } catch (invalid_argument& e) {
            continue;
        }
    }
    
    return max_val;
}
