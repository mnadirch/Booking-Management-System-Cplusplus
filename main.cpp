#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
 using namespace std;

struct member{
	char id[10];		
	char lname[30];		
	char fname[30];		
	char mname[30];		
	char occupation[50];
	int status;			
	int age;		
};
struct log{
	string username;
	string password;
	
};

struct userdetal{
	int age;
	string name;
	string lname;
	string phno;
	string username;
	string password;
};


struct Subject{
	member members[40];	
	int size;			
	char name[50];		
};

bool enrol(Subject&,member);		
bool drop(Subject&,char[]) ;		
void display(Subject);					
void display(member);				
void welcome();		
void user();
void screen( );
void welcomelogo();
void userdetail();
void logo( );
void hotel();
void game();
void menu();
void Movie();
void admin();
void login(string,string);
void displayByStatusLevel(Subject,int);	
void displayByOccupation(Subject,char[]);
void displayByName(Subject,char[]);		
void displayByID(Subject,char[]);		
void sortByName(Subject&);				
void sortByID(Subject&);				
int searchByName(Subject,char[]);	
int searchByID(Subject,char[]);

int main(){
	welcome();
return 0;
	}


bool enrol(Subject &s, member st){
	if( (searchByID(s,st.id)==-1) && (s.size < 40) ){
		s.members[s.size] = st;	
		s.size++;				
		return true;
	}
	else
		return false;
}

bool drop(Subject &s, char id[]){
	int pos = searchByID(s,id);		
	if(pos!=-1){					
		for(int i=pos; i<s.size-1; i++){
			s.members[i] = s.members[i+1];	
		}
		s.size--;			
		return true;
	}
	else
		return false;		
}

void display(member st){
	cout<<"ID #: "<<st.id<<endl;									
	cout<<"Name: "<<st.lname<<", "<<st.fname<<" "<<st.mname<<endl;	
	cout<<"Occupation: "<<st.occupation<<endl;							
	cout<<"Status Level: "<<st.status<<endl;					
	cout<<"Age: "<<st.age<<endl;								
	cout<<"Press any key to continue..."<<endl;
	getch();
}

void display(Subject s){
	if(s.size==0){									
		cout<<"No member registered yet yet..."<<endl;	
	}
	else{
		for(int i=0; i<s.size; i++)		
			display(s.members[i]);		
	}
 
}

void displayByStatusLevel(Subject s, int y){
	if(s.size==0){									
		cout<<"No Member registered yet..."<<endl;
	}
	else{
		for(int i=0; i<s.size; i++){		
			if(s.members[i].status == y)	
				display(s.members[i]);		
		}
	}
}

void displayByOccupation(Subject s, char crse[]){
	if(s.size==0){								
		cout<<"No Members enrolled yet..."<<endl;	
	}
	else{
		for(int i=0; i<s.size; i++){					
			if(strcmp(s.members[i].occupation,crse)==0)	
				display(s.members[i]);					
		}
	}
}

void displayByName(Subject s, char name[]){
	if(s.size==0){									
		cout<<"No Members enrolled yet..."<<endl;	
	}
	else{
		for(int i=0; i<s.size; i++){			
			if(strcmp(s.members[i].lname,name)==0)	
				display(s.members[i]);				
		}
	}
}

void displayByID(Subject s, char id[]){
	if(s.size==0){									
		cout<<"No Members enrolled yet..."<<endl;
	}
	else{
		for(int i=0; i<s.size; i++){				
			if(strcmp(s.members[i].id,id)==0)	
				display(s.members[i]);			
		}
	}
}

int searchByID(Subject s, char id[]){
	for(int i=0; i<s.size; i++){				
			if(strcmp(s.members[i].id,id)==0)	
				return i;						
	}
	return -1;	
}

void sortByID(Subject &s){
	for(int i=0; i<s.size-1; i++){
		int min = i;			
		for(int j=i+1; j<s.size; j++){
			
			if(strcmp(s.members[j].id,s.members[min].id)<0)	
				min = j;										
		}
		member temp = s.members[i];		
		s.members[i] = s.members[min];
		s.members[min] = temp;
	}
}

void sortByName(Subject &s){
	for(int i=0; i<s.size; i++){
		int min = i;	
		for(int j=i+1; j<s.size; j++){
			if(strcmp(s.members[j].lname,s.members[min].lname)<0)	
				min = j;											
			else
			if(strcmp(s.members[j].lname,s.members[min].lname)==0){		
				if(strcmp(s.members[j].fname,s.members[min].fname)<0)	
					min = j;
				else
				if(strcmp(s.members[j].fname,s.members[min].fname)==0){		
					if(strcmp(s.members[j].mname,s.members[min].mname)<0)	
						min = j;
				}
			}
		}
		member temp = s.members[min];	
		s.members[min] = s.members[i];
		s.members[i] = temp;
	}
}
void welcome()
{
	string a;
	welcome:
	cout<<"\n\n\n\n\n\n					*****************************************"<<endl;//Wellcome block
		cout<<"					*****************************************"<<endl;
		cout<<"\n					  Welcome to Booking Management System"<<endl;
		cout<<"	\n					*****************************************"<<endl;
		cout<<"					*****************************************"<<endl;
		cout<<"						Press enter to continue: ";	//continue block
		cin>>a;
		
		if(a=="y"){
				system("cls");
				user();
			}
	
			else
				{
					system("cls");
					goto welcome;
				}
		}

void menu(){
			system("cls");

	Subject s;
	int choice;
	strcpy(s.name,"CS210");
	s.size = 0;
		do{
					system("cls");

		cout<<"Menu: "<<endl;	//displays the menu
				cout<<"Membership Fee: 18$/year(Fee will be increased by status)"<<endl;	//displays the menu

		cout<<"1. Enroll a member\n2.Existing Member.\n3.Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;			//asks the user to enter choice
 
		switch(choice){
		case 1:										//for the case when the user chooses 1
			member st;								//this is where the inputs will be stored
			cout<<"\t\t\t\tEnter ID: ";						//the following lines asks for information about a Member
			cin>>st.id;
			cout<<"\t\t\t\tEnter first name: ";
			cin.ignore();
			cin.getline(st.fname,30);
			cout<<"\t\t\t\tEnter middle name: ";
			cin.getline(st.mname,30);
			cout<<"\t\t\t\tEnter last name: ";
			cin.getline(st.lname,30);
			cout<<"\t\t\t\tEnter occupation: ";
			cin.getline(st.occupation,50);
			status:
			cout<<"\t\t\t\t1-Status 1 will cost 18$/year.\n\t\t\t\t2-Status 2 will cost 30$/2year.\n\t\t\t\t3-Status 3 will cost 60$/5year.\n\t\t\t\t4-Status 4 will cost 110$/10year.\n\t\t\t\t5-Status 5 is life time VIP membership cost 700$.\n"<<endl;
			cout<<"\t\t\t\tEnter Status level: ";
			cin>>st.status;
			switch(st.status){
				case 1:
					cout<<"\t\t\t\tMembership Charges will be 18$/year."<<endl;
					break;
				case 2:
					cout<<"\t\t\t\tMembership Charges will be 30$/2year."<<endl;
					break;
				case 3:
					cout<<"\t\t\t\tMembership Charges will be 60$/5year."<<endl;
					break;
				case 4:
					cout<<"\t\t\t\tMembership Charges will be 110$/10year."<<endl;
					break;
				case 5:
					cout<<"\t\t\t\tCongratulations!! You're our VIP member."<<endl;
					break;
				default:
				cout<<"No such status exist. Kindly enter correct status!";
				system("pause");
				goto status;				
			}
			cout<<"\t\t\t\tEnter age: ";
			cin>>st.age;
 
			if(enrol(s,st)==true)		//checks if there was successful enrol		
				cout<<"\t\t\t\tMember successfully enrolled..."<<endl;
			else
				cout<<"\t\t\t\tEither subject is full or Member is already enrolled..."<<endl;
			
			break;
		case 2:
				int ex;
				cout<<"1-Play game.\n2-Book Tickets for movie.\n3-Book Hotel Room";
				cin>>ex;
				if(ex==1)
					game();					
					break;
				if(ex==2)					
						Movie();
				if(ex==3)
						hotel();		
		case 3:
			cout<<"\t\t\t\tThank you and have a good day.\n";	//displays this line when user chooses to exit
			system("pause");
			user();
			break;
		default:
			cout<<"\t\t\t\tNo such choice exists...\n";		//in case the user types in a choice not listed in the menu.
		}
	}while(choice!=10);
}
void user(){
	choice:
	string choice;
	char name[50];
	char lname[50];
	int age;
	string mobile;
	string rusername;
	string rpassword;
	system("cls");
	cout<<"\n\n\t\t\t\t-----------------------------------"<<endl;
		cout<<"\t\t\t\t\tRegisteration / Signup"<<endl;
	cout<<"\t\t\t\t-----------------------------------"<<endl;	
	cout<<"\n\t\t\tType Login for existing users and Signup for new users: ";
	cin>>choice;
	if(choice=="Login" || choice=="login")
	{
		login(rusername,rpassword);
	}
	else if(choice=="Signup" || choice=="signup")
	{
		system("cls");
		userdetal u2;
	cout<<"\n\n\t\t\t\t-----------------------------------"<<endl;
	cout<<"\t\t\t\t\tRegisteration / Signup"<<endl;
	cout<<"\t\t\t\t-----------------------------------"<<endl;
	cout<<"\n\t\t\tEnter your name: ";
	cin>>name;
	u2.name=name;
	cout<<"\n\t\t\tEnter your last name: ";
	cin>>lname;
	u2.lname=lname;
	cout<<"\n\t\t\tEnter your P#No: ";
	cin>>mobile;
	u2.phno=mobile;
	cout<<"\n\t\t\tEnter your Age: ";
	cin>>age;
	u2.age=age;
	cout<<"\n\t\t\tEnter your username: ";
	cin>>rusername;
	u2.username=rusername;
	cout<<"\n\t\t\tEnter your password: ";
	cin>>rpassword;
	u2.password=rpassword;
	system("pause");
			login(rusername,rpassword);

		}
	else{
		system("cls");
		cout<<"Warning Enter Valid Option!"<<endl;
		system("pause");
		goto choice;
	}

}

void login(string a,string b){
	login:
	log login;
		system("cls");

		cout<<"\n\n\t\t\t\t-----------------------------------"<<endl;
		cout<<"\t\t\t\t\t\tLogin / Signin"<<endl;
	cout<<"\t\t\t\t-----------------------------------"<<endl;	
	cout<<"\n\t\t\tEnter your username: ";
	cin>>login.username;
	cout<<"\n\t\t\tEnter your password: ";
	cin>>login.password;
	if(login.username==a && login.password==b){
		cout<<"\t\t\t\tSuccesfully logined as "<<a<<" !";
		menu();	
	}
	else if(login.username=="Nadir" && login.password=="123"){		cout<<"Succesfully logined as Admin!";
	admin();	

	}
	
	else{
		cout<<"Wrong Username or Password!";
		system("pause");
		system("cls");
		goto login;
	}
	}
	
void admin(){
	system("cls");
		Subject s;
	int choice;
	strcpy(s.name,"CS210");
	s.size = 0;
		do{
		cout<<"\t\t\t\tMenu: "<<endl;	
		cout<<"\t\t\t\t1. Enroll a member\n\t\t\t\t2. Drop a Member\n\t\t\t\t3. Sort by ID\n\t\t\t\t4. Sort by Name\n\t\t\t\t5. Display by Year\n"
			<<"\t\t\t\t6. Display by Name\n\t\t\t\t7. Display by ID\n\t\t\t\t8. Display by Course\n\t\t\t\t9. Display All\n\t\t\t\t10. Existing User"<<endl;
		cout<<"\t\t\t\t11.Userd Details\n\t\t\t\t12.Exit\n\t\t\t\tEnter your choice: ";
		cin>>choice;			
 
		switch(choice){
		case 1:									
			member st;								
			cout<<"\t\t\t\tEnter ID: ";					
			cin>>st.id;
			cout<<"\t\t\t\tEnter first name: ";
			cin.ignore();
			cin.getline(st.fname,30);
			cout<<"\t\t\t\tEnter middle name: ";
			cin.getline(st.mname,30);
			cout<<"\t\t\t\tEnter last name: ";
			cin.getline(st.lname,30);
			cout<<"\t\t\t\tEnter occupation: ";
			cin.getline(st.occupation,50);
			status:
			cout<<"\t\t\t\t1-Status 1 will cost 18$/year.\n\t\t\t\t2-Status 2 will cost 30$/2year.\n\t\t\t\t3-Status 3 will cost 60$/5year.\n\t\t\t\t4-Status 4 will cost 110$/10year.\n\t\t\t\t5-Status 5 is life time VIP membership cost 700$.\n"<<endl;
			cout<<"\t\t\t\tEnter Status level: ";
			cin>>st.status;
			switch(st.status){
				case 1:
					cout<<"\t\t\t\tMembership Charges will be 18$/year."<<endl;
					break;
				case 2:
					cout<<"\t\t\t\tMembership Charges will be 30$/2year."<<endl;
					break;
				case 3:
					cout<<"\t\t\t\tMembership Charges will be 60$/5year."<<endl;
					break;
				case 4:
					cout<<"\t\t\t\tMembership Charges will be 110$/10year."<<endl;
					break;
				case 5:
					cout<<"\t\t\t\tCongratulations!! You're our VIP member."<<endl;
					break;
				default:
				cout<<"No such status exist. Kindly enter correct status!";
				system("pause");
				goto status;
		}
			cout<<"\t\t\t\tEnter age: ";
			cin>>st.age;
 
			if(enrol(s,st)==true)	
				cout<<"\t\t\t\tMember successfully enrolled..."<<endl;
			else
				cout<<"\t\t\t\tEither subject is full or Member is already enrolled..."<<endl;
			
			break;
		case 2:
			char id[10];
			cout<<"\t\t\t\tEnter ID# of Member to be dropped: ";
			cin>>id;
 
			if(drop(s,id)==true)						
				cout<<"\t\t\t\tMember successfully dropped...\n";
			else
				cout<<"\t\t\t\tMember cannot be dropped due to non-enrolment\n";
 
			break;
		case 3:
			sortByID(s);			
			cout<<"\t\t\t\tDone sorting...\n";
 
			break;
		case 4:
			sortByName(s);				
			cout<<"\t\t\t\tDone sorting...\n";
 
			break;
		case 5:
			int y;
			cout<<"\t\t\t\tEnter Status level: ";	
			cin>>y;
 
			displayByStatusLevel(s,y);	
			
			break;
		case 6:
			char name[30];
			cout<<"\t\t\t\tEnter last name: ";	
			cin>>name;
 
			displayByName(s,name);	
 
			break;
		case 7:
			char idr[10];
			cout<<"\t\t\t\tEnter ID number: ";	
			cin>>idr;
 
			displayByID(s,idr);		
 
			break;
		case 8:
			char occupation[50];
			cout<<"\t\t\t\tEnter Member: ";
			cin.ignore();
			cin.getline(occupation,50);	
 
			displayByOccupation(s,occupation);	
			
			break;
		case 9:
			display(s);					
			break;
		case 10:
					int ex;
				cout<<"1-Play game.\n2-Book Tickets for movie.\n3-Book Hotel Room";
				cin>>ex;
				if(ex==1)
					game();					
					break;
				if(ex==2)					
						Movie();
				if(ex==3)
						hotel()	;
		case 11:
				void userdetail();
		
	
		case 12:
			cout<<"\t\t\t\tThank you and have a good day.\n";
			user();
				break;
		default:
			cout<<"\t\t\t\tNo such choice exists...\n";	
		}
			system("pause");
			system("cls");
	}while(choice!=10);
}
void Movie(){
	int option;
	welcomelogo();
	int choice;
    cout<<"                 MOVIES LIST :"<<endl;
	cout<<"                 1. Bahubali "<<endl;
	cout<<"                 2. Thor: Ragnarok "<<endl;
	cout<<"                 3. Baby Driver "<<endl;
	cout<<"                 4. X-Men Epoclyps "<<endl;
	cout<<"                 5. The Mummy "<<endl;
	cout<<"                 6. Justice League "<<endl;
	cout<<"                 7. Avengers Infinity War "<<endl;
	cout<<"                 Enter your choice :  ";
	cin>>choice;
	screen();
}

void screen( ){
	logo();
	char the[10][10];
		for(int i=0; i<9;++i){
			char che = '1';
		for(int j=0;j<9;++j){
			
		the[i][j] = che;	
		che++;
		}
	}
	char ch='A';
	for(int i=0; i<9;++i){
				cout<<ch<<"      ";			
		for(int j=0;j<9;++j){
			cout<<"["<<the[i][j]<<"]  ";
			
		}
		cout<<endl;		
		ch++;
		}
		cout<< "\n             ----------------------------";
		
cout<<endl<<endl;
	cout<<"Ticket price 700 each."<<endl;
	char row;
	int no;
	int seats;
	char answer;
	cout<<"Number of seats:";
	cin>>seats;
	int pay;
	pay = seats*700;
	for(int i=0; i<seats;i++){
	cout<<"Select seat: ";
	row = getche();
	cin>>no;
			if(row == 'A' || row == 'a' ){
				int first = 0;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'B' || row == 'b' ){
				int first = 1;
				int second = no-1;
				the[first][second] = 'X';

			}
			if(row == 'C' || row == 'c' ){
				int first = 2;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'D' || row == 'd'){
				int first = 3;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'E' || row == 'e'){
				int first = 4;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'F' || row == 'f'){
				int first = 5;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'G' || row == 'g'){
				int first = 6;
				int second = no-1;
				the[first][second] = 'X';
			}
			if(row == 'H' || row == 'h'){
				int first = 7;
				int second = no-1;
				the[first][second] = 'X';
			}
	
				if(row == 'I' || row == 'i'){
				int first = 8;
				int second = no-1;
				the[first][second] = 'X';
			}
	
	}
	cout<<endl<<endl;
	system("cls");
	
	ch='A';
	for(int i=0; i<9;++i){			
				cout<<ch<<"      ";			
		for(int j=0;j<9;++j){
			cout<<"["<<the[i][j]<<"]  ";
			
		}
		cout<<endl;		
		ch++;
		}
		cout<<endl;
		cout<<"Total Amount is "<<pay;
}
void logo(){
		system("cls");
	    cout<<"                      ------------"<<endl;
	    cout<<"                     | THE Cinepex |"<<endl;
        cout<<"                      ------------"<<endl<<endl;
}

void welcomelogo(){
	cout<<endl<<endl<<endl;
	cout<<"                       ******************************************************"<<endl;
	cout<<"                       *           WELCOME     TO	Cinepex             *"<<endl;
	cout<<"                       ******************************************************"<<endl;
	cout<<endl<<endl;
	
}
	
void game(){
	string input1;
	while(input1!="N"){
	string input,B1="-",B2="-",B3="-",B4="-",B5="-",B6="-",B7="-",B8="-",B9="-",b;
	int cut=1;

	while(cut<=9){
	system("cls");
	cout<<"\n					 B1 | B2 | B3\n";
	cout<<"					----|----|----\n";
	cout<<"					 B4 | B5 | B6\n";
	cout<<"					----|----|----\n";
	cout<<"				    	 B7 | B8 | B9\n\n";
	cout<<"				-----------------------------\n";
	cout<<"				-----------------------------\n";

	cout<<"				 	  "<<B1<<" | "<<B2<<" | "<<B3<<" \n";
	cout<<"					----|---|----\n";
	cout<<"					  "<<B4<<" | "<<B5<<" | "<<B6<<" \n";
	cout<<"					----|---|----\n";
	cout<<"					  "<<B7<<" | "<<B8<<" | "<<B9<<" \n";
	cout<<"				-----------------------------\n";
	cout<<"				-----------------------------\n";


	cout<<"Select Block : B";
	input=getche();

	
	 if(input=="1")
	{
	cout<<"\nPress X and the enter : ";
	B1=getch();}
	else if(input=="2")
	{
	cout<<"\nPress X Or O and the enter : ";
	B2=getch();}
	else if(input=="3")
	{
	cout<<"\nPress X Or O and the enter : ";
	B3=getch();}
	else if(input=="4")
	{
	cout<<"\nPress X Or O and the enter : ";
	B4=getch();}
	else if(input=="5")
	{
	cout<<"\nPress X Or O and the enter : ";
	B5=getch();}
	else if(input=="6")
	{
	cout<<"\nPress X Or O and the enter : ";
	B6=getch();}
	else if(input=="7")
	{
	cout<<"\nPress X Or O and the enter : ";
	B7=getch();}
	else if(input=="8")
	{
	cout<<"\nPress X Or O and the enter : ";
	B8=getch();}
	else if(input=="9")
	{
	cout<<"\nPress X Or O and the enter : ";
	B9=getch();}
	else{
		cout<<"\nPlease enter valid block number!";
	}

				
	cout<<"\n				 	  "<<B1<<" | "<<B2<<" | "<<B3<<" \n";
	cout<<"					----|---|----\n";
	cout<<"					  "<<B4<<" | "<<B5<<" | "<<B6<<" \n";
	cout<<"					----|---|----\n";
	cout<<"					  "<<B7<<" | "<<B8<<" | "<<B9<<" \n\n";
	if(B1=="X" && B2=="X" && B3=="X" || B4=="X" && B5=="X" && B6=="X" || B7=="X" && B8=="X" && B9=="X" || B1=="X" && B5=="X" && B9=="X" || B3=="X" && B5=="X" && B7=="X" || B1=="X" && B4=="X" && B7=="X" || B2=="X" && B5=="X" && B8=="X" || B3=="X" && B6=="X" && B9=="X"  )
	{
		cout<<"Congratulations to X!!";
		goto end;

	}
	else if(B1=="0" && B2=="0" && B3=="0" || B4=="0" && B5=="0" && B6=="0" || B7=="0" && B8=="0" && B9=="0" || B1=="0" && B5=="0" && B9=="0" || B3=="0" && B5=="0" && B7=="0" || B1=="0" && B4=="0" && B7=="0" || B2=="0" && B5=="0" && B8=="0" || B3=="0" && B6=="0" && B9=="0"  )
	{
		cout<<"Congratulations to 0!!";
		goto end;
	}
	cut++;
	system("pause");}

	end:
	cout<<"Do you want to play again(Y/N)";
	cin>>input1;
	
}
}	
	
void hotel(){
	cout<"Under maintainence!";
}	
void userdetail(){
	ofstream a;
	a.open("My File.txt");
	
	userdetal u1;
		cout<<"\n\n\t\t\t\t-----------------------------------"<<endl;
		cout<<"\t\t\t\t\tUser Detail"<<endl;
		cout<<"\t\t\t\t-----------------------------------"<<endl;
		cout<<"\n\t\t\tEnter your name: "<<u1.name;
		a<<"\n\t\t\tEnter your name: "<<u1.name;
		cout<<"\n\t\t\tEnter your last name: "<<u1.lname;
		a<<"\n\t\t\tEnter your last name: "<<u1.lname;
		cout<<"\n\t\t\tEnter your P#No: "<<u1.phno;
		a<<"\n\t\t\tEnter your P#No: "<<u1.phno;
		cout<<"\n\t\t\tEnter your Age: "<<u1.age;
		a<<"\n\t\t\tEnter your Age: "<<u1.age;
		cout<<"\n\t\t\tEnter your username:"<<u1.username;
		a<<"\n\t\t\tEnter your username:"<<u1.username;
		cout<<"\n\t\t\tEnter your password: "<<u1.password;
		a<<"\n\t\t\tEnter your password: "<<u1.password;
	a.close();
}
