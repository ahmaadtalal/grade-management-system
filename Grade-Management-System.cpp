#include <iostream>
#include <iomanip>
using namespace std;

const int maxStudents = 100;
const int maxSubjects = 100;

void inputMarks(int marks[maxStudents][maxSubjects], int numStudents, int numSubjects)
{
    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Enter marks for Student " << i + 1 << " (out of 100) for " << numSubjects << " subjects:\n";
        for (int j = 0; j < numSubjects; ++j)
        {
            do
            {
                cout << "Subject " << j + 1 << ": ";
                cin >> marks[i][j];

                if (marks[i][j] < 0 || marks[i][j] > 100)
                {
                    cout << "Invalid marks! Marks should be between 0 and 100. Please try again.\n";
                }
            }
            while (marks[i][j] < 0 || marks[i][j] > 100);
        }
    }
}

char grade(int marks)
{
    if (marks >= 90) return 'A';
    else if (marks >= 80) return 'B';
    else if (marks >= 70) return 'C';
    else if (marks >= 60) return 'D';
    else if (marks >= 50) return 'E';
    else return 'F';
}

void classifyGrades(int marks[maxStudents][maxSubjects], char grades[maxStudents][maxSubjects], int numStudents, int numSubjects)
{
    for (int i = 0; i < numStudents; ++i)
    {
        for (int j = 0; j < numSubjects; ++j)
        {
            grades[i][j] = grade(marks[i][j]);
        }
    }
}

void calculateAverages(int marks[maxStudents][maxSubjects], double studentAvg[maxStudents], double subjectAvg[maxSubjects], int numStudents, int numSubjects)
{
    for (int i = 0; i < numStudents; ++i)
    {
        double sum = 0;
        for (int j = 0; j < numSubjects; ++j)
        {
            sum += marks[i][j];
        }
        studentAvg[i] = sum / numSubjects;
    }

    for (int j = 0; j < numSubjects; ++j)
    {
        double sum = 0;
        for (int i = 0; i < numStudents; ++i)
        {
            sum += marks[i][j];
        }
        subjectAvg[j] = sum / numStudents;
    }
}

void displayResults(int marks[maxStudents][maxSubjects], char grades[maxStudents][maxSubjects], double studentAvg[maxStudents], double subjectAvg[maxSubjects], int numStudents, int numSubjects)
{
    cout << "\n\t\tSTUDENT GRADE MANAGEMENT SYSTEM" <<endl;
    cout << "\nStudent wise Grades and Averages\n" << endl;

    for (int i = 0; i < numStudents; ++i)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "\n";
        cout << setw(25) << left << "Subjects:" << setw(25) << left << "Grades:" << setw(25) << left << "Averages:" << endl;

        for (int j = 0; j < numSubjects; ++j)
        {
            cout << setw(25) << left << j + 1 << setw(25) << left << grades[i][j] << setw(25) << left << marks[i][j] << endl;
        }

        cout << endl;
    }

    cout << "\nSubject wise Averages\n" << endl;
    for (int j = 0; j < numSubjects; ++j)
    {
        cout << "Subject " << j + 1 << ":" << endl;
        cout << "\n";
        cout << setw(30) << left << "Average:" << setw(20) << left << "Average Grade:" << endl;
        cout << setw(30) << left << subjectAvg[j] << setw(20) << left << grade(subjectAvg[j]) << endl << endl;
    }
}


void updateGrades(int marks[maxStudents][maxSubjects], int numStudents, int numSubjects)
{
    int studentIndex, subjectIndex;

    cout << "Do you want to update grades for a student? (y/n): ";
    char updateChoice;
    cin >> updateChoice;

    if (updateChoice == 'y' || updateChoice == 'Y')
    {
        do
        {
            do
            {
                cout << "Enter the student index to update grades (1-" << numStudents << ") or enter 0 to stop updating: ";
                cin >> studentIndex;

                if (studentIndex == 0)
                {
                    cout << "Stopping grade update.\n";
                    return;
                }

                if (studentIndex < 1 || studentIndex > numStudents)
                {
                    cout << "Invalid student index! Please try again.\n";
                }
            }
            while (studentIndex < 1 || studentIndex > numStudents);

            do
            {
                cout << "Enter the subject index to update grades (1-" << numSubjects << ") or enter 0 to skip: ";
                cin >> subjectIndex;

                if (subjectIndex == 0)
                {
                    cout << "Skipping grade update for Student " << studentIndex << ".\n";
                    break;
                }

                if (subjectIndex < 1 || subjectIndex > numSubjects)
                {
                    cout << "Invalid subject index! Please try again.\n";
                }
            }
            while (subjectIndex < 1 || subjectIndex > numSubjects);

            cout << "Enter the new grades for Student " << studentIndex << " - Subject " << subjectIndex << " (out of 100):\n";
            do
            {
                cout << "New Grade: ";
                cin >> marks[studentIndex - 1][subjectIndex - 1];

                if (marks[studentIndex - 1][subjectIndex - 1] < 0 || marks[studentIndex - 1][subjectIndex - 1] > 100)
                {
                    cout << "Invalid marks! Marks should be between 0 and 100. Please try again.\n";
                }
            }
            while (marks[studentIndex - 1][subjectIndex - 1] < 0 || marks[studentIndex - 1][subjectIndex - 1] > 100);

            cout << "Grades updated successfully for Student " << studentIndex << " - Subject " << subjectIndex << "!\n";
        }
        while (updateChoice == 'y' || updateChoice == 'Y');
    }
    else
    {
        cout << "Stopping grade update.\n";
    }
}

int main()
{
    int numStudents, numSubjects;

    do
    {
        cout << "Enter the number of students: ";
        cin >> numStudents;

        if (numStudents > maxStudents || numStudents <= 0)
        {
            cout << "Invalid number of students. Please try again.\n";
        }
    }
    while (numStudents > maxStudents || numStudents <= 0);

    do
    {
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

        if (numSubjects > maxSubjects || numSubjects <= 0)
        {
            cout << "Invalid number of subjects. Please try again.\n";
        }
    }
    while (numSubjects > maxSubjects || numSubjects <= 0);

    int marks[maxStudents][maxSubjects];
    char grades[maxStudents][maxSubjects];
    double studentAvg[maxStudents];
    double subjectAvg[maxSubjects];

    inputMarks(marks, numStudents, numSubjects);
    classifyGrades(marks, grades, numStudents, numSubjects);
    calculateAverages(marks, studentAvg, subjectAvg, numStudents, numSubjects);
    displayResults(marks, grades, studentAvg, subjectAvg, numStudents, numSubjects);

    char updateChoice;
    cout << "Do you want to update grades? (y/n): ";
    cin >> updateChoice;
    if (updateChoice == 'y' || updateChoice == 'Y')
    {

    updateGrades(marks, numStudents, numSubjects);
    classifyGrades(marks, grades, numStudents, numSubjects);
    calculateAverages(marks, studentAvg, subjectAvg, numStudents, numSubjects);
    displayResults(marks, grades, studentAvg, subjectAvg, numStudents, numSubjects);
    
    }

    return 0;
}