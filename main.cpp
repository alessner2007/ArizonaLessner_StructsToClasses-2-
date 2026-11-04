// Structs to Classes assigmnet by Arizona Lessner // 
// 11/04/2026                                      //


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <climits>

using namespace std;

const int NO_OF_STUDENTS = 20;

class studentType {
public:
    // mutators
    void setFName(string);
    void setLName(string);
    void setScore(int);
    void setGrade(char);

    // Accessors
    string getFName() const;
    string getLName() const;
    int getScore() const;
    char getGrade() const;

private:
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

void getData(ifstream& inFile, studentType sList[], int listSize);
void assignGrade(studentType students[]);
int highestScore(const studentType students[], int listSize);
void printHighest(const studentType students[], ofstream& outFile,
                  int highest);
void printResults(const studentType students[], ofstream& outFile);

int main() {
    ifstream inFile("Ch9_Ex2Data.txt");
    ofstream outFile("Ch9_Ex2Out.txt");

    studentType students[NO_OF_STUDENTS];
    int highest;

    if (!inFile || !outFile)
    {
        return 1;
    }

    getData(inFile, students, NO_OF_STUDENTS);
    assignGrade(students);
    printResults(students, outFile);
    highest = highestScore(students, NO_OF_STUDENTS);
    printHighest(students, outFile, highest);

    inFile.close();
    outFile.close();

    return 0;
}

// Mutator functions
void studentType::setFName(string name) {
    studentFName = name;
}

void studentType::setLName(string name) {
    studentLName = name;
}

void studentType::setScore(int score) {
    testScore = score;
}

void studentType::setGrade(char letter) {
    grade = letter;
}

// Accessor functions
string studentType::getFName() const {
    return studentFName;
}

string studentType::getLName() const
{
    return studentLName;
}

int studentType::getScore() const
{
    return testScore;
}

char studentType::getGrade() const
{
    return grade;
}

void getData(ifstream& inFile, studentType sList[], int listSize) {
    string firstName, lastName;
    int score;

    for (int i = 0; i < listSize; i++)
    {
        // read values for students[i]
        inFile >> firstName >> lastName >> score;

        // use mutators
        sList[i].setFName(firstName);
        sList[i].setLName(lastName);
        sList[i].setScore(score);
    }
}

void assignGrade(studentType students[])
{
    for (int i = 0; i < NO_OF_STUDENTS; i++)
    {
        if (students[i].getScore() >= 90)
            students[i].setGrade('A');
        else if (students[i].getScore() >= 80)
            students[i].setGrade('B');
        else if (students[i].getScore() >= 70)
            students[i].setGrade('C');
        else if (students[i].getScore() >= 60)
            students[i].setGrade('D');
        else
            students[i].setGrade('F');
    }
}

// A function to find highest test score
int highestScore(const studentType sList[], int listSize) {
    int hScore = INT_MIN; 

    for (int i = 0; i < listSize; i++)
    {
        if (hScore < sList[i].getScore())
            hScore = sList[i].getScore();
    }

    return hScore;
}

void printResults(const studentType students[], ofstream& outFile) {
    outFile << left
            << setw(25) << "Student Name"
            << setw(12) << "Test Score"
            << "Grade" << endl;

    outFile << "-----------------------------------------------"
            << endl;

    for (int i = 0; i < NO_OF_STUDENTS; i++)
    {
        string name = students[i].getLName() + ", "
                    + students[i].getFName();

        outFile << left
                << setw(25) << name
                << setw(12) << students[i].getScore()
                << students[i].getGrade() << endl;
    }

    outFile << endl;
}

// A function to find the highest test score.
void printHighest(const studentType students[], ofstream& outFile,
                  int highest) {
    outFile << "Highest test score: " << highest << endl;
    outFile << "Students having the highest test score:" << endl;

    for (int i = 0; i < NO_OF_STUDENTS; i++)
    {
        if (students[i].getScore() == highest)
        {
            outFile << students[i].getLName() << ", "
                    << students[i].getFName() << endl;
        }
    }
}
