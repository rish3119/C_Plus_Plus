#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Modern ltrim
string ltrim(const string &str) {
    string s(str);
    s.erase(s.begin(),
            find_if(s.begin(), s.end(),
                    [](unsigned char ch) { return !isspace(ch); }));
    return s;
}

// Modern rtrim
string rtrim(const string &str) {
    string s(str);
    s.erase(find_if(s.rbegin(), s.rend(),
                    [](unsigned char ch) { return !isspace(ch); }).base(),
            s.end());
    return s;
}

/*
 * Complete the 'countResponseTimeRegressions' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY responseTimes as parameter.
 */
int countResponseTimeRegressions(const vector<int>& responseTimes) {
    int count = 0;
    for (size_t i = 1; i < responseTimes.size(); i++) {
        if (responseTimes[i] > responseTimes[i - 1]) {
            count++;
        }
    }
    return count;
}

int main() {
    string responseTimes_count_temp;
    getline(cin, responseTimes_count_temp);

    int responseTimes_count = stoi(ltrim(rtrim(responseTimes_count_temp)));

    vector<int> responseTimes(responseTimes_count);

    for (int i = 0; i < responseTimes_count; i++) {
        string responseTimes_item_temp;
        getline(cin, responseTimes_item_temp);

        int responseTimes_item = stoi(ltrim(rtrim(responseTimes_item_temp)));
        responseTimes[i] = responseTimes_item;
    }

    int result = countResponseTimeRegressions(responseTimes);
    cout << result << "\n";

    return 0;
}
