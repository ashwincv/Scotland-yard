#include<graphics.h>
#include<math.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include<dos.h>

int busx[]={490,500,450,445,398,340,250,185,110,65,130,135, 80, 60, 75,100,180,279,435,365,300,275,188,237,200};
int busy[]={190,125,100,150,102,55 ,60, 40,  60,85, 95,175,230,325,375,323,350,361,346,270,255,190,132,235,270};

int trainx[]={130,140,147,200,300,435,490,440,350,280,200,100,62,47,33 ,31 ,26 };
int trainy[]={95 ,150,220,270,282,346,190,205,147,70 ,58 ,26 ,31,90,180,250,344};



void highlight(int x,int y,int size)     //function for highlighting

{
setcolor(3);
circle(x,y,size+1);
circle(x,y,size+3);
}

void nolight(int x,int y,int size)       //function for removing highlight
{
setcolor(0);
circle(x,y,size+1);
circle(x,y,size+3);
}
void color(int x,int y,int r)
{   int p,q;
int v;
int x3=x+(2*r);
int x4=x-(2*r);
int y3=y+(2*r);
int y4=y-(2*r);
for( p=x4;p<=x3;p++)
for( q=y4;q<=y3;q++)
{
v=getpixel(p,q);
if(v==14)
putpixel(p,q,3);
}

}
void currentstop(int x,int y,int size)    //highlights current station
{setcolor(6);
 circle(x,y,size+1);
circle(x,y,size+3);
}


void busmoving()           //function to toggle between bus stops
{
  randomize();
  int k=random(25);
  cout<<k;
  while(!kbhit())
   {
	 for(int i=0;i<=25;i++)
	  {
	 if(busx[k]==busx[i]&&busy[k]==busy[i])
	    {
	     currentstop(busx[i],busy[i],7);
	     if(k!=25)
	      {
		 highlight(busx[i+1],busy[i+1],7);
		delay(613);
		nolight(busx[i+1],busy[i+1],7);
	       }
	if(k!=0)
    {  highlight(busx[i-1],busy[i-1],7);
		delay(613);
		nolight(busx[i-1],busy[i-1],7);}
	      }
	  }


	  }
	 }

void trainmoving()        //function to toggle between train stations
{
randomize();
int k=random(18);
cout<<k;
while(!kbhit())
{
   for(int i=0;i<=18;i++)
   if(trainx[k]==trainx[i]&&trainy[k]==trainy[i])
    {
     currentstop(trainx[i],trainy[i],7);
     if(k!=18)
      {
      highlight(trainx[i+1],trainy[i+1],7);
      delay(613);
      nolight(trainx[i+1],trainy[i+1],7);
      }
    if(k!=0)
       {
	highlight(trainx[i-1],trainy[i-1],7);
	delay(613);
	nolight(trainx[i-1],trainy[i-1],7);
	}
    }
 }
 }




 float distance(int x,int y,int x1,int y1)
 {

 float dis;
 int a=pow(x1-x,2);
 int b=pow(y1-y,2);

 dis=pow(a+b,0.5);

 return dis;
 }

void map()
{
int i,j;//x=20,y=20;
ellipse(530,360,0,360,35,35);
ellipse(530,360,0,360,36,36);            //Compass
line(530,340,530,380);
line(510,360,550,360);
for(i=0;i<6;i++)
{line(530,340,527+i,343);
 line(530,380,527+i,377);
 line(510,360,513,363-i);
 line(550,360,547,363-i);
 }


settextstyle(8,0,1);
outtextxy(525,317,"E");
outtextxy(525,375,"W");
outtextxy(497,345,"N");
outtextxy(553,345,"S");
outtextxy(255,400,"vennai 600028");
settextstyle(0,0,1);
outtextxy(480,400,"Illustrations");
outtextxy(520,410," by-");
outtextxy(520,420,"VSR");

//Sea
setcolor(1);
line(0,0,20,15);
line(20,15,100,15);
line(100,15,100,0);
line(150,0,200,25);
line(200,25,500,55);
line(500,55,640,55);
line(640,55,640,0);
setcolor(9);
setfillstyle(1,9);
floodfill(15,5,1);
floodfill(500,30,1);

//Waters

//zone III
setcolor(1);
line(410,70,410,170);
line(425,60,425,160);
line(410,70,395,65);
line(425,60,410,57);
line(410,57,410,60);
line(410,60,392,53);
line(392,53,380,105);
line(395,65,387,105);
line(387,105,380,105);
line(410,170,425,160);

setfillstyle(1,9);
floodfill(420,100,1);
setcolor(9);
bar(417,60,419,40);
for(i=0;i<2;i++)
{
line(412,167+i,365,200+i);
line(365+i,200,360+i,220);
line(360,220+i,390,240+i);
line(390+i,240,393+i,260);
line(393,260+i,385,275+i);
line(385+i,275,405+i,290);
line(405+i,290,405+i,330);
line(405,330+i,360,330+i);
line(360+i,330,360+i,380);
}

//zone II
for(i=0;i<2;i++)
{
 line(180+i,45,185+i,15);
 line(180,45+i,150,45+i);
 line(185+i,40,130+i,100);
 line(150+i,45,125+i,90);
 line(130,130+i,150,130+i);
 line(150+i,130,160+i,120);
 line(160+i,120,200+i,160);
 line(200,160+i,170,170+i);
 line(170+i,170,162+i,185);
 line(162+i,185,185+i,265);
 line(185+i,265,135+i,305);
 line(135+i,305,135+i,380);
}

//zone I
for(i=0;i<2;i++)
{
line(50+i,130,50+i,190);
line(50+i,190,120+i,230);
line(120+i,230,120+i,270);
line(120+i,270,100+i,300);
}

//Trains
setcolor(4);
line(20,380,30,150);
line(21,380,31,150);  //train- from Villivakkam to Vyasarpadi via Perambur
line(30,380,40,150);
line(31,380,41,150);
setcolor(15);
setfillstyle(1,4);
setcolor(4);
line(470,371,580,300); //Station-Guindy
line(470,379,580,310); //Station-Guindy
line(40,150,70,100);  //train-Basin Bridge
line(41,150,71,100);
line(45,120,65,90);
line(46,120,66,90);
setcolor(15);

setcolor(4);
line(30,150,50,50);
line(31,150,51,50);   //train-Washermenpet and Royapuram
line(45,120,60,50);
line(46,120,61,50);
line(50,50,61,25);
line(50,51,61,26);
bar(61,23,120,24);           //train-Beach
arc(122,28,10,100,5);        //train-to Fort
bar(128,28,129,70);

line(129,70,135,90);            //train-Fort to Chepauk via Central
line(130,70,136,90);
line(135,90,155,250);
line(136,90,156,250);
arc(163,250,170,280,6);   //Train-Chepauk to Saidapet
arc(155,265,170,280,6);
line(156,271,380,300);
line(156,272,380,301);
line(165,255,382,285);
line(165,256,382,286);
line(380,290,470,370);
line(380,291,470,371);
line(380,300,470,380);
line(380,301,470,381);
line(65,85,147,85);
line(65,86,147,86);
line(70,100,147,100);//train-basin bridge to Central
line(70,101,147,101);
line(147,85,180,50);
line(147,86,180,51);
line(147,100,180,65);
line(147,101,180,66);
arc(185,55,70,120,7);
arc(185,70,70,120,7);
line(185,63,270,70);
line(185,64,270,71);
line(185,48,270,55);
line(185,49,270,56);
arc(271,65,30,90,9);
arc(271,80,30,90,9);
line(278,60,385,180);
line(278,61,385,181);
line(278,75,385,200);
line(278,76,385,201);
arc(393,195,210,280,9);
arc(393,175,210,280,9);
line(393,184,450,198);
line(393,185,450,199);
line(393,204,450,215);
line(393,205,450,216);
line(450,215,490,200);
line(450,216,490,201);
arc(490,209,50,90,9);
line(496,203,518,215);
line(496,204,518,216);
line(496,190,525,206);
line(496,191,525,207);
bar(518,217,518,237);
bar(525,206,526,237);
arc(523,237,170,240,5);
arc(532,237,170,230,5);
line(526,240,580,300);
line(526,241,580,301);
line(520,242,575,305);
line(520,243,575,306);

//Main Roads
setcolor(8);
for(i=0;i<26;i++)       //Road to V Nagar
line(10,190-i,70,95-i);
setfillstyle(1,8);
fillellipse(67,33,7,7);
fillellipse(121,30,4,4);
bar(60,85,70,30);       //road from V.Nagar to Royapuram
bar(70,26,120,39);      //road from Royapuram to Beach
bar(118,29,126,70);     //road to High Court
for(i=0;i<9;i++)
{
 line(118+i,70,123+i,85);   //road-Curve near Fort
 line(123+i,85,140+i,250);  //road-Fort to Chepauk via Central
 line(121,30+i,350,53+i);   //Beach Road Stretch
 line(350,53+i,402,100+i);  //beach Road to Greenways Road
}
bar(140,250,149,380); //road-Chepauk to End of map
bar(149,380,80,370);
for(i=0;i<11;i++)   //Anna Nagar West
line(80,370+i,65,380);
for(i=0;i<10;i++)
line(149,370+i,190,340+i); //Anna Nagar West to Koyambedu CMBT
bar(190,340,300,350);
for(i=0;i<10;i++)          //Koyambedu to K.K.Nagar
line(300,340+i,310,350+i);
bar(310,350,445,359);//K.K.Nagar to Guindy
for(i=0;i<10;i++)
line(408+i,288,455+i,380);
bar(395,100,402,145); //Greenways Road
bar(395,145,500,155); //Thiru.Vi.Ka Bridge to Adyar
bar(65,90,130,95);//road-Basin Bridge to Central
bar(130,88,150,97);//road-Central to Chrompet
for(i=0;i<10;i++)
line(150,88+i,240,180+i);//road-Chrompet to Mahathma Gandhi Road begining
bar(233,180,242,280); //M.G.Road to Kodambakkam
for(i=0;i<10;i++)
{line(233+i,279,285+i,380);  //road-Kodambakkam to Vadapalani
line(240,180+i,300,188+i);   //Anna Salai from M.G.Road
line(300,188+i,380,280+i);   //Anna Salai upto Saidapet
}
bar(380,280,436,288);        //Saidapet to Sardar Patel Road
for(i=0;i<8;i++)
{line(425+i,320,440+i,230);   //Sardar Patel Road
 line(430,310+i,480,320+i);   //Sardar Patel Road to Velachery raod
}
for(i=0;i<10;i++)
{
line(450,350+i,520,285+i);        //Guindy to Velachery Road
line(520,285+i,580,300+i);        //Velachery Road to Velachery St.
}
bar(440,230,447,150);        //Kasturbai Nagar to Adyar
for(i=0;i<18;i++)
{line(440,200+i,520,160+i);  //O.M.R
 line(520,160+i,580,180+i);
}
bar(490,145,500,120);        //L.B.Road to Thiruvanmiyur
bar(500,120,580,130);

bar(460,150,463,100);        //near Besant Nagar
bar(460,100,450,103);
bar(450,101,440,102);
bar(440,102,441,145);
bar(440,120,460,121);       //Adyar
bar(450,103,451,145);
bar(460,115,485,116);
bar(485,116,486,180);
bar(486,116,510,115);      //near Thiruvanmiyur
bar(510,100,511,130);
bar(490,100,550,101);
bar(550,101,551,120);
line(486,116,490,100);
line(550,101,510,116);

bar(510,170,512,260);     //taramani road
for(i=0;i<4;i++)
line(510+i,260,550+i,300);  //connecting vijayanagar
bar(550,300,510,302);

for(i=0;i<5;i++)
line(500,150+i,520,160+i);   //L.B.Road to O.M.R
bar(493,155,497,175);        //Tidel Park to Thiruvanmiyur

//small roads

//Zone I
bar(60,60,118,61);
bar(60,70,118,72);    //roads above central near beach
bar(80,40,81,90);
bar(100,40,101,90);

bar(100,90,103,119); //near Basin Bridge to Central
bar(70,117,130,119);//Raja Muthiah Road, near Central
for(i=0;i<3;i++)
line(69+i,118,55+i,105);//connecting central to rajamuthiah
for(i=0;i<4;i++)
line(110+i,117,120+i,220);//From Raja Muthiah Road down
bar(120,220,125,222);
bar(130,160,125,162);
bar(125,160,127,300); //Dr.Al..... ||l to Egmore chetpet track
for(i=0;i<3;i++)
line(125+i,300,120+i,310);
bar(120,310,123,380);
for(i=0;i<3;i++)
line(120+i,220,105+i,230);
bar(105,230,80,233);     //to Ayanavaram
for(i=0;i<3;i++)
line(80+i,232,50+i,350);//Ayanavaram to ICF
bar(55,330,65,332);     //from ICF right
bar(145,260,110,262);
for(i=0;i<3;i++)
line(110+i,262,50+i,350); //Near Villivakkam
for(i=0;i<3;i++)
line(50+i,350,55+i,380);  //Villivakkam to end of map
bar(35,345,36,370);
bar(36,370,54,371);
for(i=0;i<2;i++)
line(36+i,345,50+i,355);
for(i=0;i<3;i++)
line(35+i,250,60+i,180); //Perambur High road
bar(10,180,135,183);
bar(80,232,81,165);      //St.road from ayanavaram up
bar(55,200,140,202);     //||l to vyasarpadi egmore road
for(i=0;i<2;i++)
line(95+i,117,60+i,220);
line(45,220,80,220);
for(i=0;i<3;i++)
{
line(60+i,140,80+i,120);    //road connecting the roads given below
line(73+i,140,80+i,120);
}
bar(60,180,61,140);     //from Perambur high road up
bar(73,180,74,140);     //||l to above road
bar(120,310,80,312);    //||l to annagar bus stand
bar(80,312,81,380);
bar(148,325,68,327);    //thru anna nagar bus stand

//Zone II

for(i=0;i<4;i++)
{line(135+i,160,178+i,120);   //from egmore right
line(145+i,135,175+i,165);
line(175+i,165,200+i,142);
}
bar(175,168,220,169);
bar(145,135,135,136);
bar(145,135,146,100);
bar(174,165,176,210);
bar(147,222,240,224);//from Chetpet
for(i=0;i<3;i++)
{line(174+i,210,195+i,265);
 line(195,265+i,150,300+i);
 }
for(i=0;i<2;i++)
{
line(150,277+i,245,290+i);
line(162,290+i,270,310+i);     //lower zone II
line(270,310+i,300,345+i);
}
bar(162,280,163,225);          //bet. chetpet and nungambakkam
for(i=0;i<2;i++)
{line(162+i,225,155+i,180);  //near chetpet ||l to water
 line(155+i,180,170+i,160);
 }
bar(150,180,151,150);       //near egmore ||l to train track
bar(155,180,140,182);       //_|_r to above
for(i=0;i<2;i++)
line(135,135+i,165,165+i);  //from egmore station down

//Zone III
for(i=0;i<3;i++)
{
line(180,225+i,280,145+i);//M.G.Road
line(280+i,145,295+i,47); //from M.G.road towards light house
line(225+i,165,250+i,50); //above M.G Road to V.House
line(325+i,50,280+i,240); //Luz road
line(240,250+i,285,255+i);//North Usman Road
line(240,220+i,300,225+i);//Thirumalai Pillai road
line(285,255+i,350,252+i);//South Usman road
}
bar(285,255,287,240);     //near T.Nagar circular road(right)
bar(285,240,278,242);     //" "    " "     " "      " " (top)
bar(278,242,279,255);     //" "    " "     "  "      " " (left)
bar(300,225,302,255);     //_|_r to south usman road from thirumalai pillai
for(i=0;i<2;i++)
{line(175+i,115,190+i,40); //near Chepauk to Beach Road
 line(130+i,75,150+i,40);  //from Fort to Beach Road
 line(130,70+i,160,100+i); //from Fort to Chrompet
 line(150+i,100,185+i,40); //from Chrompet to Anna Square
}

bar(180,120,190,122);
bar(202,129,235,131);    //Below Chepauk
for(i=0;i<3;i++)
line(190+i,121,200+i,130);
bar(225,48,226,165);    //_|_r below from Triplicane station
for(i=0;i<3;i++)
{line(235,131+i,290,100+i);
 line(290,100+i,400,153+i); //Thru LUZ towards Thiru.V.Ka Bridge
}
for(i=0;i<3;i++)
{
line(235,131+i,280,135+i);     //TTK Road
line(280,135+i,305,145+i);
line(305,145+i,352,175+i);
line(345,190+i,445,240+i); //Gandhi Mandapam Road
}

for(i=0;i<3;i++)
{
line(335+i,220,380+i,82);    //thru Mandaveli to Foreshore estate
line(335,220+i,300,225+i);   //connecting above road to T.Nagar
line(300+i,225,285+i,240);   //connecting circulat road to T.Nagar
line(278+i,240,240+i,185);
}
for(i=0;i<3;i++)
{line(287+i,255,280+i,340);
line(303+i,302,300+i,340);
}
bar(285,300,305,302);


//Stations
setcolor(15);
setfillstyle(1,4);
fillellipse(130,95,10,10);  //Station-Central
fillellipse(140,150,6,6); //Station-Egmore
fillellipse(147,220,6,6); //Station-Chetpet
fillellipse(200,270,10,10); //Station-Nungambakkam
fillellipse(300,282,6,6); //Station-Mambalam
fillellipse(435,346,10,10); //Station-Guindy
fillellipse(490,190,10,10); //Station-Tidel Park
fillellipse(440,205,6,6); //Station-Kasturibai Nagar
fillellipse(350,147,6,6); //Station-Mandaveli
fillellipse(280,70,6,6);  //Station-Light House
fillellipse(200,58,6,6);  //Station-Chepauk
fillellipse(130,95,10,10);  //Station-Central
fillellipse(100,26,6,6);  //Station-Beach
fillellipse(62,31,6,6);   //Station-Royapuram
fillellipse(47,90,6,6);   //Station-Washermenpet
fillellipse(33,180,6,6);  //Station-Vyasarpadi
fillellipse(31,250,6,6);  //Station-Perambur
fillellipse(26,344,6,6);  //Station-Villivakkam

setcolor(15);
setfillstyle(1,1);

//Bus Stops
fillellipse(490,190,7,7); //Station-Tidel Park//
fillellipse(500,125,7,7);//Thiruvanmiyur
fillellipse(450,100,7,7);//Besant Nagar
fillellipse(445,150,7,7);//Adyar
fillellipse(398,102,7,7);//Adyar
fillellipse(340,55,7,7);//Adyar
fillellipse(250,60,7,7);//V House
fillellipse(185,40,7,7);//Anna Square
fillellipse(110,60,7,7);//Broadway High Court
fillellipse(65,85,7,7);//V Nagar
fillellipse(130,95,7,7);//Central
fillellipse(135,175,7,7);//egmore
fillellipse(80,230,7,7);//Ayanavaram
fillellipse(60,325,7,7);//ICF
fillellipse(75,375,7,7);//Anna Nagar west
fillellipse(100,323,7,7);//Anna Nagar
fillellipse(180,350,7,7);//koyambedu CMBT//
fillellipse(279,361,7,7);//vadapalani//
fillellipse(435,346,7,7); //Station-Guindy//
fillellipse(365,270,7,7);//Saidapet
fillellipse(300,255,7,7);//T Nagar
fillellipse(275,190,7,7);//second lane beach/
fillellipse(188,132,7,7);//first lane beach///
fillellipse(237,235,7,7);//kodambakam//
fillellipse(200,270,7,7); //Station-Nungambakkam


//AUTO//
setfillstyle(1,14);
setcolor(14);

//auto in bustop//
fillellipse(75,375,2,2);//Anna Nagar west
fillellipse(60,325,2,2);//ICF
fillellipse(100,323,2,2);//Anna Nagar
fillellipse(80,230,2,2);//Ayanavaram
fillellipse(65,85,2,2);//V Nagar
fillellipse(110,60,2,2);//Broadway High Court
fillellipse(130,95,2,2);//Central
fillellipse(185,40,2,2);//Anna Square
fillellipse(250,60,2,2);//V House
fillellipse(300,255,2,2);//T Nagar
fillellipse(365,270,2,2);//Saidapet
fillellipse(445,150,2,2);//Adyar
fillellipse(450,100,2,2);//Besant Nagar
fillellipse(500,125,2,2);//Thiruvanmiyur
fillellipse(550,295,2,2);//Vijayanagar
fillellipse(180,350,2,2);//koyambedu CMBT//
fillellipse(188,132,2,2);//first lane beach//
fillellipse(275,190,2,2);//second lane beach//
fillellipse(237,235,2,2);//kodambakam//
fillellipse(490,190,2,2); //Station-Tidel Park//
fillellipse(435,346,2,2); //Station-Guindy//
fillellipse(200,270,2,2); //Station-Nungambakkam
fillellipse(398,102,2,2);//Adyarannex
fillellipse(340,55,2,2);//Adyar  annex
fillellipse(135,175,2,2);//egmore
fillellipse(279,361,2,2);//vadapalani//
//auto in railway//
fillellipse(26,344,2,2);  //Station-Villivakkam
fillellipse(33,180,2,2);  //Station-Vyasarpadi
fillellipse(31,250,2,2);  //Station-Perambur
fillellipse(75,93,2,2);   //Station-Basin Bridge
fillellipse(47,90,2,2);   //Station-Washermenpet
fillellipse(62,31,2,2);   //Station-Royapuram
fillellipse(100,26,2,2);  //Station-Beach
fillellipse(130,95,2,2);  //Station-Central
fillellipse(140,150,2,2); //Station-Egmore
fillellipse(147,220,2,2); //Station-Chetpet
fillellipse(200,270,2,2); //Station-Nungambakkam
fillellipse(300,282,2,2); //Station-Mambalam
//fillellipse(375,292,2,2); //Station-Saidapet
fillellipse(435,346,2,2); //Station-Guindy
fillellipse(440,205,2,2); //Station-Kasturibai Nagar
fillellipse(490,190,2,2); //Station-Tidel Park
fillellipse(200,58,2,2);  //Station-Chepauk
fillellipse(280,70,2,2);  //Station-Light House
fillellipse(350,147,2,2); //Station-Mandaveli

//normal auto//
  fillellipse(122,375,3,3);//Anna Nagar west1
  fillellipse(144,375,3,3);//Anna Nagar west
   fillellipse(144,325,3,3);//Anna Nagar west up
    fillellipse(144,300,3,3);//Anna Nagar west
     fillellipse(140,200,3,3);//Anna Nagar west

     fillellipse(273,345,3,3);//vadapalani
     fillellipse(354,355,3,3);//Anna Nagar west
    fillellipse(480,323,3,3); //Station-Guind
    fillellipse(428,312,3,3);//top left of triangle near guindy
    fillellipse(433,285,3,3);
     fillellipse(412,285,3,3);
    fillellipse(442,240,3,3);
	 fillellipse(252,307,3,3);//road to vadapalani
      fillellipse(269,309,3,3);//road to vadapalani
      fillellipse(282,323,3,3);//road to vadapalani
	  fillellipse(298,345,3,3);//vadapalani
      fillellipse(305,302,3,3);//vadapalani
      fillellipse(285,302,3,3);//vadapalani
     fillellipse(275,255,3,3);//above vadapalani
    fillellipse(280,240,3,3);/*+++++++++++++++++++++++++test*////////
    fillellipse(270,224,3,3);
    fillellipse(285,224,3,3);
    fillellipse(300,226,3,3);
    fillellipse(327,224,3,3);
    fillellipse(187,224,3,3);//above nungambakkam all three near river
    fillellipse(189,296,3,3);
     fillellipse(175,282,3,3);
     fillellipse(210,345,3,3);//koyambedu CMBT//
      fillellipse(240,345,3,3);//koyambedu CMBT//
	fillellipse(334,355,3,3);//Anna Nagar west
	fillellipse(394,355,3,3);//Anna Nagar west
	fillellipse(390,284,3,3);//Anna Nagar west
     fillellipse(230,303,3,3);
     fillellipse(160,295,3,3);
     fillellipse(122,327,3,3);
     fillellipse(82,327,3,3);
   fillellipse(122,310,3,3);
   fillellipse(82,310,3,3);
     fillellipse(122,350,3,3);
   fillellipse(82,350,3,3);
    fillellipse(52,350,3,3);
    fillellipse(52,370,3,3);
   fillellipse(37,370,3,3);
    fillellipse(127,280,3,3);
   fillellipse(97,280,3,3);
    fillellipse(67,288,3,3);
   fillellipse(75,260,3,3);
    fillellipse(116,260,3,3);
    fillellipse(146,260,3,3);
   fillellipse(146,280,3,3);
   fillellipse(143,240,3,3);
   fillellipse(145,350,3,3);

   fillellipse(125,240,3,3);
   fillellipse(102,230,3,3);
   fillellipse(125,220,3,3);
     fillellipse(55,202,3,3);
    fillellipse(80,202,3,3);
    fillellipse(105,202,3,3);
    fillellipse(125,202,3,3);
      fillellipse(55,180,3,3);
    fillellipse(80,180,3,3);
    fillellipse(105,180,3,3);
    fillellipse(49,118,3,3);
    fillellipse(80,118,3,3);
    fillellipse(105,118,3,3);
	fillellipse(130,118,3,3);
     fillellipse(80,72,3,3);
    fillellipse(102,92,3,3);
    fillellipse(65,57,3,3);
	 fillellipse(100,72,3,3);
      fillellipse(125,72,3,3);
      fillellipse(122,35,3,3);
     fillellipse(152,37,3,3);
   fillellipse(222,44,3,3);
   fillellipse(252,47,3,3);
      fillellipse(280,51,3,3);
     fillellipse(310,53,3,3);
    fillellipse(252,135,3,3);
   fillellipse(280,139,3,3);
   fillellipse(310,147,3,3);
    fillellipse(222,132,3,3);
    fillellipse(210,152,3,3);
    fillellipse(225,167,3,3);
   fillellipse(240,185,3,3);
   fillellipse(200,210,3,3);
   fillellipse(237,210,3,3);
   fillellipse(237,260,3,3);
   }




 void choose()
 {

//auto in bustop//
fillellipse(75,375,2,2);//Anna Nagar west
fillellipse(60,325,2,2);//ICF
fillellipse(100,323,2,2);//Anna Nagar
fillellipse(80,230,2,2);//Ayanavaram
fillellipse(65,85,2,2);//V Nagar
fillellipse(110,60,2,2);//Broadway High Court
fillellipse(130,95,2,2);//Central
fillellipse(185,40,2,2);//Anna Square
fillellipse(250,60,2,2);//V House
fillellipse(300,255,2,2);//T Nagar
fillellipse(365,270,2,2);//Saidapet
fillellipse(445,150,2,2);//Adyar
fillellipse(450,100,2,2);//Besant Nagar
fillellipse(500,125,2,2);//Thiruvanmiyur
fillellipse(550,295,2,2);//Vijayanagar
fillellipse(180,350,2,2);//koyambedu CMBT//
fillellipse(188,132,2,2);//first lane beach//
fillellipse(275,190,2,2);//second lane beach//
fillellipse(237,235,2,2);//kodambakam//
fillellipse(490,190,2,2); //Station-Tidel Park//
fillellipse(435,346,2,2); //Station-Guindy//
fillellipse(200,270,2,2); //Station-Nungambakkam
fillellipse(398,102,2,2);//Adyarannex
fillellipse(340,55,2,2);//Adyar  annex
fillellipse(135,175,2,2);//egmore
fillellipse(279,361,2,2);//vadapalani//
//auto in railway//
fillellipse(26,344,2,2);  //Station-Villivakkam
fillellipse(33,180,2,2);  //Station-Vyasarpadi
fillellipse(31,250,2,2);  //Station-Perambur
fillellipse(75,93,2,2);   //Station-Basin Bridge
fillellipse(47,90,2,2);   //Station-Washermenpet
fillellipse(62,31,2,2);   //Station-Royapuram
fillellipse(100,26,2,2);  //Station-Beach
fillellipse(130,95,2,2);  //Station-Central
fillellipse(140,150,2,2); //Station-Egmore
fillellipse(147,220,2,2); //Station-Chetpet
fillellipse(200,270,2,2); //Station-Nungambakkam
fillellipse(300,282,2,2); //Station-Mambalam
//fillellipse(375,292,2,2); //Station-Saidapet
fillellipse(435,346,2,2); //Station-Guindy
fillellipse(440,205,2,2); //Station-Kasturibai Nagar
fillellipse(490,190,2,2); //Station-Tidel Park
fillellipse(200,58,2,2);  //Station-Chepauk
fillellipse(280,70,2,2);  //Station-Light House
fillellipse(350,147,2,2); //Station-Mandaveli

//normal auto//
  fillellipse(122,375,3,3);//Anna Nagar west1
  fillellipse(144,375,3,3);//Anna Nagar west
   fillellipse(144,325,3,3);//Anna Nagar west up
    fillellipse(144,300,3,3);//Anna Nagar west
     fillellipse(140,200,3,3);//Anna Nagar
     fillellipse(273,345,3,3);//vadapalani
     fillellipse(354,355,3,3);//Anna Nagar west
    fillellipse(480,323,3,3); //Station-Guind
    fillellipse(428,312,3,3);//top left of triangle near guindy
    fillellipse(433,285,3,3);
     fillellipse(412,285,3,3);
    fillellipse(442,240,3,3);
	 fillellipse(252,307,3,3);//road to vadapalani
      fillellipse(269,309,3,3);//road to vadapalani
      fillellipse(282,323,3,3);//road to vadapalani
	  fillellipse(298,345,3,3);//vadapalani
      fillellipse(305,302,3,3);//vadapalani
      fillellipse(285,302,3,3);//vadapalani
     fillellipse(275,255,3,3);//above vadapalani
    fillellipse(280,240,3,3);
    fillellipse(270,224,3,3);
    fillellipse(285,224,3,3);////////////////////////test
    fillellipse(300,226,3,3);
    fillellipse(327,224,3,3);
    fillellipse(187,224,3,3);//above nungambakkam all three near river
    fillellipse(189,296,3,3);
     fillellipse(175,282,3,3);
     fillellipse(210,345,53,53);//koyambedu CMBT//
      fillellipse(240,345,3,3);//koyambedu CMBT//
	fillellipse(334,355,3,3);//Anna Nagar west
	fillellipse(394,355,3,3);//Anna Nagar west
	fillellipse(390,284,3,3);//Anna Nagar west
     fillellipse(230,303,3,3);
     fillellipse(160,295,3,3);
     fillellipse(122,327,3,3);
     fillellipse(82,327,3,3);
   fillellipse(122,310,3,3);
   fillellipse(82,310,3,3);
     fillellipse(122,350,3,3);
   fillellipse(82,350,3,3);
    fillellipse(52,350,3,3);
    fillellipse(52,370,3,3);
   fillellipse(37,370,3,3);
    fillellipse(127,280,3,3);
   fillellipse(97,280,3,3);
    fillellipse(67,288,3,3);
   fillellipse(75,260,3,3);
    fillellipse(116,260,3,3);
    fillellipse(146,260,3,3);
   fillellipse(146,280,7,7);
   fillellipse(143,240,7,7);
   fillellipse(145,350,7,7);

   fillellipse(125,240,3,3);
   fillellipse(102,230,3,3);
   fillellipse(125,220,3,3);
     fillellipse(55,202,3,3);
    fillellipse(80,202,3,3);
    fillellipse(105,202,3,3);
    fillellipse(125,202,3,3);
      fillellipse(55,180,3,3);
    fillellipse(80,180,3,3);
    fillellipse(105,180,3,3);
    fillellipse(49,118,3,3);
    fillellipse(80,118,3,3);
    fillellipse(105,118,3,3);
	fillellipse(130,118,3,3);
     fillellipse(80,72,3,3);
    fillellipse(102,92,3,3);
    fillellipse(65,57,3,3);
	 fillellipse(100,72,3,3);
      fillellipse(125,72,3,3);
      fillellipse(122,35,3,3);
     fillellipse(152,37,3,3);
   fillellipse(222,44,3,3);
   fillellipse(252,47,3,3);
      fillellipse(280,51,3,3);
     fillellipse(310,53,3,3);
    fillellipse(252,135,3,3);
   fillellipse(280,139,3,3);
   fillellipse(310,147,3,3);
    fillellipse(222,132,3,3);
    fillellipse(210,152,3,3);
    fillellipse(225,167,3,3);
   fillellipse(240,185,3,3);
   fillellipse(200,210,3,3);
   fillellipse(237,210,3,3);
   fillellipse(237,260,3,3);



  }

   void main()
   {
   clrscr();
int gdriver=DETECT,gmode;
initgraph(&gdriver, &gmode, "");



int i,j,k,x;
/* cout<<"bus or train";
 cin>>x;
 cleardevice();
*/ map();

/* switch(x)
 {case 1:busmoving(); break;
 case 2:trainmoving(); break;
 }
*/
int v,x2,y2;
int r11=20;
int a=144,b=375;
setcolor(9);
circle(a,b,r11);

  for(int x11=(a-r11);x11<=(a+r11);x11++)
  for(int y11=(b-r11);y11<=(b+r11);y11++)
   if(distance(a,b,x11,y11)<=r11&&distance(a,b,x11,y11)>4 )
  {

   v=getpixel(x11,y11);
   if(v==0 || v==7 || v==8)
     delay(5);

   if(v==14)
     {
     setfillstyle(1,4);
    color(x11,y11,3);
     //fillellipse(x11,y11,3,3);
    // delay(3);
     // break
	}
	  }
   // break;
    getch();

}

