#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

/*  we are using static because static keyword value 
    "finish" when main function end
    if we are not using static keyword its value 
    end after any local function is return  
*/
int static bus_count;

class depo{

     public:
    /* we are using char datatype bcoz in this project we are 
    comparing many string value
    */ 
    char install_bus_no[5];
    char arrival_time[5];
    char departure_time[5];
    char seat_number[8][4][10];
    char driver_name[20];
    char from[20];
    char to[20];
   
    // class member function name which  we are using
    int install_bus();
    int reservation();
    int installed_bus_info();
    int empty_seat();
    int seat_info();
    int seat_position(int count);

    // we are making this project for 10 buses
    // each bus we have 32 seats
}bus[10];

// this function used for install bus
int depo :: install_bus()
{
    cout<<"enter your install bus number : ";
    cin>>bus[bus_count].install_bus_no;

    cout<<"enter driver name             : ";
    cin>>bus[bus_count].driver_name;

    cout<<"enter arrival time            : ";
    cin>>bus[bus_count].arrival_time;

    cout<<"enter departure time          : ";
    cin>>bus[bus_count].departure_time;

    cout<<"enter from place              : ";
    cin>>bus[bus_count].from;

    cout<<"enter to place                : ";
    cin>>bus[bus_count].to;

    // we are calling this function bcoz in begining
    //all seat is empty
    bus[bus_count].empty_seat();

    // bus_count increment
    bus_count++;

}

// this function is used for tickit reservation
int depo::reservation()
{
    /* here we are takig int type seat no bocz we are deviding
       seat number in progeam
   */
    int seat_number,n;
    char bus_number[5];

// add lable
top:

    // this bus number for comparing with install bus number
    
    cout<<"enter bus number: "<<endl;
    cin>>bus_number;

    /*  this loop is search all install bus number and compare
        with our bus numbner and if compare is succesfull then 
        break the loop
    */
 
    for(n=0;n<=bus_count;n++)
    {
        if(strcmp(bus[n].install_bus_no,bus_number)==0)
        break;
    }
   
    while(n<=bus_count)
    {
        cout<<"enter seat number: "<<endl;
        cin>>seat_number;

        //cheack if seat number is greater then 32
        if(seat_number > 32)
        {
            cout<<"we have only 32 seat availabale in this bus: "<<endl;
        }
        // seat number is less then 32 then check the seat availibility
        else
        {
            // cheack seat availibility if yes then enter pessanger name
            // we have 8 row and 4 collum

            /*logic : assume our bus no =1 and seat no = 10 then
            bus[1].seat[10\4=2.5][(10%4=2)-1]=bus[1].seat[2][1]
            which means our seat is 2nd row and 1st collum
            Note:row and collum start with zero
            */
            if(strcmp(bus[n].seat_number[seat_number/4][(seat_number%4)-1],"empty")==0)
            {
                // first our seat number 10 = empty
                // now empty replace with the pessanger name
                cout<<"enter pessanger name:"<<endl;
                cin>>bus[n].seat_number[seat_number/4][(seat_number%4)-1];
                break;
            }
            // if seat is not avalilable
            else     
                cout<<"this seat number is already reserved:"<<endl;        
        }
    }

   if(n > bus_count)
   {
       cout<<"enter correct bus number:"<<endl;
       goto top;
   }
  
}

// this function is used for printing install bus information
int depo::installed_bus_info()
{

    for(int a=0;a<bus_count;a++)
    {
        // printing all information 
        cout<<"-------------------------------------------------"<<endl;
        cout<<"install bus number : "<<bus[a].install_bus_no<<endl;
        cout<<"driver name        : "<<bus[a].driver_name<<endl;
        cout<<"arrival time       : "<<bus[a].arrival_time<<endl;
        cout<<"departure time     : "<<bus[a].departure_time<<endl;
        cout<<"from place         : "<<bus[a].from<<endl;
        cout<<"to place           : "<<bus[a].to<<endl;
    }
        cout<<"-------------------------------------------------"<<endl;
        cout<<endl;

}

// this function is copy "empty in every seat number"
int depo:: empty_seat()
{
    // total 32 seat available in each bus
    //8*4 matrix
    for (int  s = 0; s < 8; s++)
    {
        for (int t = 0; t < 4; t++)
        {
            // this function is copy "empty" in every seat number
            strcpy(bus[bus_count].seat_number[s][t],"empty");
        }
        
    }
    
}

//this function used for know detail of bus information and seat number
int depo::seat_info()
{
    int i;
    char  bus_number[5];
    cout<<"enter the bus number:"<<endl;
    cin>>bus_number;

    for( i=0;i<=bus_count;i++)
    {
        //compare the bus number
        if(strcmp(bus[i].install_bus_no,bus_number)==0)
        break;
    }
    
    while(i<=bus_count)
    {
        // printing all information 
        cout<<"-------------------------------------------------"<<endl;
        cout<<"install bus number : "<<bus[i].install_bus_no<<endl;
        cout<<"driver name        : "<<bus[i].driver_name<<endl;
        cout<<"arrival time       : "<<bus[i].arrival_time<<endl;
        cout<<"departure time     : "<<bus[i].departure_time<<endl;
        cout<<"from place         : "<<bus[i].from<<endl;
        cout<<"to place           : "<<bus[i].to<<endl;
        cout<<"-------------------------------------------------"<<endl;
            
        // position function calling
        // this function set seat on position
        bus[i].seat_position(i);

       int seat_count=1;
       
        for(int m=0;m<8;m++)
        {
            for(int n=0;n<4;n++)
            {
                // seat number count is incrament
                seat_count++;

                // comparing seat number
                if(strcmp(bus[i].seat_number[m][n],"empty")!=0)

                    // prining  alloted seat number
                    cout<<"seat number "<<(seat_count-1)<<" is reserver for "<<bus[i].seat_number[m][n]<<endl;

            }
        }
        
        break;
       
    }

    if(i>bus_count)   
        cout<<"enter correct bus number:"<<endl;

}

// seat positon
int depo:: seat_position(int count)
{
    int num_count=0;
    int bus_count=0;

    for(int c=0;c<8;c++)
    {
        for(int d=0;d<4;d++)
        {
            cout<<endl;
            num_count++;

            if(strcmp(bus[count].seat_number[c][d],"empty")==0)
            {                               
                cout<<num_count<<".";
                cout<<bus[count].seat_number[c][d];
                bus_count++;
            }

            else
            {
                cout<<num_count<<".";            
                cout<<bus[count].seat_number[c][d];
            }
        }
        cout<<endl;
     
    }
        cout<<"\n\nThere are "<<bus_count<<" seats empty in Bus No: "<<bus[count].install_bus_no<<endl;

}

//driver code
int main()
{
    while(1)
    {
        int choise;
        // information
        cout<<"*************************************************"<<endl;
        cout<<"     1 : install bus"<<endl;
        cout<<"     2 : reservation"<<endl;
        cout<<"     3 : installed bus informatio"<<endl;
        cout<<"     4 : seat information"<<endl;
        cout<<"     5 : exit"<<endl;
        cout<<"*************************************************"<<endl;

        //  select choise
        cout<<"       -> enter your choise : ";
        cin>>choise;
        cout<<"*************************************************"<<endl;

        switch (choise)
        {
            case 1: bus[bus_count].install_bus();  
                break;

            case 2: bus[bus_count].reservation();
                break;

            case 3: bus[bus_count].installed_bus_info();
                break;

            case 4: bus[bus_count].seat_info();
                break;

            case 5:
                exit(0);
                break;

            default:
                cout<<"wrong input....again enter your choise\n"<<endl;
                break;
        }
    }
   
    return 0;
}
