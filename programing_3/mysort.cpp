// Name: Hoang Do
// Class (CECS 325-01)
// Project Name (Prog 3 – Sort Contest)
// Due Date 03/06/2025
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.
#include <iostream>
#include <fstream>

using namespace std;

void bubble_sort(int A[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cerr << "Usage: " << argv[0] << " inputfile outputfile" << endl;
        return 1;
    }

    ifstream infile(argv[1]);
    if (!infile.is_open())
    {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    const int MAX_SIZE = 1000000;
    int numbers[MAX_SIZE];
    int num;
    int index = 0;
    while (infile >> num && index < MAX_SIZE)
    {
        numbers[index++] = num;
    }
    infile.close();

    bubble_sort(numbers, index);

    ofstream outFile(argv[2]);
    if (!outFile.is_open())
    {
        cerr << "Error opening output file" << endl;
        return 1;
    }
    for (int i = 0; i < index; i++)
    {
        outFile << numbers[i] << endl;
    }
    outFile.close();

    return 0;
}