/* Samantha Casler
Last Modified 9/16/18 */

#include <iostream>
#include <string>
using namespace std;

// Initializing the functions as well as the size of all three arrays.
int getStudent ();
int linearSearch (const int [], int, int);
int binarySearch (const int [], int, int);
void linearResults (const int [], const string [], const string [], int);
void binaryResults(const int [], const string [], const string [], int);
void originalArray(const int [], const string [], const string [], int);
void bubbleSort( int [], string [], string [], int);
void sortedArray (const int [], const string [], const string [], int);
const int SIZE = 12;

int main()
{
    //Initializing the arrays for the students id, name and email.
    int id[SIZE] = {273, 362, 251, 152, 385, 481, 139, 230, 170, 435, 294, 193};

    string name[SIZE] = {"Brisa Robinson","Matthew Messer", "Melony Beli", "Michael Anthony",
    "Brittany Jolly","Erick Garant", "Sydney Thompson", "Nick McIlvoy",
    "Courtney Zito", "Josh Sinclare", "Carloine Hagan", "Adam March"};

    string email[SIZE] = {"br273@txstate.edu", "mm362@txstate.edu", "mb251@txstate.edu", "ma152@txstate.edu",
    "bj385@txstate.edu","eg481@txstate.edu", "st139@txstate.edu", "nm230@txstate.edu",
    "cz170@txstate.edu", "js435@txstate.edu", "ch294@txstate.edu", "am193@txstate.edu"};

   int sequential; // to hold the position of the correct linear search result
    int binary;     // to hold the position of the correct binary search result
    int studentID;  // to hold the chosen students id number
    char repeat;    // to hold the choice of the user

    originalArray(id, name, email, SIZE); // calling the function originalArray
    bubbleSort(id, name, email, SIZE); // calling the function sortedArray

    do
    {

    studentID = getStudent();   // calling the function getStudent and storing the result in studentID

    sequential = linearSearch (id, SIZE, studentID);    // calling the function linearSearch and storing the result in sequential
    binary = binarySearch(id, SIZE, studentID);         // calling the function binarySearch and storing the result in binary

// testing the results of the searches to see if they exist
    if (sequential == -1 && binary == -1)
        cout << "\nThat student ID does not exist in the system. \n\n";
    else
    {
        linearResults(id, name, email, sequential); // calling the function linearResults
        cout << endl;
        binaryResults(id, name, email, binary);     //calling the function binaryResults
    }
    //Prompting the user for their choice on if to look up another student
    cout << "Do you want to look up another student? (y/n) ";
    cin >> repeat;
    cout << endl << endl;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

// Function that gathers user data and returns the value to the main function
int getStudent ()
{
    int studentID;

    cout << "Enter the students ID number you wish to search for: ";
    cin >> studentID;

    return studentID;
}

// Function that searches the id array through the linear search method to see if the users data
// exists and returns the position to the main function
int linearSearch (const int student[], int size, int choice)
{
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found)
    {
        if (student [index]== choice)
        {
            found = true;
            position = index;
        }
        index++;
    }
    return position;
}

// Function that searches the id array through the binary search method to see if the users data
// exists and returns the position to the main function
int binarySearch (const int student[], int size, int choice)
{
    int beginning = 0;
    int last = size -1;
    int center;
    int position = -1;
    bool found = false;
  while (!found && beginning <= last)
    {
        center = (beginning + last)/2;
        if (student[center] == choice)
        {
            found = true;
            position=center;
        }
        else if (student[center]>choice)
            last = center -1;
        else
            beginning = center +1;
    }
    return position;
}

// Function that displays all student data that is not sorted
void originalArray (const int number [], const string student [], const string mail [], int size)
{
    cout << "\t\t Unsorted Student List: " << endl;

    for (int index =0; index < size; index++)
    {

    cout << "Student ID: " << number[index] << endl;
    cout << "Student Name: " << student[index] << endl;
    cout << "Student Email: " << mail[index] << endl<< endl;

    }

}

// Function that sorts the arrays calls the sortedArray function to display the values
void bubbleSort ( int number [], string student [], string mail[], int size)
{
    bool change;
    int numHolder;
    string studentHolder, mailHolder;

    do{
        change = false;
        for (int index = 0; index < (size -1); index++)
        {
            if (number[index] > number[index + 1])
            {
                numHolder = number[index];
                number[index] = number[index + 1];
                number[index + 1] = numHolder;
                change = true;


            studentHolder = student[index];
            student[index] = student [index +1];
            student[index + 1] = studentHolder;
            mailHolder = mail[index];
            mail[index] = mail[index + 1];
            mail [index + 1] = mailHolder;
            }

        }
    }while (change);



    sortedArray(number, student, mail, size);
}

// Function that displays the sorted array of student records
void sortedArray (const int id [], const string name [], const string email [], int SIZE)
{
    char ready;

    cout << "Are you ready to see the sorted Student List? (y/n)";
    cin >> ready;

    if (ready == 'y' || ready == 'Y')
    {
        cout << "\t\t  Sorted Student List: " << endl;

        for (int index =0; index < SIZE; index++)
        {

            cout << "Student ID: " << id[index] << endl;
            cout << "Student Name: " << name[index] << endl;
            cout << "Student Email: " << email[index] << endl<< endl;
        }
    }
}
// Function that displays the results of the linear search to the user
void linearResults (const int number[], const string student[], const string mail[], int choice)
{
    cout << "\t\t Student Found(through sequential search): \n";
 cout << "Student ID: " << number[choice] << endl;
    cout << "Student Name: " << student[choice] << endl;
    cout << "Student Email: " << mail[choice] << endl;


}

// Function that displays the results of the binary search to the user
void binaryResults (const int number[], const string student [], const string mail[], int choice)
{
    cout << "\t\t Student Found(through binary search): \n";
    cout << "Student ID: " << number[choice] << endl;
    cout << "Student Name: " << student[choice] << endl;
    cout << "Student Email: " << mail[choice] << endl;
}
