#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
	int test_case;
	int T, n, m;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
       cin >> n >> m;
       cout << '#' << test_case << ' ' << ((m % (1 << n) == (1 << n) - 1) ? "ON" : "OFF")<< '\n';
	}
	return 0;
}