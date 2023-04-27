#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
int cl1=0,cl2=0,cl3=0;

void main_menu();

class tablet
{
  int idno;
  int nfst;


public: char name[30];
	void setnfst(int a)
	{
	nfst=a;
	}
	void setidno(int b)
	{
	idno=b;
	}

	int getnfst()
	{
	return nfst;
	}

	int getidno()
	{
	return idno;
	}

	int search(char naam[])
	{
	 int q;
	 if(strcmpi(name,naam)==0)
	 {
	   q=1;
	 }
	  return q;

	}

	void input()
	{
	cout<<"\n\nEnter the name of Medicine(tablets/syrups/capsules) =>>";
	gets(name); cout<<endl;
	cout<<"Enter the id number of Medicine(tablets/syrups/capsules) =>>";
	cin>>idno; cout<<endl;
	cout<<"Enter the no of strips of Medicine(tablets/syrups/capsules) =>>";
	cin>>nfst; cout<<endl;
	cout<<endl<<endl;
	}

	void show()
	{
	 cout<<"\nName ::";
	 cout<<name<<endl;
	 cout<<"Id of Medicine ::";
	 cout<<idno<<endl;
	 cout<<"Strips::";
	 cout<<nfst<<endl;
	}
}t;
class syrup:public tablet
{
int idno;
int nfst;
}s;
class capsule:public tablet
{
int idno;
int nfst;
}c;


void add()
{
clrscr();
int y;
cout<<"          ****************Add A Medicine**************";
cout<<"\n1.Enter the tablet.";
cout<<"\n2.Enter the syrup.";
cout<<"\n3.Enter the capsule.";

cout<<"\nEnter your choice ::";
cin>>y;
clrscr();
    if(y==1)
    {
       char k;
       ofstream ofs1("tab.dat",ios::binary|ios::app);
       clrscr();
       do
	{
	  t.input();
	  ofs1.write((char*)&t,sizeof(t));
	  cl1++;
	  cout<<"Do you want to add more Tablets(y/n) ::";
	  cin>>k;
	}
	while(k=='y'||k=='Y');
       ofs1.close();
       main_menu();
    }
    else if(y==2)
       {
       char k;
       ofstream ofs2("syp.dat",ios::binary|ios::app);
       clrscr();
       do
	{
	  s.input();
	  ofs2.write((char*)&s,sizeof(s));
	  cl2++;
	  cout<<"Do you want to add more Syrups(y/n) ::";
	  cin>>k;
	}
	while(k=='y'||k=='Y');
       ofs2.close();
       main_menu();
    }
    else if(y==3)
    {
       char k;
       ofstream ofs3("cap.dat",ios::binary|ios::app);
       clrscr();
       do
	{
	  c.input();
	  ofs3.write((char*)&c,sizeof(c));
	  cl3++;
	  cout<<"Do you want to add more Capsules(y/n) ::";
	  cin>>k;

	}
	while(k=='y'||k=='Y');
       ofs3.close();
       main_menu();
    }
    else
      cout<<"Wrong choice entered.....!!!!!!!!!";


}



void remove()
{
clrscr();
int x;
cout<<"          ****************Remove A Medicine****************\n\n";
cout<<"1 Remove a Tablet "<<endl;
cout<<"2.Remove a Syrup "<<endl;
cout<<"3.Remove a Capsule "<<endl;

cout<<"enter your choice ";
cin>>x;

char na[20];

clrscr();

if(x==1)
{
cout<<"Enter the name of the tablet to be removed :: ";
gets(na);

ifstream ifs1("tab.dat",ios::in);
ofstream ofs1("temp1.dat",ios::out|ios::app);
while(!ifs1.eof())
{
ifs1.read((char*)&t,sizeof(t));
if(ifs1.eof())
break;
	if(strcmpi(t.name,na)!=0)
	{
	ofs1.write((char*)&t,sizeof(t));
	}
}
ofs1.close();
ifs1.close();

remove("tab.dat");
rename("temp1.dat","tab.dat");
}
else if(x==2)
{
cout<<"Enter the name of the syrup to be remove :: ";
gets(na);

ifstream ifs2("syp.dat",ios::in);
ofstream ofs2("temp2.dat",ios::out|ios::app);
while(!ifs2.eof())
{
ifs2.read((char*)&s,sizeof(s));
if(ifs2.eof())
break;
	if(strcmpi(s.name,na)!=0)
	{
	ofs2.write((char*)&s,sizeof(s));
	}

}
ofs2.close();
ifs2.close();

remove("syp.dat");
rename("temp2.dat","syp.dat");
}
else if(x==3)
{
cout<<"Enter the name of the capsule to be remove :: ";
gets(na);

ifstream ifs3("cap.dat",ios::in);
ofstream ofs3("temp3.dat",ios::out|ios::app);
while(!ifs3.eof())
{
ifs3.read((char*)&c,sizeof(c));
if(ifs3.eof())
break;
	if(strcmpi(c.name,na)!=0)
	{
	ofs3.write((char*)&c,sizeof(c));
	}
}
ofs3.close();
ifs3.close();

remove("cap.dat");
rename("temp3.dat","cap.dat");
}
}

void check_stock()
{
clrscr();
int ch;
cout<<"\n           *************Check Stock************\n\n";
cout<<"1.Check for tablet "<<endl;
cout<<"2.Check for syrup "<<endl;
cout<<"3.Check for capsule "<<endl;

cout<<"Enter your choice ::";
cin>>ch;
clrscr();
char na[20];
clrscr();
if(ch==1)
{

int x,y=0;
cout<<"\n\nEnter the name of tablet to check details :: ";
gets(na);
ifstream ifile1("tab.dat",ios::in);

while(!ifile1.eof())
{
 ifile1.read((char*)&t,sizeof(t));
 if(ifile1.eof())
 break;

 x=t.search(na);

 if(x==1)
 {
  y=1;
  t.show();
  break;
 }

}
if(y!=1)
cout<<"\n\nSorry Not Found...!!!";
ifile1.close();
}
else if(ch==2)
{

int x,y=0;
cout<<"\n\nEnter the name of syrup to check details :: ";
gets(na);
ifstream ifile2("syp.dat",ios::in);

while(!ifile2.eof())
{
 ifile2.read((char*)&s,sizeof(s));
 x=s.search(na);
 if(x==1)
 {
  y=1;
  s.show();
  break;
 }

}
if(y!=1)
cout<<"\n\nSorry Not Found...!!!1";
ifile2.close();
}

else if(ch==3)
{

int x,y=0;
cout<<"\n\nEnter the name of capsule to check details :: ";
gets(na);
ifstream ifile3("cap.dat",ios::in);

while(!ifile3.eof())
{
 ifile3.read((char*)&c,sizeof(c));
 if(ifile3.eof())
 break;
 x=c.search(na);
 if(x==1)
 {
  y=1;
  c.show();
  break;
 }

}
if(y!=1)
cout<<"\n\nSorry Not Found...!!!";
ifile3.close();
}


else
cout<<"\n\nWrong Choice Entered........!!!!!!!! ";


}



void issue_bill()
{
clrscr();
int k;
cout<<"\n     *************Issue Bill**************\n";
cout<<"1.To purchase Tablet. "<<endl;
cout<<"2.To Purchase Syrup. "<<endl;
cout<<"3.To Purchase Capsule. "<<endl;

cout<<"Enter your choice :: ";
cin>>k;
clrscr();

char na[20];
int n;


cout<<"\n\nEnter the name of medicine you want to purchase :: ";
gets(na);

cout<<"\n\nEnter the no. of strips you want to purchase :";
cin>>n;



if(k==1)
{
int x;
int cool1=0,q1=0;
ifstream ifs1("tab.dat",ios::in);
ofstream ofs1("tempe1.dat",ios::out|ios::app|ios::binary);

while(!ifs1.eof())
{

 ifs1.read((char*)&t,sizeof(t));
 if(ifs1.eof())
 break;

  x=t.search(na);

 if(x==1)
 {
  if(t.getnfst()<n)
  {
  cout<<"\n\nStrips available ::"<<t.getnfst();
  cout<<"\n\nReqired Strips Not AVAILABLE.....!!!!!";
  ofs1.write((char*)&t,sizeof(t));
  }
  else
  {
   cool1++;
   q1=n;
  cout<<"\nStrips Available In Stock ::"<<t.getnfst();
  cout<<"\n\nSuccessfully Purchased by Costumer."<<"Thanks for Purchasing......."<<endl;
  int b,f;
  f=  t.getnfst();
  b=f-n;
  t.setnfst(b);
  ofs1.write((char*)&t,sizeof(t));
  }
 }
 else
 {
 ofs1.write((char*)&t,sizeof(t));
 }
}
ifs1.close();
ofs1.close();

remove("tab.dat");
rename("tempe1.dat","tab.dat");
if(cool1!=0)
  {



      cout<<endl<<endl;
      cout<<"COST PER STRIP "<<"              "<<"NO OF STRIPS PURCHASED"<<"                   "<<"TOTAL BILL"<<endl;
      cout<<"==== === ===== "<<"              "<<"== == ====== ========="<<"                   "<<"===== ===="<<endl<<endl;
      cout<<"      10       "<<"              "<<"          "<<q1<<"                            "<<"  "<<(q1*10);
      cout<<endl;

     cout<<"\nSuccessfully Purchased by  the Customer.";
  }


}

else if(k==2)
{
int x;
ifstream ifs2("syp.dat",ios::in);
ofstream ofs2("tempe2.dat",ios::out|ios::binary|ios::app);

while(!ifs2.eof())
{

 ifs2.read((char*)&s,sizeof(s));
 if(ifs2.eof())
 break;

  x=s.search(na);

 if(x==1)
 {
  if(s.getnfst()<n)
  {
  cout<<"\n\nStrips available ::"<<s.getnfst();
  cout<<"\n\nReqired Strips Not AVAILABLE.....!!!!!";
  ofs2.write((char*)&t,sizeof(t));
  }
  else
  {
  cout<<"\nStrips Available In Stock ::"<<s.getnfst();
  cout<<"\n\nSuccessfully Purchased by Costumer."<<"Thanks for Purchasing......."<<endl;
  int b,f;
  f=  s.getnfst();
  b=f-n;
  s.setnfst(b);
  ofs2.write((char*)&s,sizeof(s));
  }
 }
 else
 {
 ofs2.write((char*)&s,sizeof(s));
 }
}
ifs2.close();
ofs2.close();

remove("syp.dat");
rename("tempe2.dat","syp.dat");
}

else if(k==3)
{
int x;
ifstream ifs3("cap.dat",ios::in);
ofstream ofs3("tempe3.dat",ios::out|ios::binary|ios::app);

while(!ifs3.eof())
{

 ifs3.read((char*)&c,sizeof(c));
 if(ifs3.eof())
 break;

  x=c.search(na);

 if(x==1)
 {
  if(c.getnfst()<n)
  {
  cout<<"\n\nStrips available ::"<<c.getnfst();
  cout<<"\n\nReqired Strips Not AVAILABLE.....!!!!!";
  ofs3.write((char*)&c,sizeof(c));
  }
  else
  {
  cout<<"\nStrips Available In Stock ::"<<c.getnfst();
  cout<<"\n\nSuccessfully Purchased by Costumer."<<"Thanks for Purchasing......."<<endl;
  int b,f;
  f=  c.getnfst();
  b=f-n;
  c.setnfst(b);
  ofs3.write((char*)&c,sizeof(c));
  }
 }
 else
 {
 ofs3.write((char*)&c,sizeof(c));
 }
}
ifs3.close();
ofs3.close();

remove("cap.dat");
rename("tempe2.dat","cap.dat");
}


else
cout<<"Wrong choice ";


}


void create_po()
{
int ch;
cout<<"1.List for Tablet. "<<endl;
cout<<"2.List for Syrup. "<<endl;
cout<<"3.List for Capsule. "<<endl;
cout<<"enter your choice ";
cin>>ch;
clrscr();

if(ch==1)
{
ifstream ifs1("tab.dat",ios::in);

if(cl1!=0)
{
int x;
cout<<"\n\n    Name:        Remaining no. of strips:   \n";
cout<<"    ----         --------- --- -- ------- \n";
while(!ifs1.eof())
{
 ifs1.read((char*)&t,sizeof(t));
 if(ifs1.eof())
 break;

 x=t.getnfst();
 if(x<=5)
 {
   cout<<"\n    "<<t.name<<"               "<<t.getnfst();

 }

}
}
else
cout<<"first add a tablet ";
ifs1.close();
}

if(ch==2)
{
ifstream ifs2("syp.dat",ios::in);

if(cl2!=0)
{
int x;
cout<<"\n\n    Name:        Remaining no. of strips:   \n";
cout<<"    ----         --------- --- -- ------- \n";
while(!ifs2.eof())
{
 ifs2.read((char*)&s,sizeof(s));
 if(ifs2.eof())
 break;
 x=s.getnfst();
 if(x<=5)
 {
   cout<<"\n    "<<s.name<<"               "<<s.getnfst();

 }

}
}
else
cout<<"\nSufficient Stock ....... ";
ifs2.close();
}


if(ch==3)
{
ifstream ifs3("cap.dat",ios::in);

if(cl3!=0)
{
int x;
cout<<"\n\n    Name:        Remaining no. of strips:   \n";
cout<<"    ----         --------- --- -- ------- \n";
while(!ifs3.eof())
{
 ifs3.read((char*)&c,sizeof(c));
 if(ifs3.eof())
 break;
 x=c.getnfst();
 if(x<=5)
 {
   cout<<"\n    "<<c.name<<"               "<<c.getnfst();

 }

}
}
else
cout<<"first add a tablet ";
ifs3.close();

}




}


void view_or()
{
clrscr();
int o,strip;
cout<<"1.List for Tablet. "<<endl;
cout<<"2.List for Syrup. "<<endl;
cout<<"3.List for Capsule. "<<endl;
cout<<"enter your choice ";
cin>>o;
clrscr();
if(o==1)
{
ifstream ifs1("tab.dat",ios::in);
int l;
//cout<<"    Name:        Required no. of strips:   "<<endl;
//cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifs1.eof())
{
 ifs1.read((char*)&t,sizeof(t));
 if(ifs1.eof())
 break;

 l=t.getnfst();
 if(l<=5)
 {
   cout<<"Name :: "<<t.name<<endl;
   cout<<"enter the required no of strips for order ::";
   cin>>strip;

 }



}
ifs1.close();
clrscr();
ifstream ifile1("tab.dat",ios::in);
cout<<"    Name:        Required no. of strips:   "<<endl;
cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifile1.eof())
{
 ifile1.read((char*)&t,sizeof(t));
 if(ifile1.eof())
 break;

 l=t.getnfst();
 if(l<=5)
 {
    cout<<"  "<<t.name<<"                         "<<strip<<endl;

 }


}
ifile1.close();


}

if(o==2)
{
ifstream ifs2("syp.dat",ios::in);
int l;
//cout<<"    Name:        Required no. of strips:   "<<endl;
//cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifs2.eof())
{
 ifs2.read((char*)&s,sizeof(s));
 if(ifs2.eof())
 break;

 l=s.getnfst();
 if(l<=5)
 {
   cout<<"Name :: "<<s.name<<endl;
   cout<<"enter the required no of strips for order ::";
   cin>>strip;

 }



}
ifs2.close();
clrscr();
ifstream ifile2("syp.dat",ios::in);
cout<<"    Name:        Required no. of strips:   "<<endl;
cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifile2.eof())
{
 ifile2.read((char*)&s,sizeof(s));
 if(ifile2.eof())
 break;

 l=s.getnfst();
 if(l<=5)
 {
    cout<<"  "<<s.name<<"                         "<<strip<<endl;

 }


}
ifile2.close();


}

if(o==3)
{
ifstream ifs3("cap.dat",ios::in);
int l;
//cout<<"    Name:        Required no. of strips:   "<<endl;
//cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifs3.eof())
{
 ifs3.read((char*)&c,sizeof(c));
 if(ifs3.eof())
 break;

 l=c.getnfst();
 if(l<=5)
 {
   cout<<"Name :: "<<c.name<<endl;
   cout<<"enter the required no of strips for order ::";
   cin>>strip;

 }



}
ifs3.close();
clrscr();
ifstream ifile3("cap.dat",ios::in);
cout<<"    Name:        Required no. of strips:   "<<endl;
cout<<"    ----         --------- --- -- -------   "<<endl;
while(!ifile3.eof())
{
 ifile3.read((char*)&c,sizeof(c));
 if(ifile3.eof())
 break;

 l=c.getnfst();
 if(l<=5)
 {
    cout<<"  "<<c.name<<"                         "<<strip<<endl;

 }


}
ifile3.close();


}


}




void main_menu()
{

abc:

clrscr();
int x;
cout<<"          ***************Welcome to the Project **************\n\n";
cout<<"          ***************Medical Store Management*************\n\n";
cout<<"\n1.Add a Medicine.";
cout<<"\n2.Remove Medicine from stock.";
cout<<"\n3.Check stock'";
cout<<"\n4.Issue Bill.";
cout<<"\n5.Create purchase order. ";
cout<<"\n6.View purchase order.";
cout<<"\n7.EXIT.";
cout<<"\nEnter your choice ::";

cin>>x;


if(x==1)
{
add();
}
if(x==2)
{
char c;
remove();
cout<<"\n\nDo you want to continue in program(y/n) => ";
cin>>c;
if(c=='y'||c=='Y')
goto abc;
}


if(x==3)
{
char c;
check_stock();
cout<<"\n\nDo you want to continue in program(y/n) => ";
cin>>c;
if(c=='y'||c=='Y')
goto abc;

}
if(x==4)
{
char c;
issue_bill();
cout<<"\ndo you want to continue in program(y/n) => ";
cin>>c;
if(c=='y'||c=='Y')
goto abc;

}

if(x==5)
{
char c;
create_po();
cout<<"\n\ndo you want to continue in program(y/n) => ";
cin>>c;
if(c=='y'||c=='Y')
goto abc;

}
if(x==6)
{
char c;
view_or();
cout<<"\n\ndo you want to continue in program(y/n) => ";
cin>>c;
if(c=='y'||c=='Y')
goto abc;

}
if(x==7)
{
exit(0);
}

}
void main()
{
clrscr();
main_menu();
}

