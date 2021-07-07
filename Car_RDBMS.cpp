#include<conio.h>
#include<stdlib.h>
#include<iomanip>
#include<stdio.h>
#include<string.h>
#include<string>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
#define key 3

template<typename T>
char* to_string(T a)
{
	stringstream ss;
	ss<<a;
	string str = ss.str();
	char* s = new char[str.length()+1]; 
	strcpy(s,str.c_str());
	return s;
}
void clrscr()
{
    getch();
	system("cls");
}
void gotoxy(int x, int y)
{
	int a,b;
	for(a=0;a<y;a++)
	cout<<"\n";
	for(b=0;b<x;b++)
	cout<<"\t";
}

class car																					//class car
{
	protected:
		char type[20],colour[20],model[20],company[20],cname[20];
    	int chassisno;
    	long double price;
    public:
    	car(){ price=10000;}
    	car(const car &cint)
		{
			strcpy(type,cint.type);
			strcpy(colour,cint.colour);
			strcpy(model,cint.model);
			strcpy(company,cint.company);
			strcpy(cname,cint.cname);
			chassisno=cint.chassisno;
			price=cint.price;
		}
    	void getdata()
  		{
  			cout<<"enter type(sedan/SUV/sports/luxury/mini/other):";cin>>type;
  			cout<<"enter colour   :";cin>>colour;
  			cout<<"enter model    :";cin>>model;
  			cout<<"enter company  :";cin>>company;
  			cout<<"enter car name :";cin>>cname;
  			cout<<"enter chassisno:";cin>>chassisno;
  			cout<<"enter price    :";cin>>price;
 		}
 		void showdata()
 		{
  			cout<<"type     :"<<type<<endl;
  			cout<<"colour   :"<<colour<<endl;
  			cout<<"model    :"<<model<<endl;
  			cout<<"company  :"<<company<<endl;
  			cout<<"car name :"<<cname<<endl;
  			cout<<"chassisno:"<<chassisno<<endl;
  			cout<<"price    :"<<price<<endl<<endl;
 		}
 		void inprice(){ cout<<"enter new price:";cin>>price;}
 		void inmodel(){ cout<<"enter new model:";cin>>model;}
 		void incolour(){ cout<<"enter new colour:";cin>>colour;}
 		int rchassis(){ return chassisno;}
 		char* rtype(){ return type;}
 		char* rmodel(){ return model;}
 		long double rprice(){ return price;}
};

class newcust																				//class new customer
{
	protected:
		char name[30],mail[30];
 		long long int phoneno;
 		int cid;
 		long double tot_exp;
 	public:
 		newcust(){ tot_exp=0;}
 		newcust (const newcust &cus)
		{
			strcpy(name,cus.name);
			strcpy(mail,cus.mail);
			cid=cus.cid;
			tot_exp=cus.tot_exp;
		}
 		void assign_id(int id){ cid=id+1;}	
 		int retid(){ return cid;}
 		char* retname(){ return name;}
 		void input()
 		{
  			cout<<"enter name:";cin>>name;
  			cout<<"enter phoneno:";cin>>phoneno;
  			cout<<"enter email-id:";cin>>mail;
  			cout<<"your customer id:"<<cid<<endl<<endl<<endl;
  			cout<<"***plz keep record of customer id for future***\n";
  			cout<<"press any key to continue";
  			getch();
  			clrscr();
 		}
 		void display()
 		{
  			cout<<"name:"<<name<<endl;
  			cout<<"phoneno:"<<phoneno<<endl;
  			cout<<"email-id:"<<mail<<endl;
  			cout<<"customer id:"<<cid<<endl;
  		}
};

class oldcust:public newcust															//class old customer(base-new)
{
	protected:
		float discount;//in %
		char mtype[30];//membership type(red,blue,yellow...)
	public:
		oldcust(){ strcpy(mtype,"red");}
		float rdiscount(){ return discount;}
		long double rtot_exp(){return tot_exp;}
		void calc_exp(long double toPay){tot_exp+=toPay;}
		void assign_disc(long double tot_exp)
		{
			if(tot_exp>=5000000)
			discount=10;
			else if(tot_exp<5000000 && tot_exp>=3000000)
			discount=5;
			else 
			discount=2.5;	
		}
		void assign_mtype(long double tot_exp)
		{
			if(tot_exp>=5000000)
			strcpy(mtype,"red");
			else if(tot_exp<5000000 && tot_exp>=3000000)
			strcpy(mtype,"blue");
			else 
			strcpy(mtype,"yellow");
		}
		void disp_mtype(){cout<<"membership:"<<mtype<<endl;}
};

class new_employee																			//class new employee
{
	protected:
		long double salary;
		char name[30],mail[30];
		long long int phoneno;
		int eid;
	public:
		new_employee(){salary=40000;eid=100;}
		new_employee(const new_employee &em)
		{
			salary=em.salary;
			strcpy(name,em.name);
			strcpy(mail,em.mail);
			phoneno=em.phoneno;
			eid=em.eid;
		}
		void input()
 		{
  			cout<<"enter name:";cin>>name;
  			cout<<"enter phoneno:";cin>>phoneno;
  			cout<<"enter email-id:";cin>>mail;
  			cout<<"your employee id:"<<eid<<endl<<endl<<endl;
  			cout<<"***plz keep record of employee id for future***\n";
  			cout<<"press any key to continue";
  			getch();
  			clrscr();
 		}
 		void display()
 		{
  			cout<<"name:"<<name<<endl;
  			cout<<"phoneno:"<<phoneno<<endl;
  			cout<<"email-id:"<<mail<<endl;
  			cout<<"employee id:"<<eid<<endl;
  			cout<<"salary:"<<salary<<endl;
 		}
 		int reid(){return eid;}
 		void assign_id(int id){ eid=id+1;}
 		long double insalary(){ cout<<"enter new salary:";cin>>salary;}
 		char* rname(){ return name;}
 		char* rmail(){ return mail;}
 		long long int rphoneno(){return phoneno;}
};

class old_employee:public new_employee														//class old employee(base-new)
{
	protected:
		int erating;	//no.of customers handled
		long double tot_sales;
	public:
		old_employee(){ erating=1;}
		void assign_erating(long double tot_sales)
		{
			if(tot_sales>=500000)
			erating=3;
			else if(tot_sales<500000 && tot_sales>=300000)
			erating=2;
			else 
			erating=1;
		}
		long double rtot_sales(){return tot_sales;}
		int rerating(){return erating;}
};

class manager																			//class manager
{
	protected:
		char name[30],mail[30];
		long long int phoneno;
	public:
		/*static char mpassword[6];
		manager(){ strcpy(mpassword,"betaan");}*/
		void input()
 		{
  			cout<<"enter name:";cin>>name;
  			cout<<"enter phoneno:";cin>>phoneno;
  			cout<<"enter email-id:";cin>>mail;
  			cout<<endl<<endl<<endl<<"press any key to continue";
  			getch();
  			clrscr();
 		}
 		void display()
 		{
  			cout<<"name:"<<name<<endl;
  			cout<<"phoneno:"<<phoneno<<endl;
  			cout<<"email-id:"<<mail<<endl;
 		}
		/*static void mpassword_change()//to edit
		{
			char mnpass[30],m;
			int chk=0;
			cout<<"enter old manager password:";						//check password algorithm
	   		for(int i=0; i<6 && !chk; i++)
	   		{
	    		m=getch();
	    		cout<<'*';
	    		if(m!=mpassword[i])
	    		{
	     			cout<<endl<<endl;
	     			clrscr();
	     			cout<<"\n wrong password\n\n\n";
	     			cout<<"plz make correct choice\n";
	     			chk++;
	    		}
	   		}
	   		if(!chk)
			{ 
				cout<<endl; 
				clrscr(); 
				cout<<"enter new manager password:";
				cin>>mnpass;
				strcpy(mpassword,mnpass);
			}
		}*/
};

void mainmenu(); //257
																
void customer(); //590
void newcustomer(); //618
void oldcustomer(); //663
void view_customer();//752
void viewcata(); //711
void buy(); //793*****customer yet
void bymodel(); //824*****customer yet
void bytype(); //866*****customer yet
void byprice(); //908*****customer yet

void admin(); //1015
void emp(); //936
void push(char*,char,int);//920
void captcha(char[]);//921 
void newemp(); //1062
void oldemp(); //1110
void manag(); //1037
void viewemp();//974
void promo(); //987


void password_modify(); //1105 yet
void adddata(); //328
void deletedata(); //347
void editdata(); //409
void edmodel(); //491
void edcolour(); //441
void edprice(); //540

void scno(int); //900
long double push(long double[],long double,int*,int*,long double);//1231
void emipay(long double);//1245 parameters input....take as parameter from bill
void cheque(long double);
void choose_emp();//yet*****customer yet
void mop(long double);//yet
void payment_complete(long double);//yet

void enc_rot(char[],int,int); //rotate string enc
void enc_add(char[],int,int); //shift the elements by k (+k to ascii value) enc
char* encrypt(char[],char[],int,int,int,int);

void dec_rot(char[],int,int); //rotate string dec
void dec_sub(char[],int,int); //shift the elements by k (-k to ascii value) dec
char* decrypt(char[],char[],int,int,int,int); //1565 decryption

void Merge(int*,int*,int,int*,int);
void MergeSort(int*,int);
int binarySearch(int[],int,int);
//main 239
//carlist.dat
//custin.dat
//empin.dat
//encempin.dat
//class car 37
//class new cust 74
//class oldcust 106
//class new_employee 133
//class old_employee 171

int main()
{
	cout<<"\n";
	clrscr();
 	gotoxy(5,10); cout<<"CAR DEALERSHIP WELCOMES YOU";
 	gotoxy(5,1); cout<<"...we provide good service...\n";
 	getch();
 	clrscr();
 	cout<<"what do you identify yourself as?"<<endl;
 	mainmenu();
 	getch();
	return 0;
}

void mainmenu()																		//main menu
{
	int cch;
	do
 	{
  		cout<<"1.admin\n"<<"2.customer\n"<<"3.exit\n";
  		cout<<"your choice(1/2/3):";
  		cin>>cch;
  		switch(cch)
  		{
   			case 1:	clrscr();
	   				admin();
	   				break;

   			case 2: clrscr();
	   				customer();
	   				break;

   			case 3: clrscr();
	   				cout<<"quitting...\n";
	   				exit(0);
  		}
 	}while(cch!=3);
}

void adddata()																//add car
{
	clrscr();
 	fstream fil;
 	fil.open("carlist.dat", ios::binary|ios::app);
 	car c;
 	char reply;
 	do
 	{
  		clrscr();
  		c.getdata();
  		fil.write((char*)&c,sizeof(c));
  		clrscr();
  		cout<<"do you want to add more cars(y/n)?\n";
  		cin>>reply;
 	}while(reply=='y');
 	fil.close();
}

void deletedata()															//del car
{
	clrscr();
 	char z;
 	fstream fil1,fil2;
 	fil1.open("carlist.dat",ios::binary|ios::in);
 	fil2.open("temp.dat",ios::binary|ios::out);
 	car c;
 	int del=0,sno;
 	cout<<"enter chassisno of car to delete:";
 	cin>>sno;
 	cout<<endl<<endl<<"are you sure(y/n)?";
 	cin>>z;
 	if (z=='y')
 	{
  		while(fil1.read((char*)&c,sizeof(c)))
  		{
   			char z;
   			if(c.rchassis()!=sno)
   			fil2.write((char*)&c,sizeof(c));
   			else
   			{
    			del++;
    			clrscr();
    			cout<<"following car deleted from record:\n";
    			c.showdata();
    			cout<<endl<<endl<<"press any key to continue";
    			getch();
    			clrscr();
   			}
  		}
 	}
 	else{ clrscr(); deletedata();}
 	if(!del)
 	{
  		int ch3;
  		remove("temp.dat");
  		do
  		{
   			clrscr();
   			cout<<"searched car not found\n\n";
   			cout<<"what do you wanna do?\n";
   			cout<<"1.retry entering chassisno?\n";
   			cout<<"2.go back\n";
   			cout<<"enter your choice(1/2):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				deletedata();
		    			break;

	    		case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil1.close();
 	fil2.close();
 	remove("carlist.dat");
 	rename("temp.dat","carlist.dat");
}

void editdata()																	//edit car data
{
	clrscr();
 	int ch2;
 	do
 	{
  		cout<<"what do you wanna do?\n";
  		cout<<"1.edit colour\n";
  		cout<<"2.edit model\n";
  		cout<<"3.edit price\n";
  		cout<<"4.exit to admin menu\n";
  		cout<<"your choice(1/2/3/4):";
  		cin>>ch2;
  		switch(ch2)
  		{
   			case 1: clrscr();
	   				edcolour();
	   				break;

   			case 2: clrscr();
	   				edmodel();
	   				break;

   			case 3: clrscr();
	   				edprice();
	   				break;

   			case 4: clrscr();
  		}
 	}while(ch2!=4);
}

void edcolour()														//edit color
{
	fstream fil;
 	fil.open("carlist.dat",ios::binary|ios::in|ios::out);
 	car c;
 	int sno,found=0;
 	cout<<"enter chassisno of car to edit:";cin>>sno;
 	while(!found && fil.read((char*)&c,sizeof(c)))
 	{
  		if(c.rchassis()==sno)
  		{
   			char z;
   			c.incolour();
   			fil.seekg((int)fil.tellg()-(int)sizeof(c));
   			fil.write((char*)&c,sizeof(c));
   			found++;
   			cout<<"\n\n"<<"plz verify change as shown:\n";
   			c.showdata();
   			cout<<"\n\n"<<"are you sure(y/n)?";
   			cin>>z;
   			if(z=='y')
   			clrscr();
   			else{ clrscr(); edcolour();}
  		}
 	}
 	if(!found)
 	{
  		int ch3;
  		clrscr();
  		cout<<"car searched doesn't exist\n";
  		do
  		{
   			cout<<"\n what do you wanna do?\n";
   			cout<<"1.retry\n";
   			cout<<"2.go back to edit options\n";
   			cout<<"enter your choice(y/n):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				edcolour();
	    				break;

    			case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil.close();
}

void edmodel()															//edit model
{
	fstream fil;
 	fil.open("carlist.dat",ios::binary|ios::in|ios::out);
 	car c;
 	int sno,found=0;
 	cout<<"enter chassisno of car to edit:";cin>>sno;
 	while(!found && fil.read((char*)&c,sizeof(c)))
 	{
  		if(c.rchassis()==sno)
  		{
   			char z;
   			c.inmodel();
   			fil.seekg((int)fil.tellg()-(int)sizeof(c));
   			fil.write((char*)&c,sizeof(c));
   			found++;
   			cout<<"\n\n"<<"plz verify change as shown:\n";
   			c.showdata();
   			cout<<"\n\n"<<"are you sure(y/n)?";cin>>z;
   			if(z=='y')
   			clrscr();
   			else{ clrscr(); edmodel();}
  		}
 	}
 	if(!found)
 	{
  		int ch3;
  		clrscr();
  		cout<<"car searched doesn't exist\n";
  		do
  		{
   			cout<<"\n what do you wanna do?\n";
   			cout<<"1.retry\n";
   			cout<<"2.go back to edit options\n";
   			cout<<"enter your choice(y/n):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				edmodel();
	    				break;

    			case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil.close();
}

void edprice()														//edit price
{
 	fstream fil;
 	fil.open("carlist.dat",ios::binary|ios::in|ios::out);
 	car c;
 	int sno,found=0;
 	cout<<"enter chassisno of car to edit:";cin>>sno;
 	while(!found && fil.read((char*)&c,sizeof(c)))
 	{
  		if(c.rchassis()==sno)
  		{
   			char z;
   			c.inprice();
   			fil.seekg((int)fil.tellg()-(int)sizeof(c));
   			fil.write((char*)&c,sizeof(c));
   			found++;
   			cout<<"\n\n"<<"plz verify change as shown:\n";
   			c.showdata();
   			cout<<"\n\n"<<"are you sure(y/n)?";
   			cin>>z;
   			if(z=='y')
   			clrscr();
   			else{ clrscr(); edprice();}
  		}
 	}
 	if(!found)
 	{
  		int ch3;
  		clrscr();
  		cout<<"car searched doesn't exist\n";
  		do
  		{
   			cout<<"\n what do you wanna do?\n";
   			cout<<"1.retry\n";
   			cout<<"2.go back to edit options\n";
   			cout<<"enter your choice(y/n):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				edprice();
	    				break;

    			case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil.close();
}

void customer()															//customer menu
{
 	int op;
 	do
 	{
  		cout<<"1.new customer\n";
  		cout<<"2.old customer\n";
  		cout<<"3.exit\n";
  		cout<<"your choice(1/2/3):";
  		cin>>op;
  		switch(op)
  		{
   			case 1: clrscr();
	   				newcustomer();
	   				break;

   			case 2: clrscr();
	   				oldcustomer();
	   				break;

   			default: clrscr();
	    			 cout<<"quitting from customer...\n";
	    			 clrscr();
	    	         mainmenu();
  		}
 	}while(op!=3);
}

void newcustomer()													//new customer menu
{
 	clrscr();
 	cout<<"enter your details:\n";
 	newcust x;
 	int id_gen;
 	fstream fin;
 	fin.open("custin.dat",ios::app|ios::binary);
 	
 	srand(time(NULL));//id
	id_gen=rand()%1000;
	x.assign_id(id_gen);//id 
	 
	
 	x.input();
 	fin.write((char*)&x,sizeof(x));
 	cout<<"you're logged in as new customer...\n";
 	cout<<"enjoy the services\n\n";
 	cout<<"1.view catalogue\n";
 	cout<<"2.search using filters\n";
 	cout<<"3.exit\n";
 	int opt;
 	cout<<"enter choice:";
 	cin>>opt;
 	switch(opt)
 	{
  		case 1: clrscr();
	  			viewcata();
	  			break;

  		case 2: clrscr();
	  			buy();
	  			break;

  		default: clrscr();
	   			 cout<<"quitting...";
	   			 getch();
	   			 customer();
	    		 clrscr();
 	}
 	fin.close();
}

void oldcustomer()											//old customer menu
{ 
	fstream f;
 	oldcust c;
 	int found=0,sid;
 	cout<<"enter customer id:";
 	cin>>sid;
 	f.open("custin.dat",ios::binary|ios::in);
 	while(!found && f.read((char*)&c,sizeof(c)))
 	if(c.newcust::retid()==sid)
 	{
  		clrscr();
  		cout<<"welcome\t"<<c.newcust::retname()<<endl;
  		found++;
 	}
 	if(!found)
 	{
  		cout<<"you're not old customer\n";
  		cout<<"plz register as new customer\n";
  		customer();
 	}
 	else
 	{
  		cout<<"1.view catalogue\n";
  		cout<<"2.search using filters\n";
  		cout<<"3.exit\n";
  		cout<<"enter choice:";
  		int opt;
  		cin>>opt;
  		switch(opt)
  		{
   			case 1: clrscr();
	   				viewcata();
	   				break;

   			case 2: clrscr();
	   				buy();
	   				break;

   			default: clrscr();
	    			 cout<<"quitting...\n";
	    			 getch();
	    			 customer();
	    	         clrscr();
  		}
 	}
}

void view_customer()
{
	fstream fil;
 	oldcust e;
 	int opt,chk1;
 	fil.open("custin.dat",ios::binary|ios::in);
 	clrscr();
 	cout<<"following are the customers:\n";
 	while(fil.read((char*)&e,sizeof(e)))
 	e.display();
 	fil.close();
}

void viewcata()																//view cata(all cars)
{
 	fstream fil;
 	car c;
 	int opt,chk1;
 	fil.open("carlist.dat",ios::binary|ios::in);
 	clrscr();
 	cout<<"following are the cars for sale:\n";
 	while(fil.read((char*)&c,sizeof(c)))
 	c.showdata();
 	fil.close();
}

void buy()															//buy menu
{
 	int bch;
 	do
 	{
  		cout<<"you can use following filters to find a car\n";
  		cout<<"1.by model\n"<<"2.by type\n"<<"3.by price\n";
  		cout<<"4.exit\n"<<"your choice?(1/2/3/4):";
  		cin>>bch;
  		switch(bch)
  		{
   			case 1: clrscr();
	   				bymodel();
	   				break;

   			case 2: clrscr();
	   				bytype();
	   				break;

   			case 3: clrscr();
	   				byprice();
	   				break;

   			case 4: clrscr();
	   				cout<<"quitting from buying option...\n";
	  			 	clrscr();
	  			 	customer();
  		}
 	}while(bch!=4);
}

void bymodel()											//model filter
{
 	fstream fil;
 	fil.open("carlist.dat",ios::binary|ios::in);
 	car c;
 	int found=0;
 	char smod[10],ch6;
 	cout<<"enter model you wanna buy:";
 	cin>>smod;
 	while(fil.read((char*)&c,sizeof(c)) && !found)
 	if(strcmpi(c.rmodel(),smod)==0)
 	{
  		clrscr();
  		cout<<"we have the car you wanna buy..\n";
  		cout<<"check the details below:\n";
  		c.showdata();
  		cout<<"\n do you wanna buy this car(y/n)?:";
  		cin>>ch6;
  		if(ch6=='y')
  		{
   			clrscr();
   			cout<<"\n generating cash memo...\n";
   			getch();
   			int scar;
   			scar=c.rchassis();
   			clrscr();
   			scno(scar);
   			found++;
  		}
  		else{clrscr(); buy();}
 	}
 	if(!found)
 	{
  		clrscr();
  		cout<<"model  searched not found\n";
  		cout<<"we regret the inconvenience caused\n\n";
  		cout<<"press enter to go back to main search options";
  		getch();
  		clrscr();
  		buy();
 	}
}

void bytype()													//type filter
{
 	fstream fil;
 	fil.open("carlist.dat",ios::binary|ios::in);
 	car c;
 	int found=0;
 	char smod[10],ch6;
 	cout<<"enter type you wanna buy:";
 	cin>>smod;
 	while(fil.read((char*)&c,sizeof(c)) && !found)
 	if(strcmpi(c.rtype(),smod)==0)
 	{
  		clrscr();
  		cout<<"we have the car you wanna buy..\n";
  		cout<<"check the details below:\n";
  		c.showdata();
  		cout<<"\n do you wanna buy this car(y/n)?:";
  		cin>>ch6;
  		if(ch6=='y')
  		{
   			clrscr();
   			cout<<"\n generating cash memo...\n";
   			getch();
   			int scar;
   			scar=c.rchassis();
   			clrscr();
   			scno(scar);
   			found++;
  		}
  		else{clrscr(); buy();}
 	}
 	if(!found)
 	{
  		clrscr();
  		cout<<"type searched not found\n";
  		cout<<"we regret the inconvenience caused\n\n";
  		cout<<"press enter to go back to main search options";
  		getch();
  		clrscr();
  		buy();
 	}
}

void byprice()														//price filter
{
 	fstream f;
 	f.open("carlist.dat",ios::binary|ios::in);
 	car c;
 	char ch6;
 	double slprice,suprice;
 	cout<<"We need your budget to find the best car for you\n";
 	cout<<"Enter min amt:";cin>>slprice;
 	cout<<"Enter max amt:";cin>>suprice;
 	while(f.read((char*)&c,sizeof(c)))
 	{
  		if(c.rprice()<=suprice && c.rprice()>=slprice)
  		{
   			clrscr();
   			cout<<"this is what we found:\n";
   			c.showdata();
   			cout<<"\n Do you wanna buy this car?(y/n)";
   			cin>>ch6;
   			if(ch6=='y')
   			{
   	 			clrscr();
    			cout<<"generating cash memo...";
    			getch();
    			clrscr();
    			int scar;
    			scar=c.rchassis();
    			scno(scar);
   			}
   			else{clrscr(); buy();}
  		}
  		else
  		{
   			clrscr();
   			cout<<"No car in the price range\n";
   			cout<<"We regret the inconvenience\n";
   			cout<<"\n Press enter to go back to main search options:\n";
   			getch();
   			clrscr();
   			buy();
  		}
 	}
 	f.close();
}

void scno(int scar)												//cash memo generation by chassis no.
{
 	fstream f;//scar is chassisno of car chosen by cust
 	car c,ccar;
 	long double toPay;
 	int found=0;
 	f.open("carlist.dat",ios::binary|ios::in);
 	while(!found && f.read((char*)&c,sizeof(c)))
 	{
  		if(c.rchassis()==scar)
  		{
  			ccar=c;
  			toPay=ccar.rprice();
  			
   			cout<<"-------------------------CASH MEMO--------------------\n";
   			cout<<"\n\n Below are the details of your purchase\n\n";
   			c.showdata();
   			mop(toPay);
   			payment_complete(toPay);
   			found++;
  		}
 	}
 	getch();
 	clrscr();
 	customer();
}

void admin()																		//admin menu......editted
{
	int adch;
	do
 	{
  		cout<<"1.Manager\n"<<"2.Employee\n"<<"3.Exit\n";
  		cout<<"your choice(1/2/3):";
  		cin>>adch;
  		switch(adch)
  		{
   			case 1:	clrscr();
	   				manag();
	   				break;

   			case 2: clrscr();
	   				emp();
	   				break;

   			case 3: clrscr();
	   				cout<<"quitting...\n";
	   				mainmenu();
  		}
 	}while(adch!=3);
}

void push(char *cap,char x,int *top){cap[(*top)++]=x;}
void captcha(char capc[])
{
	srand(time(NULL));	//generates different set of random captcha
	int n=6,top=0,ind;
	char capt[6],chrs[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";//numeric captcha
	while(n>0)
	{
		
		ind=rand()%52;
		push(capt,chrs[ind],&top);
		n--;
	}
	strcpy(capc,capt);
}

void emp()																		//employee menu.....editted
{
	char capc[6],usr_capc[6];
	int ech;
	captcha(capc);
	cout<<capc<<"\nEnter the above capcha:\n";
	cin>>usr_capc;
	if(strcmp(capc,usr_capc)!=0)
	{
		cout<<"Captcha Not Matched......\n";
		clrscr();
		admin();	
	}
	else
	{
		do
 		{
  			cout<<"1.new employee\n"<<"2.old employee\n"<<"3.exit\n";
  			cout<<"your choice(1/2/3):";
  			cin>>ech;
  			switch(ech)
  			{
   				case 1:	clrscr();
	   					newemp();
	   					break;

   				case 2: clrscr();
	   					oldemp();
	   					break;

   				case 3: clrscr();
	  	 				cout<<"quitting from employee...\n";
	  	 				admin();
  			}
 		}while(ech!=3);
 	}
}

void viewemp()																//view cata(all cars)
{
 	fstream fil;
 	old_employee e;
 	int opt,chk1;
 	fil.open("empin.dat",ios::binary|ios::in);
 	clrscr();
 	cout<<"following are the employees:\n";
 	while(fil.read((char*)&e,sizeof(e)))
 	e.new_employee::display();
 	fil.close();
}

void promo()									//yet to complete
{
 	fstream fil;
 	fil.open("empin.dat",ios::binary|ios::in|ios::out);
 	old_employee e;
 	int sid,found=0;
 	cout<<"enter id of employee to edit:";cin>>sid;
 	while(!found && fil.read((char*)&e,sizeof(e)))
 	{
  		if(e.reid()==sid)
  		{
   			char z;
   			e.insalary();
   			fil.seekg((int)fil.tellg()-(int)sizeof(e));
   			fil.write((char*)&e,sizeof(e));
   			found++;
   			cout<<"\n\n"<<"plz verify change as shown:\n";
   			e.new_employee::display();
   			cout<<"\n\n"<<"are you sure(y/n)?";
   			cin>>z;
   			if(z=='y')
   			clrscr();
   			else{ clrscr(); promo();}
  		}
 	}
 	if(!found)
 	{
  		int ch3;
  		clrscr();
  		cout<<"employee searched doesn't exist\n";
  		do
  		{
   			cout<<"\n what do you wanna do?\n";
   			cout<<"1.retry\n";
   			cout<<"2.go back\n";
   			cout<<"enter your choice(y/n):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				promo();
	    				break;

    			case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil.close();
}

void manag()
{
	int mch;
	char capc[6],usr_capc[6];
	int ech;
	captcha(capc);
	cout<<capc<<"\nEnter the above capcha:\n";
	cin>>usr_capc;
	if(strcmp(capc,usr_capc)!=0)
	{
		cout<<"Captcha Not Matched......\n";
		clrscr();
		admin();	
	}
	else
	{
		do
 		{
  			cout<<"1.view employee data\n"<<"2.give promotion\n"<<"3.view customers\n"<<"4.exit";
  			cout<<"your choice(1/2/3):";
  			cin>>mch;
  			switch(mch)
  			{
   				case 1:	clrscr();
	   					viewemp();
	   					break;

   				case 2: clrscr();
	   					promo();
	   					break;
	   					
	   			case 3: clrscr();
	   					view_customer();
	   					break;

   				case 4: clrscr();
	   					cout<<"quitting...\n";
	   					admin();
  			}
 		}while(mch!=3);
	}
}

void newemp()													//new customer menu
{
 	clrscr();
 	cout<<"enter your details:\n";
 	new_employee x;
 	int ech,id;
 	fstream fin;
 	fin.open("empin.dat",ios::app|ios::binary);
 	
 	srand(time(NULL));//id
	id=rand()%1000;
	x.assign_id(id);//id 
 	
 	x.input();
 	fin.write((char*)&x,sizeof(x));
 	cout<<"you're logged in as new employee...\n";
 	cout<<"enjoy the services\n\n";
 	do
 	{
 		clrscr();
  		cout<<"what do you want?\n";
  		cout<<"1.add new car in database\n";
  		cout<<"2.delete car from databse\n";
  		cout<<"3.edit car details in databse\n";
  		cout<<"4.exit to mainmenu\n";
  		cout<<"enter choice(1/2/3/4):";
  		cin>>ech;
  		switch(ech)
  		{
   			case 1: clrscr();
	   				adddata();
	   				break;
	
   			case 2: deletedata();
					break;
	
   			case 3: clrscr();
					editdata();
					break;
	
   			default: clrscr();
	   				 cout<<"quitting from new employee...\n";
	   				 clrscr();
  		}
  	}while(ech!=4);
 	fin.close();
}

void oldemp()											//old customer menu
{
 	fstream f;
 	int ech;
 	old_employee e;
 	int found=0,sid;
 	cout<<"enter employee id:";
 	cin>>sid;
 	f.open("empin.dat",ios::binary|ios::in);
 	while(!found && f.read((char*)&e,sizeof(e)))
 	if(e.reid()==sid)
 	{
  		clrscr();
  		cout<<"welcome\t"<<e.new_employee::rname()<<endl;
  		found++;
 	}
 	if(!found)
 	{
  		cout<<"you're not old employee\n";
  		cout<<"plz register as new employee\n";
  		emp();
 	}
 	else
 	{
  		do
 		{
			clrscr();
  			cout<<"what do you want?\n";
  			cout<<"1.add new car in database\n";
  			cout<<"2.delete car from databse\n";
  			cout<<"3.edit car details in databse\n";
  			cout<<"4.exit to mainmenu\n";
  			cout<<"enter choice(1/2/3/4):";
  			cin>>ech;
  			switch(ech)
  			{
   				case 1: clrscr();
	   					adddata();
	   					break;
	
   				case 2: deletedata();
	   					break;
	
   				case 3: clrscr();
	   					editdata();
	   					break;
	
   				default: clrscr();
	    				 cout<<"quitting from old employee...\n";
	    				 clrscr();
  			}
  		}while(ech!=4);
	}
}


//MERGE SORT START
void Merge(int *A,int *L,int leftCount,int *R,int rightCount)	//part of merge_sort_algo: just to merge
{
	int i=0,j=0,k=0;
	// i - to mark the index of left aubarray (L)
	// j - to mark the index of right sub-raay (R)
	// k - to mark the index of merged subarray (A)
	while(i<leftCount && j<rightCount) 
	{
		if(L[i]<R[j])
		A[k++]=L[i++];
		else 
		A[k++]=R[j++];
	}
	while(i<leftCount) 
	A[k++]=L[i++];
	while(j<rightCount) 
	A[k++]=R[j++];
}

// Recursive function to sort an array of integers.
void MergeSort(int *A,int n)								//merge sort
{
	int mid,i,*L,*R;
	if(n<2) return; 			// base condition. If the array has less than two element, do nothing.
	mid=n/2;  					// find the mid index.
	/* create left and right subarrays
	   mid elements (from index 0 till mid-1) should be part of left sub-array
	   and (n-mid) elements (from mid to n-1) will be part of right sub-array*/
	L=(int*)malloc(mid*sizeof(int));
	R=(int*)malloc((n-mid)*sizeof(int));
	for(i=0;i<mid;i++) 
	L[i]=A[i]; 					// creating left subarray
	for(i=mid;i<n;i++) 
	R[i-mid]=A[i]; 				// creating right subarray
	MergeSort(L,mid); 		    // sorting the left subarray
	MergeSort(R,n-mid);  		// sorting the right subarray
	Merge(A,L,mid,R,n-mid);  	// Merging L and R into A as sorted list.
    free(L);
    free(R);
}
//MERGE SORT END

//BINARY SEARCH START
int binarySearch(int arr[],int n,int snum)					//binary search
{
    MergeSort(arr,n);
	int start=0,end1=n-1,mid;
    mid=(start+end1)/2;
    while(start<=end1)
    {
        mid=(start+end1)/2;
        if(arr[mid]==snum)
        return 1;
        else if(arr[mid]>snum)
        end1=mid-1;
        else
        start=mid+1;
    }
    return 0;
}
//BINARY SEARCH END

long double push(long double emi[],long double amtdep,int* front,int* rear,long double toPay)
{
	if((*front)==-1&&(*rear)==-1)
	{
		*front=0; 
		*rear=0;
	}
	else 
	(*rear)++;
	emi[*rear]=amtdep;
	toPay-=amtdep;
	return toPay;
}

void emipay(long double toPay)//parameters input....take as parameter from bill...3installments
{
	long double instalmnt[3],amtdep;
	int front=-1,rear=-1,k=0,ch;
	for(int i=0;i<3;i++)
	{
		cout<<"Enter the amount for present installment:\n";
		cin>>amtdep;
		toPay=push(instalmnt,amtdep,&front,&rear,toPay);
		cout<<"Amount remaining:"<<toPay<<endl;
		if(toPay==0)
		{
			cout<<"Transaction successful...\tPayment complete...\n";
			k++;
			break;
		}
		if(toPay<0)
		{
			cout<<"Transaction successfull...\t Payment complete...\tRefunding:"<<-1*toPay<<endl;
			k++;
			break;
		}
	}
	while(k==0)
	{
		cout<<"Total amount not paid\n";
		if(toPay>0)
		cout<<"Amount remaining:"<<toPay;
		cout<<"\nEnter the amount for present installment:\n";
		cin>>amtdep;
		toPay-=amtdep;
		if(toPay==0)
		{
			cout<<"Transaction successful...\tPayment complete...\n";
			k++;	
		}
		else if(toPay<0)
		{
			cout<<"Transaction successfull...\t Payment complete...\tRefunding:"<<-1*toPay<<endl;
			k++;
		}
		else
		{
			cout<<"Insufficient amount...Total amount not paid\n";
			cout<<"Amount remaining:"<<toPay<<endl;
			
		}
	}
}

void cheque(long double toPay)
{
	long double amt;
	int k=0;
	do
	{
		cout<<"Enter amount to be deposited:";
		cin>>amt;
		if(amt>toPay)
		{
			cout<<"Transaction successfull...\t Payment complete...\tRefunding:"<<(amt-toPay)<<endl;
			k++;
		}
		else if(amt==toPay)
		{
			cout<<"Transaction successful...\tPayment complete...\n";
			k++;
		}
		else
		{
			cout<<"Insufficient amount.....cheque bounce....pay again....press 0 to try again\n";
			cin>>k;
		}
	}while(k==0);
}

void mop(long double toPay)
{
	int ch;
	cout<<"ENTER YOUR DESIRED MODE OF PAYMENT........\nPress 1 for Cheque payment\nPress 2 for EMI\n";
	cin>>ch;
	do
	{
		switch(ch)
		{
			case 1:	cheque(toPay);
					ch=0;
					break;
			case 2: emipay(toPay);
					ch=0;
					break;
			default: cout<<"Wrong choice.....enter 0 to exit\n";
				     cin>>ch;
		}
	}while(ch);
	payment_complete(toPay);//pass parameters
}

void payment_complete(long double toPay)
{
	oldcust ccust;
	ccust.calc_exp(toPay);
	long double ex = ccust.rtot_exp();
	ccust.assign_disc(ex);
	ccust.assign_mtype(ex);
	ccust.disp_mtype();
	float dis = ccust.rdiscount();
	long double bill = toPay - (dis/100)*toPay;
	cout<<"\n NET PAYABLE AMOUNT:"<<bill;
   			cout<<"\n\n";
   			cout<<"		thanks for your purchase\n";
   			cout<<"		  plz visit us again\n";

}

/*void choose_emp()
{
	//viewemp
	fstream fil,efil;
 	old_employee e;
 	int opt,chk1;
 	char z;
 	char ename[30],email[30],etsales[10],ephoneno[10];
 	char name[30],mail[30],tsales[10],phoneno[10],id[10],erating[10];
 	//int id,erating;
 	char a[30], b[30],c[30],d[30];   //............................some random strigs to pass to encrypt
 	strcpy(name,e.new_employee::rname());
 	strcpy(mail,e.new_employee::rmail());
 	strcpy(tsales,to_string(e.rtot_sales()));
 	strcpy(phoneno,to_string(e.new_employee::rphoneno()));
 	strcpy(id,to_string(e.new_employee::reid()));
 	strcpy(erating,to_string(e.rerating()));
 	fil.open("empin.dat",ios::binary|ios::in);
 	efil.open("encempin.dat",ios::binary|ios::app);
 	while(fil.read((char*)&e,sizeof(e)))
 	{
 		strcpy(ename,encrypt(name,a,strlen(name),key,key,key));
 		strcpy(email,encrypt(mail,b,strlen(mail),key,key,key));
 		strcpy(etsales,encrypt(tsales,c,strlen(tsales),key,key,key));
 		strcpy(phoneno,encrypt(phoneno,d,strlen(phoneno),key,key,key));
 		efil.write((char*)&e,sizeof(e));
 	}
	 
	 
	 
	 clrscr();
 	cout<<"following are the employees:\n";
 	while(fil.read((char*)&e,sizeof(e)))
 	e.new_employee::display();
 	fil.close();
 	
}
	
 	//WHAT IS THIS SAHARSH
 	/*car c;
 	int del=0,sno;
 	cout<<"enter chassisno of car to delete:";
 	cin>>sno;
 	cout<<endl<<endl<<"are you sure(y/n)?";
 	cin>>z;
 	if (z=='y')
 	{
  		while(fil1.read((char*)&c,sizeof(c)))
  		{
   			char z;
   			if(c.rchassis()!=sno)
   			fil2.write((char*)&c,sizeof(c));
   			else
   			{
    			del++;
    			clrscr();
    			cout<<"following car deleted from record:\n";
    			c.showdata();
    			cout<<endl<<endl<<"press any key to continue";
    			getch();
    			clrscr();
   			}
  		}
 	}
 	else{ clrscr(); deletedata();}
 	if(!del)
 	{
  		int ch3;
  		remove("temp.dat");
  		do
  		{
   			clrscr();
   			cout<<"searched car not found\n\n";
   			cout<<"what do you wanna do?\n";
   			cout<<"1.retry entering chassisno?\n";
   			cout<<"2.go back\n";
   			cout<<"enter your choice(1/2):";
   			cin>>ch3;
   			switch(ch3)
   			{
    			case 1: clrscr();
	    				deletedata();
		    			break;

	    		case 2: clrscr();
   			}
  		}while(ch3!=2);
 	}
 	fil1.close();
 	fil2.close();
 	remove("carlist.dat");
 	rename("temp.dat","carlist.dat");
	
	
}*/

//ENCRYPTION START
void enc_rot(char ex[],int arr_size,int key_rot)												//rotate string enc
{
	int i,j,n=arr_size,k=key_rot;
	for(j=0;j<k;j++)
	{
		char temp=ex[0];
		for(i=0;i<n;i++)
		ex[i]=ex[i+1];
		ex[n-1]=temp;
	}
}

void enc_add(char ex[],int arr_size,int key_add)											//shift the elements by k (+k to ascii value) enc
{
	int i,n=arr_size,k=key_add,ascii,res;
	for(i=0;i<n;i++)
	{
		ascii=int(ex[i]);
		res=ascii+k;
		if(ascii>=97 && ascii<=122)
		{
			if(res<=122)
			ex[i]=char(res);
			else
			ex[i]=char(res-26);
		}
		if(ascii>=65 && ascii<=90)
		{
			if(res<=90)
			ex[i]=char(res);
			else
			ex[i]=char(res-26);
		}
		if(ascii>=48 && ascii<=57)
		{
			if(res<=57)
			ex[i]=char(res);
			else
			ex[i]=char(res-10);
		}
	}
}

char* encrypt(char ex[],char res_ex[],int arr_size,int key_rot,int key_add,int key_n)	//encryption(ex,res_ex,strlen,r,a,n)
{
	for(int i=0;i<key_n;i++)
	{
		enc_rot(ex,arr_size,key_rot);
		enc_add(ex,arr_size,key_add);
	}
	strcpy(res_ex,ex);
	return res_ex;
}
//ENCRYPTION END

//DECRYPTION START
void dec_rot(char ex[],int arr_size,int key_rot)												//rotate string dec
{
	int i,j,n=arr_size,k=key_rot;
	for(j=0;j<k;j++)
	{
		char temp=ex[n-1];
		for(i=n-1;i>=0;i--)
		ex[i]=ex[i-1];
		ex[0]=temp;
	}
}

void dec_sub(char ex[],int arr_size,int key_add)											//shift the elements by k (-k to ascii value) dec
{
	int i,n=arr_size,k=key_add,ascii,res;
	for(i=0;i<n;i++)
	{
		ascii=int(ex[i]);
		res=ascii-k;
		if(ascii>=97 && ascii<=122)
		{
			if(res>=97)
			ex[i]=char(res);
			else
			ex[i]=char(res+26);
		}
		if(ascii>=65 && ascii<=90)
		{
			if(res>=65)
			ex[i]=char(res);
			else
			ex[i]=char(res+26);
		}
		if(ascii>=48 && ascii<=57)
		{
			if(res>=48)
			ex[i]=char(res);
			else
			ex[i]=char(res+10);
		}
	}
}

char* decrypt(char ex[],char res_ex[],int arr_size,int key_rot,int key_add,int key_n)	//decryption(ex,res_ex,strlen,r,a,n)
{
	for(int i=0;i<key_n;i++)
	{
		dec_rot(ex,arr_size,key_rot);
		dec_sub(ex,arr_size,key_add);
	}
	strcpy(res_ex,ex);
	return res_ex;
}



