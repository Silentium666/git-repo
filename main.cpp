#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <conio.h>
#include "RenderMenu.h"
#include "MyClasses.h"

#define ISWORKING 1
#define SELECTION_SIZE 3

using namespace std;

vector<Student> students;
Group group;

int main()
{
	setlocale(LC_ALL, "rus");
	int temp;
	do{
		int selectedPoint = MenuRend();
		switch(selectedPoint){
			case '1':{
				Student temp;
				
				temp.SetInformation();
				students.insert(students.end(),temp);
				break;
			}
			case '2':{
				if(students.empty()){
					cout  << "Список студентов пуст" << endl;
					break;
				}
				cout << "Количество студентов: " << students.size() << endl;
				TableHeader();
				for(int i = 0; i < students.size(); i++){
					cout.width(2);
					cout << i+1;
					students[i].GetInformation();
				}
				break;
			}
			case '3':{
				if(students.empty()){
					cout  << "Список студентов пуст" << endl;
					break;
				}
				group.clear();
				int age;
				cout << "Введите максимальный возраст: ";
				cin >> age;
				for(int i = 0; i < students.size(); i++){
					if(age >= students[i].GetAge()){
						group.AddStudent(students[i]); 
//						if(group.size() >= SELECTION_SIZE) break;
					}
				}
				if(group.size() == 0){
					cout << endl << "Отобрать команду не удалось" << endl;
					break;
				}
				cout << endl << "Команда отобрана: " << endl;
				group.GetGroup();
				break;
			}
			case '4':{
				if(students.empty()){
					system("cls");
					cout << "Список студентов пуст" << endl;
					break;
				}
				group.clear();
				int langName;
				cout << "Введите язык программирования: ";
				cin >> langName;
				for(int i = 0; i < students.size(); i++){
					if(langName == students[i].GetAge()){
						group.AddStudent(students[i]); 
						if(group.size() >= SELECTION_SIZE){
							cout <<"Команда может быть укомплектована";
							break;
						}
					}
				}
				if(group.size() < SELECTION_SIZE){
					cout << "Команда не может быть укомплектована";
				}
				else return -1;
				break;
			}
			case '5':{
				cout << "\tДо свидания!";
				exit(0);
				break;
			}
			default:
				exit(-2);
		}
		cout << endl << "[Намжите любую клавишу...]";
		_getch();
	}while(ISWORKING);
	return 0;
}

