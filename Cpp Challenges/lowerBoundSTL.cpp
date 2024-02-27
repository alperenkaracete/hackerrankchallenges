#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> num;
    int tempNum;

    for (int i=0;i<N;i++){
        
        cin >> tempNum;
        num.push_back(tempNum);
        
    }
    
    int Q;
    cin >> Q;
    for (int i=0;i<Q;i++){
        
        cin >> tempNum;
        std::vector<int>::iterator low,up;
        low=std::lower_bound (num.begin(), num.end(), tempNum); 
        if (num.at(low-num.begin()) == tempNum){
            
            cout << "Yes " << low-num.begin()+1 << endl;
        }
        else if (num.at(low-num.begin()) > tempNum){
            
            cout << "No " << low-num.begin()+1 << endl;
        }
 
    }
    
    return 0;
}
