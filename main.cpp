//Movie Ticket Management System
#include<iostream>
#include<string>
using namespace std;

class person
{
    string name;
    long long validID;
    long long phone;

public:
    person();
    // person(string n, long long c, long long p);
    void setname(string n);
    string getname();
    void setvalidID(long long c);
    long long getvalidID();
    void setphone(long long p);
    long long getphone();

    void insert();
    void display();   
};
class customer : public person
{
    int customerID;
    string address;
public:
    customer();
    void setcustomerID(int);
    int getcustomerID();
    void checkcustomer();
    void getinfo();
    void menu();
    void setaddress(string);
    string getaddress();
    void oldcustomer();
};
class membership
{
    string user;
    string pswrd;
public:
    int check=1;
    membership();
    void setuser(string);
    string getuser();
    void setpassword(string);
    string getpassword();
    void memberships();
    void Admin();
};
class Movie: public membership, public customer
{
    string moviename;
    string dimension;
    string director;
    string runtime;
    string genre;
    string release;

public:
    Movie();
    customer c;
    membership m;
    int time;
    void setmoviename(string);
    string getmoviename();
    void setdimension(string);
    string getdimension();
    void setdirector(string);
    string getdirector();
    void setruntime(string);
    string getruntime();
    void setgenre(string);
    string getgenre();
    void setreleasedate(string);
    string getreleasedate();
    void menu();
    void memoperation();

    void nowplaying();
    void schedule();
    void movieselected(Movie ms);
    void viewbooking();
    void addmovie();
    void movielist();
};
class Time
{
    string movietime;

public:
    Time();
    void setMovieTime(string);
    string getMovieTime();
    void Timing1();
    void Timing2();
    void Timing3();
    void Timing4();
};
class Ticket: public Time, public Movie
{
    double price;
    string gold_silver;
    int num;
    int seatavailable;

public:
    int ID;
    Time tim;
    Movie m;
    Ticket();
    void setID(int);
    int getID();
    void timings();

    void setPrice(double);
    double getPrice();
    void setNumber(int);
    int getNumber();
    void schedule();
    void tickettype();
    void ticket_view();
    void price_view();
    void num_ticket();
    void movie1();
    void movie2();
    void movie3();
    void movie4();
    void display();
    
    void setTicketType(string);
    string getTicketType();
    void setSeat(int);
    int getSeat();
    void seatavailabe();
};

int main()
{
    int ch,local=1,tID=11101;
    Movie m;
    Ticket t;
    customer c;
    membership me;
    again:
    me.Admin();
    if(me.check==1)
    {
        cout<<"\n\t\t\t************INVALID USERNAME OR PASSWORD***********"<<endl;
        cout<<"\n\t\t\tSESSION HAS BEEN TERMINATED!!!PLEASE RETRY!!!\n"<<endl;
        goto again;
    }
    do
    {
        m.menu();
        cout<<"\n\t\t\tEnter Your Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:
                cout<<"\n\n******************************************************************"<<endl;
                cout<<"Movie List"<<endl;
                t.schedule();
                t.tickettype();
                tID++;
                t.setID(tID);
                t.display();
            break;
            case 2:
                t.ticket_view();
            break;
            case 3:
                t.price_view();
            break;
            case 4:
                t.seatavailabe();
            break;
            case 5:
                t.timings();
            break;
            case 6:
                m.movielist();
            break;
            case 7:
                m.memoperation();
                cout<<"\n\n";
                cin.ignore();
                c.insert();
                c.oldcustomer();
                c.display();
            break;
            case 8:
                cin.ignore();
                m.addmovie();
            break;
            case 9:
                goto again;
            default:
            break;
        }
        cout<<"\n\n\t\t\t\t\tEnter 1 to go back to Main Menu"<<endl;
        cout<<"\t\t\t\t\tEnter 0 to Exit"<<endl;
        cout<<"\t\t\t\t\tChoice: ";
        cin>>local;
    }while(local==1);

    return 0;
}

person::person()
{
    string n="user";
    long long c=0000111122223333;
    long long p=1234567890;
    this->name = n;
    this->validID = c;
    this->phone = p;
}
void person::setname(string n)
{
    this->name = n;
}
string person::getname()
{
    return name;
}
void person::setvalidID(long long c)
{
    this->validID = c;
}
long long person::getvalidID()
{
    return validID;
}
void person::setphone(long long p)
{
    this->phone = p;
}
long long person::getphone()
{
    return phone;
}

void person::insert()
{
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tEnter your Name: ";
    getline(cin,name);
    setname(name);
    cout<<"\t\t\tEnter your Valid ID Number: ";
    cin>>validID;
    cout<<"\t\t\tEnter your Phone Number: ";
    cin>>phone;
    cout<<"\t\t\t**************************************************"<<endl;
}
void person::display()
{
    
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\t\t\tDetails: "<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\t\t\tName        : "<<name<<endl;
    cout<<"\t\t\t\t\tValid ID No : "<<validID<<endl;
    cout<<"\t\t\t\t\tPhone No    : "<<phone<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
}

customer::customer()
{
    this->customerID = 0;
    this->address = "NA";
}
void customer::setcustomerID(int cid)
{
    this->customerID = cid;
}
int customer::getcustomerID()
{
    return customerID;
}
void customer::setaddress(string add)
{
    this->address = add;
}
string customer::getaddress()
{
    return address;
}
void customer::checkcustomer()
{
    string check;;
    int arr[10];
    int serial=101;
    int local=0;
    int ver;
    cout<<"Are you a New Customer or a Previous Member"<<endl;
    cout<<"Enter N for New"<<endl;
    cout<<"Enter M for Member"<<endl;
    cin>>check;
    for(int i=0;i<10;i++)
    {
        arr[i]=serial;
        serial++;
    }
    if(check=="n"||check=="N")
    {
        
    }
    if(check=="m"||check=="M")
    {
        cout<<"Enter your Customer ID: ";
        cin>>ver;
        for(int i=0;i<10;i++)
        {
            if(ver==arr[i])
            {
                local++;
            }
        }
        if(local>0)
        {
            cout<<"Customer Verified"<<endl;
            cout<<"You will get Additional 15% off"<<endl;
        }
        else
        {
            cout<<"Invalid Membership ID"<<endl;
        }
    }
}
void customer::menu()
{
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tWelcome to Movie Ticket Booking"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tEnter 1 to Book a Ticket"<<endl;
    cout<<"\t\t\tEnter 2 to View your Bookings"<<endl;
    cout<<"\t\t\tEnter 3 to View Price of Tickets"<<endl;
    cout<<"\t\t\tEnter 4 to Check Available Seats"<<endl;
    cout<<"\t\t\tEnter 5 to Check Movie Show Timings"<<endl;
    cout<<"\t\t\tEnter 6 to Add a New Movie"<<endl;
    cout<<"\t\t\tEnter 7 to Show Movie List"<<endl;
    cout<<"\t\t\tEnter 8 to Get a Membership"<<endl;
    cout<<"\t\t\tEnter 9 to logout"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
}
void customer::oldcustomer()
{
    string s,st;
    int id=101;
    cout<<"\t\t\tDo you have any Old Membership"<<endl;
    cout<<"\t\t\tYES or NO ?"<<endl;
    cout<<"\t\t\tEnter Y for YES or N for NO : ";
    cin>>s;
    cout<<"\t\t\t**************************************************"<<endl;

    if(s=="y"||s=="Y")
    {
        cout<<"\t\t\tRenew your Membership"<<endl;
        cout<<"\t\t\tEnter your ID: ";
        cin>>id;
        cout<<"\t\t\tYour Membership is Renewed"<<endl;
        cout<<"\t\t\t**************************************************"<<endl;
    }
    else if(s=="n"||s=="N")
    {
        cin.ignore();
        cout<<"\t\t\tEnter Your Address: ";
        getline(cin,st);
        cout<<"\t\t\tCongratulation!! You are now a Member!! \n\t\t\tEnjoy your Membership Perks!!"<<endl;
        cout<<"\t\t\tYour Membership ID: "<<id<<endl;
    }
}

membership::membership()
{
    this->user="username";
    this->pswrd="1234";
}
void membership::setuser(string u)
{
    user=u;
}
string membership::getuser()
{
    return user;
}
void membership::setpassword(string p)
{
    pswrd=p;
}
string membership::getpassword()
{
    return pswrd;
}
void membership::memberships()
{
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tMembership Benifits"<<endl;
    cout<<"\t\t\t1. 15% off on Tickets"<<endl;
    cout<<"\t\t\t2. Free Popcorn(small) on minimum 4 Ticket Booking"<<endl;
    cout<<"\t\t\t3. Shopping Vouchers every month"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
}
void membership::Admin()
{
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\t\tWelcome to Movie Booking System"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\n\t\t\tEnter Username: ";
    cin>>user;
    setuser(user);
    if(user=="admin"||user=="User"||user=="USER"||user=="Admin"||user=="adnan")
    {
        cout<<"\n\t\t\tEnter Password: ";
        cin>>pswrd;
        if(pswrd=="adnan123"||pswrd=="admin"||pswrd=="Admin"||pswrd=="ADMIN")
        {
            setpassword(pswrd);
            check=0;
        }
    }
}
Movie::Movie()
{
    this->time = 0;
    this->moviename = "NA";
    this->runtime = "NA";
    this->director = "NA";
    this->dimension = "NA";
    this->genre = "NA";
    this->release = "NA";
}
void Movie::setmoviename(string mv)
{
    this->moviename=mv;
}
string Movie::getmoviename()
{
    return moviename;
}
void Movie::setdimension(string dim)
{
    this->dimension=dim;
}
string Movie::getdimension()
{
    return dimension;
}
void Movie::setdirector(string dir)
{
    this->director=dir;
}
string Movie::getdirector()
{
    return director;
}
void Movie::setruntime(string stime)
{
    this->runtime=stime;
}
string Movie::getruntime()
{
    return runtime;
}
void Movie::setgenre(string sgenre)
{
    this->genre=sgenre;
}
string Movie::getgenre()
{
    return genre;
}
void Movie::setreleasedate(string srelease)
{
    this->release=srelease;
}
string Movie::getreleasedate()
{
    return release; 
}
void Movie::nowplaying()
{
    Movie m[4],setm;
    int ch;
    m[0].setmoviename("The Devil All the Time");
    m[0].setreleasedate("11th September 2020");
    m[0].setruntime("2h 18min");
    m[0].setgenre("Gothic/Crime Fiction");
    m[0].setdirector("Antonio Campos");
    m[0].setdimension("Netflix");
    
    m[1].setmoviename("First Man");
    m[1].setreleasedate("12th October 2020");
    m[1].setruntime("2h 21min");
    m[1].setgenre("History/Science Fiction");
    m[1].setdirector("Damien Chazelle");
    m[1].setdimension("Imax-3D");
    
    m[2].setmoviename("TENET");
    m[2].setreleasedate("23rd July 2020");
    m[2].setruntime("2h 30min");
    m[2].setgenre("Action/Thriller");
    m[2].setdirector("Christopher Nolan");
    m[2].setdimension("Imax-3D");
    
    m[3].setmoviename("Enola Holmes");
    m[3].setreleasedate("23rd September 2020");
    m[3].setruntime("2h 1m");
    m[3].setgenre("Mystery");
    m[3].setdirector("Harry Bradbeer");
    m[3].setdimension("Netflix");

    cout<<"Choose your Movie: "<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<"******************************************************************"<<endl;
        cout<<"\t\t\tMOVIE NO: "<<i+1<<endl;
        cout<<"******************************************************************"<<endl;
        cout<<"Movie Title  : "<<m[i].getmoviename()<<endl;
        cout<<"Release Date : "<<m[i].getreleasedate()<<endl;
        cout<<"Runtime      : "<<m[i].getruntime()<<endl;
        cout<<"Directed by  : "<<m[i].getdirector()<<endl;
        cout<<"Genre        : "<<m[i].getgenre()<<endl;
        cout<<"Screen       : "<<m[i].getdimension()<<endl;
    }
    cout<<"\t\t\tEnter 1 for Movie No 1"<<endl;
    cout<<"\t\t\tEnter 2 for Movie No 2"<<endl;
    cout<<"\t\t\tEnter 3 for Movie No 3"<<endl;
    cout<<"\t\t\tEnter 4 for Movie No 4"<<endl;
    cout<<"\t\t\tEnter your Choice: ";
    cin>>ch;
    switch(ch)
    {
        case 1 :
            m[0].setmoviename("The Devil All the Time");
            m[0].setreleasedate("11th September 2020");
            m[0].setruntime("2h 18min");
            m[0].setgenre("Gothic/Crime Fiction");
            m[0].setdirector("Antonio Campos");
            m[0].setdimension("Netflix");
            time=1;
            setmoviename("The Devil All the Time");
            setreleasedate("11th September 2020");
            setruntime("2h 18min");
            setgenre("Gothic/Crime Fiction");
            setdirector("Antonio Campos");
            setdimension("Netflix");
        break;
        case 2 :
            m[0].setmoviename("First Man");
            m[0].setreleasedate("12th October 2020");
            m[0].setruntime("2h 21min");
            m[0].setgenre("History/Science Fiction");
            m[0].setdirector("Damien Chazelle");
            m[0].setdimension("Imax-3D");
            time=2;
            setmoviename("First Man");
            setreleasedate("12th October 2020");
            setruntime("2h 21min");
            setgenre("History/Science Fiction");
            setdirector("Damien Chazelle");
        break;
        case 3 :
            m[0].setdimension("Imax-3D");
            m[0].setmoviename("TENET");
            m[0].setreleasedate("23rd July 2020");
            m[0].setruntime("2h 30min");
            m[0].setgenre("Action/Thriller");
            m[0].setdirector("Christopher Nolan");
            m[0].setdimension("Imax-3D");
            time=3;
            setdimension("Imax-3D");
            setmoviename("TENET");
            setreleasedate("23rd July 2020");
            setruntime("2h 30min");
            setgenre("Action/Thriller");
            setdirector("Christopher Nolan");
            setdimension("Imax-3D");
        break;
        case 4 :
            m[0].setmoviename("Enola Holmes");
            m[0].setreleasedate("23rd September 2020");
            m[0].setruntime("2h 1m");
            m[0].setgenre("Mystery");
            m[0].setdirector("Harry Bradbeer");
            m[0].setdimension("Netflix");
            time=4;
            setmoviename("Enola Holmes");
            setreleasedate("23rd September 2020");
            setruntime("2h 1m");
            setgenre("Mystery");
            setdirector("Harry Bradbeer");
            setdimension("Netflix");
        break;
        default:
        break;
    }
    Movie::movieselected(m[0]);    
}
void Movie::movieselected(Movie ms)
{
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\t\t\t\tSELECTED MOVIE :"<<endl;
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\tMovie Title  : "<<ms.getmoviename()<<endl;
    cout<<"\t\t\tRelease Date : "<<ms.getreleasedate()<<endl;
    cout<<"\t\t\tRuntime      : "<<ms.getruntime()<<endl;
    cout<<"\t\t\tDirected by  : "<<ms.getdirector()<<endl;
    cout<<"\t\t\tGenre        : "<<ms.getgenre()<<endl;
    cout<<"\t\t\tScreen       : "<<ms.getdimension()<<endl;
}
void Movie::viewbooking()
{
    cout<<"\t\t\tYour Movie Bookings"<<endl;
    cout<<"\t\t\tMovie Details: "<<endl;
    cout<<"\t\t\tMovie Title  : "<<getmoviename()<<endl;
    cout<<"\t\t\tRelease Date : "<<getreleasedate()<<endl;
    cout<<"\t\t\tRuntime      : "<<getruntime()<<endl;
    cout<<"\t\t\tDirected by  : "<<getdirector()<<endl;
    cout<<"\t\t\tGenre        : "<<getgenre()<<endl;
    cout<<"\t\t\tScreen       : "<<getdimension()<<endl;

}
void Movie::addmovie()
{
    string name,rdate,rtime,direct,gen,dim;
    cout<<"Enter Movie Name: ";
    getline(cin,name);
    setmoviename(name);
    cout<<"Enter Release Date: ";
    getline(cin,rdate);
    setreleasedate(rdate);
    cout<<"Enter Runtime: ";
    getline(cin,rtime);
    setruntime(rtime);
    cout<<"Enter Movie Director: ";
    getline(cin,direct);
    setdirector(direct);
    cout<<"Enter Movie Genre: ";
    getline(cin,gen);
    setgenre(gen);
    cout<<"Enter Movie Screen Type: ";
    getline(cin,dim);
    setdimension(dim);
    cout<<"\t\t\t***Movie has been Successfully Added***"<<endl;
    cout<<"Movie Details: "<<endl;
    cout<<"Movie Title  : "<<getmoviename()<<endl;
    cout<<"Release Date : "<<getreleasedate()<<endl;
    cout<<"Runtime      : "<<getruntime()<<endl;
    cout<<"Directed by  : "<<getdirector()<<endl;
    cout<<"Genre        : "<<getgenre()<<endl;
    cout<<"Screen       : "<<getdimension()<<endl;

}
void Movie::movielist()
{
    Movie mlist[4];
    mlist[0].setmoviename("The Devil All the Time");
    mlist[0].setreleasedate("11th September 2020");
    mlist[0].setruntime("2h 18min");
    mlist[0].setgenre("Gothic/Crime Fiction");
    mlist[0].setdirector("Antonio Campos");
    mlist[0].setdimension("Netflix");
    
    mlist[1].setmoviename("First Man");
    mlist[1].setreleasedate("12th October 2020");
    mlist[1].setruntime("2h 21min");
    mlist[1].setgenre("History/Science Fiction");
    mlist[1].setdirector("Damien Chazelle");
    mlist[1].setdimension("Imax-3D");
    
    mlist[2].setmoviename("TENET");
    mlist[2].setreleasedate("23rd July 2020");
    mlist[2].setruntime("2h 30min");
    mlist[2].setgenre("Action/Thriller");
    mlist[2].setdirector("Christopher Nolan");
    mlist[2].setdimension("Imax-3D");
    
    mlist[3].setmoviename("Enola Holmes");
    mlist[3].setreleasedate("23rd September 2020");
    mlist[3].setruntime("2h 1min");
    mlist[3].setgenre("Mystery");
    mlist[3].setdirector("Harry Bradbeer");
    mlist[3].setdimension("Netflix");

    cout<<"Movie Playing:"<<endl;
    cout<<"Movie List :\t\tMovie 1\t\t\t\tMovie 2\t\t\t\tMovie 3\t\t\t\tMovie 3"<<endl;
    cout<<"Title      :\t\tThe Devil All The Time\t\tFirst Man\t\t\tTENET\t\t\t\tEnola Holmes"<<endl;
    cout<<"Release    :\t\t11th September 2020\t\t12th October 2020\t\t23rd July 2020\t\t23rd September 2020"<<endl;
    cout<<"Runtime    :\t\t2h 18min\t\t\t2h 21min\t\t\t2h 30min\t\t\t2h 1min"<<endl;
    cout<<"Genre      :\t\tGothic/Crime Fiction\t\tHistory/Science Fiction\t\tAction/Thriller\t\tMystery"<<endl;
    cout<<"Screen     :\t\tNetflix\t\t\t\tImax-3D\t\t\t\tImax-3D\t\t\t\tNetflix"<<endl;
    cout<<"Director   :\t\tAntonio Campos\t\t\tDamien Chazelle\t\t\tChristopher Nolan\tHarry Bradbeer"<<endl;

}
void Movie::menu()
{
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tWelcome to Movie Ticket Booking"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
    cout<<"\t\t\tEnter 1 to Book a Ticket"<<endl;
    cout<<"\t\t\tEnter 2 to View your Bookings"<<endl;
    cout<<"\t\t\tEnter 3 to View Price of Tickets"<<endl;
    cout<<"\t\t\tEnter 4 to Check Available Seats"<<endl;
    cout<<"\t\t\tEnter 5 to Check Movie Show Timings"<<endl;
    cout<<"\t\t\tEnter 6 to Show Movie List"<<endl;
    cout<<"\t\t\tEnter 7 to Get a Membership"<<endl;
    cout<<"\t\t\tEnter 8 to Add a New Movie"<<endl;
    cout<<"\t\t\tEnter 9 to Log Out"<<endl;
    cout<<"\t\t\t**************************************************"<<endl;
}
void Movie::memoperation()
{
    m.memberships();
}

Time::Time()
{
    this->movietime="NA";
}
void Time::setMovieTime(string mt)
{
    this->movietime=mt;
}
string Time::getMovieTime()
{
    return movietime;
}
void Time::Timing1()
{
    cout<<"\t\t\t\t\t1.\tMON    10am\n\t\t\t\t\t2.\tTUE    1pm\n\t\t\t\t\t3.\tTHU    5pm\n\t\t\t\t\t4.\tSUN    11pm"<<endl;
}
void Time::Timing2()
{
    cout<<"\t\t\t\t\t1.\tTUE    9am\n\t\t\t\t\t2.\tTHU    12pm\n\t\t\t\t\t3.\tSAT    4pm\n\t\t\t\t\t4.\tSUN    7pm"<<endl;
}
void Time::Timing3()
{
    cout<<"\t\t\t\t\t1.\tMON    11am\n\t\t\t\t\t2.\tWED    2pm\n\t\t\t\t\t3.\tSAT    4pm\n\t\t\t\t\t4.\tSUN    9pm"<<endl;
}
void Time::Timing4()
{
    cout<<"\t\t\t\t\t1.\tFRI    3Pm\n\t\t\t\t\t2.\tMON    10am\n\t\t\t\t\t3.\tSUN    7pm\n\t\t\t\t\t4.\tTUE    11pm"<<endl;
}
Ticket::Ticket()
{
    this->ID=11101;
    this->price=0.0;
    this->seatavailable=350;
}
void Ticket::setID(int id)
{
    this->ID=id;
}
int Ticket::getID()
{
    return ID;
}
void Ticket::setNumber(int n)
{
    this->num=n;
}
int Ticket::getNumber()
{
    return num;
}
void Ticket::setPrice(double pr)
{
    this->price=pr;
}
double Ticket::getPrice()
{
    return price;
}
void Ticket::setTicketType(string g_s)
{
    this->gold_silver=g_s;
}
string Ticket::getTicketType()
{
    return gold_silver;
}
void Ticket::setSeat(int a)
{
    this->seatavailable=a;
}
int Ticket::getSeat()
{
    return seatavailable;
}

void Ticket::movie1()
{
    int ch;
    cout<<"\t\t\t************************************************************\n"<<endl;
    cout<<"\t\t\t\t\t\t*************"<<endl;
    cout<<"\t\t\t\t\t\tMovie Timings!!"<<endl;
    cout<<"\t\t\t\t\t\t*************"<<endl;
    cout<<"\t\t\t\t\t\tDay    Time"<<endl;
    tim.Timing1();
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;   
    if(ch==1)
    {
        cout<<"\t\t\t\t\tTimings: MON    11am"<<endl;
        tim.setMovieTime("MON    11am");        
    }
    else if(ch==2)
    {
        cout<<"\t\t\t\t\tTimings: WED    2pm"<<endl;
        tim.setMovieTime("WED    2pm");        
    }
    if(ch==3)
    {
        cout<<"\t\t\t\t\tTimings: SUN    4pm"<<endl;
        tim.setMovieTime("SUN    4pm");        
    }
    if(ch==4)
    {
        cout<<"\t\t\t\t\tTimings: SUN    9pm"<<endl;
        tim.setMovieTime("SUN    9pm");        
    }
    cout<<"\t\t\t************************************************************\n"<<endl;
}
void Ticket::movie2()
{
    int ch;
    cout<<"************************************************************\n"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tMovie Timings!!"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tDay    Time"<<endl;
    cout<<"\t\t\t\t\t\t*************"<<endl;
    tim.Timing2();
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;   
    if(ch==1)
    {
        cout<<"\t\t\t\t\tTimings: TUE    3pm"<<endl;
        tim.setMovieTime("TUE    3pm");        
    }
    else if(ch==2)
    {
        cout<<"\t\t\t\t\tTimings: THU    3pm"<<endl;
        tim.setMovieTime("THU    3pm");        
    }
    if(ch==3)
    {
        cout<<"\t\t\t\t\tTimings: SAT    3pm"<<endl;
        tim.setMovieTime("SAT    3pm");        
    }
    if(ch==4)
    {
        cout<<"\t\t\t\t\tTimings: SUN    5pm"<<endl;
        tim.setMovieTime("SUN    5pm");        
    }
    cout<<"\t\t\t************************************************************\n"<<endl;
}
void Ticket::movie3()
{
    int ch;
    cout<<"************************************************************\n"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tMovie Timings!!"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tDay    Time"<<endl;
    cout<<"\t\t\t\t\t\t*************"<<endl;
    tim.Timing3();
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;   
    if(ch==1)
    {
        cout<<"\t\t\t\t\tTimings: MON    11am"<<endl;
        tim.setMovieTime("MON    11am");        
    }
    else if(ch==2)
    {
        cout<<"\t\t\t\t\tTimings: WED    2pm"<<endl;
        tim.setMovieTime("WED    2pm");        
    }
    if(ch==3)
    {
        cout<<"\t\t\t\t\tTimings: SUN    4pm"<<endl;
        tim.setMovieTime("SUN    4pm");        
    }
    if(ch==4)
    {
        cout<<"\t\t\t\t\tTimings: SUN    9pm"<<endl;
        tim.setMovieTime("SUN    9pm");        
    }
    cout<<"\t\t\t************************************************************\n"<<endl;
}
void Ticket::movie4()
{
    int ch;
    cout<<"************************************************************\n"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tMovie Timings!!"<<endl;
    cout<<"\t\t\t\t\t\t***************"<<endl;
    cout<<"\t\t\t\t\t\tDay    Time"<<endl;
    cout<<"\t\t\t\t\t\t*************"<<endl;
    tim.Timing4();
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;   
    if(ch==1)
    {
        cout<<"\t\t\t\t\t\tTimings: MON    11am"<<endl;
        tim.setMovieTime("MON    11am");        
    }
    else if(ch==2)
    {
        cout<<"\t\t\t\t\tTimings: WED    2pm"<<endl;
        tim.setMovieTime("WED    2pm");        
    }
    if(ch==3)
    {
        cout<<"\t\t\t\t\tTimings: SUN    4pm"<<endl;
        tim.setMovieTime("SUN    4pm");        
    }
    if(ch==4)
    {
        cout<<"\t\t\t\t\tTimings: SUN    9pm"<<endl;
        tim.setMovieTime("SUN    9pm");        
    }
    cout<<"\t\t\t************************************************************\n"<<endl;
}

void Ticket::schedule()
{
    m.nowplaying();
    if(m.time==1)
    {
        movie1();
    }
    if(m.time==2)
    {
        movie2();
    }
    if(m.time==3)
    {
        movie3();
    }
    if(m.time==4)
    {
        movie4();
    }
}
void Ticket::tickettype()
{
    string ch;
    cout<<"\t\t\t\t\tEnter your Ticket Type Silver or Gold"<<endl;
    cout<<"\t\t\t\t\tSilver Costs: Rs.450, Gold Costs: 800"<<endl;
    cout<<"\t\t\t\t\tEnter S for Silver"<<endl;
    cout<<"\t\t\t\t\tEnter G for Gold"<<endl;
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;

    cout<<"\t\t\t************************************************************"<<endl;
    if(ch=="s"||ch=="S")
    {
        cout<<"\t\t\t\t\tSilver Ticket Selected"<<endl;
        setPrice(450.0);
        setTicketType("Silver Ticket");       
    }
    else if(ch=="g"||ch=="G")
    {
        cout<<"\t\t\t\t\tGold Ticket Selected"<<endl;
        setPrice(800.0);
        setTicketType("Gold Ticket");       
    }
    cout<<"\t\t\t************************************************************\n"<<endl;
}
void Ticket::display()
{
    num_ticket();
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\t\t\tYour Ticket Has Been Successfully Booked"<<endl;
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\t\t\t\tBooking Details!!"<<endl;
    cout<<"\t\t\t\t\t\t******************"<<endl;
    cout<<"\t\t\t\t\t\tTicket ID: "<<getID()<<endl;
    cout<<"\t\t\t\t\t\tTicket Type: "<<getTicketType()<<endl;
    cout<<"\t\t\t\t\t\tTicket Price: Rs "<<getPrice()<<endl;
    cout<<"\t\t\t************************************************************"<<endl;
    m.movieselected(m);
}
void Ticket::ticket_view()
{
    m.viewbooking();
    cout<<"\t\t\tMovie Timing : "<<tim.getMovieTime()<<endl;
    cout<<"\t\t\tTicket ID    : "<<getID()<<endl;
    cout<<"\t\t\tTicket Type  : "<<getTicketType()<<endl;
    cout<<"\t\t\tPrice        : Rs "<<getPrice()<<endl;
}
void Ticket::price_view()
{
    string ch;
    cout<<"\n\n\t\t\t\t\tWhich Ticket type Silver or Gold"<<endl;
    cout<<"\t\t\t\t\tEnter S for Silver Ticket"<<endl;
    cout<<"\t\t\t\t\tEnter G for Gold Ticket"<<endl;
    cout<<"\t\t\t\t\tEnter Your Choice: ";
    cin>>ch;

    cout<<"\t\t\t************************************************************"<<endl;
    if(ch=="s"||ch=="S")
    {
        cout<<"\t\t\t\t\tCost of Silver Ticket = Rs 450.0 "<<endl;
        setPrice(450.0);
        setTicketType("Silver Ticket");       
    }
    else if(ch=="g"||ch=="G")
    {
        cout<<"\t\t\t\t\tCost of Gold Ticket = Rs 800.0"<<endl;
        setPrice(800.0);
        setTicketType("Gold Ticket");       
    }
    cout<<"\t\t\t************************************************************"<<endl;
}
void Ticket::num_ticket()
{
    int n;
    cout<<"\t\t\tNo. of Tickets to Book: ";
    cin>>n;
    setNumber(n);
    setSeat(seatavailable-n);
    if(getPrice()==450)
    {
        cout<<"\t\t\tPrice of Each Ticket: Rs 450.0"<<endl;
        setPrice(450*n);
    }
    else if(getPrice()==800)
    {
        cout<<"\t\t\tPrice of Each Ticket: Rs 800.0"<<endl;
        setPrice(800*n);
    }
    cout<<"\t\t\tTotal Price of the Ticket: Rs"<<getPrice()<<endl;
}
void Ticket::seatavailabe()
{
    cout<<"\n\n\t\t\tAvailable Seats in the Theatre:"<<endl;
    cout<<"\t\t\tTotal Seats in the Theatre: 350"<<endl;
    cout<<"\t\t\tSeats Booked: "<<getNumber()<<endl;
    cout<<"\t\t\tAvailable Seats: "<<getSeat()<<endl;
}
void Ticket::timings()
{
    int ch;
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\t\t\tMovie Timings"<<endl;
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\t\t\t1. The Devil All The Time"<<endl;
    cout<<"\t\t\t2. First Man"<<endl;
    cout<<"\t\t\t3. TENET"<<endl;
    cout<<"\t\t\t4. Enola Holmes"<<endl;
    cout<<"\t\t\tEnter Your Choice: ";
    cin>>ch;
    cout<<"\t\t\t************************************************************"<<endl;
    cout<<"\n\t\t\tShow Times Available: "<<endl;
    cout<<"\t\t\t************************************************************"<<endl;
    if(ch==1)
    {
        tim.Timing1();
    }
    else if(ch==2)
    {
        tim.Timing2();
    }
    else if(ch==3)
    {
        tim.Timing3();
    }
    else if(ch==4)
    {
        tim.Timing4();
    }
        cout<<"\t\t\t************************************************************"<<endl;
}
