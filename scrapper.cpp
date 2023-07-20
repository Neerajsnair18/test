#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <locale>

using namespace std;

bool comparator(const string& a, const string& b) {
    locale loc;
    return lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), 
                                   [loc](char c1, char c2) { return tolower(c1, loc) < tolower(c2, loc); });
}

int main(int argc, char* argv[]) {

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Failed to open the input file." << endl;
        return 1;
    }

    vector<string> names;
    string name;

    while (getline(inputFile, name)) {
        names.push_back(name);
    }

    inputFile.close();

    sort(names.begin(), names.end(), comparator);

    for (const auto& sortedName : names) {
        cout << sortedName << endl;
    }

    return 0;
}
