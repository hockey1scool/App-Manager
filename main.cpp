#include <iostream>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <fstream>
#include <direct.h>


using namespace std;

//calculator loopp
void calculator(){


        // Declaring variables
        float answer;
        float fNum;
        float sNum;
        string oP;

        // Asking numbers and operations
        cout << "Enter your first number: ";
        cin >>fNum;
        cout << "Enter the operation you would like to do(*,+,-,/): ";
        cin >> oP;
        cout << "Enter the second number: ";
        cin >> sNum;

        // Checking the operation
        if(oP == "*"){

                answer = fNum * sNum;
                cout << fNum << " times " << sNum << " equals " << answer << endl;

        }
        else if(oP == "/") {
                answer = fNum / sNum;
                cout << fNum << " divided by " << sNum << " equals " << answer << endl;

        }
        else if(oP == "+"){
                answer = fNum + sNum;
                cout << fNum << " plus " << sNum << " equals " << answer << endl;
        }
        else if(oP == "-"){
                answer = fNum - sNum;
                cout << fNum << " minus " << sNum << " equals " << answer << endl;
        }
}

//help command that list the commands of the program
void help(){
    cout << "Enter a command. For Example 'calc' will run calculator. If you don't know the command then type 'commands'"<< endl;
}


//file reading
char read(){
        char* buffer;
        if( (buffer = _getcwd(NULL,0)) == NULL ){
                perror( "error.");
            }
        else{
        cout << buffer << endl;
        }
        ofstream myfile;
        myfile.open(buffer);
        myfile << "This is a test." << "\n";
        //myfile.close();
        cout << "Done!"<<endl;
}

//set the appliactions to their specific files
void set(){
        string pathName;
        string nameApplication;
        cout << "Enter the path to the file to execute:";
        cin >> pathName;
        cout << "Enter the name a name so that you type on the run command: Eg(chrome, Internet Explorer: ";
        cin >> nameApplication;
        read();


}




//run command for excutable files
void run(){
        string application;
        cout << "Enter the name of the program you would like to open: ";
        cin >> application;
        if (application == "chrome"){

            SHELLEXECUTEINFO ExecuteInfo;

            memset(&ExecuteInfo, 0, sizeof(ExecuteInfo));

            ExecuteInfo.cbSize          = sizeof(ExecuteInfo);
            ExecuteInfo.fMask           = 0;
            ExecuteInfo.hwnd            = 0;
            ExecuteInfo.lpVerb          = "open";
            ExecuteInfo.lpFile          = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe","open";
            ExecuteInfo.lpParameters    = NULL;
            ExecuteInfo.lpDirectory     = 0;
            ExecuteInfo.nShow           = SW_SHOW;
            ExecuteInfo.hInstApp        = 0;

            if(ShellExecuteEx(&ExecuteInfo) == FALSE){
                cout << "not working";
            }
        }
        else{
                cout << "To set a path to a file that is not in the database, type 'set' and follow the instrucitons." << endl;
        }
}
//list the commands
void commandLoop(){
        string commandsList = "Calc \nHelp\ncommands\nquit\n";
        cout << commandsList;

}

//quit loop
int quit(){
        exit(0);
}


//main ask looop
void askLoop(){
        for( int i=0; i<10; --i){
            string command;
            cout << "App Manager: ";
            cin >> command;
            if(command == "calc"){
                calculator();
            }
            else if(command == "help"){
                help();
            }
            else if(command == "commands"){
                    commandLoop();
            }
            else if(command == "quit"){
                    quit();
            }
            else if(command == "run"){
                    run();
            }
            else if(command == "set"){
                    set();
            }
        }
}
int main()
{
    cout << "Welcome app manager!" << endl;
    askLoop();

}
