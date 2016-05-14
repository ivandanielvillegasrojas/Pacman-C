#include <graphics.h>
#include <process.h>
#include <stdio.h>
#include <conio.h>
#include <dos.h>


void abrir_graficos();
void pacman(int x, int y,int tipo);
void jugar();
int nivel(int &can_que);
void quesito(int x,int y,int &can_que);


void main()
{
	abrir_graficos();
	jugar();
}


void jugar()
{
	int tecla=0,tecla_vieja=0,x=320,y=385,inicio=0,color,i,col_niv,queso=0,cambio=1,can_que=0;
	char msg[20];

	col_niv=nivel(can_que);
	for(;can_que!=queso;){
		if(!inicio){
			arc(x,y,45,315,15);
			line(x,y,x+10,y+10);
			line(x,y,x+10,y-10);
			setfillstyle(1,14);
			floodfill(x-2,y,15);
		}
		if(cambio){
			setcolor(0);
			outtextxy(10,10,"ллл");
			setcolor(15);
			sprintf(msg,"%.3d",queso);
			outtextxy(10,10,msg);
			cambio=0;
		}
		if(kbhit()){
			tecla=getch();
			inicio=1;
		}
		if(inicio && tecla){
			delay(6);
			pacman(x,y,0);
		}
		switch(tecla){
			case 27:nosound();
							exit(0);
							break;
			case 80:for(i=2;i<39;i++){
								color=getpixel(x-20+i,y+20);
								if(color==col_niv)
									i=40;
								if(color==5){
									queso++;
									i=40;
									cambio=1;
								}
							}
							if(color!=col_niv)
								y++;
							else
								tecla=0;
							pacman(x,y,2);
							break;
			case 75:for(i=2;i<39;i++){
								color=getpixel(x-20,y-20+i);
								if(color==col_niv)
									i=40;
								if(color==5){
									queso++;
									i=40;
									cambio=1;
								}
							}
							if(color!=col_niv)
								x--;
							else
								tecla=0;
							pacman(x,y,4);
							break;
			case 77:for(i=2;i<39;i++){
								color=getpixel(x+20,y-20+i);
								if(color==col_niv)
									i=40;
								if(color==5){
									queso++;
									i=40;
									cambio=1;
								}
							}
							if(color!=col_niv)
								x++;
							else
								tecla=0;
							pacman(x,y,6);
							break;
			case 72:for(i=2;i<39;i++){
								color=getpixel(x-20+i,y-20);
								if(color==col_niv)
									i=40;
								if(color==5){
									queso++;
									i=40;
									cambio=1;
								}
							}
							if(color!=col_niv)
								y--;
							else
								tecla=0;
							pacman(x,y,8);
							break;
		}
		nosound();
		if(tecla){
			tecla_vieja=tecla;
			sound(300);
		}
		else{
			tecla=tecla_vieja;
			sound(100);
		}
	}
}


int nivel(int &can_que)
{
	int i,j=55,k=14,col_niv=1;

	setfillstyle(1,col_niv);
	for(i=0;i<9;i++,j+=50)
		bar(k,j,k+610,j+10);
	j=55;
	for(i=0;i<13;i++,k+=50)
		bar(k,j+10,k+10,j+410);
	setfillstyle(1,0);
	//horizontales
	bar(25,366,575,404);
	bar(25,416,575,454);
	bar(25,116,125,154);
	bar(475,116,575,154);
	bar(175,116,275,154);
	bar(325,116,425,154);
	bar(25,66,75,104);
	bar(525,66,575,104);
	bar(125,66,275,104);
	bar(325,66,475,104);
	bar(125,166,225,204);
	bar(375,166,475,204);
	bar(125,216,475,254);
	bar(175,266,425,304);
	bar(125,316,175,354);
	bar(225,316,375,354);
	bar(425,316,475,354);
	bar(300,166,350,204);

	//verticales
	bar(75,416,113,68);
	bar(75+450,416,113+450,68);
	bar(25,416,63,366);
	bar(575,416,613,366);
	bar(25,116,63,66);
	bar(575,116,613,66);
	bar(25+100,166,63+100,66);
	bar(25+250,166,63+250,66);
	bar(25+300,166,63+300,66);
	bar(25+450,166,63+450,66);
	bar(25+200,166+50,63+200,66+50);
	bar(25+350,166+50,63+350,66+50);
	bar(25+100,166+150,63+100,66+150);
	bar(25+450,166+150,63+450,66+150);
	bar(25+150,166+200,63+150,66+150);
	bar(25+400,166+200,63+400,66+150);
	bar(25,166,63,316);
	bar(575,166,613,316);

	//quesitos
	for(i=0,j=0;i<12;i++,j+=50)
		quesito(45+j,90,can_que);
	for(i=0,j=0;i<12;i++,j+=50)
		quesito(45+j,140,can_que);
	for(i=0,j=50;i<10;i++,j+=50)
		quesito(45+j,190,can_que);
	for(i=0,j=50;i<10;i++,j+=50)
		quesito(45+j,240,can_que);
	for(i=0,j=50;i<10;i++,j+=50)
		quesito(45+j,290,can_que);
	for(i=0,j=50;i<3;i++,j+=50)
		quesito(45+j,340,can_que);
	for(i=0,j=400;i<3;i++,j+=50)
		quesito(45+j,340,can_que);
	for(i=0,j=0;i<12;i++,j+=50)
		quesito(45+j,390,can_que);
	for(i=0,j=0;i<12;i++,j+=50)
		quesito(45+j,440,can_que);
	return col_niv;
}


void quesito(int x,int y,int &can_que)
{
	circle(x,y,2);
	setfillstyle(1,5);
	floodfill(x,y,15);
	can_que+=3;
}


void pacman(int x, int y, int tipo)
{
	static int boca=1;

	switch(tipo){
		case 0:setfillstyle(1,0);
					 bar(x-15,y-15,x+15,y+15);
					 break;
		case 2:if(boca){
						 arc(x,y,315,225,15);
						 line(x,y,x+10,y+10);
						 line(x,y,x-10,y+10);
						 boca=0;
					 }
					 else{
						 arc(x,y,285,255,15);
						 line(x,y,x+3,y+13);
						 line(x,y,x-3,y+13);
						 boca=1;
					 }
					 setfillstyle(1,14);
					 floodfill(x,y-2,15);
					 break;
		case 4:if(boca){
						 arc(x,y,225,135,15);
						 line(x,y,x-10,y+10);
						 line(x,y,x-10,y-10);
						 boca=0;
					 }
					 else{
						 arc(x,y,195,165,15);
						 line(x,y,x-13,y+3);
						 line(x,y,x-13,y-3);
						 boca=1;
					 }
					 setfillstyle(1,14);
					 floodfill(x+2,y,15);
					 break;
		case 6:if(boca){
						 arc(x,y,45,315,15);
						 line(x,y,x+10,y+10);
						 line(x,y,x+10,y-10);
						 boca=0;
					 }
					 else{
						 arc(x,y,15,345,15);
						 line(x,y,x+13,y+3);
						 line(x,y,x+13,y-3);
						 boca=1;
					 }
					 setfillstyle(1,14);
					 floodfill(x-2,y,15);
					 break;
		case 8:if(boca){
						 arc(x,y,135,45,15);
						 line(x,y,x+10,y-10);
						 line(x,y,x-10,y-10);
						 boca=0;
					 }
					 else{
						 arc(x,y,105,75,15);
						 line(x,y,x+3,y-13);
						 line(x,y,x-3,y-13);
						 boca=1;
					 }
					 setfillstyle(1,14);
					 floodfill(x,y+2,15);
					 break;
	}
}


void abrir_graficos()
{
	int driver_grafico=VGA,modo_grafico=VGAHI,error_codigo;

	initgraph(&driver_grafico,&modo_grafico,"C:\\TC\\BGI");
	error_codigo=graphresult();
	if(error_codigo!=grOk)
		exit(0);
}