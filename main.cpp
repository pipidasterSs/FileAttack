#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void ExiT()
{
    system("g++ -o programmL FileGen.cpp");
    system("i686-w64-mingw32-g++ -o programmW.exe FileGen.cpp");

    string exits = "";
    cout << "\n\n\npress q and enter to exit or any key and enter for return to menu > ";
    cin >> exits;

    if(exits == "q") exit(0);
}


void Create(string name,string path,string text)
{
    string s;

    ofstream script;
    script.open("FileGen.cpp");

    ifstream base;
    base.open("Base.txt");

    while(getline(base, s))
    {
        if(s == "    FileDos.open();"){
	     script << "    FileDos.open(\""+ path + name +"\");" + "\n";
	}
        else if(s == "    FileDos <<;"){
	     script << "    FileDos <<\"" + text +"\";" + "\n";
	}
        else{
	     script << s + "\n";
	}
	//cout << s + "\n";
    }

    base.close();
    script.close();

    ExiT();

}


void settings()
{
    string name,path,text;

    cout << "\n________________________________\n";
    cout << "|  SETTINGS FOR VIRUS PROGRAMM  |\n";
    cout << "|-------------------------------|\n";
    cout << "| ENTER NAME VIRUS-PROGRAMM     | >> ";
    cin >> name;
    cout << "|-------------------------------|\n";
    cout << "| ENTER PATH FOR VIRUS-PROGRAMM | >> ";
    cin >> path;
    cout << "|-------------------------------|\n";
    cout << "| ENTER TEXT IN VIRUS-PROGRAMM  | >> ";
    cin >> text;
    cout << "|-------------------------------|\n";

    Create(name,path,text);
}


int main()
{
    while(true)
    {
	system("clear");
        cout << "Hi! this is a Hosting, here we can make virus-programm with your settings, let's go!\n\n";
        settings();
    }
}
