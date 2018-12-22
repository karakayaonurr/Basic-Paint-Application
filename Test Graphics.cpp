#include <graphics.h>
#include <stdio.h>

void windowform(){
int i,j;
setcolor(15);
outtextxy(400,530,"Copyrights @");
outtextxy(400,530,"kanka naber");
//start building tools

bar(100,100,500,500);
setcolor(1);
outtextxy(5,5,"Paint");

setcolor(4);
outtextxy(5,75,"Tools:");

bar(5,20,80,45);
setbkcolor(15);
setcolor(2);
outtextxy(5,25,"EXIT");

bar(5,100,80,180);
setbkcolor(15);
setcolor(2);
outtextxy(5,110,"Pencil");

bar(5,200,80,280);
setbkcolor(15);
setcolor(2);
outtextxy(5,210,"Line");
line(5,250,80,250);

bar(5,300,80,380);
setbkcolor(15);
setcolor(2);
outtextxy(5,310,"Circle");
circle(50,350,25);

bar(5,400,80,480);
setbkcolor(15);
setcolor(2);
outtextxy(5,410,"Rectangle");
rectangle(30,430,70,475);

bar(250,520,350,580);
setbkcolor(15);
setcolor(2);
outtextxy(275,530,"Eraser");

bar(100,30,500,80);

//end building tools

//start building colors

setbkcolor(0);
outtextxy(520,75,"Color");

//for red color

for(i=120;i<=180;i++){
	for(j=520;j<=580;j++){
	putpixel(j,i,4);
	}
}


//for green color

for(i=220;i<=280;i++){
	for(j=520;j<=580;j++){
	putpixel(j,i,2);
	}
}

// for blue color

for(i=320;i<=380;i++){
	for(j=520;j<=580;j++){
	putpixel(j,i,1);
	}
	
}

}

//end building colors

int drawnow(int xcl,int ycl,char cmd,int clr){
setcolor(clr);
if(cmd=='e')
{
setcolor(9);
outtextxy(200,200,"exit clicked will exit in 5 seconds");
delay(5000);
exit(1);
}
else if(cmd=='p'){
clearmouseclick(WM_LBUTTONUP);
while(!ismouseclick(WM_LBUTTONUP)){
if(xcl<500&&xcl>100&&ycl<500&&ycl>100)
{
putpixel(xcl-1,ycl-1,clr);
putpixel(xcl,ycl-1,clr);
putpixel(xcl+1,ycl-1,clr);
putpixel(xcl-1,ycl,clr);
putpixel(xcl,ycl,clr);
putpixel(xcl+1,ycl,clr);
putpixel(xcl-1,ycl+1,clr);
putpixel(xcl,ycl+1,clr);
putpixel(xcl+1,ycl+1,clr);
//xcl=mousex(),ycl=mousey();
}
else
{
break;
}
}
}
else if(cmd=='l')
{
int nx,ny;
outtextxy(110,40,"enter end point of line x,y");
scanf("%d %d" , &nx,&ny);
nx=nx+xcl;ny=ny+ycl;
line(xcl,ycl,nx,ny);
bar(100,30,500,80);
}
else if(cmd=='c')
{
int r;
outtextxy(110,40,"enter radius of circle");
scanf("%d",&r);
circle(xcl,ycl,r);
bar(100,30,500,80);
}
else if(cmd=='r')
{
int xe,ye;
outtextxy(110,40,"bottom end point of rectangle");
scanf("%d %d",&xe,&ye);
xe=xe+xcl;ye=ye+ycl;
rectangle(xcl,ycl,xe,ye);
bar(100,30,500,80);
}
else if(cmd=='s')
{
clearmouseclick(WM_LBUTTONUP);
while(!ismouseclick(WM_LBUTTONUP))
{
if(xcl<500&&xcl>100&&ycl<500&ycl>100)
{
putpixel(xcl-1,ycl-1,15);
putpixel(xcl,ycl-1,15);
putpixel(xcl+1,ycl-1,15);
putpixel(xcl-1,ycl,15);
putpixel(xcl,ycl,15);
putpixel(xcl+1,ycl,15);
putpixel(xcl-1,ycl+1,15);
putpixel(xcl,ycl+1,15);
putpixel(xcl+1,ycl+1,15);
//xcl=mousex(),ycl=mousey();
}
else
{
break;
}
}
}
else
{
return(1);
}
}


void mouseclick()
{
int xcl,ycl,clr=4;
char cmd;

while(1) // starts infinite loop
{
clearmouseclick(WM_LBUTTONDOWN);
if(ismouseclick(WM_LBUTTONDOWN)) //DETECS mouse CLÝCK
{
//xcl=mousex(); ycl=mousey(); //traces x,y of mouse position
clearmouseclick(WM_LBUTTONDOWN);
//starts assocoatig an command respective click on window 
if(xcl<80&&xcl>5)
{
if(ycl<45&&ycl>20)
{
cmd='e';
drawnow(xcl,ycl,cmd,clr);
}
else if(ycl<180&&ycl>100)
{
cmd='p';
}
else if(ycl<280&&ycl>200)
{
cmd='l';
}
else if(ycl<380&&ycl>300)
{
cmd='c';
}
else if(ycl<480&&ycl>400)
{
cmd='r';
}
else
{
cmd='n';
}
}

else if(xcl<350&&xcl>250&&ycl<580&&ycl>520)
{
cmd='s';
}

else if(xcl<500&&xcl>100&&ycl<500&&ycl>100)
{
drawnow(xcl,ycl,cmd,clr);
}


else if(xcl<580&&xcl>520)
{
if(ycl<180&&ycl>120)
{
clr=4;
}
if(ycl<280&&ycl>220)
{
clr=2;
}
if(ycl<380&&ycl>320)
{
clr=1;
}
}

else cmd='n';
}
}
delay(50);
}

int main()
{
printf("input datas:\n");
initwindow(600,600,"simple paýnt program",20,20);
windowform();
mouseclick();
}

