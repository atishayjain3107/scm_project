#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
class report
{
	int date,month,year;
	long admNo;
	char res[50]; //reason for coming
	public:
		void inputData();
		void displayData();
		long getAdmno()
		{
			return(admNo);
		}
		void getDate(int &d, int &m, int &y)
		{
			d=date;
			m=month;
			y=year;
		}

}rep;

class checkUp
{
	long admNo;
	int height,weight,date,month,year;
	//char sight[30],ears[30],throat[30],tonsils[30],nails[30];
	//char hygiene[30],teeth[30],remarks[100];
	char data[7][50];
	public:
		void inputData();
		void displayData();
		int getAdmno()
		{
			return(admNo);
		}

}c;

class student
{
	long admno;
	//order-> sname,mname,fname,addr,fno,mno,bgp;
	//char sName[50],mName[50],fName[50],addr[50],fNo[10],mNo[10],bGp[3];
	char data[7][50];
	public:
		void inputData();
		void displayData(int);
		int getAdmno()
		{
			return(admno);
		}

}s;

//student database functions
void studentDB();
void SD_addRecord();
void SD_deleteRecord();
void SD_viewAll();
void SD_modifyRecord();
void SD_searchRecord();

//medical checkup functions
void MedicalCheckup();
void MC_addRecord();
void MC_searchRecord(long admn);
void MC_viewAll();

//report functions
void Report();
void R_addRecord();
void R_searchRecord(long);
void view_date(int sdate, int smonth, int syear,int edate, int emonth, int eyear);
void view_month(int mon);
void curDate(int&,int&,int&);

//ui functions
void init();
void mainmenu();
void box(int,int,int,int);
void cursor(int,int,char*,COLORS);
void setText(int,int,char*,COLORS,int);
char* getText(int,int,char*,COLORS,int);
long getNum(int,int,char*,COLORS);
void plus(char* s);
void clear();

//////////////////////////////////////////
/////////////MAIN FUNCTION////////////////
//////////////////////////////////////////

void main()
{
	clrscr();
	window(1,1,80,25);
	textbackground(BLACK);
	textcolor(BLACK);
	clrscr();
	window(2,2,79,24);
	textbackground(WHITE);
	clrscr();
	window(15,10,70,15);
	textbackground(RED);
	clrscr();
	window(38,5,48,20);
	textbackground(RED);
	clrscr();
	window(20,10,45,10);
	gotoxy(20,10);
	cout<<"€€€€€  €€€    €€€€€   €€€   €€€€€ €     € €€€€€"<<endl;
	window(20,11,45,11);
	gotoxy(20,11);
	cout<<"€   €  €  €   €   €  €   €  €      €   €  €   €"<<endl;
	window(20,12,45,12);
	gotoxy(20,12);
	cout<<"€   €  €  €   €   €  €   €  €       € €   €   €"<<endl;
	window(20,13,45,13);
	gotoxy(20,13);
	cout<<"€€€€€  €€€    €€€€€  €   €  € €€€    €    €€€€€"<<endl;
	window(20,14,45,14);
	gotoxy(20,14);
	cout<<"€   €  €  €   €   €  €   €  €   €    €    €   €"<<endl;
	window(20,15,45,15);
	gotoxy(20,15);
	cout<<"€   €  €   €  €   €   €€€   €€€€€    €    €   €"<<endl;
	getch();
	init();
	mainmenu();
}

/////////////////////////////////////////////
////DEFINITION OF UI FUNCTIONS///////////////
/////////////////////////////////////////////

void box(int x1,int y1,int x2,int y2)
{
	int i;
	char ch='€';
	window(1,1,80,25);
	textcolor(BLACK);
	for(i=x1;i<=x2;i++)
	{
		gotoxy(i,y1);
		cout<<ch;
		gotoxy(i,y2);
		cout<<ch;
	}
	for(i=y1;i<=y2;i++)
	{
		gotoxy(x1,i);
		cout<<ch;
		gotoxy(x2,i);
		cout<<ch;
	}
}

void cursor(int x,int y, char* s)
{
	window(x,y,20+x,y);
	textbackground(MAGENTA);
	clrscr();
	gotoxy(x+1,y);
	puts(s);
}

void setNum(int x,int y, char* s,int n,COLORS c = BLUE,int size=24)
{
	window(x,y,x+size,y);
	textbackground(c);
	textcolor(BLACK);
	clrscr();
	gotoxy(x+1,y);
	puts(s);
	window(x+10,y,x+30,y);
	gotoxy(x+10,y);
	cout<<n;
}

void setText(int x,int y, char* s,COLORS c = BLUE,int size=24)
{
	window(x,y,x+size,y);
	textbackground(c);
	textcolor(BLACK);
	clrscr();
	gotoxy(x+1,y);
	puts(s);
}

long getNum(int x, int y, char* s,COLORS c = BLUE)
{
	long n;
	window(x,y,30+x,y);
	textbackground(c);
	clrscr();
	gotoxy(x+1,y);
	puts(s);
	window(x+22,y,x+50,y);
	gotoxy(x+22,y);
	cin>>n;
	return n;
}

void getText(int x, int y, char* s,char str[],COLORS c = BLUE)
{
	window(x,y,30+x,y);
	textbackground(c);
	clrscr();
	gotoxy(x+1,y);
	puts(s);
	window(x+22,y,x+50,y);
	gotoxy(x+22,y);
	gets(str);
}

//makes the plus sign
void plus(char* s)
{
	window(8,19,32,21);
	textbackground(RED);
	clrscr();
	window(17,17,23,23);
	textbackground(RED);
	clrscr();
	window(14,20,24,20);
	textcolor(WHITE);
	setText(14,20,s,RED,18);
}

void clear()
{
	window(5,5,75,15);
	textcolor(WHITE);
	textbackground(BLUE);
	clrscr();
	box(5,5,75,15);
}

void console(char* s)
{
	window(40,18,75,22);
	textcolor(WHITE);
	textbackground(BLACK);
	clrscr();
	box(40,18,75,22);
	window(45,20,75,20);
	gotoxy(45,20);
	puts(s);
} void mainmenu()
{
	//options
	int cr=0,tX=6,tY=7,flag=0;
	char ch,option[4][30] = {"Student Database","Medical Checkup","Visitor Entry/Report","Quit"};
	do
	{
		if(flag==0)
		{
			cr=0;
			tX=6;
			tY=7;
			console("");
			clear();
			plus("MAIN");
			for(int i=0;i<4;i++)
				setText(tX,tY+i,option[i]);
			cursor(tX,tY,option[cr]);
			flag=1;
		}
		ch = getch();
		switch(ch)
		{
			case 80:setText(tX,tY,option[cr]); //down key
				if(cr==3)
				{
					cr=0;
					tY-=3;
				}
				else
				{
					cr++;
					tY++;
				}
				cursor(tX,tY,option[cr]);
				break;
			 case 72:setText(tX,tY,option[cr]);  //up key
				 if(cr==0)
				 {
					cr=3;
					tY+=3;
				 }
				 else
				 {
					cr--;
					tY--;
				 }
				 cursor(tX,tY,option[cr]);
				 break;
			 case 13:switch(cr+1)
				 {
					case 1: studentDB();
						flag=0;
						break;
					case 2: MedicalCheckup();
						flag=0;
						break;
					case 3: Report();
						flag=0;
						break;
					case 4: exit(0);
				 }
		}
	} while(1);
}void studentDB()
{
	plus("Student DB");
	int cr=0,tX=6,tY=7,flag=0;
	char ch,option[6][30] = {"Add Record","Delete Record","View All","Search Record","Modify Record","Go Back"};
	do
	{
		if(flag==0)
		{
			console("");
			cr=0;
			tX=6;
			tY=7;
			clear();
			for(int i=0;i<6;i++)
				setText(tX,tY+i,option[cr+i]);
			cursor(tX,tY,option[cr]);
			flag=1;
		}
		ch=getch();
		switch(ch)
		{
			case 80:setText(tX,tY,option[cr]); //down key
				if(cr==5)
				{
					cr=0;
					tY-=5;
				}
				else
				{
					cr++;
					tY++;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 72:setText(tX,tY,option[cr]);  //up key
				if(cr==0)
				{
					cr=5;
					tY+=5;
				}
				else
				{
					cr--;
					tY--;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 13:switch(cr+1)
				{
					case 1: clear();
						SD_addRecord();
						flag=0;
						break;
					case 2: SD_deleteRecord();
						flag=0;
						break;
					case 3: SD_viewAll();
						flag=0;
						break;
					case 4: SD_searchRecord();
						flag=0;
						break;
					case 5: SD_modifyRecord();
						flag=0;
						break;
					case 6: ch=27;
				 }
		}
	} while(ch!=27);
}void student:: inputData()
{
	int tX=6, tY=6;
	char list[7][50] = {"2.Name:","3.Blood Group:","4.Address:","5.Father's Name:","6.Father's Phone No.:","7.Mother's Name:","8.Mother's Phone No.:"};
	char str[50];
	admno = getNum(tX,tY++,"1.Admno: ");
	for(int i=0;i<7;i++)
	{
		getText(tX,tY+i,list[i],str);
		strcpy(data[i],str);
	}
}

void student:: displayData(int tX=6)
{
	int tY=6;
	char list[7][50] = {"2.Name:","3.Blood Group:","4.Address:","5.Father's Name:","6.Father's Phone No.:","7.Mother's Name:","8.Mother's Phone No.:"};
	char* str;
	setNum(tX,tY++,"1.Admno:",admno,BLUE,30);
	for(int i=0;i<7;i++)
	{
		str = list[i];
		strcat(str,data[i]);
		setText(tX,tY+i,str,BLUE,30);
	}
} //adding normal data for student
void SD_addRecord()
{
	fstream f1;
	char ch;
	f1.open("student.dat",ios::app|ios::binary);
	while(1)
	{
		s.inputData();
		f1.write((char*)&s,sizeof(s));
		window(9,15,30,15);
		cout<<"Press N to stop entering-";
		cin>>ch;
		if(ch=='n'|| ch=='N')
			break;
		clear();
	}
	f1.close();
}

//display function for normal student
void SD_viewAll()
{
	fstream f1;
	f1.open("student.dat",ios::in|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	while(!f1.eof())
	{
		f1.read((char*)&s,sizeof(s));
		if(f1.eof())
			break;
		s.displayData();
		getch();
	}
	f1.close();
}
//deleting data for normal student by admission number
void SD_deleteRecord()
{
	fstream f1,f2;
	int flag=0;
	long admn;
	f1.open("student.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	clear();
	admn = getNum(8,8,"Admno -> ");
	while(!f1.eof())
	{
		f1.read((char*)&s,sizeof(s));
		if(f1.eof())
			break;
		if(s.getAdmno()==admn)
		{
			flag=1;
			continue;
		}

		else
		{
	
			f2.write((char*)&s,sizeof(s));
		}
	}
	f2.close();
	f1.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
	if(flag==1)
		console("Deleted!");
	else
		console("NotFound!");
	getch();

}
}

	f1.close();
	f2.close();
}

void MC_viewAll()
{
	fstream f1;
	f1.open("checkup.dat",ios::in|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	while(!f1.eof())
	{
		f1.read((char*)&c,sizeof(c));
		if(f1.eof())
			break;
		c.displayData();
		getch();
		init();
	}
	f1.close();

}

//////////////////////////////////////////////
//////////VISITOR ENTRY AND REPORT////////////
//////////////////////////////////////////////

void Report()
{
	int cr,tX,tY,flag=0;
	int choice,ch2,smonth,sdate,syear,emonth,edate,eyear;
	long admn;
	char ch,option[4][50] = {"Add New Visitor Entry","Get Visit Record","Get visitor reports","Go Back"};
	do
		{
		if(flag==0)
		{
			init();
			console("");
			cr=0;
			tX=6;
			tY=7;
			plus("VISITOR ENTRY");
			clear();
			for(int i=0;i<4;i++)
				setText(tX,tY+i,option[cr+i]);
			cursor(tX,tY,option[cr]);
			flag=1;
		}
		ch=getch();
		switch(ch)
		{
			case 80:setText(tX,tY,option[cr]); //down key
				if(cr==3)
				{
					cr=0;
					tY-=3;
				}
				else
				{
					cr++;
					tY++;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 72:setText(tX,tY,option[cr]);  //up key
				if(cr==0)
				{
					cr=3;
					tY+=3;
				}
				else
				{
					cr--;
					tY--;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 13:switch(cr+1)
				{
					case 1: init();
						R_addRecord();
						flag=0;
						break;
						case 2: init();
						setText(5,5,"Enter Admno. to search -> ",WHITE);
						admn = getNum(5,6,"",WHITE);
						R_searchRecord(admn);
						flag=0;
						break;
					case 3: init();
						int tX=5,tY=5;
						setText(tX,tY++,"Press 1 to get reports between two dates",WHITE);
						setText(tX,tY++,"Press 2 get reports for past 3 months",WHITE);
						setText(tX,tY++,"Press 3 to get repots for past 6 months",WHITE);
						window(tX,tY,tX+20,tY);
						gotoxy(tX,tY);
						cin>>ch2;
						if(ch2==1)
						{
							tX=5;
							tY=5;
							line2:
							console("");
							init();
							setText(tX,tY++,"Enter date from when reports are required -> ",WHITE);
							sdate = getNum(tX,tY++,"",WHITE);
							setText(tX,tY++,"Enter month from when reports are required -> ",WHITE);
							smonth = getNum(tX,tY++,"",WHITE);
							setText(tX,tY++,"Enter year from when reports are required -> ",WHITE);
							syear = getNum(tX,tY++,"",WHITE);
							setText(tX,tY++,"Enter date till when reports are required -> ",WHITE);
							edate = getNum(tX,tY++,"",WHITE);
							setText(tX,tY++,"Enter month till when reports are required -> ",WHITE);
							emonth = getNum(tX,tY++,"",WHITE);
							setText(tX,tY++,"Enter year till when reports are required -> ",WHITE);
							eyear = getNum(tX,tY++,"",WHITE);
							if(sdate>31 || smonth>12 || edate>31 || emonth>12 || sdate<1 || smonth<1 || edate<1 || emonth<1)
							{
								console("Enter dates correctly");
								goto line2;
							}
							init();
							view_date(sdate,smonth,syear,edate,emonth,eyear);
						}
						else if(ch2==2)
						{
							view_month(3);
						}
						else if(ch2==3)
						{
							view_month(6);
						}
						flag=0;
						break;
					case 4: ch=27;
				 }
		}
	} while(ch!=27);
}

void report:: displayData()
{
	init();
	window(6,6,26,6);
	cout<<"Admission num-> "<<admNo;
	window(6,7,26,7);
	gotoxy(6,7);
	cout<<date<<"-"<<month<<"-"<<year<<"\t";
	setText(6,8,res,WHITE);
	getch();
}

void report:: inputData()
{
	init();
	admNo = getNum(6,6,"Enter admission num-> ",WHITE);
	setText(6,7,"Remarks/Reason (under 40 characters) -> ",WHITE);
	getText(6,8,"",res,WHITE);
	curDate(date,month,year);
}

void curDate(int &date, int&month, int&year)
{
	time_t t=time(0); // time right now
	struct tm *now=localtime(&t);
	year=(now->tm_year+1900);
	month=(now->tm_mon+1);
	date=(now->tm_mday);
}

void R_addRecord() //disp mech
{
	fstream f1;
	char ch;
	f1.open("report.dat",ios::app|ios::binary);
	while(1)
	{
		rep.inputData();
		f1.write((char*)&rep,sizeof(rep));
		init();
		setText(5,5,"Press N to stop entering data and ",WHITE);
		setText(5,6,"any other key to continue entering data",WHITE);
		window(5,7,10,7);
		cin>>ch;
		if(ch=='n'|| ch=='N')
			break;
	}
		f1.close();
}

void R_searchRecord(long admn) //disp mech
{
	fstream f1;
	int f=0;//flag
	f1.open("report.dat",ios::in|ios::binary);
	if(!f1)
	{
		cout<<"ERROR";
		getch();
		return;
	}
	while(!f1.eof())
	{
		f1.read((char*)&rep,sizeof(rep));
		if(f1.eof())
			break;
		if(rep.getAdmno()==admn)
		{
			rep.displayData();
			++f;
		}
	}
	f1.close();
       if(f==0)
		cout<<"No record for this student is stored";
}

void view_date(int sdate, int smonth, int syear,int edate, int emonth, int eyear) //sdate,smonth,syear -> starting date
//view reports on the basis of date
{							       //edate,emonth,eyear -> end date
	init();
	fstream f1;
	int d,m,y,f=0;//f is flag
	f1.open("report.dat",ios::in|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	while(!f1.eof())
	{
		f1.read((char*)&rep,sizeof(rep));
		rep.getDate(d,m,y);// d,m,y are date month and year stored in the record
		if(f1.eof())
			break;
		if(y<syear || y>eyear)
			continue;
		else if((y==syear&&m<smonth) || (y==eyear&&m>emonth))
			continue;
		else if((y==syear&&m==smonth&&d<sdate) || (y==eyear&&m==emonth&&d>edate))
			continue;
		else
		{
			rep.displayData();
			getch();
			f++;
		}
	}
	f1.close();
	if(f==0)
		cout<<"No record stored for given dates";
}

void view_month(int mon)//mon: number of months of record required from current date
//view records on the basis of months
{
	init();
	fstream f1;
	int date_beg,month_beg,year_beg,d,m,y,date,month,year;
	f1.open("report.dat",ios::in|ios::binary);
	if(!f1)
	{
		cout<<"ERROR";
		getch();
		return;
	}
	curDate(date,month,year);
	while(!f1.eof())
	{
		if(mon<=month)
		{
			date_beg=date;
			month_beg=month-mon;
			year_beg=year;
			f1.read((char*)&rep,sizeof(rep));
			if(f1.eof())
				break;
			rep.getDate(d,m,y);
			if(y<year_beg)
				continue;
			else if((y==year_beg&&m<month_beg))
				continue;
			else if((y==year_beg&&m==month_beg&&d<date_beg))
				continue;
			else
				rep.displayData();
		}
		if(mon>month)
		{
			date_beg=date;
			month_beg=12-(mon-month)+1;
			year_beg=year-1;
			f1.read((char*)&rep,sizeof(rep));
			if(f1.eof())
				break;
			rep.getDate(d,m,y);
			if(y<year_beg)
				continue;
			else if((y==year_beg&&m<month_beg))
				continue;
			else if((y==year_beg&&m==month_beg&&d<date_beg))
				continue;
			else
				rep.displayData();
		}
	}
}

void init()
{
	window(1,1,80,25);
	textbackground(BLACK);
	clrscr();
	window(1,1,80,24);
	textcolor(BLACK);
	textbackground(WHITE);
	clrscr();A
	box(1,1,80,24);
	gotoxy(27,1);
	cout<<"AAROGYA :: MEDICAL EXPERT";
}

//search a student by admn
void SD_searchRecord()
{
	clear();
	fstream f;
	int admn;
	f.open("student.dat",ios::in|ios::binary);
	if(!f)
	{
		console("ERROR");
		getch();
		return;
	}
	admn = getNum(8,8,"Admno -> ");
	while(!f.eof())
	{
		f.read((char*)&s, sizeof(s));
		if(f.eof()) break;
		if(s.getAdmno() == admn)
		{
			s.displayData();
			getch();
		}
	}
	f.close();
}

//modifying existing normal student data
void SD_modifyRecord()
{
	clear();
	fstream f1,f2;
	int admn;
	f1.open("student.dat",ios::in|ios::binary);
	f2.open("temp.dat",ios::out|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	admn=getNum(8,8,"Admno-> ");
	while(!f1.eof())
	{
		f1.read((char*)&s,sizeof(s));
		if(f1.eof())
			break;
		if(s.getAdmno()==admn)
		{
			clear();
			s.inputData();
			f2.write((char*)&s,sizeof(s));
		}
		else
		{
			f2.write((char*)&s,sizeof(s));
		}
	}
	f1.close();
	f2.close();
	remove("student.dat");
	rename("temp.dat","student.dat");
	console("Updated");
	getch();

void MedicalCheckup()
{
	int cr,tX,tY,flag=0;
	long admn;
	char ch,option[4][50] = {"Add new Record","Search Record","View All Records","Go Back"};
	do
	{
		if(flag==0)
		{
			init();
			console("");
			cr=0;
			tX=6;
			tY=7;
			plus("MEDICAL CHECKUP");
			clear();
			for(int i=0;i<4;i++)
				setText(tX,tY+i,option[cr+i]);
			cursor(tX,tY,option[cr]);
			flag=1;
		}
		ch=getch();
		switch(ch)
		{
			case 80:setText(tX,tY,option[cr]); //down key
				if(cr==3)
				{
					cr=0;
					tY-=3;
				}
				else
				{
					cr++;
					tY++;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 72:setText(tX,tY,option[cr]);  //up key
				if(cr==0)
				{
					cr=3;
					tY+=3;
				}
				else
				{
					cr--;
					tY--;
				}
				cursor(tX,tY,option[cr]);
				break;
			case 13:switch(cr+1)
				{
					case 1: init();
						MC_addRecord();
						flag=0;
						break;
					case 2: init();
						setText(5,5,"Enter Admno. to search -> ",WHITE);
						admn = getNum(5,6,"",WHITE);
						MC_searchRecord(admn);
						flag=0;
						break;
					case 3: init();
						MC_viewAll();
						flag=0;
						break;
					case 4: ch=27;
				 }
		}
	} while(ch!=27);
}


}



void checkUp:: displayData()
{
	int tX=6, tY=6;
	//displaying the medical report
	char list[7][50] = {"4.Sight:","5.Ears:","6.Teeth:","7.Throat:","8.Tonsils:","9.Nails:","10.Hygiene:"};
	char *str;
	gotoxy(tX+3,3);
	cout<<"Date of exa\mination "<<date<<"-"<<month<<"-"<<year<<"\n";
	box(5,5,31,16);
	setNum(tX,tY++,"1.Admno: ",admNo);
	setNum(tX,tY++,"2.Height: ",height);
	setNum(tX,tY++,"3.Weight: ",weight);
	for(int i=0;i<7;i++)
	{
		str = list[i];
		strcat(str,data[i]);
		setText(tX,tY+i,str);
	}
}
void checkUp:: inputData()
{
	init();
	int tX=6, tY=6;
	char list[7][50] = {"4.Sight:","5.Ears:","6.Teeth:","7.Throat:","8.Tonsils:","9.Nails:","10.Hygiene:"};
	char str[50];
	admNo = getNum(tX,tY++,"1.Admno: ",WHITE);
	height = getNum(tX,tY++,"2.Height: ",WHITE);
	weight = getNum(tX,tY++,"3.Weight: ",WHITE);
	for(int i=0;i<7;i++)
	{
		getText(tX,tY+i,list[i],str,WHITE);
		strcpy(data[i],str);
	}
	curDate(date,month,year);
	init();
}
void MC_addRecord()
{
	fstream f1;
	char ch;
	f1.open("checkup.dat",ios::app|ios::binary);
	if(!f1)
	{
		console("ERROR");
		getch();
		return;
	}
	while(1)
	{
		c.inputData();
		f1.write((char*)&c,sizeof(c));
		init();
		setText(5,5,"Press N to stop entering data and ",WHITE);
		setText(5,6,"any other key to continue entering data",WHITE);
		window(5,7,10,7);
		cin>>ch;
		if(ch=='n'|| ch=='N')
			break;
	}
		f1.close();
}

void MC_searchRecord(long admn)
{
	init();
	fstream f1,f2;
	int f=0;//flag
	f1.open("checkup.dat",ios::in|ios::binary);
	f2.open("student.dat",ios::in|ios::binary);
	if(!f1 || !f2)
	{
		console("ERROR");
		getch();
		exit(0);
	}
	while(!f2.eof())
	{
		f2.read((char*)&s,sizeof(s));
		if(f2.eof())
			break;
		if(s.getAdmno()==admn)
		{
			box(44,5,76,14);
			s.displayData(45);
			++f;
		}
	}
	while(!f1.eof())
	{
		f1.read((char*)&c,sizeof(c));
		if(f1.eof())
			break;
		if(c.getAdmno()==admn)
		{
			box(5,5,25,14);
			c.displayData();
			getch();
		}
	}

	f1.close();
	f2.close();
}
