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
vector<string>productie;

public:

    Gramatica()
    {
        sir.resize(100);
        in>>litera;
        int n;
        string s;
        in>>n;
        for(int i=0;i<n;i++)
        {
            in>>s;
            productie.push_back(s);
        }

        sir[litera]=productie;


    }

    void afisare()
    {
        int i,j;
        for(i=0;i<sir.size();i++)
        {
            if(sir[i].size()!=0)
            {
                for(j=0;j<sir[i].size()-1;j++)
                    cout<<sir[i][j]<<"|";
                cout<<sir[i][j]<<endl;
            }

        }
    }

};

int main()
{

Gramatica g;
g.afisare();

    return 0;
}
