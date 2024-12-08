#include <iostream>
#include <vector>
#include <string>
using namespace std;
//          EX  1 Operator Overloading
/*
    class Student {
    private:
        int credits;
    public:
        Student(int c = 0) : credits(c) {}

        // Overload the + operator for adding credits of two students
        Student operator+(const Student& other) {
            return Student(credits + other.credits);
        }

        // // Overload the + operator for adding credits between a student and an int (facultate)
        Student operator+(int additionalCredits) {
            return Student(credits + additionalCredits);
        }
        int getCredits() const {
            return credits;
        }

        void showCredits() const {
            std::cout << "Student has " << credits << " credits.\n";
        }
    };
    // Suprascrierea operatorului + in afara clasei permite 2 argumente
    // int operator+(const Student &ind1,const Student &ind2) 
    // {
    //     return ind1.getCredits() + ind2.getCredits();
    // }
    int main() 
    {
        //Utilizarea operatorilor de suprascriere
            Student st1(10);
            Student st2(10);
            Student g =  st1 + 5; 
            g.showCredits();
            Student b = st1 + st2;
            b.showCredits();
        return 0;
    }
*/
//          EX  2 Single and Multiple Inheritance   
/*
    class Student
    {
        public:
        void func1()
        {
            cout << "Student class" << endl;
        }
    };

    class Employee
    {
        public:
        void func2()
        {
            cout << "Employee class" << endl;
        }
    };
    class StudentEmployee : public Student, public Employee
    {
        public:
        void func3()
        {
            cout << "StudentEmployee class" << endl;
        }
    };
    int main()
    {
        StudentEmployee object;
        object.func1();
        object.func2();
        object.func3();

        return 0;
    }
*/
//          EX  3,4 Pure Virtual Functions and Abstract Classes    ,     Polymorphism
/*
    class Interface
    {
        public:
            virtual string get_class_name() = 0;
    };

    class Rock : public Interface
    {
        public:
            virtual string Get_name(){return "Rock";}
            string get_class_name() override { return "Rock";}
    };

    class Substance : public Rock
    {
        private:
            string name;
        public:
            Substance(const string& name) : name(name) {}

        string Get_name() override {return this->name;}
        string get_class_name() override { return "Substance";}
        
    };
    void print_class_name(Interface * object)
    {
        cout << object->get_class_name() << endl;
    }
    void print_name(Rock * rock)
    {
        cout << rock->Get_name() << endl;
    }


    int main()
    {
        Rock * object1 = new Rock();
        // print_name(object1);

        Substance * object2 = new Substance("Substance");
        // print_name(object2);

        print_class_name(object1);
        print_class_name(object2);

        return 0;
    }
*/
//          EX  5.1 Relationships between Classes: Aggregation
/*
    class Student 
    {
    public:
        string name;

        Student(const string& name) : name(name) {}
    };

    class Faculty 
    {
    private:
        string facultyName;
        vector<Student*> students;

    public:
        Faculty(const string& name) : facultyName(name) {}

        void addStudent(Student* student) 
        {
            students.push_back(student);
        }

        void printStudents() 
        {
            cout << "Faculty: " << facultyName << endl;
            for (auto student : students) 
            {
                cout << "Student: " << student->name << endl;
            }
        }
    };

    int main() 
    {
        Student* student1 = new Student("Alice");
        Student* student2 = new Student("Bob");

        Faculty faculty("Engineering");
        faculty.addStudent(student1);
        faculty.addStudent(student2);

        faculty.printStudents();

        // Curățăm memoria
        delete student1;
        delete student2;

        
        return 0;
    }
*/
//          EX  5.2 Relationships between Classes: Composition
/*
    class Book 
    {
    public:
        string title;

        Book(const string& title) : title(title) {}
    };

    class Library 
    {
    private:
        vector<Book> books; 

    public:
        void addBook(const string& title) 
        {
            books.emplace_back(title);
        }

        void printBooks() 
        {
            cout << "Library Books:" << endl;
            for (const auto& book : books) 
            {
                cout << "Book: " << book.title << endl;
            }
        }
    };

    int main() 
    {
        Library library;
        library.addBook("1990");
        library.addBook("THE IAN");

        library.printBooks();

        // Nu este nevoie de curățare manuală, cărțile vor fi distruse automat
        return 0;
    }
*/
//              EX 6