#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout << '#' << test_case << '\n';
        int n;
        cin >> n;
        int arr[n][n], ans1[n][n], ans2[n][n], ans3[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int k;
                cin >> k;
                arr[i][j] = k;
            }
        }        
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans1 [i][j] = arr[n-j-1][i];
            }
        }
            
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans2 [i][j] = ans1[n-j-1][i];
            }
        }
            
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans3 [i][j] = ans2[n-j-1][i];
            }
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << ans1[i][j];
            }
            cout << ' ';
            for(int j = 0; j < n; j++){
                cout << ans2[i][j];
            }
            cout << ' ';
            for(int j = 0; j < n; j++){
                cout << ans3[i][j];
            }
            cout << '\n';
        }
	}
	return 0;
}