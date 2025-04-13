#include <iostream>
#include<mysql.h>  //these libralies were added by including folders to project options
#include<mysqld_error.h> //and this particularly , when pasting th ".dll" tothe project folder
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "Atharv02";  //you data to login
                                //these are not necessary , but useful.
                                


int main() {
	MYSQL* obj;
	int College_ID;
	char Name[20];
	char BirthDate[11]; //this is always yyyy-mm-dd+0 from every char array
	float Grade;
	 
	bool ProgramIsOpened = true;
	int answer;
	char* consult;
	char* sentence;
	string sentence_aux;
	
	
	if(!(obj=mysql_init(0)))
	{
		cout<<"ERROR : MySQL objects could not be created"<<endl;
		
	}
	else
	{
		if(!mysql_real_connect(obj,HOST,USER,PASS,"school",3306,NULL,0))
		{
			cout<<"ERROR : Some database info is wrong or do not exist."<<endl;
			cout<<mysql_error(obj)<<endl;
		}
		else
		{
			cout<<"Logged in."<<endl<<endl;
			
			while(ProgramIsOpened)
			{
				cout<<"College ID : ";
				cin>>College_ID;
				cin.ignore(100,'\n');
				
				cout<<"Name : ";
				cin.getline(Name, 20 , '\n');
				
				cout<<"BirthDate : ";
				cin.getline(BirthDate, 11,'\n');
				
				cout<<"Grade : ";
				cin>>Grade;
				cin.ignore(100,'\n');
				cout<<endl;
				
				//setting our update.
 
				sentence_aux="INSERT INTO student(College_ID,Name,BirthDate,Grade) VALUES('%d','%s','%s','%f')";
				sentence = new char[sentence_aux.length()+1];
				strcpy(sentence,sentence_aux.c_str());
				consult=new char[strlen(sentence)+sizeof(int)+strlen(Name)+strlen(BirthDate)+sizeof(float)];
				//sentence = new char[strlen(sentence)+strlen(Name)+strlen(Name)+strlen(BirthDate)+sizeof(float)];
				sprintf(consult,sentence,College_ID,Name, BirthDate,Grade);
				
				
				
				if(mysql_ping(obj))
				{
					cout<<"ERROR : Impossible to connect. "<<endl;
					cout<<mysql_error(obj)<<endl;
					
				}
				if(mysql_query(obj,consult))
				{
					cout<<"ERROR:"<<mysql_error(obj)<<endl;
					rewind(stdin);
					getchar();
		
				}
				else
				{
					cout<<"Info added Correctly. "<<endl;
					
				}
				mysql_store_result(obj);
				
				cout<<endl<<"Another ? "<<endl;
				cout<<"[1]: Yes"<<endl;
				cout<<"[0]: No"<<endl;
				cout<<"Answer: ";
				cin>>answer;
				cin.ignore(100,'\n');
				if(answer==0)
				{
					ProgramIsOpened=false;
					
				}
				cout<<endl;
				
			}
		}
	}
	cout<<"bye!!!"<<endl;
	return 0;
}
