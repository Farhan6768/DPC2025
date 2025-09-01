#include <iostream>
using namespace std;

int main() 
{
    int N;
    cout << "Enter a number: "; 
    cin >> N;

    int count = 0;
    for (int i = 1; i <= N; i++) 
	{
        if (N % i == 0) 
		{
            count++;
        }
    }
    
    cout << count << endl;  
    
    return 0;
}
/*
Enter a number: 12
6
*/
