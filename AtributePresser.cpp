#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <sstream>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
        int n, q;
    cin >> n >> q;
    cin.ignore(); // to handle newline after numbers
    unordered_map<string, string> mp;
    vector<string> tagStack;
    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        // Closing tag
        if (line.substr(0, 2) == "</") {
            tagStack.pop_back();
        } 
        // Opening tag
        else {
            // Remove < and >
            line = line.substr(1, line.size() - 2);
            stringstream ss(line);
            string tag;
            ss >> tag;
            // Build hierarchy
            tagStack.push_back(tag);
            string path = tagStack[0];
            for (int j = 1; j < tagStack.size(); j++) {
                path += "." + tagStack[j];
            }
            // Parse attributes
            string attr, equal, value;
            while (ss >> attr >> equal >> value) {
                // remove quotes
                value = value.substr(1, value.size() - 2);
                string key = path + "~" + attr;
                mp[key] = value;
            }
        }
    }
    // Process queries
    for (int i = 0; i < q; i++) {
        string query;
        getline(cin, query);
        if (mp.find(query) != mp.end())
            cout << mp[query] << endl;
        else
            cout << "Not Found!" << endl;
    }
  

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
