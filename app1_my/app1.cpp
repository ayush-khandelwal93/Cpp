#include<iostream>
#include<string>
#include<map>
using namespace std;
class command{
public:
    static map<string, command*> commands;
    command(const string cmdName)
    {
        commands[cmdName]=this;
    }
    virtual void process(double commandData, double &val)
    {

    }
};
map<string, command*> command :: commands;
class ConsoleUi
{
public:

    void show()
    {
        double val=0;
        string commandName;
        double commandData;
        while(true)
        {
            cout<<val<<endl;
            cin>>commandName>>commandData;
            if (command::commands.find(commandName)!=
            command::commands.end())
            {
                command::commands[commandName]->process(
                    commandData, val
                );
            }
            else
            {
                cout<<"Command not supported"<<endl;
            }
            
        }
    }
};

int main()
{
    ConsoleUi cui;
    cui.show();
}
//--------------------------------------------------------------------------------------------------------
// Only change below this
// Code extensible down below

class addcommand : public command
{
public:
    addcommand(const string cmdname) : command(cmdname)
    {

    }
    void process(double commandData, double &val)
    {
        val+=commandData;
    }

};
addcommand ac("add");

class mulcommand : public command
{
public:
    mulcommand(const string cmdname) : command(cmdname)
    {

    }
    void process(double commandData, double &val)
    {
        val*=commandData;
    }

};
mulcommand ad("mul");
// Just keep adding more classes like this and no need to change 
// To implement subtraction to just add this
class subcommand : public command
{
public:
    subcommand(const string cmdname) : command(cmdname)
    {

    }
    void process(double commandData, double &val)
    {
        val-=commandData;
    }

};
subcommand ae("sub");