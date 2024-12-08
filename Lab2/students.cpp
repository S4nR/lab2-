#include "students.hpp"
#include "log_system.hpp"
Students::Students(std::string first_name,std::string last_name, std::string email,std::string enrollment_date,
std::string date_of_birth,int study_year/*std::string fac_abrv*/)
{
    this->first_name = first_name;
    this->last_name = last_name;
    this->email = email;
    this->enrollment_date = enrollment_date;
    this->date_of_birth = date_of_birth;
    this->study_year = study_year;
    // this->fac_abrv = fac_abrv;
}
Students::Students() = default;

Students Students::create_student(std::fstream &students_file,std::fstream &logging_file)
{
    Students new_student;
    std::string line;
    if(std::getline(students_file,line))
    {
        std::istringstream sub_string (line);
        std::getline(sub_string,new_student.first_name,',');
        std::getline(sub_string, new_student.last_name, ',');
        std::getline(sub_string, new_student.email, ',');
        std::getline(sub_string, new_student.enrollment_date, ',');
        std::getline(sub_string, new_student.date_of_birth);
        // std::getline(sub_string, new_student.fac_abrv);
    }
    Logging_system::log_student(logging_file,new_student);
    new_student.study_year = 1;
    return new_student;
}
   