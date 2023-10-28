#include<bits/stdc++.h>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;


int RandomInt(int a, int b)
{
    return (a + rand() % (b - a));
}



class bus{
private:
    string b_no, b_name, d_name;
    int b_seats;
public :
    void menu();
    void new_bus();
    void view_bus();
    void single_view_bus();
    void all_view_bus();
    void update_bus();
    void del_bus();
    void rout_bus();
    void detail_bus_seat();
    void booking();
    void renew_bus();
    void search_booking();
    void update_booking();
    void del_booking();
    void show_booking();
};

void bus :: menu(){
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    cout<<"\n\t 1. ADD BUS RECORD"<<endl;
    cout<<"\n\t 2. VIEW BUS DETAILS"<<endl;
    cout<<"\n\t 3. UPDATE BUS DETAILS"<<endl;
    cout<<"\n\t 4. DELETE BUS DETAILS"<<endl;
    cout<<"\n\t 5. ROUTES OF BUSES"<<endl;
    cout<<"\n\t 6. SEAT BOOKING"<<endl;
    cout<<"\n\t 7. SEAT DETAILS"<<endl;
    //cout<<"\n\t 8. SEATS UPDATION"<<endl;
    cout<<"\n\t 8. SEARCH BOOKING RECORD"<<endl;
    cout<<"\n\t 9. UPDATE BOOKING RECORD"<<endl;
    cout<<"\n\t 10. DELETE BOOKING RECORD"<<endl;
    cout<<"\n\t 11. SHOW ALL BOOKING RECORD"<<endl;
    cout<<"\n\t 12. EXIT..."<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        new_bus();
        break;
    case 2:
        view_bus();
        break;
    case 3:
        update_bus();
        break;
    case 4:
        del_bus();
        break;
    case 5:
        rout_bus();
        break;
    case 6:
        booking();
        break;
    case 7:
        detail_bus_seat();
        break;
    //case 8:
      //  renew_bus();
        //break;
    case 8:
        search_booking();
        break;
    case 9:
        update_booking();
        break;
    case 10:
        del_booking();
        break;
    case 11:
        show_booking();
        break;
    case 12:
        exit(0);
    default:
        cout<<"\n\tERROR: Invalid choice...."<<endl;
    }
    getch();
    goto p;

}

void bus :: new_bus(){
    p:
    system("cls");
    fstream file;
    int found = 0;
    string t_no, tb_name, td_name;
    int t_seats;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    cout<<"\n\n Bus No. : ";
    cin>>b_no;
    cout<<"\n\n Bus Name : ";
    cin>>b_name;
    cout<<"\n\n Total seats : ";
    cin>>b_seats;
    cout<<"\n\n Driver name : ";
    cin>>d_name;
    file.open("bus.txt", ios::in);
    if(!file){
        file.open("bus.txt", ios::app|ios::out);
        file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<endl;
        file.close();
    }
    else{
        file>>t_no>> tb_name>>t_seats>>td_name;
        while(!file.eof()){
            if(b_no == t_no){
                found++;
            }
            file>>t_no>> tb_name>>t_seats>>td_name;
        }
        file.close();
        if(found == 0){
            file.open("bus.txt", ios::app|ios::out);
            file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<endl;
            file.close();
        }
        else{
            cout<<"\n\nDuplicate Record Found...";
            getch();
            goto p;
        }
    }
    cout<<"\n\n New Bus Inserted Successfully..."<<endl;
}


void bus :: view_bus(){
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    cout<<"\n\n 1. Single Bus View"<<endl;
    cout<<"\n\n 2. All Buses View"<<endl;
    cout<<"\n\n 3. Go Back"<<endl;
    cout<<"Enter your choice : ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        single_view_bus();
        break;
    case 2:
        all_view_bus();
        break;
    case 3:
        menu();
        break;
    default :
        cout<<"\n\tERROR: Invalid choice...."<<endl;
    }
    getch();
    goto p;
}



void bus :: single_view_bus(){
    system("cls");
    string t_no;
    fstream file;
    int found = 0;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    cout<<"\n\nBus number to view :";
    cin>>t_no;
    file.open("bus.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Bus No. : ";
        cin>>t_no;
        file>>b_no>>b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no == b_no){
                system("cls");
                cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
                cout<<"\n\n Bus No.\tBus Name\tNo. of Seats\tDriver name"<<endl;
                cout<<" "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
                found++;
            }
            file>>b_no>> b_name>>b_seats>>d_name;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n Invalid Bus Number..."<<endl;
        }
    }


}



void bus :: all_view_bus(){
    system("cls");
    fstream file;
    //int found = 0;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    //cout<<"Bus number to view :";
    //cin>>t_no;
    file.open("bus.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        //cout<<"\n\n Bus No. : ";
        //cin>>t_no;
        //new
        cout<<"\n\n Bus No.\tBus Name\tNo. of Seats\tDriver name"<<endl;
        cout<<"--------------------------------------------------------------"<<endl;
        file>>b_no>>b_name>>b_seats>>d_name;
        while(!file.eof()){
            //if(t_no == b_no){
                //cout<<"Bus No.\tBus Name\tNo. of Seats\tDriver name"<<endl;
                cout<<"\n\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
                //found++;
            //}
            file>>b_no>> b_name>>b_seats>>d_name;
        }
        file.close();
        //if(found == 0){
          //  cout<<"\n\n Invalid Bus Number..."<<endl;
        //}
    }


}





void bus :: update_bus(){
    system("cls");
    fstream file, file1;
    string no, t_no, t_name, td_name;
    int t_seats;
    int found = 0;

    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("bus.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Bus No. to update : ";
        cin>>t_no;
        file1.open("bus1.txt", ios::app | ios::out);
        file>>b_no>> b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no == b_no){
                cout<<"\n\n Enter new Bus No. ";
                cin>>no;
                cout<<"\n\n Bus Name : ";
                cin>>t_name;
                cout<<"\n\n No. of Seats : ";
                cin>>t_seats;
                cout<<"\n\n Driver Name : ";
                cin>>td_name;
                file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<endl;
                cout<<"\n\n\n\t Update Bus Record Successfully..."<<endl;
                found++;
            }
            else{
                file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<endl;

            }
            file>>b_no>> b_name>>b_seats>>d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
        if(found == 0){
            cout<<"\n\n Invalid Bus No."<<endl;
        }
    }
}




void bus :: del_bus(){
    system("cls");
    fstream file, file1;
    string t_no;
    int t_seats;
    int found = 0;

    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("bus.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Bus No. to delete : ";
        cin>>t_no;
        file1.open("bus1.txt", ios::app | ios::out);
        file>>b_no>> b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no == b_no){
                //file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<endl;
                cout<<"\n\n\n\t Delete Bus Record Successfully..."<<endl;
                found++;
            }
            else{
                file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<endl;

            }
            file>>b_no>> b_name>>b_seats>>d_name;
        }
        file.close();
        file1.close();
        remove("bus.txt");
        rename("bus1.txt", "bus.txt");
        if(found == 0){
            cout<<"\n\n Invalid Bus No."<<endl;
        }
    }
}



void bus :: rout_bus(){
    p:
    system("cls");
    int choice;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    cout<<"\n\n 0. To exit/go back : "<<endl;
    cout<<" 1. FIrst Route Details : "<<endl;
    cout<<" 2. Second Route Details : "<<endl;
    cout<<" 3. Third Route Details : "<<endl;
    cout<<" 4. Fourth Route Details : "<<endl;
    cout<<" 5. Fifth Route Details : "<<endl;
    cout<<"\n Enter your choice : "<<endl;
    cin>>choice;
    switch (choice)
    {
    case 0:
        menu();
        break;
    case 1:
        cout<<"\n    From : A\t To : B"<<endl;
        cout<<"9:00am ....... 10:00am"<<endl;
        cout<<"\n    From : B\t To : C"<<endl;
        cout<<"10:00am ....... 11:00am"<<endl;
        cout<<"\n    From : C\t To : D"<<endl;
        cout<<"11:00am ....... 12:00pm"<<endl;
        cout<<"\n    From : A\t To : B"<<endl;
        cout<<"12:00pm ....... 1:00pm"<<endl;

        break;
    case 2:
        cout<<"\n    From : A\t To : B"<<endl;
        cout<<"9:00am ....... 10:00am"<<endl;
        cout<<"\n    From : B\t To : C"<<endl;
        cout<<"10:00am ....... 11:00am"<<endl;
        cout<<"\n    From : C\t To : D"<<endl;
        cout<<"11:00am ....... 12:00pm"<<endl;
        cout<<"\n    From : D\t To : E"<<endl;
        cout<<"12:00pm ....... 1:00pm"<<endl;
        break;
    case 3:
        cout<<"\n    From : K\t To : L"<<endl;
        cout<<"9:00am ........ 10:00am"<<endl;
        cout<<"\n    From : L\t To : M"<<endl;
        cout<<"10:00am ....... 11:00am"<<endl;
        cout<<"\n    From : M\t To : N"<<endl;
        cout<<"11:00am ....... 12:00pm"<<endl;
        cout<<"\n    From : N\t To : O"<<endl;
        cout<<"12:00pm ....... 1:00pm"<<endl;
        break;
    case 4:
        cout<<"\n    From : P\t To : Q"<<endl;
        cout<<"9:00am ....... 10:00am"<<endl;
        cout<<"\n    From : Q\t To : R"<<endl;
        cout<<"10:00am ....... 11:00am"<<endl;
        cout<<"\n    From : R\t To : S"<<endl;
        cout<<"11:00am ....... 12:00pm"<<endl;
        cout<<"\n    From : S\t To : T"<<endl;
        cout<<"12:00pm ....... 1:00pm"<<endl;
        break;
    case 5:
        cout<<"\n    From : U\t To : V"<<endl;
        cout<<"9:00am ....... 10:00am"<<endl;
        cout<<"\n    From : V\t To : W"<<endl;
        cout<<"10:00am ....... 11:00am"<<endl;
        cout<<"\n    From : W\t To : X"<<endl;
        cout<<"11:00am ....... 12:00pm"<<endl;
        cout<<"\n    From : X\t To : Y"<<endl;
        cout<<"12:00pm ....... 1:00pm"<<endl;
        cout<<"\n    From : Y\t To : Z"<<endl;
        cout<<"1:00pm ....... 2:00pm"<<endl;
        break;
    default:
        cout<<"\n\tERROR: Invalid choice...."<<endl;
    }
    getch();
    goto p;

}



void bus :: detail_bus_seat(){
    system("cls");
    fstream file, file1;
    string t_no, s_b_no, s_no;
    int count = 0, found = 0;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";

    file.open("bus.txt", ios::in);
    file1.open("seat.txt", ios::in);
    if(!file || !file1){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\nBus No. for seat details : ";
        cin>>t_no;
        file1>>s_b_no>>s_no;
        while(!file1.eof()){
            if(t_no == s_b_no){count++;}
            file1>>s_b_no>>s_no;
        }
        file1.close();
        file>>b_no>> b_name>>b_seats>>d_name;
        while(!file.eof()){
            if(t_no == b_no){
                system("cls");
                cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
                cout<<"\n\n Total no. of seats : "<<b_seats<<endl;       //bus file
                cout<<"\n Total reserved seats : "<<count<<endl;         //seat file
                cout<<"\n Total empty seats : "<<b_seats - count<<endl;
                found++;
            }
            file>>b_no>> b_name>>b_seats>>d_name;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n Invalid Bus No."<<endl;
        }
    }

}





void bus :: booking(){
    p:
    system("cls");
    fstream file;
    int s_no, seats, s_s_no;
    int found = 0, count = 0, i = 0, ss_no[15];
    //single person can book max 15 seats
    char x;
    string Pass_name, phone, from, to;
    int s_amount, total_amount = 0, r_amount;
    string t_no, s_b_no;
    srand(time(0));
    int k=(RandomInt(10,30));
    float discount = k*0.01;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("bus.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
  else{
    cout<<"\n\n Bus No. : ";
    cin>>t_no;
    file.close();
    file.open("seat.txt, ios::in");
    if(file){
    file>>s_b_no>>s_s_no;
    while(!file.eof()){
      if(t_no == s_b_no)
        count++;
        file>>s_b_no>>s_s_no;
        }
      file.close();
    }

    file.open("bus.txt", ios::in);
    file>>b_no>> b_name>>b_seats>>d_name;
    while(!file.eof()){
      if(t_no == b_no){
       seats = b_seats;
        found++;
      }
      file>>b_no>> b_name>>b_seats>>d_name;
    }
    file.close();

    if(seats-count == 0){
      cout<<"\n\n All seats already reserved..."<<endl;
    }

    else if(found == 1){
      do
      {
        h:
        cout<<"\n\n Seat No. : ";
        cin>>s_no;
        if(s_no > seats){
          cout<<"\n\n Seat No. is invalid...Try Again"<<endl;
          goto h;
        }
        file.open("seat.txt", ios::in);
          if(!file){
            file.open("seat.txt", ios::app | ios::out);
            file<<t_no<<" "<<s_no<<endl;
            file.close();
          }

          else{
            file>>s_b_no>>s_s_no;
            while(!file.eof()){
              if(t_no == s_b_no && s_no == s_s_no){
                cout<<"\n\n Seat already reserved, try again"<<endl;
                file.close();
                goto h;
              }
              file>>s_b_no>>s_s_no;
            }
            file.close();
            file.open("seat.txt", ios::app | ios::out);
            file<<t_no<<" "<<s_no<<endl;
            file.close();
          }
        ss_no[i] = s_no;
        i++;
        cout<<"\n\n Booking another seat (Y,N) : ";
        cin>>x;
      } while (x == 'Y' || x == 'y');
        system("cls");
        cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
        cout<<"\n\n Passenger Name : ";
        cin>>Pass_name;
        cout<<"\n\n Phone No. :";
        cin>>phone;
        cout<<"\n\n From : ";
        cin>>from;
        cout<<"\n\n To: ";
        cin>>to;
        s_amount=(RandomInt(150,1000));
        cout<<"\n\n Seat Amount : "<<s_amount;
        total_amount = s_amount*i;
        float final_amount = total_amount*(1-discount);
        cout<<"\n\n Total amount : "<<final_amount<<endl;
        cout<<"\n Received amount from passenger : ";
        cin>>r_amount;
        file.open("customer.txt", ios::app | ios::in);
        file<<Pass_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<endl;
        file.close();

        system("cls");
        cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
        cout<<"\n\n\t\t*************************************************"<<endl;
        cout<<"\n\n\t\t__________BOOKING INFO____________"<<endl;
        cout<<"\n\n\t\t*************************************************"<<endl;
        cout<<"\n\n\t\tName :          "<<Pass_name<<endl;
        cout<<"\n\t\tFrom :            "<<from<<endl;
        cout<<"\n\t\tTo :              "<<to<<endl;
        cout<<"\n\t\tTotal Seats :     "<<Pass_name<<endl;
        cout<<"\n\t\tReserved Seats :  ";
        for(int j = 0; j<i; j++){
          if(j != 0)
          cout<<", ";
          cout<<ss_no[j];
        }
        cout<<"\n\t\tSingle seat amount 	         	 : "<<s_amount<<endl;
        cout<<"\t\tTotal amount         		         : "<<total_amount<<endl;
        cout<<"\t\tPercentage of discount   	         : "<<k<<endl;
        cout<<"\t\tTotal amount after discount nd taxes  : "<<final_amount<<endl;
        cout<<"\t\tReceive amount       	       	     : "<<r_amount<<endl;
        cout<<"\t\tReturn amount 				         : "<<r_amount - final_amount<<endl;
        cout<<"\n\n\t\t*************************************************"<<endl;
        cout<<"\n\n\t\t\tTHANK YOU FOR BOOKING...."<<endl;
        cout<<"\n\n\t\t*************************************************"<<endl;

    }

    else{
      cout<<"\n\n Invalid Bus No.\tTry again..."<<endl;
      getch();
      goto p;
    }
  }
}




/*
void bus :: renew_bus(){
    p:
    system("cls");
    fstream file;
    char x;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("seat.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Do you want to renew all seats (Y/N)? : ";
        cin>>x;
        if(x == 'Y' || x == 'y'){
            remove("seat.txt");
            cout<<"\n\n\t\t Thank you! All seats empty..."<<endl;

        }
        else{
            cout<<"\n\n\t\t Thank you! All seats reservation saved..."<<endl;
        }
    }
}
*/


void bus :: search_booking(){
    p:
    system("cls");
    fstream file;
    string name, no, phone, t_name;
    int t_seats, t_amo, found = 0;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("customer.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Passenger name : ";
        cin>>t_name;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_name == name){
                cout<<"\n\n Passenger name : "<<name<<endl;
                cout<<"\n Bus No. : "<<no<<endl;
                cout<<"\n Phone No. : "<<phone<<endl;
                cout<<"\n Reserved seats : "<<t_seats<<endl;
                cout<<"\n Total amount : "<<t_amo<<endl;
                found++;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n No Passenger with this detail found..."<<endl;
        }
    }
}

/*
void bus :: update_booking(){
    system("cls");
    fstream file, file1;
    string name, no, phone, t_name, t_phone;
    int t_seats, t_amo, found = 0, i = 0;
    string del_no;
    string del_seats;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("customer.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Phone number of passenger : "<<endl;
        cin>>t_phone;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_phone == phone){
                file.close();
                file.open("customer.txt", ios::in);
                file1.open("customer1.txt", ios::app | ios::out);
                file>>name>>no>>phone>>t_seats>>t_amo;
                while(!file.eof()){
                        if(t_phone != phone){
                            del_no = no;
                            del_seats = seats;
                        }
                    if(t_phone != phone){
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<endl;
                    }
                    file>>name>>no>>phone>>t_seats>>t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt", "customer.txt");
                file.open("seat.txt", ios::in);
                file1.open("seat1.txt", ios::app | ios::out);
                file>>no>>t_seats;
                while(!file.eof()){
                    if(!(del_no==no && i<del_seats)){
                        file1<<no<<" "<<t_seats<<endl;
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file.close();
                remove("seat.txt");
                rename("seat1.txt", "seat.txt");
                //detail removed, seat emptied. so recalling fn
                booking();
                found ++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        h:
        if(found == 0){
            cout<<"\n\n No passenger found with this number..."<<endl;
        }
    }
}
*/






void bus :: update_booking(){
    system("cls");
    fstream file, file1;
    int t_seats, t_amo, found = 0, i = 0;
    string name, no, phone, t_phone;
    int del_seats;
    string del_no;

    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("customer.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Phone number of passenger : "<<endl;
        cin>>t_phone;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_phone == phone){
                file.close();
                file.open("customer.txt", ios::in);
                file1.open("customer1.txt", ios::app | ios::out);
                file>>name>>no>>phone>>t_seats>>t_amo;
                while(!file.eof()){
                    if(t_phone == phone){
                        del_no = no;
                        del_seats = t_seats;
                    }
                    if(t_phone != phone){
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<endl;
                    }
                    file>>name>>no>>phone>>t_seats>>t_amo;
                }

                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt", "customer.txt");

                file.open("seat.txt", ios::in);
                file1.open("seat1.txt", ios::app | ios::out);
                file>>no>>t_seats;
                while(!file.eof()){
                    if(!(del_no==no && i<del_seats)){
                        file1<<no<<" "<<t_seats<<endl;
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file.close();
                remove("seat.txt");
                rename("seat1.txt", "seat.txt");
                //detail removed, seat emptied. so recalling fn
                booking();

                found ++;
                goto h;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }

        file.close();
        h:
        if(found == 0){
            cout<<"\n\n No passenger found with this number..."<<endl;
        }
    }
}



void bus :: del_booking(){
    system("cls");
    fstream file, file1;
    string name, no, phone, t_name, t_phone;
    int t_seats, t_amo, found = 0, i = 0;
    string del_no;
    int del_seats;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________";
    file.open("customer.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        cout<<"\n\n Phone number of passenger : "<<endl;
        cin>>t_phone;
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){
            if(t_phone == phone){
                file.close();
                file.open("customer.txt", ios::in);
                file1.open("customer1.txt", ios::app | ios::out);
                file>>name>>no>>phone>>t_seats>>t_amo;
                while(!file.eof()){
                        if(t_phone != phone){
                            del_no = no;
                            del_seats = t_seats;
                        }
                    if(t_phone != phone){
                        file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<endl;
                    }
                    file>>name>>no>>phone>>t_seats>>t_amo;
                }
                file.close();
                file1.close();
                remove("customer.txt");
                rename("customer1.txt", "customer.txt");
                file.open("seat.txt", ios::in);
                file1.open("seat1.txt", ios::app | ios::out);
                file>>no>>t_seats;
                while(!file.eof()){
                    if(!(del_no==no && i<del_seats)){
                        file1<<no<<" "<<t_seats<<endl;
                    }
                    file>>no>>t_seats;
                }
                file.close();
                file.close();
                remove("seat.txt");
                rename("seat1.txt", "seat.txt");
                //detail removed, seat emptied. so recalling fn
                //booking();
                found ++;
                cout<<"\n"<<"------------SUCCESSFULLY DELETED--------------"<<endl;
                goto h;
            }
            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        h:
        if(found == 0){
            cout<<"\n\n No passenger found with this number..."<<endl;
        }
    }
}





void bus :: show_booking(){
    p:
    system("cls");
    fstream file;
    string name, no, phone, t_name;
    int t_seats, t_amo, found = 0;
    cout<<"\n\t\t__________BUS MANAGEMENT SYSTEM____________"<<endl;
    file.open("customer.txt", ios::in);
    if(!file){
        cout<<"File opening error..."<<endl;
    }
    else{
        file>>name>>no>>phone>>t_seats>>t_amo;
        while(!file.eof()){

            cout<<"\n\n Passenger name : "<<name<<endl;
            cout<<"\n Bus No. : "<<no<<endl;
            cout<<"\n Phone No. : "<<phone<<endl;
            cout<<"\n Reserved seats : "<<t_seats<<endl;
            cout<<"\n Total amount : "<<t_amo<<endl;
            cout<<"----------------------------------------------"<<endl<<endl;
            found++;

            file>>name>>no>>phone>>t_seats>>t_amo;
        }
        file.close();
        if(found == 0){
            cout<<"\n\n No any booking record found..."<<endl;
        }
    }
}


main(){
    p:
    system("cls");
    bus b;
    string owner, pass;
    char ch;
    cout<<"\n\n\t\t\t***SECURITY VERIFICATION***"<<endl;
    cout<<"\n Owner's name(Case Sensitive) : ";
    cin>>owner;
    cout<<"\n\n Password(Case Sensitive) : ";
    for (int i = 1; i <= 6; i++)
    {
        ch = getch();
        pass += ch;
        cout<<"*";
    }
    if(owner == "Marcopolo" && pass == "Grp@16"){
        cout<<"\n\n\n\t\tLoading...";
        for (int i = 1; i <= 5; i++)
        {
            Sleep(500);
            cout<<".";
        }
        b.menu();
    }
    else{
        cout<<"***ERROR***\n\n\t\tWrong username or password."<<endl;
        cout<<"\n\t\tPress any key to retry (:"<<endl;
        getch();
        goto p;
    }
    }











