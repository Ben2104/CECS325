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

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        cerr << "error" << endl;
    }
    for (int i = 0; i < 4; i++)
    {
        cout << "argv[" << i << "]: " << argv[i] << endl;
    }
    int count = atoi(argv[1]);
    int min = atoi(argv[2]);
    int max = atoi(argv[3]);

    ofstream outFile("numbers.dat");

    if (!outFile.is_open())
    {
        cerr << "Error opening the file \n";
    }
    srand(time(NULL));

    for (int i = 0; i < count; i++)
    {
        int num = min + rand() % (max - min + 1);
        outFile << num << endl;
    }
    outFile.close();
    return 0;
}