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