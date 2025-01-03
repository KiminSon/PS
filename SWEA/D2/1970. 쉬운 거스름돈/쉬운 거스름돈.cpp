#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int a[8] = {0,};
        int b[8] = {50000, 10000, 5000, 1000, 500, 100, 50, 10};
        int n;
        cin >> n;
        
        for(int i = 0; i < 8; i++){
            a[i] += n / b[i];
            n %= b[i];
        }
        
        
        cout << '#' << test_case << '\n';
        for(int i = 0; i < 8; i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
	}
	return 0;
}