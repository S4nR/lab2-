#include "faculty.hpp"
#include "log_system.hpp"
Faculty::Faculty(){};
Faculty::Faculty(const std::string &p_faculty_name,const std::string &p_faclt_abreviation,const std::string &p_study_field)
    : faculty_name (p_faculty_name), faclt_abreviation (p_faclt_abreviation), study_field  (p_study_field){}
void Faculty::add_student(std::fstream &students_file,std::fstream &logging_file)
{
    students.push_back(create_student(students_file,logging_file));
}
void Faculty::graduate_student(std::fstream &logging_file)
{
    std::string students_email;
    std::cout << "Write student's email" << std::endl;
    std::cin >> students_email;
    for(auto iter = students.begin(); iter != students.end(); iter++)
    {
        if(iter->email == students_email)
        {
            iter->study_year += 1;
            std::cout << "Student: " << iter->first_name << " " << iter->last_name << " is now year " << iter->study_year << std::endl;
            Logging_system::log_graduation(logging_file,students_email,iter->study_year);
            return;
        }
    }
    Logging_system::log_error_graduation(logging_file,students_email);

    std::cout <<"Student with email '" << students_email <<"' was not found" << std::endl;
}
void Faculty::display_all_graduates()
{
    std::cout << "Graduates students of " << faculty_name << std::endl;
    for(auto iter = students.begin(); iter != students.end(); iter++)
    {
        if(iter->study_year >= 4)
        {
            std::cout << iter->first_name << " " << iter->last_name <<" - year " << iter->study_year;
            std::cout << " email: " << iter->email << " date of birth:" <<iter->date_of_birth << std::endl;
        }
    }
}
void Faculty::display_all_enrolled_students()
{
    std::cout << "Enrolled students of (" << faculty_name << ")" << std::endl;
    for(auto iter = students.begin(); iter != students.end(); iter++)
    {
        if(iter->study_year < 4)
        {
            std::cout << iter->first_name << " " << iter->last_name <<" - year " << iter->study_year;
            std::cout << " email: " << iter->email << " date of birth:" <<iter->date_of_birth << std::endl;
        }
    }
}
void Faculty::verify_students_adherence()
{
    std::string email;
    std::cout << "Enter student's email" << std::endl;
    std::cin >> email;
    for(auto iter = students.begin(); iter != students.end(); iter++)
    {
        if(iter->email == email)
        {
            std::cout <<"Student: " << iter->first_name << " " << iter->last_name <<" - year " << iter->study_year;
            std::cout << " belongs to " << faclt_abreviation <<std::endl;
            return;
        }
    }
    std::cout << "Such student doesn't exist here" << std::endl;
}