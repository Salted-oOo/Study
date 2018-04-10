#include <iostream>
#include <vector>
using namespace std;

int main() 
{
	vector<int> ivec;
	int ival;
	while ( cin >> ival ) {
		ivec.push_back( ival );
	}	
	int sum;
	for ( int ix = 0; ix < ivec.size(); ++ix ) {
		sum += ivec[ ix ];
	}
	int average = sum / ivec.size();
	cout << "sum of " << ivec.size()
		 << " elements: " << sum
		 << ". Average: " << average << endl;

	return 0;
}


#include <iostream> 
using namespace std;

int main()
{
	const int array_size = 128;
	int ia[ array_size ];
	int ival, icnt = 0;

	while ( cin >> ival && icnt < array_size ) {
		ia[ icnt++ ] = ival;
	}

	int sum = 0;
	for ( int ix = 0; ix < icnt; ix++ ) {
		sum += ia[ ix ];
	}

	int average = sum / icnt;

	cout << "Sum of " << icnt
		 << " elements: " << sum
		 << ". Average: " << average << endl;

	return 0;
}