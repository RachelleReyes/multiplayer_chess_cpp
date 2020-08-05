#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>
#include <math.h>

void inicializa()
{
  int gm,gd = DETECT;
  initgraph(&gd,&gm,"C:\\turboc3\\bgi");
}

void mouse(int &a,int &b,int &c,int &d )
{
 union REGS inregs, outregs;

 inregs.x.ax  =  a;
 inregs.x.bx  =  b;
 inregs.x.cx  =  c;
 inregs.x.dx  =  d;
 int86( '\x33' , &inregs, &outregs );
 a = outregs.x.ax ;
 b = outregs.x.bx ;
 c = outregs.x.cx ;
 d = outregs.x.dx ;
}

void activa()
{  int a=0,b,c,d;
   mouse(a,b,c,d);
}
void pon()
{  int a=1,b,c,d;
   mouse(a,b,c,d);
}
void quita()
{  int a=2,b,c,d;
   mouse(a,b,c,d);
}
void mcoord ( int &a, int &b, int &x, int &y )
{
   mouse(a,b,x,y);
}
void mgoto( int x, int y )
{  int a=4,b;
   mouse(a,b,x,y);
}
void columnas ( int low, int hi )
{  int a=7,b;
   mouse(a,b,low,hi);
}
void renglones ( int low, int hi )
{  int a=8,b;
   mouse(a,b,low,hi);
}

void box(int x1,int y1,int x2,int y2, int relleno, int color)
{
 int poly[8];
 poly[0] =x1;
 poly[1] =y1;
 poly[2] =x2;
 poly[3] =y1;
 poly[4] =x2;
 poly[5] =y2;
 poly[6] =x1;
 poly[7] =y2;
 setfillstyle(relleno, color);
 fillpoly(4,poly);
}

void asigna(int M[8][8])
{
  int i,j;
  for(i=0;i<8;i++)
  for(j=0;j<8;j++)
  {
   M[i][j]=0;
   if((i+j+1)%2==0) M[i][j]=1;
  }
}

void pintamatriz(int M[8][8])
{
 int i,j;
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
 {

	if(M[i][j]==1)
	{
	 box(160+(40*j),100+(40*i),200+(40*j),140+(40*i),1,BLACK);

	}
	if(M[i][j]==0)
	{
	 box(160+(40*j),100+(40*i),200+(40*j),140+(40*i),1,WHITE);
	}
 }
}

void pintamatrizreglas(int M[8][8],int x, int y)
{
 int i,j;
 for(i=0;i<8;i++)
 for(j=0;j<8;j++)
 {
	if(M[i][j]==1)
	{
	 box(x+55+(15*j),y+125+(15*i),x+70+(15*j),y+140+(15*i),1,BLACK);

	}
	if(M[i][j]==0)
	{
	  box(x+55+(15*j),y+125+(15*i),x+70+(15*j),y+140+(15*i),1,WHITE);
	}
 }
}

void torre(int k, int l)
{
	int tor[40];
	tor[0] = 166+40*l;//1X
	tor[1] = 105+40*k;//1Y
	tor[2] = 171+40*l;//2X
	tor[3] = 105+40*k;//2Y
	tor[4] = 171+40*l;//3X
	tor[5] = 110+40*k;//3Y
	tor[6] = 177+40*l;//4X
	tor[7] = 110+40*k;//4Y
	tor[8] = 177+40*l;//5X
	tor[9] = 105+40*k;//5Y
	tor[10] = 183+40*l;//6X
	tor[11] = 105+40*k;//6Y
	tor[12] = 183+40*l;//7X
	tor[13] = 110+40*k;//7Y
	tor[14] = 188+40*l;//8X
	tor[15] = 110+40*k;//8Y
	tor[16] = 188+40*l;//9X
	tor[17] = 105+40*k;//9Y
	tor[18] = 194+40*l;//10X
	tor[19] = 105+40*k;//10Y
	tor[20] = 194+40*l;//11X
	tor[21] = 112+40*k;//11Y
	tor[22] = 188+40*l;//12X
	tor[23] = 115+40*k;//12Y
	tor[24] = 188+40*l;//13X
	tor[25] = 130+40*k;//13Y
	tor[26] = 193+40*l;//14X
	tor[27] = 130+40*k;//14Y
	tor[28] = 195+40*l;//15X
	tor[29] = 135+40*k;//15Y
	tor[30] = 165+40*l;//16X
	tor[31] = 135+40*k;//16Y
	tor[32] = 167+40*l;//17X
	tor[33] = 130+40*k;//17Y
	tor[34] = 172+40*l;//18X
	tor[35] = 130+40*k;//18Y
	tor[36] = 172+40*l;//19X
	tor[37] = 115+40*k;//19Y
	tor[38] = 166+40*l;//20X
	tor[39] = 112+40*k;//20Y
    fillpoly(20,tor);

	setcolor(BLACK);
	line(171+40*l,130+40*k,189+40*l,130+40*k); //abajo
	line(171+40*l,115+40*k,189+40*l,115+40*k); //arriba
	
}

void caballo(int k, int l)
{
	int cab[30];
	cab[0] = 172+40*l;//1X
	cab[1] = 110+40*k;//1Y
	cab[2] = 177+40*l;//2X
	cab[3] = 105+40*k;//2Y
	cab[4] = 185+40*l;//3X
	cab[5] = 105+40*k;//3Y
	cab[6] = 195+40*l;//4X
	cab[7] = 120+40*k;//4Y
	cab[8] = 195+40*l;//5X
	cab[9] = 125+40*k;//5Y
	cab[10] = 190+40*l;//6X
	cab[11] = 125+40*k;//6Y
	cab[12] = 177+40*l;//7X
	cab[13] = 115+40*k;//7Y
	cab[14] = 187+40*l;//8X
	cab[15] = 127+40*k;//8Y
	cab[16] = 187+40*l;//9X
	cab[17] = 127+40*k;//9Y
	cab[18] = 190+40*l;//10X
	cab[19] = 130+40*k;//10Y
	cab[20] = 195+40*l;//11X
	cab[21] = 130+40*k;//11Y
	cab[22] = 195+40*l;//12X
	cab[23] = 135+40*k;//12Y
	cab[24] = 165+40*l;//13X
	cab[25] = 135+40*k;//13Y
	cab[26] = 165+40*l;//14X
	cab[27] = 132+40*k;//14Y
	cab[28] = 172+40*l;//15X
	cab[29] = 127+40*k;//15Y
	fillpoly(15,cab);
	
	setcolor(BLACK);
	line(168+40*l,130+40*k,190+40*l,130+40*k); //abajo
}

void alfil(int k, int l)
{
	int alf[48];
	alf[0] = 179+40*l;//1X
	alf[1] = 103+40*k;//1Y
	alf[2] = 183+40*l;//2X
	alf[3] = 103+40*k;//2Y
	alf[4] = 183+40*l;//3X
	alf[5] = 105+40*k;//3Y
	alf[6] = 188+40*l;//4X
	alf[7] = 108+40*k;//4Y
	alf[8] = 188+40*l;//5X
	alf[9] = 108+40*k;//5Y
	alf[10] = 187+40*l;//6X
	alf[11] = 112+40*k;//6Y
	alf[12] = 187+40*l;//7X
	alf[13] = 117+40*k;//7Y
	alf[14] = 190+40*l;//8X
	alf[15] = 120+40*k;//8Y
	alf[16] = 192+40*l;//9X
	alf[17] = 123+40*k;//9Y
	alf[18] = 192+40*l;//10X
	alf[19] = 126+40*k;//10Y
	alf[20] = 190+40*l;//11X
	alf[21] = 128+40*k;//11Y
	alf[22] = 195+40*l;//12X
	alf[23] = 130+40*k;//12Y
	alf[24] = 195+40*l;//13X
	alf[25] = 135+40*k;//13Y
	alf[26] = 165+40*l;//14X
	alf[27] = 135+40*k;//14Y
	alf[28] = 165+40*l;//15X
	alf[29] = 130+40*k;//15Y
	alf[30] = 170+40*l;//16X
	alf[31] = 128+40*k;//16Y
	alf[32] = 168+40*l;//17X
	alf[33] = 126+40*k;//17Y
	alf[34] = 168+40*l;//18X
	alf[35] = 123+40*k;//18Y
	alf[36] = 170+40*l;//19X
	alf[37] = 120+40*k;//19Y
	alf[38] = 174+40*l;//20X
	alf[39] = 117+40*k;//20Y
	alf[40] = 174+40*l;//21X
	alf[41] = 112+40*k;//21Y
	alf[42] = 173+40*l;//22X
	alf[43] = 108+40*k;//22Y
	alf[44] = 173+40*l;//23X
	alf[45] = 108+40*k;//23Y
	alf[46] = 179+40*l;//24X
	alf[47] = 105+40*k;//24Y
    fillpoly(24,alf);
	
	setcolor(BLACK);
	line(167+40*l,130+40*k,193+40*l,130+40*k); //abajo
}

void reina(int k, int l)
{
	int rea[72];
	rea[0] = 162+40*l;//1X
	rea[1] = 106+40*k;//1Y
	rea[2] = 168+40*l;//2X
	rea[3] = 106+40*k;//2Y
	rea[4] = 168+40*l;//3X
	rea[5] = 110+40*k;//3Y
	rea[6] = 167+40*l;//4X
	rea[7] = 110+40*k;//4Y
	rea[8] = 171+40*l;//5X
	rea[9] = 120+40*k;//5Y
	rea[10] = 174+40*l;//6X
	rea[11] = 120+40*k;//6Y
	rea[12] = 175+40*l;//7X
	rea[13] = 110+40*k;//7Y
	rea[14] = 172+40*l;//8X
	rea[15] = 110+40*k;//8Y
	rea[16] = 172+40*l;//9X
	rea[17] = 106+40*k;//9Y
	rea[18] = 178+40*l;//10X
	rea[19] = 106+40*k;//10Y
	rea[20] = 178+40*l;//11X
	rea[21] = 110+40*k;//11Y
	rea[22] = 176+40*l;//12X
	rea[23] = 110+40*k;//12Y
	rea[24] = 179+40*l;//13X
	rea[25] = 120+40*k;//13Y
	rea[26] = 182+40*l;//14X
	rea[27] = 120+40*k;//14Y
	rea[28] = 184+40*l;//15X
	rea[29] = 110+40*k;//15Y
	rea[30] = 182+40*l;//16X
	rea[31] = 110+40*k;//16Y
	rea[32] = 182+40*l;//17X
	rea[33] = 106+40*k;//17Y
	rea[34] = 188+40*l;//18X
	rea[35] = 106+40*k;//18Y
	rea[36] = 188+40*l;//19X
	rea[37] = 110+40*k;//19Y
	rea[38] = 186+40*l;//20X
	rea[39] = 110+40*k;//20Y
	rea[40] = 188+40*l;//21X
	rea[41] = 120+40*k;//21Y
	rea[42] = 190+40*l;//22X
	rea[43] = 120+40*k;//22Y
	rea[44] = 195+40*l;//23X
	rea[45] = 110+40*k;//23Y
	rea[46] = 192+40*l;//24X
	rea[47] = 110+40*k;//24Y
	rea[48] = 192+40*l;//25X
	rea[49] = 106+40*k;//25Y
	rea[50] = 198+40*l;//26X
	rea[51] = 106+40*k;//26Y
	rea[52] = 198+40*l;//27X
	rea[53] = 110+40*k;//27Y
	rea[54] = 197+40*l;//28X
	rea[55] = 110+40*k;//28Y
	rea[56] = 190+40*l;//29X
	rea[57] = 130+40*k;//29Y
	rea[58] = 195+40*l;//30X
	rea[59] = 130+40*k;//30Y
	rea[60] = 195+40*l;//31X
	rea[61] = 136+40*k;//31Y
	rea[62] = 165+40*l;//32X
	rea[63] = 136+40*k;//32Y
	rea[64] = 165+40*l;//33X
	rea[65] = 130+40*k;//33Y
	rea[66] = 170+40*l;//34X
	rea[67] = 130+40*k;//34Y
	rea[68] = 164+40*l;//35X
	rea[69] = 110+40*k;//35Y
	rea[70] = 162+40*l;//36X
	rea[71] = 110+40*k;//36Y

	fillpoly(36,rea);
	
	setcolor(BLACK);
	line(169+40*l,129+40*k,191+40*l,129+40*k); //abajo
}

void rey(int k, int l)
{
	int rey[58];
	rey[0] = 165+40*l;//1X
	rey[1] = 115+40*k;//1Y
	rey[2] = 170+40*l;//2X
	rey[3] = 110+40*k;//2Y
	rey[4] = 176+40*l;//3X
	rey[5] = 110+40*k;//3Y
	rey[6] = 178+40*l;//4X
	rey[7] = 113+40*k;//4Y
	rey[8] = 178+40*l;//5X
	rey[9] = 108+40*k;//5Y
	rey[10] = 176+40*l;//6X
	rey[11] = 108+40*k;//6Y
	rey[12] = 176+40*l;//7X
	rey[13] = 106+40*k;//7Y
	rey[14] = 179+40*l;//8X
	rey[15] = 106+40*k;//8Y
	rey[16] = 179+40*l;//9X
	rey[17] = 104+40*k;//9Y
	rey[18] = 181+40*l;//10X
	rey[19] = 104+40*k;//10Y
	rey[20] = 181+40*l;//11X
	rey[21] = 106+40*k;//11Y
	rey[22] = 183+40*l;//12X
	rey[23] = 106+40*k;//12Y
	rey[24] = 183+40*l;//13X
	rey[25] = 108+40*k;//13Y
	rey[26] = 181+40*l;//14X
	rey[27] = 108+40*k;//14Y
	rey[28] = 181+40*l;//15X
	rey[29] = 113+40*k;//15Y
	rey[30] = 183+40*l;//16X
	rey[31] = 110+40*k;//16Y
	rey[32] = 190+40*l;//17X
	rey[33] = 110+40*k;//17Y
	rey[34] = 195+40*l;//18X
	rey[35] = 115+40*k;//18Y
	rey[36] = 195+40*l;//19X
	rey[37] = 120+40*k;//19Y
	rey[38] = 190+40*l;//20X
	rey[39] = 125+40*k;//20Y
	rey[40] = 190+40*l;//21X
	rey[41] = 130+40*k;//21Y
	rey[42] = 195+40*l;//22X
	rey[43] = 130+40*k;//22Y
	rey[44] = 195+40*l;//23X
	rey[45] = 135+40*k;//23Y
	rey[46] = 165+40*l;//24X
	rey[47] = 135+40*k;//24Y
	rey[48] = 165+40*l;//25X
	rey[49] = 130+40*k;//25Y
	rey[50] = 170+40*l;//26X
	rey[51] = 130+40*k;//26Y
	rey[52] = 170+40*l;//27X
	rey[53] = 125+40*k;//27Y
	rey[54] = 165+40*l;//28X
	rey[55] = 120+40*k;//28Y
	rey[56] = 165+40*l;//29X
	rey[57] = 115+40*k;//29Y

	fillpoly(28,rey);
	
	setcolor(BLACK);
	line(167+40*l,130+40*k,193+40*l,130+40*k); //abajo
}

void peon(int k, int l)
{
	int peo[32];
	peo[0] = 178+40*l;//1X
	peo[1] = 115+40*k;//1Y
	peo[2] = 182+40*l;//2X
	peo[3] = 115+40*k;//2Y
	peo[4] = 185+40*l;//3X
	peo[5] = 122+40*k;//3Y
	peo[6] = 187+40*l;//4X
	peo[7] = 122+40*k;//4Y
	peo[8] = 187+40*l;//5X
	peo[9] = 125+40*k;//5Y
	peo[10] = 183+40*l;//6X
	peo[11] = 125+40*k;//6Y
	peo[12] = 186+40*l;//7X
	peo[13] = 132+40*k;//7Y
	peo[14] = 190+40*l;//8X
	peo[15] = 132+40*k;//8Y
	peo[16] = 190+40*l;//9X
	peo[17] = 136+40*k;//9Y
	peo[18] = 170+40*l;//10X
	peo[19] = 136+40*k;//10Y
	peo[20] = 170+40*l;//11X
	peo[21] = 132+40*k;//11Y
	peo[22] = 174+40*l;//12X
	peo[23] = 132+40*k;//12Y
	peo[24] = 177+40*l;//13X
	peo[25] = 125+40*k;//13Y
	peo[26] = 173+40*l;//14X
	peo[27] = 125+40*k;//14Y
	peo[28] = 173+40*l;//15X
	peo[29] = 122+40*k;//15Y
	peo[30] = 175+40*l;//16X
	peo[31] = 122+40*k;//16Y
	fillpoly(16,peo);
	
	setcolor(BLACK);
	//line(170+40*l,131+40*k,190+40*l,131+40*k); //abajo
	line(174+40*l,131+40*k,186+40*l,131+40*k); //abajo
}

void asignapiezas(int P[8][8])
{
  int k, l, p;
  int P2[8][8] =    { 11,12,13,14,15,16,17,18,
					  1,2,3,4,5,6,7,8,
					  0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0,
					  0,0,0,0,0,0,0,0,
					  -1,-2,-3,-4,-5,-6,-7,-8,
					 -11,-12,-13,-14,-15,-16,-17,-18,};
				 
  for(k=0;k<8;k++)
  {
	  for(l=0;l<8;l++)
	  {
		  P[k][l]=P2[k][l];
		  p= P[k][l];

		 if (P[k][l]>0)
		{
			setfillstyle(1,BROWN);
			setcolor(BROWN);
		}
		if (P[k][l]<0)
		{
			setfillstyle(1,YELLOW);
			setcolor(YELLOW);
		}

	   switch(p)
	   {
		   case 11:
		   case 18:
		   case -11:
		   case -18: torre(k,l); break;

		   case 12:
		   case 17:
		   case -12:
		   case -17: caballo(k,l); break;

		   case 13:
		   case 16:
		   case -13:
		   case -16: alfil(k,l); break;

		   case 14:
		   case -14: reina(k,l); break;
		   case 15:
		   case -15: rey(k,l); break;

		   case 1:
		   case 2:
		   case 3:
		   case 4:
		   case 5:
		   case 6:
		   case 7:
		   case 8:
		   case -1:
		   case -2:
		   case -3:
		   case -4:
		   case -5:
		   case -6:
		   case -7:
		   case -8:  peon(k,l); break;
	   }
	  }
 }

}
void piezasop() //piezas del oponente
{
	 setcolor(WHITE);
	 setlinestyle(0,0,2);

	 box(500,100,620,220,1,BLACK);
	 box(500,300,620,420,1,BLACK);
	 
	 ////////////////////////////////////////////////////
	//Piezas obtenidas del jugador 2
	setfillstyle(1,YELLOW);
	setcolor(YELLOW);
	
	alfil(0,9);
	caballo(1,9);
	torre(2,9);
	reina(0,10);
	peon(1,10);

	////////////////////////////////////////////////////
	//Piezas obtenidas del jugador 1
	setfillstyle(1,BROWN);
	setcolor(BROWN);

	alfil(5,9);
	caballo(6,9);
	torre(7,9);
	reina(5,10);
	peon(6,10);
}


 void piezaregla(int i, int j, int x, int y)
 {
	 box(x+55+(15*j),y+125+(15*i),x+70+(15*j),y+140+(15*i),1,GREEN);
 }
 
void juego()  //Los submenus del menu Jugar
{
	setcolor(WHITE);

	box(20,100,130,235,1,BLACK);

	box(30,110,120,135,1,BROWN);
	outtextxy(40,113,"REINICIAR");
	outtextxy(55,125,"JUEGO");

	box(30,140,120,165,1,BROWN);
	outtextxy(49,150,"GUARDAR");

	box(30,170,120,195,1,BROWN);
	outtextxy(55,180,"ABRIR");

	box(30,200,120,225,1,BROWN);
	outtextxy(45,210,"RESIGNAR");

}

void menu() //Muestra los menus principales
{
	 box(0,0,getmaxx(),getmaxy(),1,LIGHTGRAY);

	 int M[8][8];
	 asigna(M);
	 pintamatriz(M);

     int P[8][8];
     asignapiezas(P);

	 setcolor(WHITE);
	 setlinestyle(0,0,2);

	 box(1,1,640,25,1,BLACK);
	 outtextxy(295,10,"AJEDREZ");

	 setcolor(WHITE);
	 setlinestyle(0,0,0);

	 box(1,25,100,50,1,BROWN);
	 outtextxy(33,32,"JUEGO");

	 box(100,25,200,50,1,BROWN);
	 outtextxy(132,32,"AYUDA");

	 box(200,25,300,50,1,BROWN);
	 outtextxy(228,32,"SALIR");

	 box(300,25,640,50,1,BROWN);
 }
 
 void ayuda()  //Es lo que esta dentro del menu ayuda
{
	int M[8][8],x,y, i,j;
   
   	 box(0,0,getmaxx(),getmaxy(),1,LIGHTGRAY);

	 setcolor(WHITE);
	 setlinestyle(0,0,2);

	 box(1,1,640,25,1,BLACK);
	 outtextxy(295,10,"AJEDREZ");

	 setcolor(WHITE);
	 setlinestyle(0,0,0);

	 box(1,25,100,50,1,BROWN);
	 outtextxy(33,32,"JUEGO");

	 box(100,25,200,50,1,BROWN);
	 outtextxy(132,32,"AYUDA");

	 box(200,25,300,50,1,BROWN);
	 outtextxy(228,32,"SALIR");

	 box(300,25,640,50,1,BROWN);
	 
	 outtextxy(230,58,"MOVIMIENTO DE LAS PIEZAS");
	 
	 asigna(M);
	 
	 //REY
	box(80,75,150,100,1,GREEN);
	outtextxy(90,85,"EL REY");
	outtextxy(65,105,"Mueve un paso");
	outtextxy(55,115,"para todos lados");
	 x=0;y=10;
	 pintamatrizreglas(M,x,y);
	 for(i=3;i<6;i++)
		for(j=2;j<5;j++) piezaregla(i,j,x,y);
		setfillstyle(1,BLACK);
	fillellipse(107,202,5,5); 

	//ALFIL
	box(72,275,155,300,1,GREEN);
	setcolor(WHITE);
	 outtextxy(82,285,"EL ALFIL");
	 outtextxy(50,305,"Mueve en diagonal");
	 x=0;y=200;
	 pintamatrizreglas(M,x,y);
	 j=0;
	 for(j=0;j<7;j++)
		{
			i=j+1;
			piezaregla(i,j,x,y);
		}
		j=0;
	for(i=7;i>=0;i--)
		{
			piezaregla(i,j,x,y);
			j++;
		}
	setfillstyle(1,BLACK);
	fillellipse(107,392,5,5); 
	 
	 //REINA
	 box(275,75,355,100,1,GREEN);
	 outtextxy(285,85,"LA REINA");
	 outtextxy(235,110,"Mueve para todos lados");
	 x=200;y=10;
	 pintamatrizreglas(M,x,y);

	 for(j=0;j<7;j++)
		{
			i=j+1;
			piezaregla(i,j,x,y);
		}
		j=0;
	for(i=7;i>=0;i--)
		{
			piezaregla(i,j,x,y);
			j++;
		}
	 for(j=0;j<8;j++)
		{
			i=4;
			piezaregla(i,j,x,y);
		}
	
	for(i=0;i<8;i++)
		{
			j=3;
			piezaregla(i,j,x,y);
		}
		setfillstyle(1,BLACK);
		fillellipse(307,202,5,5); 
	
	 //CABALLO
	 box(270,275,370,300,1,GREEN);
	 outtextxy(280,285,"EL CABALLO");
	 outtextxy(245,303,"Mueve tres casillas");
	 outtextxy(265,313,"Forma una L");
	 x=200;y=200;
	 pintamatrizreglas(M,x,y);
	 i=2;j=4;
	 piezaregla(i,j,x,y);
	 i=3;j=5;
	 piezaregla(i,j,x,y);
	 i=5;j=5;
	 piezaregla(i,j,x,y);
	 i=6;j=4;
	 piezaregla(i,j,x,y);
	 i=6;j=2;
	 piezaregla(i,j,x,y);
	 i=5;j=1;
	 piezaregla(i,j,x,y);
	 i=3;j=1;
	 piezaregla(i,j,x,y);
	 i=2;j=2;
	 piezaregla(i,j,x,y);
	 setfillstyle(1,BLACK);
	fillellipse(307,392,5,5); 
	 
	 //PEON
	 box(480,75,560,95,1,GREEN);
	 outtextxy(490,85,"EL PEON");
	 outtextxy(445,99,"Mueve un paso hacia");
	 outtextxy(450,109," hacia adelante");
	 outtextxy(435,119,"Come un paso en diagonal");
	 x=400;y=10;
	 pintamatrizreglas(M,x,y);
	  for(i=3;i<6;i++)
		for(j=2;j<5;j++) piezaregla(i,j,x,y);
	
	setfillstyle(1,BLACK);
	fillellipse(507,202,5,5); 
	 
	 //TORRE
	 box(480,275,560,300,1,GREEN);
	 outtextxy(490,285,"LA TORRE");
	 outtextxy(440,305,"Mueve en linea recta");
	 x=400;y=200;
	 pintamatrizreglas(M,x,y);
	 
	 for(j=0;j<8;j++)
		{
			i=4;
			piezaregla(i,j,x,y);
		}
	
	for(i=0;i<8;i++)
		{
			j=3;
			piezaregla(i,j,x,y);
		}
		setfillstyle(1,BLACK);
	fillellipse(507,392,5,5); 
	 
	
	box(535,460,635,475,1,BLACK);
	outtextxy(555,462,"Regresar");
}
 
void guardar(int P[8][8],int G[8][8], int C[10], int C2[10], int turno,int &gturno)
{
	int i,j;
	
	for(i=0;i<8;i++)
	for(j=0;j<8;j++)  G[i][j] = P[i][j];

	 gturno=turno;
	for(i=0;i<10;i++) C2[i] = C[i];

}
void abrir(int P[8][8],int G[8][8], int C[10], int C2[10], int &turno,int gturno)
{
	int i,j;
	for(i=0;i<8;i++)
	for(j=0;j<8;j++)
	{
	 P[i][j] = 0;
	 P[i][j] = G[i][j];
	}
	gturno = turno;
	for(i=0;i<10;i++) C[i] = C2[i];
}

void selecciona()  //pinta barras
{
	int a,b,c,d,P[8][8],M[8][8],z,j,x1,x2,y1,y2,mov=3,movimiento=0,adelante, salir, colornumber=0,colornumber2,p2,
	  btor=0, bcab=0, balf=0, brei=0, bpeo=0, ntor=0, ncab=0, nalf=0, nrei=0, npeo=0,
	  C[10],i,C2[10], k, l, p, G[8][8], gturno, colorturno1, colorturno2,turno=1, atraviesa=0,u,v;
	
	char pieza, pieza2, cbtor[2], cbcab[2], cbalf[2], cbrey[2] ,cbrei[2], cbpeo[2], cntor[2], cncab[2], cnalf[2], cnrey[2], cnrei[2], cnpeo[2];

	  menu();
	  asigna(M);
	  asignapiezas(P);
	  piezasop();

   do {
		salir =0;
		a=3;
		mouse(a,b,c,d);

		switch( b ) {   //que boton presiono
		case 1 :
	    quita();
		if ( c>1 && c<100 && d>25 && d<50 ) juego();
		
			
		if( c>30 && c<120 && d>110 && d<135 ) selecciona(); //Boton de reiniciar

		if( c>30 && c<120 && d>140 && d<165 ) guardar(P,G,C,C2,turno,gturno); //Boton de guardar
		

		if( c>30 && c<120 && d>170 && d<195 )  //Boton de ABRIR
		{
			abrir(P,G,C,C2,turno,gturno);
					
			for(k=0;k<8;k++)
		  {
			  for(l=0;l<8;l++)
			  {
				  p= P[k][l];

				 if (P[k][l]>0)
				{
					setfillstyle(1,BROWN);
					setcolor(BROWN);
				}
				if (P[k][l]<0)
				{
					setfillstyle(1,YELLOW);
					setcolor(YELLOW);
				}

			   switch(p)
			   {
				   case 11:
				   case 18:
				   case -11:
				   case -18: torre(k,l); break;

				   case 12:
				   case 17:
				   case -12:
				   case -17: caballo(k,l); break;

				   case 13:
				   case 16:
				   case -13:
				   case -16: alfil(k,l); break;

				   case 14:
				   case -14: reina(k,l); break;
				   case 15:
				   case -15: rey(k,l); break;

				   case 1:
				   case 2:
				   case 3:
				   case 4:
				   case 5:
				   case 6:
				   case 7:
				   case 8:
				   case -1:
				   case -2:
				   case -3:
				   case -4:
				   case -5:
				   case -6:
				   case -7:
				   case -8:  peon(k,l); break;
				   case 0: 
				   if(M[k][l]==1)
					{
					 box(160+(40*l),100+(40*k),200+(40*l),140+(40*k),1,BLACK);

					}
					if(M[k][l]==0)
					{
					 box(160+(40*l),100+(40*k),200+(40*l),140+(40*k),1,WHITE);
					}
					break;
			   }
					 box(510,115,520,210,1,BLACK);
					 box(605,115,615,200,1,BLACK);
					 box(510,315,520,410,1,BLACK);
				     box(605,315,615,410,1,BLACK);
					
					 btor = C[0];
					 bcab = C[1];
					 balf = C[2];
					 brei = C[3];
					 bpeo = C[4];
					 ntor = C[5];
					 ncab = C[6];
					 nalf = C[7];
					 nrei = C[8];
					 npeo = C[9];
					 
					 
			  }
			}
			
		 }
		if( c>30 && c<120 && d>200 && d<225 ) {if(turno==0 && mov>=3) {setcolor(WHITE);outtextxy(240,75,"Felicidades jugador 1!!!"); }
												else if(turno==1 && mov>=3) {setcolor(WHITE);outtextxy(240,75,"Felicidades jugador 2!!");}
												j=0;}  //Boton de resignar


		if ( c>100 && c<200 && d>25 && d<50 ) //AYUDA
		{
			ayuda();
			guardar(P,G,C,C2,turno,gturno);
		}
		if ( c>535 && c<635 && d>460 && d<475 ) //REGRESAR DESDE LAS REGLAS
		{
			
		menu();
		abrir(P,G,C,C2,turno,gturno);
		for(k=0;k<8;k++)
		  {
			  for(l=0;l<8;l++)
			  {
				  //P[k][l]=G[k][l];
				  p= P[k][l];

				 if (P[k][l]>0)
				{
					setfillstyle(1,BROWN);
					setcolor(BROWN);
				}
				if (P[k][l]<0)
				{
					setfillstyle(1,YELLOW);
					setcolor(YELLOW);
				}

			   switch(p)
			   {
				   case 11:
				   case 18:
				   case -11:
				   case -18: torre(k,l); break;

				   case 12:
				   case 17:
				   case -12:
				   case -17: caballo(k,l); break;

				   case 13:
				   case 16:
				   case -13:
				   case -16: alfil(k,l); break;

				   case 14:
				   case -14: reina(k,l); break;
				   case 15:
				   case -15: rey(k,l); break;

				   case 1:
				   case 2:
				   case 3:
				   case 4:
				   case 5:
				   case 6:
				   case 7:
				   case 8:
				   case -1:
				   case -2:
				   case -3:
				   case -4:
				   case -5:
				   case -6:
				   case -7:
				   case -8:  peon(k,l); break;
				   case 0: 
				   if(M[k][l]==1) box(160+(40*l),100+(40*k),200+(40*l),140+(40*k),1,BLACK);

					if(M[k][l]==0) box(160+(40*l),100+(40*k),200+(40*l),140+(40*k),1,WHITE);
					break;
			   }
			  }
			}
					piezasop();
		}
		if ( c>200 && c<300 && d>25 && d<50 ) salir=1;

		////////////////////////////////SI SE PRESIONÓ DENTRO DEL TABLERO/////////////////////////////////////
		if ( c>160 && c<480 && d>100 && d<420)
		{
			
			if(colornumber==0)
			{
				box(10,440,120,460,1,YELLOW);
				setcolor(BLACK);
				outtextxy(10,430,"Turno");
				outtextxy(30,450,"Jugador 1");
				turno =1;
			}
			
			  setcolor(WHITE);
			  outtextxy(510,115,itoa(balf,cbalf,10)); //alfil blanco
			  outtextxy(510,155,itoa(bcab,cbcab,10)); //caballo
			  outtextxy(510,195,itoa(btor,cbtor,10)); //torre
			  outtextxy(605,115,itoa(brei,cbrei,10)); //reina 
			  outtextxy(605,155,itoa(bpeo,cbpeo,10)); //peon

			  outtextxy(510,315,itoa(nalf,cnalf,10)); //alfil negro
			  outtextxy(510,355,itoa(ncab,cncab,10)); //caballo
			  outtextxy(510,395,itoa(ntor,cntor,10)); //torre
			  outtextxy(605,315,itoa(nrei,cnrei,10)); //reina 
			  outtextxy(605,355,itoa(npeo,cnpeo,10)); //peon
			

			///////////////////////SACA LAS COORDENADAS DEL X Y Y/////////////////////////////////////////
			x1 = floor((c-160)/40);
			y1 = floor((d-100)/40);

			//////////////////PINTA EL CONTORNO DEL CUADRO ROJO///////////////////////////////////////////
			setcolor(RED);
			rectangle(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1));

			/////////////////////ASIGNA EL NUMERO DE LA PIEZA A Z//////////////////////////////////////////
			z = P[y1][x1];

			/////////////////////COMPARA Z PARA SABER QUE PIEZA ES/////////////////////////////////////////
		 switch(z)
			   {
				   case 11:
				   case 18:
				   case -11:
				   case -18: pieza = 't'; break;

				   case 12:
				   case 17:
				   case -12:
				   case -17: pieza = 'c'; break;

				   case 13:
				   case 16:
				   case -13:
				   case -16: pieza = 'a'; break;

				   case 14:
				   case -14: pieza = 'q'; break;
				   case 15:
				   case -15: pieza = 'r'; break;

				   case 1:
				   case 2:
				   case 3:
				   case 4:
				   case 5:
				   case 6:
				   case 7:
				   case 8:
				   case -1:
				   case -2:
				   case -3:
				   case -4:
				   case -5:
				   case -6:
				   case -7:
				   case -8:  pieza = 'p'; break;
				   default: break;
				}

				//////////////////////SACA EL COLOR DE LA PIEZA SELECCIONADA////////////////////////////////////
			if (z>0)
			{
				colornumber = 6; //BROWN
				movimiento=1;
			}
			if (z<0)
			{
				colornumber = 14; //YELLOW
				movimiento=0;
			}
					
		}
			    ///////////////////////////////TERMINA LA 1era CONDICION ADENTRO DEL TABLERO/////////////////////////
				
				break;
				/////////////////////////////////////AQUI EMPIEZA LA 2DA CONDICION/////////////////////////////

			   case 2 :
			   quita();
			    //////////////////////EMPIEZA EN EL SEGUNDO CLIC/////////////////////////////////////////////////
				if( c>160 && c<480 && d>100 && d<420)
				{
					
					x2 = floor((c-160)/40);
					y2 = floor((d-100)/40);

					p2 = P[y2][x2];
					if (p2>0) colornumber2 = 6; //BROWN
					if (p2<0) colornumber2 = 14; //YELLOW
					

				/////////////////////VALIDACION////////////////////////////////
				///////////Empieza con blanco (z's negativo)//////////////////

				if (mov>=1)
				{
					//////////////////////CABALLO////////////////////////////
					if(pieza=='c')
					{
						if((abs(y2-y1)==2) && (abs(x2-x1)==1)) adelante =1;
						else if((abs(x2-x1)==2) && (abs(y2-y1)==1)) adelante =1;
						else adelante =0;
						
					}
					////////////////////////TORRE////////////////////////////
					if(pieza=='t')
					{
						
						if (x2>x1)
						{
							for(v=x1+1;v<x2;v++) if (P[y1][v]!=0) atraviesa=1;
						}
						else if (x1>x2)
						{
							for(v=x2+1;v<x1;v++) if (P[y1][v]!=0) atraviesa=1;
				
						}
						else if (y1>y2)
						{
							for(v=y2+1;v<y1;v++) if (P[v][x1]!=0) atraviesa=1;
				
						}
						else if (y2>y1)
						{
							for(v=y1+1;v<y2;v++) if (P[v][x1]!=0) atraviesa=1;
				
						}
						
						if(x2==x1 && atraviesa ==0) adelante =1;
						else if(y2==y1 && atraviesa==0) adelante =1;
						else adelante =0;
						
						atraviesa=0;
					}

					////////////////////////ALFIL////////////////////////////
					if(pieza=='a')
					{
						if (x2>x1 && y2>y1)
							{
								u=x1+1;
								v=y1+1;
								do
								{
									u++;
									v++;
									if (P[v][u]!=0) atraviesa=1;
								}while(atraviesa!=0 && v<y2 && u<x2);
							}
							
						else if (x2>x1 && y1>y2)
							{
								u=x1+1;
								v=y1-1;
								do
								{
									u++;
									v--;
									if (P[v][u]!=0) atraviesa=1;
								}while(atraviesa!=0 && v>y2 && u<x2);
							}
						else if (x1>x2 && y1>y2)
						{
							u=x1-1;
							v=y1-1;
							do
							{
								u--;
								v--;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v>y2 && u>x2);
						}
						else if (x1>x2 && y2>y1)
						{
							u=x1-1;
							v=y1+1;
							do
							{
								u--;
								v++;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v<y2 && u>x2);
						}
							
							if(x1==y1 && x2==y2) adelante=1;
							else if(x2>x1 && y2>y1 && ((abs(x1-y1))==(abs(x2-y2))) && atraviesa==0) adelante=1;
							else if(x2>x1 && y1>y2 && ((x1+y1)==(x2+y2)) && atraviesa ==0 ) adelante=1;
							else if(x1>x2 && y1>y2 && (abs(x1-y1))==(abs(x2-y2)) && atraviesa==0) adelante=1;
							else if(x1>x2 && y2>y1 && ((x1+y1)==(x2+y2)) && atraviesa==0) adelante=1;
							else adelante =0; 
						
							atraviesa=0;
					}
					
					/////////////////////////VALIDACION REINA/////////////////////////////////

					if(pieza=='q')
					{
						if(((y1==(y2+1))) && (x2==x1))
						{
							adelante =1;
						}
						else if(((y1==(y2+2))) && (x2==x1))
						{
							adelante =1;
							
						}
						else if(((x1==(x2-1)) || (x1==(x2+1))) && (y1==(y2+1)))
						{
							adelante =1;
						}
						else if(((y1==(y2-1))) && (x2==x1))
						{
							adelante =1;
						}
						else if(((y1==(y2-2))) && (x2==x1))
						{
							adelante =1;
							
						}
						else if(((x1==(x2-1)) || (x1==(x2+1))) && (y1==(y2-1)))
						{
							adelante =1;
						}
						
						else if(x2==x1) 
						{
							if (y1>y2) {for(v=y2+1;v<y1;v++) if (P[v][x1]!=0) atraviesa=1;}
						
							else if (y2>y1) {for(v=y1+1;v<y2;v++) if (P[v][x1]!=0) atraviesa=1;}
							
							if (atraviesa==0) adelante=1;
						}	
						else if(y2==y1)
						{
							if (x2>x1) {for(v=x1+1;v<x2;v++) if (P[y1][v]!=0) atraviesa=1;}
						
							else if (x1>x2){for(v=x2+1;v<x1;v++) if (P[y1][v]!=0) atraviesa=1;} 
							
							if (atraviesa==0) adelante=1;
						}
						
						else if(x2>x1 && y2>y1 && ((abs(x1-y1))==(abs(x2-y2)))) 
						{
							u=x1+1;
							v=y1+1;
							do
							{
								u++;
								v++;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v<y2 && u<x2);
								
							if(atraviesa==0) adelante=1;
						}
						else if(x2>x1 && y1>y2 && ((x1+y1)==(x2+y2)))
						{
							u=x1+1;
							v=y1-1;
							do
							{
								u++;
								v--;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v>y2 && u<x2);
								
							if(atraviesa==0) adelante=1;
						}
						else if(x1>x2 && y1>y2 && (abs(x1-y1))==(abs(x2-y2)))
						{
							u=x1-1;
							v=y1-1;
							do
							{
								u--;
								v--;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v>y2 && u>x2);
							
							if(atraviesa==0) adelante=1;
						}
						else if(x1>x2 && y2>y1 && ((x1+y1)==(x2+y2))) 
						{
							u=x1-1;
							v=y1+1;
							do
							{
								u--;
								v++;
								if (P[v][u]!=0) atraviesa=1;
							}while(atraviesa!=0 && v<y2 && u>x2);
							
								if(atraviesa==0) adelante=1;
						}
						else if(x1==y1 && x2==y2) adelante=1;
						else adelante =0;
				
						atraviesa=0; 
					}
					///////////////////////PEON////////////////////////////
					if(pieza=='p' && colornumber==6) //FOR BROWN
					{
						if(((y1==(y2-1))) && (x2==x1))
						{
							adelante =1;
						}
						else if(((y1==(y2-2))) && (x2==x1) && (y1==1))
						{
							adelante =1;
							
						}
						else if((((x1==(x2-1)) && (P[y2][x2]!=0))|| (x1==(x2+1)) && (P[y2][x2]!=0)) && (y1==(y2-1)))
						{
							adelante =1;
						}
						else
						{
							adelante =0;
						}
					}
					else if(pieza=='p' && colornumber==14)
					{
						if(((y1==(y2+1))) && (x2==x1))
						{
							adelante =1;
						}
						else if(((y1==(y2+2))) && (x2==x1)&& (y1==6))
						{
							adelante =1;
							
						}
						else if((((x1==(x2-1)) && (P[y2][x2]!=0))|| (x1==(x2+1)) && (P[y2][x2]!=0)) && (y1==(y2+1)))
						{
							adelante =1;
						}
						else
						{
							adelante =0;
						}
					}
					//////////////////////REY////////////////////////////
					if(pieza=='r')
					{
						if(colornumber==14 && x1==4 && y1==7 && x2==6 && y2==7 && P[7][5]==0 && P[7][6]==0 && P[7][7]==-18) 
						{
							adelante =1;
						}
						else if(colornumber==6 && x1==4 && y1==0 && x2==6 && y2==0 && P[0][5]==0 && P[0][6]==0 && P[0][7]==18) 
						{
							adelante =1;
						}
						else if(colornumber==14 && x1==4 && y1==7 && x2==2 && y2==7 && P[7][1]==0 && P[7][2]==0 && P[7][3]==0 && P[7][0]==-11) 
						{
							adelante =1;
						}
						else if(colornumber==6 && x1==4 && y1==0 && x2==2 && y2==0 && P[7][1]==0 && P[0][2]==0 && P[0][3]==0 && P[0][0]==11) 
						{
							adelante =1;
						}
						else if(((y1==(y2-1)) || (y1==(y2+1))) && (x2==x1))
						{
							adelante =1;
						}
						else if(((x1==(x2-1)) || (x1==(x2+1))) && (y2==y1))
						{
							adelante =1;
						}
						
						else if(((x1==(x2-1)) || (x1==(x2+1))) && ((y1==(y2-1)) || (y1==(y2+1))))
						{
							adelante =1;
						}
						else
						{
							adelante =0;
						}
					}
				}

				
			if (colornumber==6 && turno==1) adelante =0;
			if (colornumber==14 && turno==0) adelante =0;
			
			if(adelante==1)
			{
				if (movimiento==0)
				{ 
					box(10,440,120,460,1,BROWN);
					setcolor(WHITE);
					outtextxy(10,430,"Turno");
					outtextxy(30,450,"Jugador 2");
					turno = 0;
					
				} 
				if (movimiento!=0)
				{
					box(10,440,120,460,1,YELLOW);
					setcolor(BLACK);
					outtextxy(10,430,"Turno");
					outtextxy(30,450,"Jugador 1");
					turno =1;
				}
				//////////////////////////DESPINTA EL CUADRO SELECCIONADO////////////////////////////////////
				setcolor(WHITE);
				rectangle(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1));

				//////////////////////USA EL COLOR SACADO PARA PINTAR LA PIEZA//////////////////////////////////////////////
				setfillstyle(1,colornumber);
				setcolor(colornumber);

				/////////////////////PARA SABER SI HAY UNA PIEZA EN LA SEGUNDA POSICION//////////////////////////////////////////
			
				if(p2!=0 && colornumber!=colornumber2)
				{
					/////////////////////////DESPINTA LA POSICIÓN ELEGIDA CON BLANCO O NEGRO  ////////////////////////////////
					if(M[y2][x2]==1)
					{
					 box(160+(40*x2),100+(40*y2),200+(40*x2),140+(40*y2),1,BLACK);

					}
					else if(M[y2][x2]==0)
					{
					 box(160+(40*x2),100+(40*y2),200+(40*x2),140+(40*y2),1,WHITE);
					}
					
					   setcolor(BLACK); 
				/////////////////////COMPARA p2 PARA SABER QUE PIEZA ES/////////////////////////////////////////
				 switch(p2)
					   {
						   case 11:
						   case 18: outtextxy(510,395,itoa(ntor,cntor,10)); ntor++; break; //torre negro
						   case -11:
						   case -18: outtextxy(510,195,itoa(btor,cbtor,10)); btor++; break; //torre blanco

						   case 12:
						   case 17:  outtextxy(510,355,itoa(ncab,cncab,10)); ncab++; break; //caballo negro
						   case -12:
						   case -17:  outtextxy(510,155,itoa(bcab,cbcab,10)); bcab++; break; //caballo blanco

						   case 13:
						   case 16: outtextxy(510,315,itoa(nalf,cnalf,10));  nalf++; break; //alfil negro
						   case -13: 
						   case -16: outtextxy(510,115,itoa(balf,cbalf,10)); balf++; break; //alfil blanco

						   case 14: outtextxy(605,315,itoa(nrei,cnrei,10)); nrei++; break; //reina negra
						   case -14: outtextxy(605,115,itoa(brei,cbrei,10)); brei++; break; //reina blanca
						   case 15:  setcolor(WHITE);outtextxy(240,75,"Felicidades jugador 1!!!"); 	break;
						   case -15: setcolor(WHITE);outtextxy(240,75,"Felicidades jugador 2!!!"); break;
						   case 1:
						   case 2:
						   case 3:
						   case 4:
						   case 5:
						   case 6:
						   case 7:
						   case 8: outtextxy(605,355,itoa(npeo,cnpeo,10)); npeo++; break; //peon negro
						   case -1:
						   case -2:
						   case -3:
						   case -4:
						   case -5:
						   case -6:
						   case -7:
						   case -8: outtextxy(605,155,itoa(bpeo,cbpeo,10)); bpeo++; break;//peon blanco
									
						   default: break;
						}
				}
				//////////////////////PONE EL NUMERO DE LA PIEZA A LA NUEVA POSICIÓN////////////////////////////////////////
				P[y2][x2] = z;
				
					   if (z>0) setcolor(colornumber); setfillstyle(1,colornumber);
					   if (z<0) setcolor(colornumber); setfillstyle(1,colornumber);
				
				////////////////////////////////COMPARA PARA PEGAR LA PIEZA ADECUADA////////////////////////////////////////
				switch(pieza)
				   {
					   case 't': torre(y2,x2);break;

					   case 'c': caballo(y2,x2); break;

					   case 'a': alfil(y2,x2); break;

					   case 'q':reina(y2,x2); break;
					   case 'r': rey(y2,x2);
					   
						if(colornumber==14 && x1==4 && y1==7 && x2==6 && y2==7) 
						{
							P[7][5] = -18;
							torre(7,5);
							box(160+(40*7),100+(40*7),200+(40*7),140+(40*7),1,WHITE);
						}
						if(colornumber==6 && x1==4 && y1==0 && x2==6 && y2==0) 
						{
							P[0][5] = 18;
							torre(0,5);
							box(160+(40*7),100+(40*0),200+(40*7),140+(40*0),1,BLACK);
						}
						if(colornumber==14 && x1==4 && y1==7 && x2==2 && y2==7) 
						{
							P[7][3] = -18;
							torre(7,3);
							box(160+(40*0),100+(40*7),200+(40*0),140+(40*7),1,BLACK);
						}
						if(colornumber==6 && x1==4 && y1==0 && x2==2 && y2==0) 
						{
							P[0][3] = 18;
							torre(0,3);
							box(160+(40*0),100+(40*0),200+(40*0),140+(40*0),1,WHITE);
						}
						break;

					   case 'p': 
					   if(y2==0 || y2==7) 
					   {
						   reina(y2,x2); 
						   if(y2==0) P[y2][x2]=-14;
						   else if(y2==7) P[y2][x2]=14;
					   }
						else peon(y2,x2); 
					   break;
					   default: break;
				   }

				  /////////////////////////BORRA EL NUMERO DE LA PIEZA EN LA POSICIÓN ORIGINAL/////////////////////////////
					P[y1][x1] =0;
					/////////////////////////PINTA LA POSICIÓN ORIGINAL CON BLANCO O NEGRO ////////////////////////////////
					if(M[y1][x1]==1)
					{
					 box(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1),1,BLACK);
					 setcolor(WHITE);
					 rectangle(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1));

					}
					else if(M[y1][x1]==0)
					{
					 box(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1),1,WHITE);
					 setcolor(WHITE);
					 rectangle(160+(40*x1),100+(40*y1),200+(40*x1),140+(40*y1));
					}
					C[0] = btor;
					C[1] = bcab;
					C[2] = balf;
					C[3] = brei;
					C[4] = bpeo;
					C[5] = ntor;
					C[6] = ncab;
					C[7] = nalf;
					C[8] = nrei;
					C[9] = npeo;
			   }
			}
			adelante =0;
			mov++;
			break;
    }
       pon();
   } while (salir!=1);
}
void main()
{
   inicializa();
   activa();
   pon();
   selecciona();
   closegraph();
   
   printf("\n\n\n\n            Gracias por jugar!, presione enter para salir del programa           ");
   printf("\n\n                 Programa hecho por: Reyes Udasco Rachelle Nerie                 ");
   printf("\n\n                                    Grupo 23                                     ");
   printf("\n\n                                      UABC                                       ");
   printf("\n\n                             Creado en: Feb-May 2017                             ");
   
   getch();
   quita();
}