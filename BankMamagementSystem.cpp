#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Account{
    private:
    int account_number;
    string name;
    string cnic;
    string phone_number;
    string address;
    double balance;
    string password;
    public:

    Account(){
        account_number=0;
        name="";
        cnic="";
        phone_number="";
        address="";
        balance=0;
        password="";
    }
    Account(int ac, string n, string c, string ph, string a, double b, string p){
        account_number=ac;
        name=n;
        cnic=c;
        phone_number=ph;
        address=a;
        balance=b;
        password=p;
    }
    void input(){
        cout<<"Enter your Account Number: ";
        cin>>account_number;
        cout<<"Enter name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter CNIC number: ";
        getline(cin,cnic);
        cout<<"Enter mobile number: ";
        getline(cin,phone_number);
        cout<<"Enter Address: ";
        getline(cin,address);
        cout<<"Enter Balance: ";
        cin>>balance;
        cout<<"Enter Password: ";
        cin.ignore();
        getline(cin,password);

    }
    void display(){
        cout<<"\n----------------------------------\n";
        cout<<"Account number is: "<<account_number<<endl;
        cout<<"Name is: "<<name<<endl;
        cout<<"CNIC number is: "<<cnic<<endl;
        cout<<"Mobile number is: "<<phone_number<<endl;
        cout<<"Address is: "<<address<<endl;
        cout<<"Balance is: "<<balance<<endl;
        cout<<"Password is: "<<"**********"<<endl;
        cout<<"\n----------------------------------\n";
    }
    int ac(){
        return account_number;
    }
    void deposit(){
        double amount;
        cout<<"Enter amount to deposit: ";
        cin>>amount;
        if(amount<=0){
            cout<<"Invalid amount to deposit...\n";
        }
        else{
            balance+=amount;
        cout<<amount<<" Deposited Successfully..."<<endl;
        cout<<"New balance is: "<<balance<<endl;
        }
    }
    void withdraw(){
        double amount;
        cout<<"Enter amount to withdraw: ";
        cin>>amount;
        if(amount<=0){
            cout<<"Invalid amount to withdraw...\n";
        }
        else{
             if(amount<=balance){
            balance-=amount;
            cout<<amount<<" Withdrawn Succssfully..."<<endl;
            cout<<"Current balance is: "<<balance<<endl;
        }
        else{
            cout<<"insufficient balance to withdraw "<<amount;
        }
        }
    }
    void update(){
        cout<<"Enter new name: ";
        cin.ignore();
        getline(cin,name);
        cout<<"Enter new CNIC No. : ";
        getline(cin,cnic);
        cout<<"Enter new Phone Number: ";
        getline(cin,phone_number);
        cout<<"Enter new Address: ";
        getline(cin,address);
        cout<<"Enter new password: ";
        getline(cin,password);
    }
    double getbalance(){
        return balance;
    }
    void addbalance(double amount){
        balance+=amount;
    }
    
    void deductbalance(double amount){
        balance-=amount;
    }
};

class Bank{
    private:
    vector<Account>Accounts;
    public:
    void createAccount(){
        Account a;
        a.input();
        Accounts.push_back(a);
        cout<<"Account created successfully...\n";
    }
    void displayAccounts(){
        if(Accounts.empty()){
            cout<<"No accounts to show...";
        }
        else{
        for(int i=0; i<Accounts.size();i++){
            Accounts[i].display();
        }
    }
    }
    void searchAccount(){
        int A;
        bool found=false;
        cout<<"Enter Account Number: ";
        cin>>A;
        for(int i=0;i<Accounts.size();i++){
            if(Accounts[i].ac() == A){
                Accounts[i].display();
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Account not found..."<<endl;
        }
    }
    void deleteAccount(){
        int B;
        bool found=false;
        cout<<"Enter Account Number: ";
        cin>>B;
        for(int i=0;i<Accounts.size();i++){
            if(Accounts[i].ac()==B){
            Accounts.erase(Accounts.begin()+i);
            cout<<"Account deleted Successfully..."<<endl;
            found=true;
            break;
            }
        }
        if(!found){
            cout<<"Account not found..."<<endl;
        }
    }
    void updateAccount(){
        int C;
        bool found=false;
        cout<<"Enter Account Number: ";
        cin>>C;
        for(int i=0; i<Accounts.size();i++){
            if(Accounts[i].ac()==C){
                Accounts[i].update();
                cout<<"Record updated Successfully..."<<endl;
                found=true;
                break;
            }
        }
        if(!found){
            cout<<"Account not found..."<<endl;
        }
    }
    void depositAccount(){
        int D;
        bool found=false;
        cout<<"Enter account number: ";
        cin>>D;
        for(int i=0; i<Accounts.size();i++){
            if(Accounts[i].ac()==D){
                Accounts[i].deposit();
                found = true;
                break;
            }
        }
        if(!found){
            cout<<"Account not found..."<<endl;
        }
    }
    void withdrawAccount(){
        int E;
        bool found=false;
        cout<<"Enter Account Number: ";
        cin>>E;
        for(int i=0;i<Accounts.size();i++){
            if(Accounts[i].ac()==E){
                Accounts[i].withdraw();
                found=true;
                break;
            }
        }
        if(!found){
            cout<<"Account not found...";
        }
    }
    void transfermoney(){
        int sender;
        int reciever;
        cout<<"Enter sender account number: ";
        cin>>sender;
        cout<<"Enter reciever account number: ";
        cin>>reciever;
        if(sender==reciever){
            cout<<"Sender and Reciever cannot be same...\n";
            return;
        }
        int senderindex=-1;
        int recieverindex=-1;
        for(int i=0; i<Accounts.size();i++){
            if(Accounts[i].ac()==sender){
                senderindex=i;
            }
            if(Accounts[i].ac()==reciever){
                recieverindex=i;
            }
        }
        if(senderindex==-1){
            cout<<"Sender account not found...\n";
            return;
        }
        if(recieverindex==-1){
            cout<<"Reciever account not found...\n";
            return;
        }
        int amount;
        cout<<"Enter amount: ";
        cin>>amount;
    if(amount>0){
        if(Accounts[senderindex].getbalance()<amount){
            cout<<"Insufficient balance to transfer "<<amount;
            return;
        }
        Accounts[senderindex].deductbalance(amount);
        Accounts[recieverindex].addbalance(amount);
        cout<<"Money transferred successfully...\n";
    }
    else{
        cout<<"Invalid amount to transfer...\n";
    }
}
};

int main(){
    int choice;
    Bank b;
    do{
        cout<<"\n----------------------"<<endl;
        cout<<"Bank Management System"<<endl;
        cout<<"----------------------\n"<<endl;
        cout<<"1.Create new account.\n";
        cout<<"2.Display accounts.\n";
        cout<<"3.Search your Account.\n";
        cout<<"4.Update your Account.\n";
        cout<<"5.Delete your Account.\n";
        cout<<"6.Deposit amount.\n";
        cout<<"7.Withdraw Amount\n";
        cout<<"8.Transfer Money\n";
        cout<<"9.Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;

        switch(choice){
        case 1:{
            b.createAccount();
            break;
        }
        case 2:{
            b.displayAccounts();
            break;
        }
        case 3:{
            b.searchAccount();
            break;
        }
        case 4:{
            b.updateAccount();
            break;
        }
        case 5:{
            b.deleteAccount();
            break;
        }
        case 6:{
            b.depositAccount();
            break;
        }
        case 7:{
            b.withdrawAccount();
            break;
        }
        case 8:{
            b.transfermoney();
            break;
        }
        case 9:{
            cout<<"------Thankyou------"<<endl;
            break;
        }
        default:{
            cout<<"Invalid choice...";
            break;
        }
    }
    }while(choice!=9);
    
    return 0;
}