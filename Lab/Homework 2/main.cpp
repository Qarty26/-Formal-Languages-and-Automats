#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream in("date.in");
ofstream out("date.out");


int lungimeMax,stareFinala[100],nrStariFinale;

void afisare(char M[100][100][10],int nrStari)
{
    for(int i=0;i<nrStari;i++)
    {
        for(int j=0;j<nrStari;j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}

void cautare(char M[100][100][10],int nrStari,int lungimeActuala,int stareActuala,char cuv[100])
{
    for(int i=0;i<nrStariFinale;i++)
        if(stareActuala==stareFinala[i])
        {
            out<<cuv<<endl;
            break;
        }



    for(int j=0;j<nrStari;j++)
    {
        if(strcmp(M[stareActuala][j],"#")!=0 && lungimeActuala!=lungimeMax)
        {
            for(int i=0;i<strlen(M[stareActuala][j]);i++)
            {
                cuv[lungimeActuala]=M[stareActuala][j][i];
                for(int k=lungimeActuala+1;k<lungimeMax;k++)
                {
                   cuv[k]=' ';
                }
                cautare(M,nrStari,lungimeActuala+1,j,cuv);
            }
        }
    }
}


int main()
{

    int nrStari,stareInitiala,nrMuchii,st,dr,i,j;
    char M[100][100][10],val[100];

    //cout<<"Nr stari: ";
    in>>nrStari;
    ///citire nr stari
    for(i=0;i<nrStari;i++)
        for(j=0;j<nrStari;j++)
            strcpy(M[i][j],"#");

    //cout<<"Nr muchii: ";
    in>>nrMuchii;
    ///citire nr muchii

    ///citire muchii+compl matrice adiacenta
    //cout<<"Muchii:"<<endl;
    for(i=0;i<nrMuchii;i++)
    {
        in>>st>>dr>>val;
        if(strcmp(M[st][dr],"#")==0)
            strcpy(M[st][dr],val);
        else{
            strcat(M[st][dr],val);
        }
    }
    //cout<<"Stare initiala: ";
    in>>stareInitiala;
    ///citire stare initiala

    //cout<<"Nr stari finale: ";
    in>>nrStariFinale;

    //cout<<"Stari finale:"<<endl;
    for(i=0;i<nrStariFinale;i++)
        in>>stareFinala[i];
    ///citire stari finale

    //cout<<"Lungime maxima: ";
    in>>lungimeMax;
    ///citire lungime maxima

    char cuv[lungimeMax+1];
    for(i=0;i<lungimeMax;i++)
        cuv[i]=' ';


    cautare(M,nrStari,0,stareInitiala,cuv);

    return 0;
}
