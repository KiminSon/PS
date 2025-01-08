#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(int argc, char** argv)
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        s[i] = toupper(s[i]);
    }
    cout << s;
	return 0;
}