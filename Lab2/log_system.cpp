#include "log_system.hpp"

Operation_logger* Logging_system::logger = nullptr;
bool Logging_system::has_changes = false;
void Logging_system::log_student(std::fstream &logging_file,Students &student)
{
    std::string message = "Enroled student: " + student.first_name + " " +  student.last_name;
    execute_logging(logging_file,message);
}
void Logging_system::log_faculty(std::fstream &logging_file,Faculty &faculty)
{
    std::string message = "Added faculty: " + faculty.faculty_name + " to field: " + faculty.study_field ;
    execute_logging(logging_file,message);
}
void Logging_system::log_graduation(std::fstream &logging_file,std::string email, int year_study)
{
    std::string message = "Student with email " + email + " is now year " + std::to_string(year_study); ;
    execute_logging(logging_file,message);
}
void Logging_system::log_error_graduation(std::fstream &logging_file,std::string email)
{
    std::string message = "Error:Student with email " + email + " could not graduate";
    execute_logging(logging_file,message);
}
void Logging_system::log_error_searching_student(std::fstream &logging_file,std::string email)
{
    std::string message = "Error: Student with email " + email + " wasn't found";
    execute_logging(logging_file,message);
}
void Logging_system::log_found_student(std::fstream &logging_file,std::string email)
{
    std::string message = "Error: Student with email " + email + " wasn found";
    execute_logging(logging_file,message);
}
Operation_logger* Logging_system::choose_logger()
{
    unsigned int choice;
    jump:
    std::cout << "Choose logger:  " << std::endl;
    std::cout << "1.File logger " << std::endl;
    std::cout << "2.Console logger " << std::endl;
    std::cin >> choice;
    if(choice != 1 && choice !=2)
    {
        std::cout <<"Idiot!!!" << std::endl;
        goto jump;
    }
    if(choice == 1)
        return new File_logger();
    else
        return new Console_logger();
}
void Logging_system::delete_logger()
{
    delete logger;
    logger = nullptr;
}
void Logging_system::execute_logging(std::fstream &logging_file,std::string &message)
{
    logger = choose_logger();
    logger->log(logging_file,message);
    delete_logger();
}