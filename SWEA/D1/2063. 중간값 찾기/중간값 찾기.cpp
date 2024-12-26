#include<iostream>
#include<vector>
#include<algorithm>
 
using namespace std;
 
int main(int argc, char** argv)
{
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i = 0; i < n; i++){
        int j;
        cin >> j;
        v[i] = j;
    }
    sort(v.begin(), v.end());
    cout << v[n/2] << '\n';
     
    return 0;
}