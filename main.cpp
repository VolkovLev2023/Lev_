
#include <iostream>
#include <string.h>

class Student {
public:
        Student();
    void setLastName(const char *);
    void setFirstName(const char *);
    void setAge(int);
    void setMarks(int *, int);
    void calcAverageMark();

    bool isStudentExcellent();

    void showInfo();

private:
    char lastName[255];
    char firstName[255];
    int age;
    int *marks;
    int marksCount;
    float averageMark;
};

Student::Student() {
    strcpy(this->firstName, "");
    strcpy(this->lastName, "");
    this->age = 0;
    this->averageMark = 0;
}

void Student::setMarks(int *arrayMarks, int countMarks) {
    this->marks = arrayMarks;
    this->marksCount = countMarks;
}

void Student::setFirstName(const char *argFirstName) {
    if (argFirstName == 0) {
        std::cout << "Name cannot be empty!" << std::endl;
        return;
    }

    strcpy(this->firstName, argFirstName);
}

void Student::setLastName(const char *argLastName) {
    if (argLastName == 0) {
        std::cout << "Last name cannot be empty!" << std::endl;
        return;
    }

    strcpy(this->lastName, argLastName);
}

void Student::setAge(int argAge) {
    if (argAge < 0 || age > 100) {
        std::cout << "Age must be in the range of 1-100 years!" << std::endl;
        return;
    }

    this->age = argAge;
}

void Student::calcAverageMark() {
    float tmpSumm = 0;
    for (int i = 0; i < this->marksCount; i++) {
        tmpSumm += float(marks[i]);
    }

    this->averageMark = tmpSumm / float(this->marksCount);
}

bool Student::isStudentExcellent() {
    if (this->averageMark >= 4.5) {
        return true;
    }

    return false;
}

void Student::showInfo() {
    std::cout << "Student information: " << std::endl;
    std::cout << "Surname: " << this->lastName << std::endl;
    std::cout << "Name: " << this->firstName << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "Average score: " << this->averageMark << std::endl;
    std::cout << "Is the student an excellent student?: " << (this->isStudentExcellent() ? "yes" : "no") << std::endl;
}

int main() {
        setlocale(LC_ALL, "RU");
    int m[255] = {5, 3, 4, 2, 5, 5, 3, 4, 5, 5, 4, 5, 2, 2, 5};

    Student *s = new Student();

    s->setLastName("Harry");
    s->setFirstName("Potter");
    s->setAge(19);

    s->setMarks(m, 10);

    s->calcAverageMark();

    s->showInfo();

    delete s;

    return 0;
}
