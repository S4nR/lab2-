#include <iostream>
#include <fstream>
#include "file_manager.hpp"

void File_manager::save_all_changes(std::vector<Faculty> * faculties)
{
    std::fstream faclties_file;
    std::fstream students_file;
    faclties_file.open("C:\\Users\\Capitan\\OneDrive\\Desktop\\WriteFaculties.txt",std::ios::out);
    students_file.open("C:\\Users\\Capitan\\OneDrive\\Desktop\\students_with_abreviation.txt",std::ios::out);
    // faclties_file.open("WriteFaculties.txt",std::ios::out);
    // students_file.open("WriteStudents.txt",std::ios::out);
    if (!students_file.is_open())
    {
        std::cerr << "Fisierul de facultati nu se poate deschide." << std::endl;
    }
    if (!faclties_file.is_open())
    {
        std::cerr << "Fisierul de studenti nu se poate deschide." << std::endl;
    }
    int i = 0;
    for(auto iter = faculties->begin(); iter != faculties->end(); iter++)
    {
        for(auto students_iter = faculties->at(i).students.begin(); students_iter != faculties->at(i).students.end(); students_iter++)
        {
            students_file 
            << students_iter->first_name << "," 
            << students_iter->last_name << "," 
            << students_iter->email << ","
            << students_iter->enrollment_date << ","
            << students_iter->date_of_birth << ","
            << students_iter->study_year << ","
            << iter->faclt_abreviation << std::endl;
        }
        faclties_file << iter->faculty_name << "," 
        <<  iter->faclt_abreviation << "," 
        <<  iter->study_field << std::endl;
        i++;
    }
    faclties_file.close();
    students_file.close();
}

void File_manager::load_all_previous_changes(std::vector<Faculty> * faculties,std::map<std::string,int> &all_faculty_abreviations)
{
    std::ifstream faclties_file;
    std::ifstream students_file;
    faclties_file.open("C:\\Users\\chicu\\OneDrive\\Desktop\\WriteFaculties.txt",std::ios::in);
    students_file.open("C:\\Users\\chicu\\OneDrive\\Desktop\\students_with_abreviation.txt",std::ios::in);
    if (!students_file.is_open())
    {
        std::cerr << "Fisierul de facultati nu se poate deschide." << std::endl;
    }
    if (!faclties_file.is_open())
    {
        std::cerr << "Fisierul de studenti nu se poate deschide." << std::endl;
    }
    // while(!faclties_file.eof())
    // Faculty new_faculty;
    std::string line1;
    int i = 0;
    while(getline(faclties_file,line1))
    {
        std::string faculty_name;
        std::string faculty_abreviation;
        std::string studyField;
        std::istringstream sub_string (line1);
        std::getline(sub_string,faculty_name,',');
        std::getline(sub_string,faculty_abreviation, ',');
        std::getline(sub_string, studyField);
        all_faculty_abreviations[faculty_abreviation] = i;
        faculties->emplace_back(Faculty(faculty_name,faculty_abreviation,studyField));
        i++;
    }
    std::string line2;
    while(getline(students_file,line2))
    {
        std::string first_name;
        std::string second_name;
        std::string email;
        std::string enrollment_date;
        std::string date_of_birth;
        std::string std_year;
        int study_year;
        std::string faculty_abrv;
        std::istringstream sub_string (line2);
        std::getline(sub_string,first_name,',');
        std::getline(sub_string,second_name, ',');
        std::getline(sub_string,email,','); 
        std::getline(sub_string,enrollment_date,',');  
        std::getline(sub_string,date_of_birth,',');
        std::getline(sub_string,std_year,',');
        study_year = std::stoi(std_year);
        // sub_string >> study_year;
        std::getline(sub_string,faculty_abrv);
        faculties->at(all_faculty_abreviations[faculty_abrv]).students.
        emplace_back(Students(first_name,second_name,email,enrollment_date,date_of_birth,study_year));
    }
}
