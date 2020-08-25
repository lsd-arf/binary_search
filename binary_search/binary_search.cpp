#include <iostream>

// поиск числа в отсортированном массиве
// методом деления пополам

// итеративная реализация
int binarySearchI(int* array, int target, int min, int max)
{
	while (min <= max)
	{
		int average = (min + max) / 2; // среднее искомое число

		if (array[average] > target)
			max = average - 1;
		else if (array[average] < target)
			min = average + 1;
		else if (array[average] == target) {
			return average;
		}
	}

	return -1;
}

// рекурсивная реализация
int binarySearchR(int* array, int target, int min, int max)
{
	if (min > max)
		return -1;

	int average = (min + max) / 2;

	if (array[average] > target)
		return binarySearchR(array, target, min, average - 1);
	else if (array[average] < target)
		return binarySearchR(array, target, average + 1, max);
	else if (array[average] == target)
		return average;
}

int main()
{
    using namespace std;

	int array[] = { 4, 7, 9, 13, 15, 19, 22, 24, 28, 33, 37, 41, 43, 47, 50 };

	std::cout << "Enter a number: ";
	int x;
	std::cin >> x;

	int index = binarySearchR(array, x, 0, 14);

	if (index == -1)
		std::cout << "Fail! Your value " << x << " isn't in array!\n";
	else
		std::cout << "Good! Your value " << x << " is on position " << index << " in array!\n";

    return 0;
}