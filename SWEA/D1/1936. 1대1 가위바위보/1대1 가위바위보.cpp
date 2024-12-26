#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    int a, b;
    cin >> a >> b;
    cout << (((a + 1) % 3 == (b % 3)) ? 'B' : 'A');
	return 0;
}