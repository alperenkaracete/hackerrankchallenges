#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'flippingBits' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts LONG_INTEGER n as parameter.
 */
 
string intToBin(unsigned k) {
    if (k == 0) return "0";
    if (k == 1) return "1";
    return intToBin(k / 2) + to_string(k % 2);
}

long binToInt(string bin) {
    long result = 0;
    int length = bin.length();
    for (int i = 0; i < length; i++) {
        if (bin[length - i - 1] == '1') {
            result += pow(2, i);
        }
    }
    return result;
}

long flippingBits(long n) {
    string wholeNum = intToBin(n);

    while (wholeNum.size() < 32) {
        wholeNum.insert(0, "0");
    }

    for (int i = 0; i < 32; i++) {
        if (wholeNum[i] == '0') {
            wholeNum[i] = '1';
        } else {
            wholeNum[i] = '0';
        }
    }

    long num = binToInt(wholeNum);

    return num;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        long n = stol(ltrim(rtrim(n_temp)));

        long result = flippingBits(n);

        fout << result << "\n";
    }

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
