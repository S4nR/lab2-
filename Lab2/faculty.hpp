#include <iostream>
#include <string>
#include <fstream>
#include <stdbool.h>
#include <list>
#include <vector>
#include "students.hpp"
// #include <string_view>
#ifndef FACULTY_HPP     
#define FACULTY_HPP
enum study_field {MECHANICAL_ENGINEER = 0,SOFTWARE_ENGINEERING = 1,FOOD_TECHNOLOGY = 2,
                        URBANISM_ARCHITECTURE = 3,VETERINARY_MEDICINE = 4};

class Faculty : public Students
{
    public:
        std::string faculty_name;
        std::string faclt_abreviation;
        std::string study_field;
        std::list<Students> students;
        
        Faculty();
        Faculty(const std::string &p_faculty_name,const std::string &p_faclt_abreviation,const std::string &p_study_field);
        void add_student(std::fstream &students_file,std::fstream &logging_file);
        void graduate_student(std::fstream &logging_file);
        void display_all_graduates();
        void display_all_enrolled_students();
        void verify_students_adherence();

};

#endif