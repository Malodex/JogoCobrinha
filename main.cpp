#include<cstdlib>
#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;
bool gameover;
const int altura=20;
const int largura=20;
int caudax[200],cauday[200];
int numcauda;
int x,y,frutax,frutay,pontos;
enum eDirection {STOP=0,LEFT,RIGHT,UP,DOWN};
eDirection dir;
char con;
char continuar;

void config()
{
    gameover=false;
    dir=STOP;
    x=altura/2;
    y=largura/2;
    frutax= rand() % altura;
    frutay= rand() % largura;
    pontos=0;

}
void visual()
{
    system("cls");
    for(int i=0;i<largura+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<altura;i++)
    {
        for(int j=0;j<largura;j++)
        {
            if(j==0)
                cout<<"#";
            if(i==y && j==x)
                cout<<"=";
            else
            if(i==frutay && j==frutax)
                cout<<"*";
            else
            {
                bool printtail=false;
                for(int k=0;k<numcauda;k++)
                {
                    if(caudax[k]==j && cauday[k]==i)
                    {
                        cout<<"=";
                        printtail=true;
                    }
                }
                if(!printtail)
                cout<<" ";
            }
            if(j==largura-1)
                cout<<"#";
        }
        cout<<endl;
    }
    for(int i=0;i<largura+2;i++)
    {
        cout<<"#";
    }
    cout<<endl;
    cout<<"Pontos:"<<pontos<<endl;
}
void logica()
{
    int prevx=caudax[0],prevy=cauday[0];
    int prev2x,prev2y;
    caudax[0]=x;
    cauday[0]=y;
    for(int i=1;i<numcauda;i++)
    {
        prev2x=caudax[i];
        prev2y=cauday[i];
        caudax[i]=prevx;
        cauday[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(dir)
    {
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        default:
        break;
    }
    if(x==frutax && y==frutay)
    {
        pontos+=10;
        frutax= rand() % altura;
        frutay= rand() % largura;
        numcauda++;
    }
    if(x>=largura)
        x=0;
    else
    if(x<0)
        x=largura-1;
    if(y>=altura)
        y=0;
    else
    if(y<0)
        y=altura-1;

    for(int i=0;i<numcauda;i++)
    {
        if(caudax[i]==x && cauday[i]==y)
        {
            cout<<"Jogar novamente ?:"<<endl;
            cin>>continuar
            if(continuar=='S'){
                gameover=false
            }
            else{
            gameover=true;
            }
        }

    }
}
void controles()
{
    if(_kbhit())
    {
    switch(_getch())
    {

        case 'a':
            dir= LEFT;
            break;
        case 'w':
            dir= UP;
            break;
        case 's':
            dir= DOWN;
            break;
        case 'd':
            dir= RIGHT;
            break;
        case 'x':
            gameover = true;
            break;
        default:
            break;
    }
    }
}
int main()
{
    config();
    while(!gameover)
    {
        visual();
        controles();
        logica();
        Sleep(40);
    }



    return 0;
}
