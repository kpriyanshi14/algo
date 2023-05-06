
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>

#define MIN_SIZE 30
#define MAX_SIZE 1000

using namespace std;

int insertionSort(int *, int);

int main()
{
    try
    {
        //srand(time(0));

        int array[MAX_SIZE];
        int size, comparisons;

        ofstream fout("./results.csv");

        cout << "+------------------------------------------------+\n";
        cout << "| Input Size | Best Case | Avg Case | Worst Case |\n";
        cout << "+------------------------------------------------+\n";

        fout << "size,best,avg,worst\n";

        for (int i = 0; i < 100; i++)
        {
            size = rand() % (MAX_SIZE + 1 - MIN_SIZE) + MIN_SIZE;
            cout << "| " << setw(10) << size;
            fout << size << ",";
            for (int i = 0; i < size; i++)
                array[i] = i + 1;
            comparisons = insertionSort(array, size);
            cout << " | " << setw(9) << right << comparisons;
            fout << comparisons << ",";
            try
            {
                ifstream fin("./random.txt");
                for (int i = 0; i < size; i++)
                    fin >> array[i];
                fin.close();
                comparisons = insertionSort(array, size);
                cout << " | " << setw(8) << right << comparisons;
                fout << comparisons << ",";
            }
            catch (exception e)
            {
                cerr << e.what();
                return -1;
            }

            for (int i = 0; i < size; i++)
                array[i] = size - i;
            comparisons = insertionSort(array, size);
            cout << " | " << setw(10) << right << comparisons << " |\n";
            fout << comparisons << "\n";
        }

        cout << "+------------------------------------------------+\n\n";

        fout.close();

        return 0;
    }
    catch (exception e)
    {
        cerr << e.what();
        return -1;
    }
}

int insertionSort(int *array, int size)
{
    int  key, count = 0;

    for(int j=1;j<size;j++)
    {
    	key=array[j];
    
		for (int i = j - 1; i >= 0; i--)
        {
            count++;

            if (array[i] > key)
            {
                array[i + 1] = array[i];
            }
            else
            {
                break;
            }
            array[1 + 1] = key;
        }
	}

    return count;
}
