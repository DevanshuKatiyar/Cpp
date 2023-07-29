#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student
{
    private:
    string name,dep,std,div;
    int id;

    public:

        void set_studentname(string Name)
        {
            name = Name;
        }
        void set_studentdepartment(string Dep)
        {
            dep = Dep;
        } 
        void set_studentStandard(string Std)
        {
            std = Std;
        } 
        void set_studentDivision(string Div)
        {
            div = Div;
        }
        void set_studentid(int ID)
        {
            id = ID;
        }

        string get_studentname()
        {
            return name;
        }
        string get_studentdepartment()
        {
            return dep;
        } 
        string get_studentStandard()
        {
            return std;
        } 
        string get_studentdivision()
        {
            return div;
        }
        int get_studentid()
        {
            return id;
        }  
};

class Lib
{
    private:
    string name,quali,exp;

    public:
    void set_lname(string nam)
    {
        name = nam;
    }
    void set_led(string ed)
    {
        quali = ed;
    }
    void set_lexp(string xp)
    {
        exp = xp;
    }

    string get_lname()
    {
        return name;
    }
    string get_led()
    {
        return quali;
    }
    string get_lexp()
    {
        return exp;
    }

};

class Book
{
    private:
    string name,author,pub,bId;
    int quan;

    public:

    void set_bname(string nam)
    {
        name = nam;
    }
    void set_baut(string aut)
    {
        author = aut;
    }
    void set_bpub(string publication)
    {
        pub = publication;
    }
    void set_bquan(int num)
    {
        quan = num;
    }
    void set_bid(string bookid)
    {
        bId = bookid;
    }

    string get_bname()
    {
        return name;
    }
    string get_baut()
    {
        return author;
    }
    string get_bpub()
    {
        return pub;
    }
    string get_bid()
    {
        return bId;
    }
    int get_bquan()
    {
        return quan;
    }

};

void issue(Lib l,Student s[],Book b[],int ns,int book_number)
{
    ofstream ifile;

    int i,j,id;
    string BID,t1,t2;
    cout<<"\nEnter the identification number of student who want to issue book: ";
    cin>>id;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>id;
     }
     if(!cin.fail())
     {
     break;
     }
    }
    cout<<"\nEnter the identification number of book to issue: ";
    cin>>BID;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>BID;
     }
     if(!cin.fail())
     {
     break;
     }
    }

    for(i=0;i<ns;i++)
    {
        if(s[i].get_studentid() == id)
        {
            for(j=0;j<book_number;j++)
            {
                if(b[j].get_bid() == BID)
                {
                   if(b[j].get_bquan() > 0)
                   {
                     cout<<"\nBook has been issued sccuessfully: "<<endl;
                     cout<<"Name of student who issued the book: "<<s[i].get_studentname()<<endl;
                     cout<<"Name of book that was issued : "<<b[j].get_bname()<<endl;
                     t1 = s[i].get_studentname();
                     t2 = b[j].get_bname();
                     b[j].set_bquan((b[j].get_bquan() - 1));
                        ifile.open("Issue_info.txt");
                        ifile<<"\nName of librarian who issued the book: "<<l.get_lname()<<endl;
                        ifile<<"Name of Student who issued the book: "<<t1<<endl;
                        ifile<<"identification number of Student who issued the book: "<<id<<endl;
                        ifile<<"Name of Book that was issued: "<<t2<<endl;
                        ifile<<"identification number of Book that was issued: "<<BID<<endl;
                        ifile.close();
                   }
                   else
                   {
                    cout<<"\nProblem issuing the book as no copy was found\n";
                   }
                   
                }
            }
        }
    }

    ofstream bfile;
    bfile.open("Book_details.txt");

    for(i=0;i<book_number;i++)
    {
        bfile<<"\n Book info"<<i+1<<" \n";
        bfile<<"Name of book: "<<b[i].get_bname()<<endl;
        bfile<<"Author of book: "<<b[i].get_baut()<<endl;
        bfile<<"Publication of book: "<<b[i].get_bpub()<<endl;
        bfile<<"Number of copies : "<<b[i].get_bquan()<<endl;
        bfile<<"Book identification number: "<<b[i].get_bid()<<endl;
    }
    bfile.close();

}

void ret(Lib l,Student s[],Book b[],int ns,int ncop[],int book_number)
{
    ofstream ifile;

    int i,j,id;
    string BID,t1,t2;
    cout<<"\nEnter the identification number of student who wants to return book: ";
    cin>>id;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>id;
     }
     if(!cin.fail())
     {
     break;
     }
    }
    cout<<"\nEnter the identification number of book to be returned: ";
    cin>>BID;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>BID;
     }
     if(!cin.fail())
     {
     break;
     }
    }

    for(i=0;i<ns;i++)
    {
        if(s[i].get_studentid() == id)
        {
            for(j=0;j<book_number;j++)
            {
                if(b[j].get_bid() == BID)
                {
                if(ncop[j] > b[j].get_bquan())
                  {
                    cout<<"\nBook has been returned successfully: "<<endl;
                    cout<<"Name of Student who reurned the book: "<<s[i].get_studentname()<<endl;
                    cout<<"Name of that was returned: "<<b[j].get_bname()<<endl;
                    t1 = s[i].get_studentname();
                    t2 = b[j].get_bname();
                    b[j].set_bquan((b[j].get_bquan() + 1));
                    ifile.open("Return_info.txt");
                    ifile<<"\nName of librarian: "<<l.get_lname()<<endl;
                    ifile<<"Name of Student who returned the book: "<<t1<<endl;
                    ifile<<"identification number of Student: "<<id<<endl;
                    ifile<<"Name of Book that was returned: "<<t2<<endl;
                    ifile<<"identification number of Book: "<<BID<<endl;
                    ifile.close();
                  }
                  else
                  {
                    cout<<"\nRETURN not possible as book is not issued\n";
                  }
                  
                }
            }
        }
    }
    ofstream bfile;
    bfile.open("Book_details.txt");

    for(i=0;i<book_number;i++)
    {
        bfile<<"\n Book info"<<i+1<<" \n";
        bfile<<"Name of book: "<<b[i].get_bname()<<endl;
        bfile<<"Author of book: "<<b[i].get_baut()<<endl;
        bfile<<"Publication of book: "<<b[i].get_bpub()<<endl;
        bfile<<"Number of copies : "<<b[i].get_bquan()<<endl;
        bfile<<"Book identification number: "<<b[i].get_bid()<<endl;
    }
    bfile.close();
}

void sadd(Student s[],int *number_students)
{
    string sname,sdep,sstd,sdiv;
    int sid;

    cout<<"\nSTUDENT "<<(*number_students+1)<<endl;
    cout<<"Enter the name of student: ";
    cin>>sname;
    cout<<"Enter the student ID: ";
    cin>>sid;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>sid;
     }
     if(!cin.fail())
     {
     break;
     }
    }
    cout<<"Enter the department of student: ";
    cin>>sdep;
    cout<<"Enter the class of student ";
    cin>>sstd;
    cout<<"Enter the division of student: ";
    cin>>sdiv;
    s[*number_students].set_studentname(sname);
    s[*number_students].set_studentdepartment(sdep);
    s[*number_students].set_studentStandard(sstd);
    s[*number_students].set_studentDivision(sdiv);
    s[*number_students].set_studentid(sid);

    fstream file;
    file.open("Student_details.txt",ios::app);

    file<<"\n STUDENT "<<(*number_students+1)<<" \n";
    file<<"NAME: "<<s[*number_students].get_studentname()<<endl;
    file<<"ID: "<<s[*number_students].get_studentid()<<endl;
    file<<"DEPARTMENT: "<<s[*number_students].get_studentname()<<endl;
    file<<"CLASS: "<<s[*number_students].get_studentStandard()<<endl;
    file<<"DIVISION: "<<s[*number_students].get_studentdivision()<<endl;

    file.close();

    *number_students = *number_students + 1;
}

void badd(Book b[],int *book_number,int ncop[])
{
    string bname,bauthor,bpub,bid;
    int bquan;

    cout<<"BOOK NUMBER "<<*book_number+1<<endl;
    cout<<"Enter the name of book: ";
    cin>>bname;
    cout<<"Enter the name of the author: ";
    cin>>bauthor;
    cout<<"Enter the publiction of book: ";
    cin>>bpub;
    cout<<"Enter the number of copies: ";
    cin>>bquan;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>bquan;
     }
     if(!cin.fail())
     {
     break;
     }
    }
    cout<<"Enter the id of book: ";
    cin>>bid;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>bid;
     }
     if(!cin.fail())
     {
     break;
     }
    }

    b[*book_number].set_bname(bname);
    b[*book_number].set_baut(bauthor);
    b[*book_number].set_bpub(bpub);
    b[*book_number].set_bquan(bquan);
    b[*book_number].set_bid(bid);
    ncop[*book_number] = b[*book_number].get_bquan();

    fstream bfile;
    bfile.open("Book_details.txt",ios::app);

    bfile<<"\n BOOK "<<*book_number+1<<" \n";
    bfile<<"NAME: "<<b[*book_number].get_bname()<<endl;
    bfile<<"AUTHOR: "<<b[*book_number].get_baut()<<endl;
    bfile<<"PUBLICATION: "<<b[*book_number].get_bpub()<<endl;
    bfile<<"NUMBER OF COPIES: "<<b[*book_number].get_bquan()<<endl;
    bfile<<"BOOK ID: "<<b[*book_number].get_bid()<<endl;

    bfile.close();

    *book_number = *book_number + 1;
}

int main()
{
    string sname,sdep,sstd,sdiv;
    int sid,ncop[10];
    string lname,lquali,lexp;
    string bname,bauthor,bpub,bid;
    int bquan,book_number;

    Lib l;
    cout<<"\nEnter the name of librarian: ";
    cin>>lname;
    cout<<"Enter the qualification of librarian: ";
    cin>>lquali;
    cout<<"Enter the experience of librarian in years: ";
    cin>>lexp;
    l.set_lname(lname);
    l.set_led(lquali);
    l.set_lexp(lexp);
    ofstream lfile;
    lfile.open("Librarian_Info.txt");
    lfile<<" Librarian information "<<endl;
    lfile<<"Name of librarian: "<<l.get_lname()<<endl;
    lfile<<"Qualification of librarian: "<<l.get_led()<<endl;
    lfile<<"Experience of librarian: "<<l.get_lexp()<<" years"<<endl;
    lfile.close();


    Student s[10];
    int number_students,i;

    cout<<"\nEnter Number of students info you want to add : ";
    cin>>number_students;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>number_students;
     }
     if(!cin.fail())
     {
     break;
     }
    };
    ofstream sfile;
    sfile.open("Student_details.txt");
    for(i=0;i<number_students;i++)
    {
        cout<<"\nSTUDENT "<<i+1<<endl;
        cout<<"Enter the name of student: ";
        cin>>sname;
        cout<<"Enter the student identification number: ";
        cin>>sid;
         while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>sid;
     }
     if(!cin.fail())
     {
     break;
     }
    }
        cout<<"Enter the department of student: ";
        cin>>sdep;
        cout<<"Enter the class of student ";
        cin>>sstd;
        cout<<"Enter the division of student: ";
        cin>>sdiv;
        s[i].set_studentname(sname);
        s[i].set_studentdepartment(sdep);
        s[i].set_studentStandard(sstd);
        s[i].set_studentDivision(sdiv);
        s[i].set_studentid(sid);
        sfile<<"\n Student information "<<i+1<<" \n";
        sfile<<"Name of student: "<<s[i].get_studentname()<<endl;
        sfile<<"Student identification number: "<<s[i].get_studentid()<<endl;
        sfile<<"Department of student: "<<s[i].get_studentname()<<endl;
        sfile<<"Class of student: "<<s[i].get_studentStandard()<<endl;
        sfile<<"Division of student:: "<<s[i].get_studentdivision()<<endl;
    }
    sfile.close();


    Book b[10];
    cout<<"\n\n";
    cout<<"Number of book to enter: ";
    cin>>book_number;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>book_number;
     }
     if(!cin.fail())
     {
     break;
     }
    }

    cout<<"\nEnter the information for "<<book_number<< "books\n";

    ofstream bfile;
    bfile.open("Book_details.txt");
    for(i=0;i<book_number;i++)
    {
        cout<<"Book Number "<<i+1<<endl;
        cout<<"Enter the name of book: ";
        cin>>bname;
        cout<<"Enter the name of the author: ";
        cin>>bauthor;
        cout<<"Enter the publiction of book: ";
        cin>>bpub;
        cout<<"Enter the number of copies: ";
        cin>>bquan;
         while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>bquan;
     }
     if(!cin.fail())
     {
     break;
     }
    }
        cout<<"Enter the identification number of book: ";
        cin>>bid;
         while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>bid;
     }
     if(!cin.fail())
     {
     break;
     }
    }
        b[i].set_bname(bname);
        b[i].set_baut(bauthor);
        b[i].set_bpub(bpub);
        b[i].set_bquan(bquan);
        b[i].set_bid(bid);
        ncop[i] = b[i].get_bquan();
        bfile<<"\n Book information "<<i+1<<" \n";
        bfile<<"Name of book: "<<b[i].get_bname()<<endl;
        bfile<<"Name of the author: "<<b[i].get_baut()<<endl;
        bfile<<"Publiction of book: "<<b[i].get_bpub()<<endl;
        bfile<<"Number of copies: "<<b[i].get_bquan()<<endl;
        bfile<<"Identification number of book: "<<b[i].get_bid()<<endl;
    }
    bfile.close();
    
    int r;
    cout<<"\nTo issue a book press 1\nTo return a book press 2\nTo add students press 3\nTo add books press 4\nTo exit press 5\nEnter your responce: ";
    cin>>r;
     while(1)
    {
    if(cin.fail())
     {
        cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>r;
     }
     if(r>5)
     {cin.clear();
        cin.ignore(512,'\n');
        cout<<"enter again\n";
        cin>>r;
     }
     if(!cin.fail())
     {
     break;
     }
    }

    while(r != 0)
    {
        switch(r)
        {
            case 1:
            issue(l,s,b,number_students,book_number);
            cout<<"\nTo issue a book press 1\nTo return a book press 2\nTo add students press 3\nTo add books press 4\nTo exit press 0\nEnter your responce: ";
    cin>>r;
            break;

            case 2:
            ret(l,s,b,number_students,ncop,book_number);
            cout<<"\nTo issue a book press 1\nTo return a book press 2\nTo add students press 3\nTo add books press 4\nTo exit press 0\nEnter your responce: ";
    cin>>r;
            break;

            case 3:
            sadd(s,&number_students);
            
            cout<<"\nTo issue a book press 1\nTo return a book press 2\nTo add students press 3\nTo add books press 4\nTo exit press 0\nEnter your responce: ";
    cin>>r;

            case 4:
            badd(b,&book_number,ncop);
             cout<<"\nTo issue a book press 1\nTo return a book press 2\nTo add students press 3\nTo add books press 4\nTo exit press 0\nEnter your responce: ";
    cin>>r;
     
            default:
            break;

        }
    }
    return 0;
}