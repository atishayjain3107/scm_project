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
}
