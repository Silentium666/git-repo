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
					cout  << "������ ��������� ����" << endl;
					break;
				}
				cout << "���������� ���������: " << students.size() << endl;
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
					cout  << "������ ��������� ����" << endl;
					break;
				}
				group.clear();
				int age;
				cout << "������� ������������ �������: ";
				cin >> age;
				for(int i = 0; i < students.size(); i++){
					if(age >= students[i].GetAge()){
						group.AddStudent(students[i]); 
//						if(group.size() >= SELECTION_SIZE) break;
					}
				}
				if(group.size() == 0){
					cout << endl << "�������� ������� �� �������" << endl;
					break;
				}
				cout << endl << "������� ��������: " << endl;
				group.GetGroup();
				break;
			}
			case '4':{
				if(students.empty()){
					system("cls");
					cout << "������ ��������� ����" << endl;
					break;
				}
				group.clear();
				int langName;
				cout << "������� ���� ����������������: ";
				cin >> langName;
				for(int i = 0; i < students.size(); i++){
					if(langName == students[i].GetAge()){
						group.AddStudent(students[i]); 
						if(group.size() >= SELECTION_SIZE){
							cout <<"������� ����� ���� ��������������";
							break;
						}
					}
				}
				if(group.size() < SELECTION_SIZE){
					cout << "������� �� ����� ���� ��������������";
				}
				else return -1;
				break;
			}
			case '5':{
				cout << "\t�� ��������!";
				exit(0);
				break;
			}
			default:
				exit(-2);
		}
		cout << endl << "[������� ����� �������...]";
		_getch();
	}while(ISWORKING);
	return 0;
}

