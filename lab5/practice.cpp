#include <iostream>

using namespace std;

int findMin(int num);

int main()
{

	int how_many;

	cout << "How many numbers:" << endl;
	cin >> how_many;
	cout << findMin(how_many);

return 0;

}

int findMin(int num)
{
	cout << "Give numbers:" << endl;
	
	int input, curr_min, counter;	
	cin >> input;
	counter=1;
	curr_min = input;
	
	while (counter < num)
	{
		cin >> input;
		if (input < curr_min)
		{
			curr_min=input;
		}
		counter++;
	}
	return curr_min;
}
