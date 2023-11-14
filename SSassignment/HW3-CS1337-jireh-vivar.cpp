//<------------------------------Searching & Sorting program------------------------------------------------->
/*jirehVivar 02.25.2023       --Developed generating number function, along with a function asking the user to input their parameters
                              --fixed generating random number error
                              --created function that displays the numbers sorted and created another function that displays the numbers unsorted
                              --user cannot input a number larger than 20 or else prompted again
jirehVivar 02.26.2023         -- Separating functions from main to be able to use vectors and debuggers more efficiently
                              --added a repeat function so can stop exiting out
                              --fixed error in prompting <--affected generating parameters
                              --moved option to reset program into own function, cleared numbers in vector and clear
                              system so the program can restart without exiting
jirehVivar 03.1.2023          --developed copied vector sort using bubble sort
                              --prompting user to input number to search for
                              --binary search algorithm now finds number in correct location
                              --fixed error in how many times user can look for another number
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<int> numbers;
vector<int>numbersCopy;

int numCount, maxNum;
char resetChoice;

//created this for any area where there is an incorrect submission
void validInput()
{
    cout << "Invalid Submission. Try Again." << endl;
}


//set up the parameters of users preference
void generateParameters()
{
    cout << "Enter the number of integers to generate: ";
    cin >> numCount;


    cout << "Enter the maximum integer limit (CANNOT EXCEED 20): ";
    cin >> maxNum;

    cout << endl;

}
//  Generate random numbers and add them to the vector
 void generateNumbers()
 {
     srand(time(nullptr));
    for (int i = 0; i < numCount; i++) {
        int num = rand() % (maxNum + 1) ;
        numbers.push_back(num);
    }
 }
//original vector number unsorted function
 void unsortedNum()
 {
     cout << "Unsorted random numbers:\n";
    for (int num : numbers) {
        cout << num << "|";
    }
    cout << endl << endl;
 }
//original vector number sorted function
 void sortedNum()
 {
    sort(numbers.begin(), numbers.end());
    cout << "Sorted random numbers:\n";
    for (int num : numbers) {
        cout << num << "|";
    }
    cout << endl << endl;
 }

//  user can only enter integer
 int userNumberSearch(int searchNum)
 {
    cout << "Enter a random number you want to find:" << endl;

    while(!(cin >> searchNum))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "ERROR. ONLY INTEGER \n";
    }
    return searchNum;
 }

 // searches for numbers occurrence
void binarySearch(int searchNum)
{
    int numIndex = -1;
    int count =0;
    for (int i =0; i < numbers.size(); i++)
    {
        if(numbers[i] == searchNum)
        {
            if(numIndex == -1)
            {
                numIndex = i;
            }
            count++;
        }
    }
    if(numIndex != -1){
    cout <<"Numbers position is at " << numIndex+1 << " in sorted vector." << endl;
    cout << "Number appears " << count << " times in vector." << endl;
    } else
        {
            cout << searchNum << " not in vector. " << endl;
        }
}

//function that runs two functions, so user can input however many times they would like to run the code
void searchSortedVec()
{
    int searchNum = userNumberSearch(searchNum);
    binarySearch(searchNum);


}

void gameReset();//just so findAnotherNumber function can gather the inputs of gamereset

void findAnotherNum()
{
    char searchAgainChoice;

    cout << endl << "Would you like to search for another number? \n Enter y if yes or n if not" << endl;
    cin >> searchAgainChoice;


    if(searchAgainChoice == 'y' || searchAgainChoice == 'Y')
    {
        searchSortedVec();
        cout << endl;
    }
    else if(searchAgainChoice == 'n' || searchAgainChoice == 'N'){gameReset();}


}

void gameRun();


// functino clears any duplicated of a number
void clearMultiples(vector<int>& numbers) {
    int n = numbers.size();
    vector<bool> toRemove(n, false);

    for (int i = 1; i < n; i++) {
        if (numbers[i] == numbers[i-1]) {
            toRemove[i] = true;
        }
    }

    int j = 0;
    for (int i = 0; i < n; i++) {
        if (!toRemove[i]) {
            numbers[j] = numbers[i];
            j++;
        }
    }

    while (numbers.size() > j) {
        numbers.pop_back();
    }
}

//if user decides to reset the program
void gameReset()
{
    cout << "The vector without duplicates are: \n" << endl;
clearMultiples(numbers);

    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << "|";
    }
//  allow user to re-run program
    cout << endl << endl << "Would you like to re-run the program? Enter y if you would, and n if you want to exit the program" << endl;
    cin >> resetChoice;

    if(resetChoice == 'y' || resetChoice =='Y')
    {
        cout << endl;
        numbers.clear();
        numbersCopy.clear();
        system("cls");
        gameRun();

    }
     else if(resetChoice == 'n' || resetChoice == 'N')
    {
//      exit program
        exit(0);
    }
    else{
        validInput();
        cout << endl;
        cin >> resetChoice;
    }
}

 void gameRun()
 {

    generateParameters();
    while(maxNum > 20)
    {
        validInput();
        generateParameters();
    }
//  generate randomized numbers
    generateNumbers();

    vector<int>numbersCopy = numbers;//  copy the numbers into a second vector

    unsortedNum();//  Print the unsorted random numbers

//  print the copied vectors unsorted numbers
    cout << "Unsorted random numbers copied Vector:\n";
    for (int num : numbersCopy) {
        cout << num << "|";
    }
    cout << endl << endl << endl;

    sortedNum();//  Sort the numbers and print the sorted version

//  sort copied vector
    int n = numbersCopy.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j = 0;j < n-i-1; j++)
        {
            if(numbersCopy[j] > numbersCopy[j+1])
            {
                int temp = numbersCopy[j];
                numbersCopy[j]=numbersCopy[j+1];
                numbersCopy[j+1]=temp;
            }
        }
    }

//  print the bubble sort copied vector
    cout << "Sorted copied vector using bubble sort:\n";
    for(int i =0; i < n; i++)
    {
        cout << numbersCopy[i] << "|";
    }
    cout << endl << endl << endl;

//  Ask the user for random number to search for
    searchSortedVec();
// ask user if they would like to find another random number
for(int a = 0; a < 4; a++)
{
    findAnotherNum();
}

cout << endl;


gameReset();
}

int main()
 {
    gameRun();
    return 0;
}







