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
        vector<int> v = {0,0,0,0,0};
        vector<int> num = {2,3,5,7,11};
        int n;
        cin >> n;
        
        for(int i = 0; i * i <= n; i++){
        	while(n % num[i] == 0){
        		v[i]++;
                n /= num[i];
        	}
        }
        
        v[4] += n / num[4];
        
        cout << '#' << test_case << ' ';
        for(int i = 0; i < 5; i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}