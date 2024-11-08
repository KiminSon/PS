#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        cin >> n;
        if(n == 2){
            cout << "BA" << '\n';
        } else if(n % 3 == 1){
        	cout << "impossible" << '\n';
        } else if(n%3 == 2){
            cout << "BA";
            for(int i = 2; i < n; i++){
           		if(i % 3 == 1)
                    cout << 'A';
                else
                    cout <<'B';
            }
            cout << '\n';
        } else{
        	for(int i = 0; i < n; i++){
            	if(i % 3 == 2)
                    cout << 'A';
                else
                    cout <<'B';
            }
            cout << '\n';
        }
	}
    
	return 0;
}