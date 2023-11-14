#include<iostream>
#include<String>
#include<vector>
#include<cstdlib>
#include<algorithm>


using namespace std;

vector<int> theNumbers;

void generateTheNumbers()
{
    int numNbrs;
    int maxNbr;
    cout << "How many numbers should I generate? " << endl;
    cin >> numNbrs;

    cout << "What is the largest number you want to consider?" << endl;
    cin >> maxNbr;
    for (int n=0; n <numNbrs; n++)
    {
        int nextNbr = (rand()% maxNbr) +1;

        theNumbers.push_back(nextNbr);

    }
}

void showTheNumbers(string msg)
{
    cout << msg << endl;
    for(int j=0; j < theNumbers.size(); j++)
    {
        cout << theNumbers[j] << "|";

    }
    cout << endl;

}

void showTheNumbers2(string msg)
{
    cout << msg << endl;
    for(auto num:theNumbers)
    {
        cout << "|";
    }
    cout << endl;

}
void sortTheNumbers()
{
    cout << endl;
    int numNbrs = theNumbers.size();

     for (int n=0; n < theNumbers.size(); n++)
     {

            for(int j=0; j < numNbrs-1; j++)
        {
           // cout << "Checking: " << theNumbers[j] << " and " << theNumbers[j+1] << endl;
                if(theNumbers[j] > theNumbers[j+1])
                {
                        cout /*<< "    theNumbers[j] = " */<<theNumbers[j] << endl;
                        cout /*<< "    theNumbers[j+1] = " */<< theNumbers[j+1] << endl;

                        int temp =theNumbers[j];
                        theNumbers[j] = theNumbers[j+1];
                        theNumbers[j+1] = temp;
                }
        }
     }
}

int main()
{
    string msg;
    int temp;
    generateTheNumbers();
    showTheNumbers(msg);
    sortTheNumbers();
    showTheNumbers2(msg);

    return 0;
}
