#include<iostream>
#include <windows.h>
using namespace std;
char arr[3][3]={{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
int down;
int up;
char initiate='X';
bool draw=false;
string p1="";
string p2="";

void firstfunction() {
    
    // of tic-tac-toe game
    cout<<"                              "<<"----------------"<<endl;
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,00);
    cout<< "                              "<<"    "<<" |  "<<" "<<"  |  "<<" "<< endl;
    SetConsoleTextAttribute(h,00);
    cout<< "                              "<<"  "<<arr[0][0]<<"  |  "<<arr[0][1]<<"  |  "<<arr[0][2]<< endl;
    SetConsoleTextAttribute(h,00);
    cout<<"                              "<<"_____"<<"|"<<"_____"<<"|"<<"_____"<< endl;
    SetConsoleTextAttribute(h,00);
    cout<<"                              "<< "   "<<" "<<" |  "<<" "<<"  |  "<<" "<< endl;
    SetConsoleTextAttribute(h,00);
    cout<<"                              "<< "  "<<arr[1][0]<<"  |  "<<arr[1][1]<<"  |  "<<arr[1][2]<< endl;
    SetConsoleTextAttribute(h,00);
    cout<<"                              "<<"_____"<<"|"<<"_____"<<"|"<<"_____"<< endl;
    SetConsoleTextAttribute(h,00);
    cout<< "                              "<<"   "<<" "<<" |  "<<" "<<"  |  "<<" "<< endl;
    SetConsoleTextAttribute(h,00);
    cout<<"                              "<< "  "<<arr[2][0]<<"  |  "<<arr[2][1]<<"  |  "<<arr[2][2]<< endl;
    SetConsoleTextAttribute(h,00);
    cout<< "                              "<<"    "<<" |  "<<" "<<"  |  "<<" "<< endl;
}
/****************************************************************************
chk for any invalid value and will make sure that it is not there and we will create a variable called value so that we can take input from the user.
****************************************************************************/
void secondfunction() {
    int value;
    if(initiate=='X'){
        cout<<p1<<" :Enter value ";
        cin>>value;
    }
    if(initiate=='O'){
        cout<<p2<<" :Enter value ";
        cin>>value;
    }
    if(value==1){
        down=0;
        up=0;
    }
    if(value==2){
        down=0;
        up=1;
    }
    if(value==3){
        down=0;
        up=2;
    }
    if(value==4){
        down=1;
        up=0;
    }
    if(value==5){
        down=1;
        up=1;
    }
    if(value==6){
        down=1;
        up=2;
    }
    if(value==7){
        down=2;
        up=0;
    }
    if(value==8){
        down=2;
        up=1;
    }
    if(value==9){
        down=2;
        up=2;
    }
    else if(value<1 || value>9){
        cout<<"Invalid value"<<endl;
    }
/**************************************************************************** Here we are chking if there is any unused space which is left in the structure to fill.
****************************************************************************/

    if(initiate=='X' && arr[down][up]!='X' && arr[down][up]!='O') {
        arr[down][up]='X';
        initiate='O';

    }
    else if(initiate=='O' && arr[down][up]!='X' && arr[down][up]!='O') {
        arr[down][up]='O';
        initiate='X';
    }
    else {
        //cout<<"No empty spaces"<<"\n";
        cout<<"game is draw"<<endl;
        return 
        secondfunction();
    }
    

}

/****************************************************************************Function of boolean type because we have to return and false only.In this function we will set the condition for players to win and chk whether the game is still gng on or it is a draw .
****************************************************************************/
bool thirdfunction() {
/****************************************************************************
                              PLAYER TO WIN
****************************************************************************/
    for(int p=0;p<3;p++) {
        if(arr[p][0]==arr[p][1] && arr[p][0]==arr[p][2] || arr[0][p]==arr[1][p] && arr[0][p]==arr[2][p]) {
            return true;
        }
    }
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] || arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0]) {
        return true;
    }

/****************************************************************************                   Finished or still going on 
****************************************************************************/
    for(int p=0;p<3;p++) {
        for(int q=0;q<3;q++) {
            if(arr[p][q]!='x' && arr[p][q]!='0') {
                return false;
/**************************GAME NOT FINISHED********************************/
            }
        }
    }
/****************************************************************************                          Game is draw
****************************************************************************/
    draw=true;
    return false;
}
/****************************************************************************                    Calling three functions
****************************************************************************/
int main() {

    cout<<"----------------"<<endl;
    cout<<"                              "<<"TIC - TAC - TOE"<<endl;
    cout<<"                       "<<"Enter the first player's name :"<<endl;
    cin>>p1;
    cout<<"----------------"<<endl;
    cout<<"                       "<<"Enter the second player's name :"<<endl;
    cin>>p2;

    while(!thirdfunction()) {
        firstfunction();
        secondfunction();
        thirdfunction();
    }
    if(initiate=='X' && draw==false) {
        cout<<p2<<" is the second player who WINS"<<"\n";
    }
    else if(initiate=='O' && draw==false) {
        cout<<p1<<" is the first player who WINS"<<"\n";
    }
    else {
        cout<<"Game is draw"<<"\n";
    }
    return 0;
}