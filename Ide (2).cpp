//Mini project(ATM)
#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
/*Mini project - ATM
   -->Check Balance
   -->Cash Withdraw
   -->User details
   -->Update Mobile Number
*/

class atm{                          //class atm
     private:                       //private member variables
          long long account_No;
          string name;
          int PIN;
          double balance;
          string mobile_No;
          
     public:                        //public member functions
          //SetData function is setting the Data into the private member variables
          void SetData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_No_a){
               account_No=account_No_a; // assigning the formal arguments to the private member variables
               name=name_a;
               PIN=PIN_a;
               balance=balance_a;
               mobile_No=mobile_No_a;
               
               
          }
          
          //getAccountNo. function is returning the user's Account no.
          long int getAccountNo(){
               return account_No;
          }
          //getName function is returning the user's Name
          string getName(){
               return name;
          }       
          //getPIN function is returning the user's PIN
          int getPIN(){
               return PIN;
          }
          //getBalance function is returning the user's Bank Balance
          double getBalance(){
               return balance;
          }
          //getMobileNo function is returning the user's Mobile No.
          string getMobileNo(){
               return mobile_No;
          }
          //setMobile function is updating the user's mobile no.
          void setMobile(string mob_prev,string mob_new){
               if(mob_prev==mobile_No){   //It will check if old mobile no is same
                    mobile_No=mob_new;    //update with new , if old matches
                    cout<<endl<<"Successfully Updated Mobile no.";
                    getch();      //getch is to hold the screen (until user press any key)
                    
               }
               else{               //do not update if old mobile no. does not matches
                    cout<<endl<<"Incorrect !!! Old Mobile No";
                    getch();      //getch is to hold the screen (until user press any key)
               }
          }
          //cashwithdraw function is used to Withdraw money from ATM 
          void cashWithDraw(int amount_a){
               if(amount_a > 0 && amount_a < balance){      //check entered amount validity
                    balance -= amount_a;
                    cout<<endl<<"Please Collect Your Cash";
                    cout<<endl<<"Available Balance : "<<balance;
                    getch();      //getch is to hold the screen (until user press any key)
               }  
               else{
                    cout<<"Invalid Input or Insufficient Balance";
                    getch();      //getch is to hold the screen (until user press any key)
               }
          }
          
};

/////////////////////////// Main Functions //////NIRAJ// 4/01/2022 
int main(){
     int choice=0,enterPIN;        //-->user authentication
     long int enterAccountNo;
     
     system("cls");
     
     //created User(object)
     atm user1;
     //set user details (into object)     (Setting Default Data)
     user1.SetData(1234567,"NIRAJ",1234,45000.90,"9162876585");
     
     do{
          system("cls");
          
          cout<<endl<<"****Welcome to ATM****"<<endl;
          cout<<endl<<"Enter Your Account No ";
          cin>>enterAccountNo;
          
          cout<<endl<<"Enter PIN ";
          cin>>enterPIN;
          
          
          //check whether entered values matches with user details
          if((enterAccountNo==user1.getAccountNo()) && (enterPIN==user1.getPIN())){
               do{
                    int amount=0;
                    string oldMobileNo,newMobileNo;
                    
                    system("cls");
                    //user interface
                    cout<<endl<<"****Welcome to ATM****"<<endl;
                    cout<<endl<<"Select Options ";
                    cout<<endl<<"1. Check Balance";
                    cout<<endl<<"2. Cash Withdraw";
                    cout<<endl<<"3. Show User Details";
                    cout<<endl<<"4. Update Mobile No. ";
                    cout<<endl<<"3. Exit ";
                    cin>>choice;   // taking choice
                    
                    switch(choice){
                         case 1: 
                              cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                              
                              getch();
                              break;
                              
                         case 2:
                              cout<<endl<<"Enter The Amount : ";
                              cin>>amount;
                              user1.cashWithDraw(amount);     //calling Withdraw function and passing Withdraw amount
                              
                              break;
                              
                         case 3:
                              cout<<endl<<"**** User Details are :- ";
                              cout<<endl<<"-> Account no. "<<user1.getAccountNo();
                              cout<<endl<<"-> Name        "<<user1.getName();
                              cout<<endl<<"-> Balance     "<<user1.getBalance();
                              cout<<endl<<"-> Mobile no.  "<<user1.getMobileNo();
                              
                              getch();
                              break;
                              
                         case 4: 
                              cout<<endl<<"Enter Old Mobile No. ";
                              cin>>oldMobileNo;
                              
                              cout<<endl<<"Enter New Mobile No. ";
                              cin>>newMobileNo;
                              
                              user1.setMobile(oldMobileNo,newMobileNo);
                              break;
                              
                         case 5:
                              exit(0);
                         
                         default:
                              cout<<endl<<"Enter Valid Data !!!";
                    }
               }while(1);              //MENU //condition will always TRUE and loop is capable of running infinite times
          }
          else {
               cout<<endl<<"User Details are Invalid !!! ";
               getch();
          }
          
     }
     while(1);    //LOGIN          //condition will always TRUE and loop is capable of running infinite times
     
     
     return 0;
}








