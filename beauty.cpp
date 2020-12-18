

//RESULT :   8495665195524
#include <iostream>
using namespace std;

template <int BITNESS, int NUM_COMPARED_DIGITS_ON_ONE_SIDE>
struct Number
{
	static int const SIZE = NUM_COMPARED_DIGITS_ON_ONE_SIDE * (BITNESS-1) + 1;

	inline void GenerateNext(int position, int recursionWidth ){
		if (!(recursionWidth)){
			data[position]++;
			return;
		}
		for (int i = 0 ; i < BITNESS; i++){
			GenerateNext(position + i, recursionWidth-1 );
		}
	}

	unsigned long long Generate(){
		memset(data,0,SIZE*sizeof(unsigned long long));
		GenerateNext(0, NUM_COMPARED_DIGITS_ON_ONE_SIDE );
			unsigned long long summ = 0;
		    for (int i = 0; i < SIZE; i++)	
				summ +=data[i] * data[i];
		return summ; //*(BITNESS-1)
	}

protected:
	unsigned long long data[SIZE];	
};

int main()
{
	Number<13,6> calculator;
	cout << "quantity of beauty numbers: " << calculator.Generate()*(13-1) <<"\n";
}


