#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'howManyGames' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER d
 *  3. INTEGER m
 *  4. INTEGER s
 */


//=== my O(1) method ===
int howManyGames(int p, int d, int m, int s) {
    // invalid condition
    if (s < p) {
        return 0;
    }
    
    int n1 = 1 + (p - m) / d; // max number of games down to 'm'
    int s1 = n1 * (2*p - (n1 - 1) * d) / 2;      // total cost down to 'm'
    int res;
    
    // case 01 : 's' is in between 'p' and 's1'
    if (s < s1) {
        double det = sqrt((2*p + d) * (2*p + d) - 8*s*d);
        res = (2*p + d - det) / (2 * d);
    } 
    
    // case 02 : 's' is greater than 's1'
    else{
        res = n1 + (s - s1) / m;
    }
    
    return res;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int p = stoi(first_multiple_input[0]);

    int d = stoi(first_multiple_input[1]);

    int m = stoi(first_multiple_input[2]);

    int s = stoi(first_multiple_input[3]);

    int answer = howManyGames(p, d, m, s);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
