#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int max = -1, min = 10001;
        double sum = 0;
        for(int i = 0; i < 10; i++){
            int tmp;
            cin >> tmp;
            sum += tmp;
            if(max < tmp){
                max = tmp;
            }
            if(min > tmp){
                min = tmp;
            }
        }
        sum = floor((sum - min - max) / 8 + 0.5);
        cout << '#' << test_case << ' ' << sum << '\n';
	}
	return 0;
}