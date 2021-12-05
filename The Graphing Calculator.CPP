#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<fstream.h>
#include<math.h>


fstream f;
class graph
{
	int s,c,o;
	char i[50],w[3],z[3];
	float x,y;
	int midx,midy;
	void linear();
	void quadratic();
	void cubic();
	void cir();
	void ell();
	public:
	graph();
	void plotgraph(int);
};


graph :: graph()
{
	midx=getmaxx()/2;
	midy=getmaxy()/2;
}


void graph :: linear()
{
	f.open("graph.dat",ios::binary|ios::app);
	x=-midx;
	outtextxy(400,350,"y = mx + c");
	outtextxy(400,365,"Enter 'm' and 'c'");
	float m,c;
	cin>>m>>c;
	f<<"y = "<<m<<"x + "<<c<<"\n";
	f.close();
	setcolor(RED);
	char i[50];
	float x1=-c/m;
	sprintf(i,"x-intercept = %g",x1);
	outtextxy(350,100,i);
	sprintf(i,"y-intercept = %g",c);
	outtextxy(350,115,i);
	int s=50;
	sprintf(i,"y = %gx + ",m);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g",c);
	outtextxy(s,midy-15,i);
	while(x<=midx)
	{
		y=-(m*x + c);
		line(x+midx,y+midy,x+1+midx,-(m*(x+1)+c)+midy);
		x++;
	}
}


void graph :: quadratic()
{
	f.open("graph.dat",ios::binary|ios::app);
	x=-50;
	outtextxy(400,350,"y = axý + bx + c");
	outtextxy(400,365,"Enter 'a', 'b' and 'c'");
	float a,b,c;
	cin>>a>>b>>c;
	f<<"y = "<<a<<"xý + "<<b<<"x + "<<c<<"\n";
	f.close();
	setcolor(RED);
	if((b*b)-(4*a*c)<0)
		outtextxy(350,100,"No x-intercept");
	else
	{
		float x1=(-b+sqrt((b*b)-(4*a*c)))/(2*a);
		float x2=(-b-sqrt((b*b)-(4*a*c)))/(2*a);
		sprintf(i,"x-intercept = %g",x1);
		outtextxy(350,100,i);
		sprintf(i,", %g",x2);
		outtextxy(525,100,i);
	}
	sprintf(i,"y-intercept = %g",c);
	outtextxy(350,115,i);
	s=50;
	sprintf(i,"y = %gxý + ",a);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%gx + ",b);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g",c);
	outtextxy(s,midy-15,i);
	while(x<=50)
	{
		y=-(a*x*x + b*x+c);
		line(x+midx,y+midy,x+1+midx,-(a*(x+1)*(x+1)+b*(x+1)+c)+midy);
		x=x+1;
	}
}


void graph :: cubic()
{
	f.open("graph.dat",ios::binary|ios::app);
	x=-10;
	outtextxy(400,350,"y = ax^3 + bxý + cx + d");
	outtextxy(400,365,"Enter 'a', 'b', 'c' and 'd'");
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	f<<"y = "<<a<<"x^3 + "<<b<<"xý + "<<c<<"x + "<<d<<"\n";
	f.close();
	char i[50];
	setcolor(RED);
	float x1,x2,x3,y1,f,g,h,D;
	f=((3*c)/a - (b*b)/(a*a))/3;
	g=((2*b*b*b)/(a*a*a) -(9*b*c)/(a*a) + (27*d)/a)/27;
	h=(g*g)/4 + (f*f*f)/27;
	D=18*a*b*c*d - 4*b*b*b*d + b*b*c*c - 4*a*c*c*c - 27*a*a*d*d;
	if(D>0)
	{
		float i,j,k,l,m,n,p;
		i=sqrt((g*g)/4 - h);
		j=pow(i,1/3.);
		k=acos(-(g/(2*i)));
		l=j*(-1);
		m=cos(k/3);
		n=sqrt(3)*sin(k/3);
		p=(b/(3*a))*(-1);
		x1=2*j*cos(k/3) - b/(3*a);
		x2=l*(m+n) + p;
		x3=l*(m-n) + p;
	}
	else if(D<0)
	{
		float r,s,t,u;
		r=-(g/2) + sqrt(h);
		if(r<0)
		{
			r=fabs(r);
			s=-pow(r,1/3.);
		}
		else
			s=pow(r,1/3.);
		t=-(g/2) - sqrt(h);
		if(t<0)
		{
			t=fabs(t);
			u=-pow(t,1/3.);
		}
		else
			u=pow(t,1/3.);
		x1=s+u - (b/(3*a));
		x2=sqrt(-1);
		x3=sqrt(-1);
	}
	else
	{
		x1=x2=x3=pow(d/a,1/3.)*(-1);
	}
	sprintf(i,"x-intercept = %g",x1);
	outtextxy(350,100,i);
	sprintf(i,"x-intercept = %g",x2);
	outtextxy(350,115,i);
	sprintf(i,"x-intercept = %g",x3);
	outtextxy(350,130,i);
	y1=d;
	sprintf(i,"y-intercept = %g",y1);
	outtextxy(350,145,i);
	s=50;
	sprintf(i,"y = %gx^3 + ",a);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%gxý + ",b);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%gx + ",c);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g",d);
	outtextxy(s,midy-15,i);
	while(x<=10)
	{
		y=-(a*x*x*x + b*x*x + c*x + d);
		line(x+midx,y+midy,x+1+midx,-(a*(x+1)*(x+1)*(x+1) + b*(x+1)*(x+1) + c*(x+1) + d)+midy);
		x=x+1;
	}
}


void graph :: cir()
{
	f.open("graph.dat",ios::binary|ios::app);
	outtextxy(400,350,"(x - a)ý + (y - b)ý = rý");
	outtextxy(400,365,"Enter 'a','b' and 'r'");
	float a,b,r;
	cin>>a>>b>>r;
	f<<"(x - "<<a<<")ý + (y - "<<b<<")ý = "<<r<<"ý\n";
	f.close();
	char i[50];
	setcolor(RED);
	float x1,x2,y1,y2;
	if(fabs(b)-r>0)
		outtextxy(350,100,"No x-intercept");
	else
	{
		x1=sqrt((r*r)-(b*b))+a;
		x2=-sqrt((r*r)-(b*b))+a;
		sprintf(i,"x-intercept = %g",x1);
		outtextxy(350,100,i);
		sprintf(i,",%g",x2);
		outtextxy(525,100,i);
	}
	if(fabs(a)-r>0)
		outtextxy(350,115,"No y-intercept");
	else
	{
		y1=sqrt((r*r)-(a*a))+b;
		y2=-sqrt((r*r)-(a*a))+b;
		sprintf(i,"y-intercept = %g",y1);
		outtextxy(350,115,i);
		sprintf(i,",%g",y2);
		outtextxy(525,115,i);
	}
	s=30;
	sprintf(i,"(x - %g)ý + (y - ",a);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g)ý = ",b);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%gý",r);
	outtextxy(s,midy-15,i);
	circle(a+midx,-b+midy,r);
}


void graph :: ell()
{
	f.open("graph.dat",ios::binary|ios::app);
	outtextxy(350,350,"[(x - x1)/a]ý + [(y - y1)/b]ý = 1");
	outtextxy(350,365,"Enter 'x1', 'y1' and 'a', 'b'");
	float x1,a,y1,b;
	cin>>x1>>y1>>a>>b;
	f<<"[(x - "<<x1<<")/"<<a<<"]ý + [(y - "<<y1<<")/"<<b<<"]ý = 1\n";
	f.close();
	char i[50];
	setcolor(RED);
	float x2,x3,y2,y3;
	if(fabs(y1)-b>0)
		outtextxy(350,100,"No x-intercept");
	else
	{
		x2=sqrt(1-((y1*y1)/(b*b)))*a + x1;
		x3=-sqrt(1-((y1*y1)/(b*b)))*a + x1;
		sprintf(i,"x-intercept = %g",x2);
		outtextxy(350,100,i);
		sprintf(i,",%g",x3);
		outtextxy(525,100,i);
	}
	if(fabs(x1)-a>0)
		outtextxy(350,115,"No y-intercept");
	else
	{
		y2=sqrt(1-((x1*x1)/(a*a)))*b + y1;
		y3=-sqrt(1-((x1*x1)/(a*a)))*b + y1;
		sprintf(i,"y-intercept = %g",y2);
		outtextxy(350,115,i);
		sprintf(i,",%g",y3);
		outtextxy(525,115,i);
	}
	s=5;
	sprintf(i,"[(x - %g)/",x1);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g]ý + [(y - ",a);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g)/",y1);
	outtextxy(s,midy-15,i);
	s+=textwidth(i);
	sprintf(i,"%g]ý = 1",b);
	outtextxy(s,midy-15,i);
	ellipse(x1+midx,-y1+midy,0,360,a,b);
}


void graph :: plotgraph(int c)
{
	if(c==1)
		linear();
	else if(c==2)
		quadratic();
	else if(c==3)
		cubic();
	else if(c==4)
		cir();
	else if (c==5)
		ell();
}


void main()
{
	clrscr();
	int gd=DETECT,gm,err;
	initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
	err=graphresult();
	if(err!=0)
	{
		cout<<grapherrormsg(err)<<endl;
		exit(0);
	}
	else
	{
		setcolor(DARKGRAY);
		setbkcolor(WHITE);
		settextstyle(0,0,2);
		outtextxy(230,200,"SUCCESSFUL");
	}
	cleardevice();
	graph g;
	int ch;
	char c[50];
	do
	{
		cleardevice();
		settextstyle(4,0,4);
		outtextxy(65,1,"THE GRAPHING CALCULATOR");
		settextstyle(0,0,1);
		outtextxy(65,100,"1. Linear Equation");
		outtextxy(65,200,"2. Quadratic Equation");
		outtextxy(65,300,"3. Cubic Equation");
		outtextxy(65,400,"4. Circle");
		outtextxy(425,100,"5. Ellipse");
		outtextxy(425,200,"6. View saved equations");
		outtextxy(425,300,"7. Clear Data");
		outtextxy(425,400,"8. Exit");
		cin>>ch;
		int i;
		char a[50];
		switch(ch)
		{
			case 1: cleardevice();
				for(i=44;i<=getmaxx();i+=50)
				{
					line(i,getmaxy()/2-1,i,getmaxy()/2+1);
					sprintf(a,"%d",i-getmaxx()/2);
					outtextxy(i-10,getmaxy()/2+5,a);
				}
				settextjustify(RIGHT_TEXT,TOP_TEXT);
				for(i=14;i<=getmaxy();i+=50)
				{
					line(getmaxx()/2-1,i,getmaxx()/2+1,i);
					sprintf(a,"%d",getmaxy()/2-i);
					outtextxy(getmaxx()/2-3,i-3,a);
				}
				settextjustify(LEFT_TEXT,TOP_TEXT);
				line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
				line(getmaxx()/2,1,getmaxx()/2,getmaxy());
				g.plotgraph(ch);
				getch();
				break;
			case 2: cleardevice();
				for(i=44;i<=getmaxx();i+=50)
				{
					line(i,getmaxy()/2-1,i,getmaxy()/2+1);
					sprintf(a,"%d",i-getmaxx()/2);
					outtextxy(i-10,getmaxy()/2+5,a);
				}
				settextjustify(RIGHT_TEXT,TOP_TEXT);
				for(i=14;i<=getmaxy();i+=50)
				{
					line(getmaxx()/2-1,i,getmaxx()/2+1,i);
					sprintf(a,"%d",getmaxy()/2-i);
					outtextxy(getmaxx()/2-3,i-3,a);
				}
				settextjustify(LEFT_TEXT,TOP_TEXT);
				line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
				line(getmaxx()/2,1,getmaxx()/2,getmaxy());
				g.plotgraph(ch);
				getch();
				break;
			case 3: cleardevice();
				for(i=44;i<=getmaxx();i+=50)
				{
					line(i,getmaxy()/2-1,i,getmaxy()/2+1);
					sprintf(a,"%d",i-getmaxx()/2);
					outtextxy(i-10,getmaxy()/2+5,a);
				}
				settextjustify(RIGHT_TEXT,TOP_TEXT);
				for(i=14;i<=getmaxy();i+=50)
				{
					line(getmaxx()/2-1,i,getmaxx()/2+1,i);
					sprintf(a,"%d",getmaxy()/2-i);
					outtextxy(getmaxx()/2-3,i-3,a);
				}
				settextjustify(LEFT_TEXT,TOP_TEXT);
				line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
				line(getmaxx()/2,1,getmaxx()/2,getmaxy());
				g.plotgraph(ch);
				getch();
				break;
			case 4: cleardevice();
				for(i=44;i<=getmaxx();i+=50)
				{
					line(i,getmaxy()/2-1,i,getmaxy()/2+1);
					sprintf(a,"%d",i-getmaxx()/2);
					outtextxy(i-10,getmaxy()/2+5,a);

				}
				settextjustify(RIGHT_TEXT,TOP_TEXT);
				for(i=14;i<=getmaxy();i+=50)
				{
					line(getmaxx()/2-1,i,getmaxx()/2+1,i);
					sprintf(a,"%d",getmaxy()/2-i);
					outtextxy(getmaxx()/2-3,i-3,a);
				}
				settextjustify(LEFT_TEXT,TOP_TEXT);
				line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
				line(getmaxx()/2,1,getmaxx()/2,getmaxy());
				g.plotgraph(ch);
				getch();
				break;
			case 5: cleardevice();
				for(i=44;i<=getmaxx();i+=50)
				{
					line(i,getmaxy()/2-1,i,getmaxy()/2+1);
					sprintf(a,"%d",i-getmaxx()/2);
					outtextxy(i-10,getmaxy()/2+5,a);
				}
				settextjustify(RIGHT_TEXT,TOP_TEXT);
				for(i=14;i<=getmaxy();i+=50)
				{
					line(getmaxx()/2-1,i,getmaxx()/2+1,i);
					sprintf(a,"%d",getmaxy()/2-i);
					outtextxy(getmaxx()/2-3,i-3,a);
				}
				settextjustify(LEFT_TEXT,TOP_TEXT);
				line(1,getmaxy()/2,getmaxx(),getmaxy()/2);
				line(getmaxx()/2,1,getmaxx()/2,getmaxy());
				g.plotgraph(ch);
				getch();
				break;
			case 6: cleardevice();
				f.open("graph.dat",ios::binary|ios::in);
				if(f)
				{
				f.seekg(0);
				int n=1;
				while(!f.eof())
				{
					f.getline(c,50,'\n');
					outtextxy(1,15*n,c);
					n++;
				}
				getch();
				f.close();
				}
				else
				{
					settextstyle(0,0,2);
					outtextxy(190,100,"NO SAVED EQUATIONS");
					getch();
					break;
				}
				break;
			case 7: cleardevice();
				f.open("graph.dat",ios::binary|ios::in);
				if(f)
				{
					remove("graph.dat");
					settextstyle(0,0,2);
					outtextxy(225,100,"DATA CLEARED");
					getch();
				}
				else
				{
					settextstyle(0,0,2);
					outtextxy(200,100,"NO SAVED DATA");
					getch();
					break;
				}
				f.close();
				break;
			case 8: cleardevice();
				settextstyle(4,0,4);
				outtextxy(65,1,"THE GRAPHING CALCULATOR");
				exit(0);
				break;
			default: cleardevice();
				settextstyle(0,0,2);
				outtextxy(85,200,"SELECT FROM THE GIVEN CHOICES");
				getch();
		}cleardevice();
		setcolor(DARKGRAY);
		if(ch>=1 && ch<6)
		{
			outtextxy(200,200,"Your Equation has been saved.");
			getch();
		}
	}while(ch!=8);
	closegraph();
}