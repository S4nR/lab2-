#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>
#ifndef STUDENTS_HPP     
#define STUDENTS_HPP    

class Students
{
    public:
        std::string first_name{"no data"};
        std::string last_name{"no data"};
        std::string email{"no data"};
        std::string enrollment_date{"no data"};
        std::string date_of_birth{"no data"};
        std::string fac_abrv{"no data"};
        int study_year{0};
        Students();
        Students(std::string first_name,
                 std::string last_name, 
                 std::string email,
                 std::string enrollment_date,
                 std::string date_of_birth,
                 int study_year
                //  std::string fac_abrv
        );  
        Students create_student(std::fstream &students_file,std::fstream &logging_file);

};

#endif