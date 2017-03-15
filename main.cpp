#include <iostream>
#include "TAD.h"
#include <stdlib.h>
#include <sys/time.h>

#define ROSU 0
#define NEGRU 1

using namespace std;

void afis_carte(int c)
{
    if(c==0)
        cout<<"ROSU ";
    else if(c==1)
        cout<<"NEGRU ";
    else
        cout<<"CARTE INVALIDA ";
}

void afis_pachet(coada<int> a)
{
    stiva<int> b;

    while(!a.is_empty())
        b.push(a.pop());

    while(!b.is_empty())
        afis_carte(b.pop());
}

int main()
{
    srand(time(NULL));
    stiva<int> masa;
    coada<int> j1,j2;

    int i,n,c,rosii=0,negre=0;

    cout<<"n= ";
    cin>>n;



    for(i=0;i<n;i++)
    {
        c=rand()%2;
        if(rosii==n)
            c=NEGRU;
        if(negre==n)
            c=ROSU;
        if(c==ROSU)
            rosii++;
        else negre++;
        j1.push(c);
    }

    for(i=0;i<n;i++)
    {
        c=rand()%2;
        if(rosii==n)
            c=NEGRU;
        if(negre==n)
            c=ROSU;
        if(c==ROSU)
            rosii++;
        else negre++;
        j2.push(c);
    }
    int turn=1;

    while((j1.is_empty()==0)&&(j2.is_empty()==0))
    {
        cout<<endl;
        cout<<"J1: ";afis_pachet(j1);
        cout<<endl;
        cout<<"J2: ";afis_pachet(j2);
        cout<<endl;

        if(turn==1)
        {
            masa.push(j1.pop());
            turn=2;
            cout<<"Jucatorul 1 a pus ";afis_carte(masa.get_varf());cout<<endl;
        }
        else if(turn==2)
        {
            masa.push(j2.pop());
            turn=1;
            cout<<"Jucatorul 2 a pus ";afis_carte(masa.get_varf());cout<<endl;
        }
        if(masa.get_varf()==ROSU)
            {if(turn==1)
                cout<<"Jucatorul 1 ia toate cartile"<<endl;
            else
                cout<<"Jucatorul 2 ia toate cartile"<<endl;
            }
        cout<<endl;

        if(masa.get_varf()==ROSU)
            while(masa.is_empty()==0)
            {
                if(turn==1)
                    j1.push(masa.pop());
                else
                    j2.push(masa.pop());
            }
    }
    if(j1.is_empty()==0)
        cout<<"Jucatorul 2 castiga!";
    else cout<<"Jucatorul 1 castiga!";



    return 0;
}
