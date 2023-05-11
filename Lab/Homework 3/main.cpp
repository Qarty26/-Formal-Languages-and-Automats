#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("gramatica.in");
ifstream inn("cuvinte.in");
ofstream out("output.out");

class Gramatica
{
char litera;
vector<vector<string>>sir;

public:

    Gramatica()
    {
        sir.resize(100);
        while(in>>litera)
        {
            int n;
            string s;
            in>>n;
            for(int i=0;i<n;i++)
            {
                in>>s;
                sir[litera].push_back(s);
            }
        }
    }

    void afisare()
    {
        int i,j;
        for(i=0;i<sir.size();i++)
        {
            if(sir[i].size()!=0)
            {
                cout<<(char)i<<" -> ";
                for(j=0;j<sir[i].size()-1;j++)
                    cout<<sir[i][j]<<"|";
                cout<<sir[i][j]<<endl;
            }

        }
    }

    bool acceptare(char start, string cuvant, int index)
    {
        if(index==cuvant.size())
        {
            cout<<"aici ies"<<endl;
            return true;
        }


        for(int i=0;i<sir[start].size();i++)
            if(sir[start][i][0]==cuvant[index] && sir[start][i][1] && index<cuvant.size()-1)
            {
                cout<<"Movin from "<<(char)start<<" to "<<sir[start][i][1]<<" with "<<sir[start][i]<<endl;
                return acceptare(sir[start][i][1],cuvant,index+1);
            }

            else if(sir[start][i][0]==cuvant[index] && !sir[start][i][1] && index==cuvant.size()-1)
            {
                cout<<"Terminating here with my nigga: "<<sir[start][i]<<endl;
                return true;
            }

        cout<<"Am crapat"<<endl;
        return false;
    }

};

int main()
{

Gramatica g;
g.afisare();
cout<<g.acceptare('S',"abccdxabccdd",0);

    return 0;
}
