#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std; 
 
int main() 
{
    vector<int> ages { 10, 4, 1, 99, 101, 5 }; 

    sort(ages.begin(), ages.end(), [](auto i, auto j) {
        return i <= j; 
    }); 
 
    for (auto age : ages) {
        cout << age << " " << endl;
    }
}
