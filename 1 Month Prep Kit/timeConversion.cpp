#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    
    size_t substring_length;
    
    if ((substring_length = s.find("AM") != string::npos)){
        
        string tempStr;
        tempStr = s.substr(0,2);        
        int hour = stoi(tempStr);
        if (hour==12)
            s.replace(0,2,"00");  
         
        s.pop_back();
        s.pop_back();       
               
        return s;
    }
    
    string tempStr;
    tempStr = s.substr(0,2);

    int hour = stoi(tempStr);
    
    if (hour < 12)    
        hour = hour + 12;
        
    tempStr = to_string(hour);

    s.replace(0,2,tempStr);
    
    s.pop_back();
    s.pop_back();
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
