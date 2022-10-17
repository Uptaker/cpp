#include <iostream>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

int main(void)
{
	int opAmount, changeAmount, num;
	cin >> opAmount >> changeAmount;
	string operation[opAmount + changeAmount];
	int numbers[opAmount + changeAmount];

	string name;
	for (int i = 0; i < opAmount; i++) cin >> operation[i] >> numbers[i];

	int place, num1, num2;
	for (int i = 0; i < changeAmount; i++)
	{
		cin >> place >> operation[place - 1] >> numbers[place - 1];
		num1 = 0;
		for (int i = 0; i < opAmount; i++) { 
			string op = operation[i];
			int num2 = numbers[i];

			if (op == "AND") num1 = num1 & num2;
			else if (op == "OR") num1 = num1 | num2;
			else if (op == "XOR") num1 = num1 ^ num2;
		}
		cout << num1 << endl;
	}
}