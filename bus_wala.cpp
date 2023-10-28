#include <bits/stdc++.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

using namespace std;

static int count = 0;
int Random(int a, int b)
{
    return (a + rand() % (b - a));
}

class bus
{
    private:
    
    char seat[8][4][10];
    int discount;
    int tax;

    public:
    int bus_num;
    string PassengerName;
    int age;
    string gender;
    string from_city, to_city;
    string arrival_time, departure_time;
    int ticket_price;

    void Load_Booking();
    void Reservation();
    void Seat_Allotment();


    void setDicount(int discount){ this->discount = discount; }
    int getDiscount(){ return discount; }

    void setTax(int tax){ this->tax = tax; }
    int getTax(){ return tax; }
};
bus reserve[10];

void bus::Load_Booking(){
    cout<<"\n\n\tEnter Bus Details : \t\n\n";
    cout<<"Bus number : ";
    cin<< reserve[count].bus_num;
    cout<<"From city : ";
    cin<< reserve[count].from_city ;
    cout<<"To city : ";
    cin<< reserve[count].to_city ;
    cout<<"Distance b/w cities : ";
    cin<< reserve[count].distance ;
    reserve[count].empty();
    count++;
}

void bus::Reservation(){
    cout<<"\n\n\tEnter Reservation Details : \t\n\n";
    cout<<"Bus number : ";
    cin<< reserve[count].bus_num;
    cout<<"From city : ";
    cin<< reserve[count].from_city ;
    cout<<"To city : ";
    cin<< reserve[count].to_city ;
    cout<<"Passenger's name : ";
    cin<< reserve[count].PassengerName ;
    
    reserve[count].empty();
    count++;
}

void bus::Seat_Allotment(){

  int seat;
  char number[5];
  
  top:             // A label

  cout<<"Bus no: ";
  cin>>number;

  int n;
  for(n=0; n<=count; n++){

    //if input(number) == 0, i.e bus num == 0; then break.
    if(strcmp(reserve[n].bus_num, number)==0)
    break;
  }

    while(n<=count){
    cout<<"\nSeat Number: ";
    cin>>seat;

    if(seat>32)
        cout<<"\nThere are only 32 seats available in this bus.";

        else{
        if (strcmp(reserve[n].seat[seat/4][(seat%4)-1], "Empty")==0){

        cout<<"Enter passanger's name: ";
        cin>>reserve[n].seat[seat/4][(seat%4)-1];

        break;

      }

    else

      cout<<"The seat no. is already reserved.\n";

      }

      }

    if(n>count){
      cout<<"Enter correct bus no.\n";
      goto top;
    }

  }


class passenger
{
  protected :
  string pass_name;
  int age;
  string gender;


  public :
  int bus_num;
  string source, destination;

  void New_Booking();
}

void passenger::New_Booking(){
  cout>>"Enter passenger's name: ";
  cin>>pass_name;
  cout<<"Age : ";
  cin<< age;
  cout<<"Gender : ";
  cin<< gender ;
  cout<<"To city : ";
  cin<< reserve[count].to_city ;
  cout<<"Distance b/w cities : ";
  cin<< reserve[count].distance ;
  reserve[count].empty();
  count++;
}





  //----------------------------------------------------------------
  int main()
  {
    /*
    system("cls");

    int w;

    while(1){
    cout<<"\n\n\n\n\n";

    cout<<"\t\t\t1.Install\n\t\t\t"

    <<"2.Reservation\n\t\t\t"

    <<"3.Show\n\t\t\t"

    <<"4.Buses Available. \n\t\t\t"

    <<"5.Exit";

    cout<<"\n\t\t\tEnter your choice:-> ";

    cin>>w;

    switch(w)

    {

    case 1:  reserve[count].Load_Booking();

      break;

    case 2:  reserve[count].Seat_Allotment();

      break;

//    case 3:  bus[0].show();

  //    break;

  //  case 4:  bus[0].avail();

  //    break;

    case 5:  exit(0);

  }

  }
*/



return 0;
}
