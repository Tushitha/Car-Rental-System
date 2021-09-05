#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;
class Cars
{
	protected:
		char name[30];
		int ID;  
		bool booked; // 1 or 0
	public:
		void getdata();
		void putdata();
		void modify();
		bool booked_status(){
			return booked;
		}
		int get_ID(){
			return ID;
		}
		char* get_name(){
			return name;
		}
		void bookit(){
			this->booked = 1;
		}
		void unbookit(){
			this->booked = 0;			
		}
}c;
class Login{
	protected:
		char username[100];
		char password[50];
};
class Login_user:public Login{
	public:
		void Register();
		int check_user_existence(char[]);
		void login(char user_n[], char pass[]);
		int show_hatchback();
		int show_sedan();
		int show_suv();
		int show_luxury();
		void book_hatchback();
		void book_sedan();
		void book_suv();
		void book_luxury();
		void bill(int);  
		void do_user_work();
		void unbook();
		int search_car_hatchback(int);
		int search_car_sedan(int);
		int search_car_suv(int);
		int search_car_luxury(int);
};
class Login_admin:public Login{
	public:
		void login_admin(char user_n[],char pass[]); 
		void Read_user_data();
		void search_car();
		void delete_c();
		void modify_car();
		void add_car_hatchback();
		void add_car_luxury();
		void add_car_sedan();
		void add_car_suv();
		void display_car_hatchback();
		void display_car_luxury();
		void display_car_sedan();
		void display_car_suv();
		void do_work();
	
};
int str_len(char c[])
{
	int length=0;
	while(c[length]!='\0')
	{
		length++;
	}
	return length;
}
string conv_to_str(char* a,int size)
{
	int i;
	string s = "";
	for(i=0;i<size;i++)
	{
		s = s + a[i];
	}
	return s;
}

int isSubstring(string s1, string s2) 
{ 
    int M = s1.length(); 
    int N = s2.length(); 
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        for (j = 0; j < M; j++) 
            if (s2[i + j] != s1[j]) 
                break; 
        if (j == M) 
            return i; 
    } 
    return -1;
} 

void delay(int delay)
{
int now=time(NULL);
int later=now+delay;
while(now<=later)now=time(NULL);
}
void menu()
{	
Login_user l;
	Login_admin la;
	char username[100],password[50];
	int choosing;
	string user;
	string line;
	ifstream fin("decorate.txt");
	while(getline(fin,line))
	{
		cout<<line<<endl;
	}
	do{
		cout<<"\n\t\t\tEnter:\n \t\t\t[1]Login\n \t\t\t[2]User Registeration\n \t\t\t[3]Exit Program\n \t\t\tYour Choice: ";
		cin>>choosing;
		switch(choosing)
	{
		case 1: 
				system("cls");
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"\t\t\tLogin"<<endl;
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"\n\tUsername - ";
			cin>>username;
			cout<<"\tPassword - ";
			cin>>password;
			user = conv_to_str(username,str_len(username));
			if(isSubstring("@cadmin.ac.in",user)!=-1)
			{
				la.login_admin(username,password);
				choosing = 3;
			}
			else{
				l.login(username,password);
				choosing = 3;
			}
			break;
		case 2: 
		system("cls");
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"\t\t\tRegistration"<<endl;
			cout<<"------------------------------------------------------------"<<endl;
			l.Register();
			cout<<"Thank You For Registering"<<endl;
			break;
		case 3:
			cout<<"Thank You for using our service..!!"<<endl;
			delay(4);
			exit(0);
			break;
		default:
			cout<<"Wrong option selected please refer menu"<<endl;
			exit(1);
	}
	}while(choosing!=3);	
		
}
void Cars::getdata()
{
	cout<<"Enter name of car: ";
	scanf(" %[^\n]s",name);
	while(1)
	{
		cout<<"Enter ID of the car: ";
		cin>>ID;
		if(ID/10000 == 0 && ID/1000!=0)
			break;
		else
			cout<<"4 Digit please"<<endl;
	}
	while(1)
	{
		cout<<"Booked status(1 for yes/0 for no): ";
		cin>>booked;
		if(booked==1||booked==0)
			break;
		else
			cout<<"Enter (1 for yes/0 for no)"<<endl;
	}
}

void Cars::putdata()
{
	if(booked==1)
		cout<<"\t"<<"|"<<setw(20)<<name<<" |"<<setw(5)<<ID<<" |"<<setw(4)<<"Yes"<<" |"<<endl;
	else
		cout<<"\t"<<"|"<<setw(20)<<name<<" |"<<setw(5)<<ID<<" |"<<setw(4)<<"No"<<" |"<<endl;
}
void Cars::modify() 
{
	int ch;
	cout<<"Current details are"<<endl;
	putdata();
	cout<<"Modify:\n 1.Name\n 2.ID\n 3.Booked?\n 4.All\n Your choie: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
			cout<<"Enter new name of the Car: ";
			cin>>name;
			break;
		case 2:
			cout<<"Enter new ID: ";
			cin>>ID;
			break;
		case 3:
			cout<<"Booking status?(1 for yes/0 for no): ";
			cin>>booked;
			break;
		case 4:
			getdata();
			break;
		default:
			cout<<"Wrong option selected, refer menu"<<endl;
	}
}

void Login_admin::login_admin(char user_n[], char pass[])
{
	string name;
	int ch = 0,round = 0;
	ifstream fin("admin_data.txt",ios::in);
	if(!(fin)) 
	{
		cout<<"No admin Data Available!"<<endl;
		fin.close();
		return;
	}
	else{
		while(fin>>username>>password)
		{
			if(strcmp(user_n,username)==0 && strcmp(pass,password)==0)
			{
				name = conv_to_str(user_n,str_len(user_n));
				size_t found = name.find("@cadmin.ac.in"); 
					system("cls");
				cout<<"Hello "<<name.substr(0,found)<<endl;
				round = 1;
				do_work();
			}
			else if(strcmp(user_n,username)==0)
			{
				cout<<"Entered password is incorrect"<<endl;
				delay(4);
				system("cls");
				menu();
								round = 1;
			}
		}
		fin.close();
		if(round==0)
		{
			cout<<"This admin does not exist!"<<endl;
		}
	}
}
void Login_admin::Read_user_data()
{
	ifstream fin("login_data.txt",ios::in);
	if(!(fin)) 
	{
		cout<<"No User Data Available!"<<endl;
		fin.close();
		return;
	}
	while(fin>>username>>password)
	{
		cout<<"|"<<setw(20)<<username<<"|"<<setw(10)<<password<<"|"<<endl;
	}
	fin.close();
}

void Login_admin::add_car_hatchback(){
	char ch='y';
	ofstream fout("HATCHBACK.txt",ios::out|ios::app);
	while(ch=='y'|ch=='Y')
	{
		c.getdata();
		fout.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to add more(y/n): ";
		cin>>ch;
	}
	cout<<"\nData added to file\n"<<endl;
	fout.close();
}

void Login_admin::add_car_luxury(){
	char ch='y';
	ofstream fout("LUXURY.txt",ios::out|ios::app);
	while(ch=='y'|ch=='Y')
	{
		c.getdata();
		fout.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to add more(y/n): ";
		cin>>ch;
	}
	cout<<"\nData added to file\n"<<endl;
	fout.close();
}

void Login_admin::add_car_sedan(){
	char ch='y';
	ofstream fout("SEDAN.txt",ios::out|ios::app);
	while(ch=='y'|ch=='Y')
	{
		c.getdata();
		fout.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to add more(y/n): ";
		cin>>ch;
	}
	cout<<"\nData added to file\n"<<endl;
	fout.close();
}

void Login_admin::add_car_suv(){
	char ch='y';
	ofstream fout("SUV.txt",ios::out|ios::app);
	while(ch=='y'|ch=='Y')
	{
		c.getdata();
		fout.write((char*)&c,sizeof(c));
		cout<<"\nDo you wish to add more(y/n): ";
		cin>>ch;
	}
	cout<<"\nData added to file\n"<<endl;
	fout.close();
}

void Login_admin::display_car_hatchback()
{
	ifstream fin("HATCHBACK.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No HATCHBACK Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |\n"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_luxury()
{
	ifstream fin("LUXURY.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No LUXURY Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |\n"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_sedan()
{
	ifstream fin("SEDAN.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SEDAN Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |\n"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::display_car_suv()
{
	ifstream fin("SUV.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SUV Data Available!"<<endl;
		fin.close();
		return;
	}
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |\n"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		c.putdata();
		cout<<endl; 
	}
	fin.close();
}

void Login_admin::search_car()
{
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be searched: ";
	cin>>entered_id;
	ifstream fin1("HATCHBACK.txt",ios::in);
	while(fin1.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin1.close();
	if(found =='y'){return;}
	ifstream fin2("SEDAN.txt",ios::in);
	while(fin2.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin2.close();
	if(found =='y'){return;}
	ifstream fin3("SUV.txt",ios::in);
	while(fin3.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin3.close();
	if(found =='y'){return;}
	ifstream fin4("LUXURY.txt",ios::in);
	while(fin4.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			c.putdata();
			found = 'y';
		}
	}
	fin4.close();
	if(found =='n'){cout<<"\nCar of ID "<<entered_id<<" is not in the file.\n";}
	return;
}
void Login_admin::modify_car()
{
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be searched: ";
	cin>>entered_id;
	fstream fio1("HATCHBACK.txt",ios::in|ios::out);
	fio1.seekg(0);
	while(!fio1.eof())
	{
		int loc = fio1.tellg(); //storing the current location in loc
		fio1.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio1.seekg(loc); //moving the pointer to current location
			fio1.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
			break;
		}
	}
	fio1.close();
	if(found =='y'){return;}
	fstream fio2("SEDAN.txt",ios::in|ios::out);
	fio2.seekg(0);
	while(!fio2.eof())
	{
		int loc = fio2.tellg(); //storing the current location in loc
		fio2.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio2.seekg(loc); //moving the pointer to current location
			fio2.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
		}
	}
	fio2.close();
	if(found =='y'){return;}
	fstream fio3("SUV.txt",ios::in|ios::out);
	fio3.seekg(0);
	while(!fio3.eof())
	{
		int loc = fio3.tellg(); 
		fio3.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio3.seekg(loc); 
			fio3.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
		}
	}
	fio3.close();
	if(found =='y'){return;}
	fstream fio4("LUXURY.txt",ios::in|ios::out);
	fio4.seekg(0);
	while(!fio4.eof())
	{
		int loc = fio4.tellg(); 
		fio4.read((char*)&c,sizeof(c));
		if(c.get_ID()==entered_id)
		{
			c.modify();
			found = 'y';
			fio4.seekg(loc); 
			fio4.write((char*)&c,sizeof(c));
			cout<<"\nYour record of ID "<<entered_id<<" has been updated"<<endl;
		}
	}
	fio4.close();
	if(found =='n'){cout<<"\nCar of ID "<<entered_id<<"is not in the file.\n";}
	return;
}
void Login_admin::delete_c() 
{	
	int entered_id;
	char found  = 'n';
	cout<<"\nEnter the ID to be deleted: ";
	cin>>entered_id;
	ifstream fin1("HATCHBACK.txt",ios::in);
	ofstream fout1("temp1.txt",ios::out|ios::app);
	while(fin1.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			found = 'y';
		}
		else{
			fout1.write((char*)&c,sizeof(c)); 
		}
	}
	fin1.close();
	fout1.close();
	remove("HATCHBACK.txt");
	rename("temp1.txt","HATCHBACK.txt");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	ifstream fin2("SEDAN.txt",ios::in);
	ofstream fout2("temp2.txt",ios::out|ios::app);
	while(fin2.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			found = 'y';
		}
		else{
			fout2.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}	
	fin2.close();
	fout2.close();
	remove("SEDAN.txt");
	rename("temp2.txt","SEDAN.txt");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	ifstream fin3("SUV.txt",ios::in);
	ofstream fout3("temp3.txt",ios::out|ios::app);
	while(fin3.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			found = 'y';
		}
		else{
			fout3.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	fin3.close();
	fout3.close();
	remove("SUV.txt");
	rename("temp3.txt","SUV.txt");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	ifstream fin4("LUXURY.txt",ios::in);
	ofstream fout4("temp4.txt",ios::out|ios::app);
	while(fin4.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID()==entered_id)
		{
			found = 'y';
		}
		else{
			fout4.write((char*)&c,sizeof(c)); //writing to temp file
		}
	}
	fin4.close();
	fout4.close();
	remove("LUXURY.txt");
	rename("temp4.txt","LUXURY.txt");
	if(found=='y'){
		cout<<"Record successfully deleted"<<endl;
		return;
	}
	else{
		cout<<"Record not found"<<endl;
	}
}
void Login_admin::do_work()
{ 
	int ch,op,ap;
	int choose;
	do{
		    cout<<"------------------------------------------------------------"<<endl;
			cout<<"\t\t\tADMIN PAGE "<<endl;
			cout<<"------------------------------------------------------------"<<endl;
			cout<<"CHOOSE OPTION\n\n";
		cout<<"\t1.Add Data \n\t2.Display Data \n\t3.Search Data \n\t4.Modify Data \n\t5.Delete Data\n\t6.To see all the users\n\t7.Main menu\n"<<endl;
		cout<<"Enter choice: ";
		cin>>ch;
		system("cls");
		switch(ch)
		{
			case 1:
				cout<<"\n\n*********ADD CAR DATA**********\n\n";
				cout<<"Car Categories\n 1.Hatchback\n 2.Sedan\n 3.SUV\n 4.Luxury\n Your choice: ";
				cin>>choose;
				switch(choose)
				{
					case 1:
						add_car_hatchback();
						cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 2:
						add_car_sedan();
							cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 3:
						add_car_suv();
								cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 4:
						add_car_luxury();
								cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					default:
						cout<<"Wrong option selected"<<endl;
				}
				break;
			case 2:
				choose = 0;
		cout<<"\n\n**********DISPLAY RECORD**********\n\n";
				cout<<"Car Categories\n 1.Hatchback\n 2.Sedan\n 3.SUV\n 4.Luxury\n 5.All\n Your choice: ";
				cin>>choose;
				switch(choose)
				{
					case 1:
						display_car_hatchback();
							cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
			           break;
					case 2:
						display_car_sedan();
								cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 3:
						display_car_suv();
							cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 4:
						display_car_luxury();
						cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					case 5:
						display_car_hatchback();
						display_car_sedan();
						display_car_suv();
						display_car_luxury();
							cout<<"\n ENTER 0: ADMIN PAGE:\t";
				        cin>>ap;
			            system("cls");
			           do_work();
						break;
					default:
						cout<<"Wrong option selected"<<endl;
				}
				break;
			case 3:
				cout<<"\n\n**********SEARCH RECORD**********\n";
				search_car();
					cout<<"\n ENTER 0: ADMIN PAGE:\t";
				cin>>ap;
			system("cls");
			           do_work();
				
				break;
			case 4:
			cout<<"\n\n**********MODIFY RECORD**********\n";
				modify_car();
			cout<<"\n ENTER 0: ADMIN PAGE:\t";
				cin>>ap;
			system("cls");
			           do_work();
				break;
			case 5:
				cout<<"\n\n**********DELETE RECORD**********\n";
				delete_c();
			cout<<"\n ENTER 0: ADMIN PAGE:\t";
				cin>>ap;
			system("cls");
			           do_work();
				break;
			case 6:
				cout<<"\n\n**********USER DATA**********\n";
				Read_user_data();
					cout<<"\n ENTER 0: ADMIN PAGE:\t";
				cin>>ap;
			system("cls");
			           do_work();
				break;
			case 7:
				system("cls");
				menu();
				break;
			default:
				cout<<"Wrong choice\n";
				break;
		}
	}while(ch!=8);
	return ;
}

int Login_user::check_user_existence(char uname[] )
{
	int flag = 0;
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password)
	{
		if(strcmp(uname,username)==0){
			flag = 1;
		}
	}
	fin.close();
	if(flag==1)
	{
		return 1;
	}
	return 0;
}
void Login_user :: Register()
{
	char new_name[100];
	char pass[50];
	int val;
	ofstream fout("login_data.txt",ios::app);
	do{
		cout<<"Enter username: ";
		cin>>new_name;
		val = check_user_existence(new_name);
		if(val==1){cout<<"Username already exists use another one "<<endl;}
	}while(val==1);
	cout<<"Enter your preferred password: ";
	cin>>pass;
	fout<<new_name<<" "<<pass<<endl;
	fout.close();
}
int Login_user :: show_hatchback()
{
	ifstream fin("HATCHBACK.txt",ios::in);
	if(!(fin)) 
	{
		cout<<"No HATCHBACK Data Available!"<<endl;
		fin.close();
		return 1;
	}
	cout<<"\n"<<endl;
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |"<<endl;
	cout<<"\n\tAvailable hatchback cars are\n"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.close();
	return 0; 
}

int Login_user :: show_sedan()
{
	ifstream fin("SEDAN.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SEDAN Data Available!"<<endl;
		fin.close();
		return 1;
	}
	cout<<"FORMAT"<<endl;
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |"<<endl;
	cout<<"Available SEDAN cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.close();
	return 0;
}
int Login_user :: show_suv()
{
	ifstream fin("SUV.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No SUV Data Available!"<<endl;
		fin.close();
		return 1;
	}
	cout<<"FORMAT"<<endl;
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |"<<endl;
	cout<<"Available SUV cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.close();
	return 0;
}
int Login_user :: show_luxury()
{
	ifstream fin("LUXURY.txt",ios::in);
	if(!(fin)) //check if the file is empty
	{
		cout<<"No LUXURY Data Available!"<<endl;
		fin.close();
		return 1;
	}
	cout<<"FORMAT"<<endl;
	cout<<"\t"<<"|"<<setw(20)<<"NAME"<<" |"<<setw(5)<<"ID"<<" |"<<setw(4)<<"BOOKED"<<" |"<<endl;
	cout<<"Available LUXURY cars are"<<endl;
	while(fin.read((char*)&c,sizeof(c)))
	{
		if(c.booked_status()==0){
			c.putdata();
		}
	}
	fin.close();
	return 0;
}
void Login_user :: book_hatchback()
{
	int car_to_book;
	char found = 'n';
	int check;
	do{
		cout<<"Enter the ID of car to book: ";
		cin>>car_to_book;
		check = search_car_hatchback(car_to_book);
		if(check == 0){
			cout<<"ID is wrong :( refer menu"<<endl;
		}
	}while(check==0);
	fstream fio("HATCHBACK.txt",ios::in|ios::out);
	fio.seekg(0);
	while(!fio.eof())
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book && c.booked_status() == 0){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == car_to_book && c.booked_status() == 1)
		{
			cout<<"Sorry its Already booked"<<endl;
			found = 'y';
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		cout<<"You've chosen a hatchback car"<<endl;
		bill(car_to_book); //this->invoice(car_to_book,name_of_car);
		return;
	}
}

void Login_user :: book_sedan()
{
	int car_to_book;
	char found = 'n';
	int check;
	do{
		cout<<"Enter the ID of car to book: ";
		cin>>car_to_book;
		check = search_car_sedan(car_to_book);
		if(check == 0){
			cout<<"ID is wrong :( refer menu"<<endl;
		}
	}while(check==0);
	fstream fio("SEDAN.txt",ios::in|ios::out);
	fio.seekg(0);
	while(!fio.eof())
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book && c.booked_status() == 0){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == car_to_book && c.booked_status() == 1)
		{
			cout<<"Sorry its Already booked"<<endl;
			found = 'y';
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		cout<<"You've chosen a sedan car"<<endl;
		bill(car_to_book);
		return;
	}
}
void Login_user :: book_suv()
{
	int car_to_book;
	char found = 'n';
	int check;
	do{
		cout<<"Enter the ID of car to book: ";
		cin>>car_to_book;
		check = search_car_suv(car_to_book);
		if(check == 0){
			cout<<"ID is wrong :( refer menu"<<endl;
		}
	}while(check==0);
	fstream fio("SUV.txt",ios::in|ios::out);
	fio.seekg(0);
	while(!fio.eof())
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book && c.booked_status() == 0){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == car_to_book && c.booked_status() == 1)
		{
			cout<<"Sorry its Already booked"<<endl;
			found = 'y';
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		cout<<"You've chosen a SUV car"<<endl;
		bill(car_to_book);
		return;
	}
}

void Login_user :: book_luxury()

{
	int car_to_book;
	char found = 'n';
	int check;
	do{
		cout<<"Enter the ID of car to book: ";
		cin>>car_to_book;
		check = search_car_luxury(car_to_book);
		if(check == 0){
			cout<<"ID is wrong :( refer menu"<<endl;
		}
	}while(check==0);
	fstream fio("LUXURY.txt",ios::in|ios::out);
	fio.seekg(0);
	while(!fio.eof())
	{
		int loc = fio.tellg(); 
		fio.read((char*)&c,sizeof(c));
		if(c.get_ID() == car_to_book && c.booked_status() == 0){
			c.bookit();
			found = 'y';
			fio.seekg(loc);
			fio.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == car_to_book && c.booked_status() == 1)
		{
			cout<<"Sorry its Already booked"<<endl;
			found = 'y';
		}
	}
	fio.close();
	if(found=='n'){
		cout<<"Not Available!"<<endl;
		return;
	}
	else if(found == 'y'){
		cout<<"You've chosen a LUXURY car"<<endl;
		bill(car_to_book);
		return;
	}
}
void Login_user::unbook()
{
	char* name_of_car;
	int id_car;
	do{
	cout<<"Enter the ID of car you want to submit: ";
	cin>>id_car;
	if(id_car/10000!=0 && id_car/1000==0){cout<<"ID is of 4 digit please check your bill"<<endl;}
	}while(id_car/10000!=0 && id_car/1000==0);
	char found = 'n';
	fstream fio1("HATCHBACK.txt",ios::in|ios::out);
	fio1.seekg(0);
	while(!fio1.eof())
	{
		int loc = fio1.tellg(); 
		fio1.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car && c.booked_status()==1){
			c.unbookit();
			name_of_car = c.get_name();
			found = 'y';
			fio1.seekg(loc);
			fio1.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == id_car && c.booked_status()==0){
			name_of_car = c.get_name();
			cout<<"This ID is of "<<name_of_car<<"\nPlease enter the correct ID of Your car"<<endl;
			found = 'j';
		}
	}
	fio1.close();
	if(found == 'j'){return;}
	if(found == 'y'){
		cout<<"Hope You liked Our Hatchback Car :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio2("SEDAN.txt",ios::in|ios::out);
	fio2.seekg(0);
	while(!fio2.eof())
	{
		int loc = fio2.tellg(); 
		fio2.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car && c.booked_status()==1){
			c.unbookit();
			name_of_car = c.get_name();
			found = 'y';
			fio2.seekg(loc);
			fio2.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == id_car && c.booked_status()==0){
			name_of_car = c.get_name();
			cout<<"This ID is of "<<name_of_car<<"\nPlease enter the correct ID of Your car"<<endl;
			found = 'j';
		}
	}
	fio2.close();
	if(found == 'j'){return;}
	if(found == 'y'){
		cout<<"Hope You liked Our SEDAN Car  :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio3("SUV.txt",ios::in|ios::out);
	fio3.seekg(0);
	while(!fio3.eof())
	{
		int loc = fio3.tellg(); 
		fio3.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			name_of_car = c.get_name();
			found = 'y';
			fio3.seekg(loc);
			fio3.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == id_car && c.booked_status()==0){
			name_of_car = c.get_name();
			cout<<"This ID is of "<<name_of_car<<"\nPlease enter the correct ID of Your car"<<endl;
			found = 'j';
		}
	}
	fio3.close();
	if(found == 'j'){return;}
	if(found == 'y'){
		cout<<"Hope You liked Our SUV Car  :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	
	fstream fio4("LUXURY.txt",ios::in|ios::out);
	fio4.seekg(0);
	while(!fio4.eof())
	{
		int loc = fio4.tellg(); 
		fio4.read((char*)&c,sizeof(c));
		if(c.get_ID() == id_car){
			c.unbookit();
			name_of_car = c.get_name();
			found = 'y';
			fio4.seekg(loc);
			fio4.write((char*)&c,sizeof(c));
		}
		else if(c.get_ID() == id_car && c.booked_status()==0){
			name_of_car = c.get_name();
			cout<<"This ID is of "<<name_of_car<<"\nPlease enter the correct ID of Your car"<<endl;
			found = 'j';
		}
	}
	fio4.close();
	if(found == 'j'){return;}
	if(found == 'y'){
		cout<<"Hope You liked Our LUXURY Car  :)"<<endl;
		cout<<"Thank You for using our services!!"<<endl;
		return;
	}
	else if(found == 'n')
	{
		cout<<"The Car you are submitting does not belong to us!!"<<endl;
	}
}
int Login_user::search_car_hatchback(int id_car)
{
	char found = 'n';
	ifstream fio1("HATCHBACK.txt",ios::in);
	while(fio1.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID() == id_car){
			found = 'y';
		}
	}
	fio1.close();
	if(found == 'y'){
		return 1;
	}
	return 0;
}
int Login_user::search_car_sedan(int id_car)
{
	char found = 'n';
	ifstream fio2("SEDAN.txt",ios::in);
	while(fio2.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID() == id_car){
			found = 'y';
		}
	}
	fio2.close();
	if(found == 'y'){
		return 1;
	}
	return 0;
}
int Login_user::search_car_suv(int id_car)
{
	char found = 'n';
	ifstream fio3("SUV.txt",ios::in);
	while(fio3.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID() == id_car){
			found = 'y';
		}
	}
	fio3.close();
	if(found == 'y'){
		return 1;
	}
	return 0;
}
int Login_user::search_car_luxury(int id_car)
{
	char found = 'n';
	ifstream fio4("LUXURY.txt",ios::in);
	while(fio4.read((char*)&c,sizeof(c)))
	{
		if(c.get_ID() == id_car){
			found = 'y';
		}
	}
	fio4.close();
	if(found == 'y'){
		return 1;
	}
	return 0;
}
void Login_user::bill(int carid)  //(float rate,int carid,char* name_of_car)
{
	int see_car,rate,km;
	string namethecar,payment,phone,snum;
	string ploc,dloc,licence;
	int choice,n,bill_id;
	float pay,min_pay,penalty_rate;
	see_car = search_car_hatchback(carid);
	if(see_car==1)
	{
		rate = 50;
		ifstream fin("HATCHBACK.txt",ios::in);
		while(fin.read((char*)&c,sizeof(c)))
		{
			if(c.get_ID() == carid)
			{
				namethecar = c.get_name();
			}
		}
		fin.close();
	}
	see_car = search_car_sedan(carid);
	if(see_car==1)
	{
		rate = 75;
		ifstream fin("SEDAN.txt",ios::in);
		while(fin.read((char*)&c,sizeof(c)))
		{
			if(c.get_ID() == carid)
			{
				namethecar = c.get_name();
			}
		}
		fin.close();
	}
	see_car = search_car_suv(carid);
	if(see_car==1)
	{
		rate = 85;
		ifstream fin("SUV.txt",ios::in);
		while(fin.read((char*)&c,sizeof(c)))
		{
			if(c.get_ID() == carid)
			{
				namethecar = c.get_name();
			}
		}
		fin.close();
	}
	see_car = search_car_luxury(carid);
	if(see_car==1)
	{
		rate = 220;
		ifstream fin("LUXURY.txt",ios::in);
		while(fin.read((char*)&c,sizeof(c)))
		{
			if(c.get_ID() == carid)
			{
				namethecar = c.get_name();
			}
		}
		fin.close();
	}
	system("cls");
	cout<<"\n********** Please enter following info**********"<<endl;
	cout<<"Enter Time for which you want the car for rent\n"<<endl;
    cout<<" (1)Less than a day(less than 23 hours)\n (2)Min 1 whole day(max 15days)\n Your choice: ";
    cin>>choice;
    fstream file1("Invoice.txt",ios::in);
	file1>>bill_id;
	bill_id=bill_id+1;
	file1.seekg(0);
	file1<<bill_id;
	file1.close();
	switch(choice)
	{
		case 1:
			label5:
cout<<"enter your phone number\n";
    cin>>phone;
     if(phone.length()!=10)
    {
        cout<<"invalid phone number \n";
        goto label5;
    }
			    cout<<"please enter in licence number :";
                cin>>licence;
while(licence.length()!=15)
{
  cout<<"please re-enter licence should be 15 characters:"<<endl<<"first 2 are letters last 13 are numbers :\n";
  cout<<"please enter in licence number :\n";
  cin>>licence;
}
for(int i=0;i<=2;i++)
{
  for(int j=2;j<=13;j++)
  {
    while(!isdigit(licence[j])&&!isalpha(licence[i]))
    {
       cout<<"please re-enter licence should be 15 characters:"<<endl<<"first 2 are letters last 13 are numbers :\n";
      cout<<"please enter in licence number :\n";
      cin>>licence;
    }
  }
}
label4:
cout<<"enter your aadhaar card number\n";
    cin>>snum;
     if(snum.length()!=12)
    {
        cout<<"invalid aadhaar card number\n";
        goto label4;
    }
	
			cout<<"Enter car pick-up location\n ";
			cin>>ploc;
			cout<<"Enter car drop location\n ";
			cin>>dloc;
			cout<<"Enter estimated kilometers\n ";
			cin>>km;
			
				cout<<"Enter number of hours for which u want to get car on rent:(max 23 hours)\n ";
            	cin>>n;	
            	label2:
            	if(n>23)
            	{ 
            	cout<<"!!!!!INVALID INPUT!!!!!\n";
            		cout<<"Enter valid number of hours for which u want to get car on rent:(less than 24)\n ";
            		cin>>n;
            		goto label2;
            		
				}
            	cout<<"Enter payment mode( Online / Cash / Card)\n";
		        cin>>payment;
			pay = n * rate;
			min_pay = 0.3 * pay;
			penalty_rate = 0.1 * rate + rate;
			cout<<endl;
			system("cls");
		cout<<"************************ BILL ********************************"<<endl;
			cout<<"|"<<setw(30)<<"Invoice Number"<<"|"<<setw(30)<<bill_id<<endl;
			cout<<"|"<<setw(30)<<"Customer Name"<<"|"<<setw(30)<<username<<endl;
			cout<<"|"<<setw(30)<<"Customer Phone number"<<"|"<<setw(30)<<phone<<endl;
			cout<<"|"<<setw(30)<<"Aadhaar number"<<"|"<<setw(30)<<snum<<endl;
			cout<<"|"<<setw(30)<<"DL Number"<<"|"<<setw(30)<<licence<<endl;
			cout<<"|"<<setw(30)<<"Car Name"<<"|"<<setw(30)<<namethecar<<endl;	
			cout<<"|"<<setw(30)<<"Car ID"<<"|"<<setw(30)<<carid<<endl;
			cout<<"|"<<setw(30)<<"car pick-up loc"<<"|"<<setw(30)<<ploc<<endl;
			cout<<"|"<<setw(30)<<"car drop loc"<<"|"<<setw(30)<<dloc<<endl;	
			cout<<"|"<<setw(30)<<"Estimated Km"<<"|"<<setw(28)<<km<<"KM"<<endl;
			cout<<"|"<<setw(30)<<"Numbers of Hours"<<"|"<<setw(30)<<n<<endl;
			cout<<"|"<<setw(30)<<"Mode of Payment"<<"|"<<setw(30)<<payment<<endl;
			cout<<"|"<<setw(30)<<"Total Pay"<<"|"<<setw(30)<<pay<<endl;
			cout<<"|"<<setw(30)<<"Advance Pay "<<"|"<<setw(30)<<min_pay<<endl;
			cout<<"|"<<setw(30)<<"After use Pay"<<"|"<<setw(30)<<pay-min_pay<<endl;
			cout<<"|"<<setw(30)<<"Penalty per hour"<<"|"<<setw(30)<<penalty_rate<<endl;
			cout<<"***************************************************************"<<endl;
		do_user_work();
			break;
		case 2:
			label6:
cout<<"enter your phone number\n";
    cin>>phone;
    
     if(phone.length()!=10)
    {
        cout<<"invalid phone number\n";
        goto label6;
    }
			   cout<<"please enter in licence number :";
cin>>licence;
while(licence.length()!=15)
{
  cout<<"please re-enter licence should be 15 characters:\n"<<endl<<"first 2 are letters last 13 are numbers :\n";
  cout<<"please enter in licence number :\n";
  cin>>licence;
}
for(int i=0;i<=2;i++)
{
  for(int j=2;j<=13;j++)
  {
    while(!isdigit(licence[j])&&!isalpha(licence[i]))
    {
       cout<<"please re-enter licence should be 15 characters:\n"<<endl<<"first 2 are letters last 13 are numbers :\n";
      cout<<"please enter in licence number :\n";
      cin>>licence;
    }
  }
}
label3:
cout<<"enter your aadhaar card number\n";
    cin>>snum;
     if(snum.length()!=12)
    {
        cout<<"invalid aadhaar card number\n";
        goto label3;
    }
				cout<<"Enter car pick-up location \n";
			cin>>ploc;
			
			cout<<"Enter car drop location \n ";
			cin>>dloc;
			cout<<"Enter estimated kilometers\n ";
			cin>>km;
				cout<<"Enter number of days for which u want to get car on rent(max  15days ):\n ";
           		cin>>n;
           		label1:
           		if(n>15)
            	{ 	
				cout<<"!!!!!INVALID INPUT!!!!!\n";
            		cout<<"Enter valid number of days for which u want to get car on rent:(less than 15 days)\n ";
            		cin>>n;
            		goto label1;
				}
           		cout<<"Enter payment mode( Online / Cash / Card)\n";
		        cin>>payment;
			pay = n * rate * 23; //23 = hours driven per day
			min_pay = 0.3 * pay;
			penalty_rate = 0.1 * rate + rate;
			cout<<endl;
			system("cls");
			cout<<"************************ BILL ***********************************"<<endl;
			cout<<"|"<<setw(30)<<"Invoice Number"<<"|"<<setw(30)<<bill_id<<endl;
			cout<<"|"<<setw(30)<<"Customer Name"<<"|"<<setw(30)<<username<<endl;
			cout<<"|"<<setw(30)<<"Customer Phone number"<<"|"<<setw(30)<<phone<<endl;
			cout<<"|"<<setw(30)<<"Aadhaar number"<<"|"<<setw(30)<<snum<<endl;
			cout<<"|"<<setw(30)<<"DL Number"<<"|"<<setw(30)<<licence<<endl;
			cout<<"|"<<setw(30)<<"Car Name"<<"|"<<setw(30)<<namethecar<<endl;	
			cout<<"|"<<setw(30)<<"Car ID"<<"|"<<setw(30)<<carid<<endl;
			cout<<"|"<<setw(30)<<"car pick-up loc"<<"|"<<setw(30)<<ploc<<endl;
			cout<<"|"<<setw(30)<<"car drop loc"<<"|"<<setw(30)<<dloc<<endl;	
			cout<<"|"<<setw(30)<<"Estimated Km"<<"|"<<setw(28)<<km<<"KM"<<endl;
			cout<<"|"<<setw(30)<<"Numbers of days"<<"|"<<setw(30)<<n<<endl;
			cout<<"|"<<setw(30)<<"Mode of Payment"<<"|"<<setw(30)<<payment<<endl;
			cout<<"|"<<setw(30)<<"Total Pay"<<"|"<<setw(30)<<pay<<endl;
			cout<<"|"<<setw(30)<<"Advance Pay "<<"|"<<setw(30)<<min_pay<<endl;
			cout<<"|"<<setw(30)<<"After use Pay"<<"|"<<setw(30)<<pay-min_pay<<endl;
			cout<<"|"<<setw(30)<<"Penalty per hour"<<"|"<<setw(30)<<penalty_rate<<endl;
			cout<<"******************************************************************"<<endl;

			do_user_work();
			break;
		default:
			cout<<"Wrong option selected"<<endl;
	}
}
void Login_user :: do_user_work()
{
	int choice,UP;

	        cout<<"------------------------------------------------------------"<<endl;
			cout<<"\t\t\tMENU"<<endl;
			cout<<"------------------------------------------------------------"<<endl;
	 cout<<"\t1.Rent a car\n\t2.Submit the car\n\t3.Main menu\n\nYOUR CHOICE: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			int ch;
			int collect;	
		cout<<setw(30)<<"QUICK INFO"<<endl;
			cout<<"|"<<setw(10)<<"TYPE"<<" |"<<setw(15)<<"RATE(per hr)"<<" |"<<setw(20)<<"PENALTY RATE(per hr)"<<" |"<<endl;
			cout<<"|"<<setw(10)<<"HATCHBACK"<<" |"<<setw(15)<<50<<" |"<<setw(20)<<50*(0.1) + 50<<" |"<<endl;
			cout<<"|"<<setw(10)<<"SEDAN"<<" |"<<setw(15)<<75<<" |"<<setw(20)<<75*(0.1) + 75<<" |"<<endl;
			cout<<"|"<<setw(10)<<"SUV"<<" |"<<setw(15)<<85<<" |"<<setw(20)<<85*(0.1) + 85<<" |"<<endl;
			cout<<"|"<<setw(10)<<"LUXURY"<<" |"<<setw(15)<<220<<" |"<<setw(20)<<220*(0.1) + 220<<" |"<<endl;
			cout<<"\nCar Categories\n 1.Hatchback\n 2.Sedan\n 3.Suv\n 4.Luxury\n Your Choice: ";
			cin>>ch;	
			switch(ch)
			{
				case 1:
					collect = show_hatchback();
					if(collect == 0)
						book_hatchback();	
					break;
				case 2:
					collect = show_sedan();
					if(collect == 0)
						book_sedan();
					break;
				case 3:
					collect = show_suv();
					if(collect == 0)
						book_suv();
					break;
				case 4:
					collect = show_luxury();
					if(collect == 0)
						book_suv();
					break;
				default:
					cout<<"Seems You selected wrong option"<<endl;
			}
			break;
		case 2:
			unbook();
				cout<<"\n ENTER 0: TO GO TO MAIN MENU :\t";
				cin>>UP;
			system("cls");
			menu();
			break;
		case 3:
			menu();
			break;
	}	
}

void Login_user :: login(char user_n[], char pass[])
{
	string name;
	int round = 0;
	ifstream fin("login_data.txt",ios::in);
	while(fin>>username>>password)
	{
		if(strcmp(user_n,this->username)==0 && strcmp(pass,this->password)==0)
		{
			name = conv_to_str(user_n,str_len(user_n));
			size_t found = name.find("@");
				system("cls");
			
			cout<<"\t\t\tWelcome  Back  "<<name.substr(0,found)<<endl;
			round = 1;
			do_user_work();
		}
		else if(strcmp(user_n,this->username)==0)
		{
			cout<<"Entered Password is incorret"<<endl;
			round =1;
		}
	}
	fin.close();
	if(round == 0)
	{
		char ans;
		cout<<"You might want to consider registering(y/n): ";
			cin>>ans;
			if(ans=='y'||ans=='Y'){
				this->Register();
			}
			else{
				cout<<"Allright see ya!"<<endl;
			}
	}
}
int main()
{
	Login_user l;
	Login_admin la;
	char username[100],password[50];
	int choosing;
	string user;
	string line;
	menu();
	return 0;
}

