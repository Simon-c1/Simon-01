#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>


using namespace std;

class Student {
    std::string name;
    std::string surname;
    std::vector<float> grades;
    std::string album_Number;
    float final_grade;

public:
    Student(string n, string s)
        {
            name = n;
            surname = s;
        }
    string get_name()
        {
            return name;
        }
    void setName(string n)
        {
            name = n;
        }
    void setSurname(string srn)
        {
            surname = srn;
        }
    string get_Surname()
        {
            return surname;
        }
        bool add_grade(float grade){
            if (grade >= 2.0 && grade <= 5.0) {
                    grades.push_back(grade);
                return true;
                }
            return false;
        }

        void calculate_grade() {
            float sum = std::accumulate(grades.begin(), grades.end(), 0.0f);
            final_grade = sum / grades.size();
        }
        void print() {
            std::cout << name << "\n" << surname << "\n";
            std::cout << "Album number" << album_Number << "\n";
            std::cout << "Grades ";
            for(float grade : grades) {
                std::cout << grade << "\t";
            }
            std::cout << "\nMean grade: " << final_grade << "\n";
        }
        bool set_albumNumber(string an) {
            if (an.length() >=5 && an.length() <=6){
                album_Number = an;
                return true;
            }
            return false;
        }
        string getalbumNumber() {
            return album_Number;
        }
        void semesterPassed() {
            int max_one_2 = std::count(grades.begin(), grades.end(), 2.0);
            if (max_one_2 <=1){
                std::cout <<"Passed";
            }
            else{
                std::cout << "Failed";
            }
        }
};


void homework_1(){
    Student student ("Szymon", "Chróśniak");
    student.set_albumNumber("000000");
    student.add_grade(2.0);
    student.add_grade(3.0);
    student.add_grade(4.5);
    student.calculate_grade();
    student.print();
    student.semesterPassed();
}


class Complex {
    float R;
    float I;

public:
    Complex(float a = 0, float b =0) {
        R = a;
        I = b;
    }
    void setR(float a){
        R = a;
    }
    float getR(){
        return R;
    }
    void setI(float b){
        I = b;
    }
    float getI(){
        return I;
    }
    void print() {
        if (I < 0) {
            std::cout << R << I << "i";
        }
        else{
            std::cout << R << "+" << I << "i";
        }
    }

    Complex add(Complex complex){
        R = R + complex.R;
        I = I + complex.I;
        return Complex(R, I);
    }

};


void homework_2(){
    Complex a(1.0, -2.0); // creates 1-2i
    Complex b(3.14); // creates 3.14

    b.setI(-5);

    Complex c = a.add(b);

    c.print(); // prints 4.14-7i
}

int main()
{
    int task;
    std::cout << "Which task would u like to check? (1-Student, 2-Complex) \n";
    std::cin >> task;
    if(task == 1) {
        homework_1();
    }
    else if(task == 2){
        homework_2();
    }
    else{
        std::cout << "Only 1 or 2";
    }
    return 0;
}
