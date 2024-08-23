/*
Задание 1. Реализация программы учёта времени
Что нужно сделать
Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.
Пользователь взаимодействует с программой с помощью команд:
• Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название задачи, 
над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна быть автоматически 
завершена и начата новая.
• Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
• Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено. 
Также выводится название текущей выполняемой задачи, если таковая имеется.
• Команда exit выходит из программы.

Советы и рекомендации
Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.
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

    std::cout << "Введите команду" << std::endl;
    std::string command;
    std:: cin >> command;

    while (command != "exit"){
        if (command == "begin"){
            if (!have_task){
                std::cout << "Введите название задачи: ";
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

                std::cout << "Введите название задачи: ";
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
                std::cout << "Текущая задача - " << name_task << std::endl; 
            }
        }
        std::cout << "Введите команду" << std::endl;
        std:: cin >> command;
    }
}