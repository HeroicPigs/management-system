#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
string password="123iam";
void func(string search,string replace){
      string data,newdata; // for user input
      fstream fin;
      cout<<"Find string \""<<search<<"\" and replace with \""<<replace<<"\" in file\""<<" student.txt"<<" \"\n";
      fin.open("student.txt",ios::in);
      if(!fin)
      {
           cout<<"error opening file";
           return;
      }
      while(fin)
      {
           getline(fin,data);
           cout<<data<<endl;
      }
      fin.close();
      fin.open("student.txt",ios::in);
      newdata="";
      if(!fin)
      {
           cout << "Unable to open file";
           return;
      }
      while(fin)
      {
           getline(fin,data);
           int a =(int) data.find(search,0);
           while (a != string::npos)
           {
                data.replace(a,search.size(),replace);
                a =(int) data.find(search,(a+1));
           }
           newdata=newdata+data+"\n";
      }
      int index=newdata.size()-1;
      newdata.erase(index,1);
      fin.close();
      fin.open("student.txt",ios::out | ios_base::trunc);
      if(!fin)
      {
           cout<<"error opening file";
           return;
      }
      fin<<newdata;
      cout<<"Replacement successful\n";
      fin.close();
    }
	class Student{
	public:
		string name;
		long int roll_no;
		int grade;
		string section;
		string id_no;
		string address;
		string phone_no;
		string mother_name;
		string father_name;
	};
	istream& operator>>(istream& is,Student& s){
		getline(is,s.name);
		is>>s.roll_no>>s.grade>>s.section>>s.id_no>>s.address>>s.phone_no>>s.mother_name>>s.father_name;
		is.ignore(200,'\n');
		return is;
	}
	ostream& operator<<(ostream& os,Student& s){
		os<<s.name<<"\n"<<s.roll_no<<" "<<s.grade<<" "<<s.section<<" "<<s.id_no<<" "<<s.address<<" "<<s.phone_no<<" "<<s.mother_name<<" "<<s.father_name<<"\n";
		return os;
	}
			std::vector<Student> vs;
	void read(){
		ifstream ist{"student.txt"};
		if(!ist){
			cout<<"error opening file\n";
			return;
		}
		Student s;
			while(ist>>s){
			vs.push_back(s);
	}
	}
	void show(){
		read();
		for(auto a:vs){
			cout<<a;
		}
	}

	void r_new(){
		ofstream ost{"student.txt",ios_base::app};
		cout<<"registering new student\n";
		Student s;
		cout<<"Enter name of the student: ";
		//string a_name;
		cin.ignore(200, '\n');
		getline(cin,s.name);
		//ost<<a_name<<" ";
		/*
		cout<<"\n Enter last name of the student: ";
		//string b_name;
		cin>>s.l_name;
		*/
		//ost<<b_name<<" ";
		cout<<"\n Enter roll_no of student: ";
		cin>>s.roll_no;
		cout<<"\n Enter grade of student: ";
		//int gr;
		cin>>s.grade;
		//ost<<gr<<" ";
		cout<<"\n Enter section of student: ";
		//char se;
		cin>>s.section;
		//ost<<se<<" ";
		cout<<"\n Enter id of student: ";
		//string i;
		cin>>s.id_no;
		//ost<<i<<" ";
		cout<<"\n Enter adress of student: ";
		//string addr;
		cin>>s.address;
		//ost<<addr<<" ";
		cout<<"\n Enter phone_no of student: ";
		//string p_no;
		cin>>s.phone_no;
		//ost<<p_no<<" ";
		cout<<"\n Enter the mother's name of student: ";
		//string m_n;
		cin.ignore(50,'\n');
		getline(cin,s.mother_name);
		//ost<<m_n<<" ";
		cout<<"\n Enter the father's name of student: ";
		//string f_n;
		getline(cin,s.father_name);
		ost<<s;
	}
	void c_p(){
		string pass2;
		cout<<"Enter new password:";
		getline(cin,pass2);
		string pass3;
		cout<<"Confirm password:";
		getline(cin,pass3);
		if (pass3==pass2)
		{
			cout<<"password changed\n";
		}
		else{
			while(pass2!=pass3){
				cout<<"Both password donot match\n";
				cout<<"Enter new password:";
				getline(cin,pass2);
				cout<<"Confirm password:";
				getline(cin,pass3);
			}
		}
	}
	void display(Student& x){
		cout<<"What would you like to do\n";
		cout<<"(1) change first name 	(2) change roll_no\n"   
			<<"(3)change grade			(4) change section\n"
			<<"(5)change id_no			(6) change address\n"
			<<"(7)change phone_no\n";
		int options;
		cin>>options;
		switch(options){
			case 1:
			{
			cout<<"Enter new name of the student: ";
			string a_name;
			cin.ignore(100,'\n');
			getline(cin,a_name);
			func(x.name,a_name);
			break;
		}
			case 2:
			{
			cout<<"\n Enter roll_no of the student: ";
			long int r_i;
			cin>>r_i;
			func(to_string(x.roll_no),to_string(r_i));
			break;
		}
			case 3:
			{
			cout<<"\n Enter grade of student: ";
			int gr;
			cin>>gr;
			auto grad=to_string(x.grade);
			auto gr2=to_string(gr);
			func(grad,gr2);
			break;
		}
			case 4:
			{
			cout<<"\n Enter section of student: ";
			string se;
			cin>>se;
			func(x.section,se);
			break;
		}
			case 5:
			{
			cout<<"\n Enter id of student: ";
			string i;
			cin>>i;
			func(x.id_no,i);
			break;
		}
			case 6:
			{
			cout<<"\n Enter adress of student: ";
			string addr;
			cin.ignore(200,'\n');
			getline(cin,addr);
			func(x.address,addr);
			break;
		}
			case 7:
			{
			cout<<"\n Enter phone_no of student: ";
			string p_no;
			cin>>p_no;
			func(x.phone_no,p_no);
			break;
		}
			default:
			cout<<"i donot know what that menas\n";
	}
}
void check(const string& d_no){
	for(auto& s:vs){
	if(s.id_no==d_no){
		cout<<s;
		display(s);
		return;
			}
		}
	cout<<"not found\n";
}
	void change(){
		cout<<"Enter id of student: ";
		string d_no;
		cin>>d_no;
		read();
		check(d_no);
	}
	void procede(){
		system("clear");
		cout<<"Welcome\n";
		cout<<"What would you like to do\n";
		cout<<"(1) register a new student    (2)change password\n"   
			<<"(3) nothing                   (4)check student details\n"
			<<"(5) change student details\n"
			<<"Enter the no of action you want to do\n";
		int options;
		cin>>options;
		switch(options){
			case 1:
			r_new();
			break;
			case 2:
			c_p();
			break;
			case 3:
			break;
			case 4:
			show();
			break;
			case 5:
			change();
			break;
			default:
			cout<<"i donot know what that menas\n";
		}
	}
	int main()
	try{
		cout<<"\tWelcome to the school management system\n";
		char choice;
		cout<<"are you an adminstrator[enter y or n]: ";
		cin>>choice;
		switch(choice){
			case 'y':
			{
			string pass;
			cout<<"Enter your password:";
			cin.ignore(100,'\n'); 
			getline(cin,pass);
			if(pass==password){
				procede();
			}
			else {
				if(pass!=password){
				while(pass!=password){
					cout<<"sorry try again\n";
					getline(cin,pass);
				if(pass==password){
				procede();
			}
		}
	}
}
		break;
	}
			case 'n':
			 cout<<"hello user \n";
			 break;
			default:
			cout<<"press y or n: ";
}
}
catch(exception& e){
	cerr<<e.what()<<"\n";
}