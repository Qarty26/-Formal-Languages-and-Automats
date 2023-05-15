#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
ifstream in("gramatica.in");

class Gramatica
{
char litera;
vector<vector<string>>sir;
bool debugger;

public:

    void SetDebugger(bool debugger)
    {
        this->debugger=debugger;
    }

    Gramatica()
    {
        sir.clear();
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

        Gramatica(int stari)
    {
        sir.clear();
        sir.resize(100);

        for(int i=0;i<stari;i++)
        {
            cin>> litera;
            int n;
            string s;
            cin>>n;
            for(int j=0;j<n;j++)
            {
                cin>>s;
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
                    cout<<sir[i][j]<<" | ";
                cout<<sir[i][j]<<endl;
            }

        }
    }

   bool acceptare(char start, string cuvant, int index)
    {
        if(index==cuvant.size())
        {
            if(debugger==true)
                cout<<"Am atins limita maxima de caractere, sunt bine"<<endl;
            return true;
        }

        for(int i=0;i<sir[start].size();i++)

            if(sir[start][i][0]=='^' && sir[start][i][1])
            {
                return acceptare(sir[start][i][1],cuvant,index);
            }
            else if(sir[start][i][0]=='^' && !sir[start][i][1] && index==cuvant.size()-1)
            {
                return true;
            }
            else if(debugger==true && sir[start][i][0]==cuvant[index] && sir[start][i][1] && index<=cuvant.size()-1 && (cout<<"Movin from "<<(char)start<<" to "<<sir[start][i][1]<<" with "<<sir[start][i]<<endl && acceptare(sir[start][i][1],cuvant,index+1)))
            {
                return true;
            }
            else if(debugger==false && sir[start][i][0]==cuvant[index] && sir[start][i][1] && index<=cuvant.size()-1 && acceptare(sir[start][i][1],cuvant,index+1))
            {
                return true;
            }
            else if(sir[start][i][0]==cuvant[index] && !sir[start][i][1] && index==cuvant.size()-1)
            {
                if(debugger==true)
                    cout<<"Terminating here with my nigga: "<<sir[start][i]<<endl;
                return true;
            }

        if(debugger==true)
            cout<<"A crapat ramura asta de recursie"<<endl;
        return false;
    }

};


int main()
{
Gramatica g;
int choice,choice2,nrstari;
string s;

while(true)
{
    cout<<"Choose one of the options:"<<endl;
    cout<<"1. Read the grammar"<<endl;
    cout<<"2. Print the grammar"<<endl;
    cout<<"3. Verify the grammar for a word or more"<<endl;
    cout<<"4. Run the verifier with the debugger"<<endl;
    cout<<"Press anything else to quit..."<<endl;
    cin>>choice;

    if(choice==1)
    {
        cout<<"Choose the source:"<<endl;
        cout<<"1. File(recommended)"<<endl;
        cout<<"2. Keyboard"<<endl;
        cin>>choice2;
        if(choice2==1)
        {
            Gramatica g;
            cout<<"Task completed!"<<endl<<endl;
        }

        else if(choice2==2)
        {
            cout<<"How many states do you have? : ";
            cin>>nrstari;
            Gramatica g(nrstari);

        }
    }
    else if(choice==2)
    {
        g.afisare();
    }



    else if(choice==3)
    {
        g.SetDebugger(false);
        cout<<"Choose the input source:"<<endl;
        cout<<"1. File(recommended)"<<endl;
        cout<<"2. Keyboard"<<endl;
        cin>>choice2;

        if(choice2==1)
        {
            ifstream inn("cuvinte.in");
            while(inn>>s)
            {
                cout<<g.acceptare('S',s,0)<<" pentru cuvantul "<<s<<endl<<endl;
            }
            inn.close();
        }
        else if(choice2==2)
        {
            cout<<"Gimme the word: ";
            cin>>s;
            cout<<g.acceptare('S',s,0)<<" pentru cuvantul "<<s<<endl<<endl;
        }
    }

    else if(choice==4)
    {
        g.SetDebugger(true);
        cout<<"Choose the input source:"<<endl;
        cout<<"1. File(recommended)"<<endl;
        cout<<"2. Keyboard"<<endl;
        cin>>choice2;

        if(choice2==1)
        {
            ifstream inn("cuvinte.in");
            while(inn>>s)
            {
                cout<<g.acceptare('S',s,0)<<" pentru cuvantul "<<s<<endl<<endl;
            }
            inn.close();
        }
        else if(choice2==2)
        {
            cout<<"Gimme the word: ";
            cin>>s;
            cout<<g.acceptare('S',s,0)<<" pentru cuvantul "<<s<<endl<<endl;
        }
    }
    else break;
}





    return 0;
}
