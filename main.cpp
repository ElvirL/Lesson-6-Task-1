/*
������� 1. ���������� ��������� ����� �������
��� ����� �������
��������� ������� ��������� �������� ������� std::time, ���������� ���������� �������� ����� �������.
������������ ��������������� � ���������� � ������� ������:
� ������� begin �������� ������������ ����� ������. ����� ����� ���� ������� ������������ ������ ������ �������� ������, 
��� ������� �� ��������� ������ ��������. ���� ��� ���� ������ �����-�� ������ ������, ���������� ������ ���� ������������� 
��������� � ������ �����.
� ������� end ����������� ������������ ������� ������. ���� ������� ������� ������ ���, �� ������� ������ �� ������.
� ������� status ������� �� ����� ���������� � ���� ����������� ������� � �������, ������� ���� �� ��� ���������. 
����� ��������� �������� ������� ����������� ������, ���� ������� �������.
� ������� exit ������� �� ���������.

������ � ������������
��� std::time_t ���������� �� ������� � � ������� ���� ������������� ����� � �����, ������� ���� ���������.
*/

#include <iostream>
#include <map>
#include <ctime>
#include <string>

int main(){
    setlocale(LC_ALL,"Russian");
    std::time_t start_time;
    std::time_t end_time;
    bool have_task = false;

    std::map<std::string, std::string> tasks;
    std::string name_task;

    std::cout << "������� �������" << std::endl;
    std::string command;
    std:: cin >> command;

    while (command != "exit"){
        if (command == "begin"){
            if (!have_task){
                std::cout << "������� �������� ������: ";
                std::cin >> name_task;
                start_time = time(nullptr);
                have_task = true;
            }
            else {
                end_time = time(nullptr);
                double diff_time = std::difftime(end_time,start_time);
                int hours = (int)diff_time / 3600;
                int minutes = ((int)diff_time % 3600) /60;
                int seconds = ((int)diff_time % 3600) % 60;
                std::string spent_time = std::to_string(hours) + " hours " + std::to_string(minutes) + " minutes " + std::to_string(seconds) + " seconds"; 
                tasks[name_task] = spent_time;

                std::cout << "������� �������� ������: ";
                std::cin>> name_task;
                start_time = time(nullptr);
            }
        }
        else if (command == "end"){
            if (have_task){
                end_time = time(nullptr);
                double diff_time = std::difftime(end_time,start_time);
                int hours = (int)diff_time / 3600;
                int minutes = ((int)diff_time % 3600) /60;
                int seconds = ((int)diff_time % 3600) % 60;
                std::string spent_time = std::to_string(hours) + " hours " + std::to_string(minutes) + " minutes " + std::to_string(seconds) + " seconds"; 
                tasks[name_task] = spent_time;
                have_task = false;
            }
        }
        else if (command == "status"){
            for (std::map<std::string, std::string>::iterator it  = tasks.begin(); it!=tasks.end(); ++it){
                std:: cout << it->first << " - " << it->second << std::endl;
            }
            if (have_task){
                std::cout << "������� ������ - " << name_task << std::endl; 
            }
        }
        std::cout << "������� �������" << std::endl;
        std:: cin >> command;
    }
}