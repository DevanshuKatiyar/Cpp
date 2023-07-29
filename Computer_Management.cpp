#include <iostream>
#include <conio.h>
#include <string.h>
#include <fstream>
using namespace std;
class computer
{
    private:
        char type[10], pro[5];
        int ram, hdisk, usb, hdmi, time;
    
    public:
        void set_data (char *ty, char *p, int r, int hd, int u, int h, int t)
        {
            strcpy (type, ty);
            strcpy (pro, p);
            ram = r;
            hdisk = hd;
            usb = u;
            hdmi = h;
            time = t;
        }
        char *get_type ()
        {
            return type;
        }
        char *get_pro ()
        {
            return pro;
        }
        int get_ram ()
        {
            return ram;
        }
        int get_hd ()
        {
            return hdisk;
        }
        int get_usb ()
        {
            return usb;
        }
        int get_hdmi ()
        {
            return hdmi;
        }
        int get_time ()
        {
            return time;
        }
};

class details: public computer
{
    private:
        char pern[20], email[30], cp[20], em[30];
        int date;
        unsigned long int mobi;
        int quantity;  
    
    public:
        void set_datap (char *per, char *em, unsigned long int mob, int dat)
        {
            strcpy (pern, per);
            strcpy (email, em);
            mobi = mob;
            date = dat;
        }
        
        void set_datac (char *cpn, unsigned long int mob, char *email, int qu,int dat)
        {
            strcpy (cp, cpn);
            strcpy (em, email); 
            mobi = mob;
            quantity = qu;
            date = dat;
        }
        char *get_per ()
        {
            return pern;
        }
        char *get_tem ()
        {
            return email;
        }
        unsigned long int get_mobi ()
        {
            return mobi;
        }
        int get_dat ()
        {
            return date;
        }

        int get_q ()
        {
            return quantity;
        }
        char *get_cp ()
        {
            return cp;
        }
};

int main ()
{
    class details z;
    int num, i;
    char pro[10], typ[10];
    unsigned int ram, hd, usb, hdmi, time;
    ofstream fout;
    int x;
    char pern[20], email[30], cp[20];
    int date;
    unsigned long int mob;
    int quantity;
    
    fout.open ("sample.txt");
    cout << "Enter 1 if its a individual person\nEnter 2 if its a company \n: ";
    cin >> x;

    if (x == 1)
        {
            cout << "Enter person name : " << endl;
            cin >> pern;
            cout << "Enter mobile number : " << endl;
            cin >> mob;
            cout << "Enter email : " << endl;
            cin >> email;
            cout << "Enter date : " << endl;
            cin >> date;

            z.set_datap (pern, email, mob, date);

            fout << z.get_per () << endl;
            fout << z.get_tem () << endl;
            fout << z.get_mobi () << endl;
            fout << z.get_dat () << endl;

            char d;

            cout << "Do you want to do more task in person details\nEnter y to continue:";
            cin >> d;

            if (d == 'y' || d == 'Y')
            {
                cout << "What would u like to do ?\n";
                cout << "1. Modification\n";
                cout << "2. Delete\n : ";

                int opt, opt1, opt2, opt3, w;

                cin >> opt;
            
            
                if (opt == 1)
                {
                    cout << "What would u like to change?\n";
                    cout << "1. Person name\n";
                    cout << "2. Mobile number\n";
                    cout << "3. Email\n";
                    cout << "4. Date\n : ";
                    cin >> opt1;
                    if (opt1 == 1)
                    {
                        cout << "Enter the new name : ";
                        cin >> pern;
                        fout << "------------- NEW MODIFIED PERSON DATA ----------------" << endl;
                        fout << "NEW : " << pern << endl;
                        fout << z.get_tem () << endl;
                        fout << z.get_mobi () << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt1 == 2)
                    {
                        cout << "Enter the new email : ";
                        cin >> email;
                        fout << "------------- NEW MODIFIED PERSON DATA ----------------" << endl;
                        fout << z.get_per () << endl;
                        fout << "NEW" << email << endl;
                        fout << z.get_mobi () << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt1 == 3)
                    {
                        cout << "Enter the new moblie numberl : ";
                        cin >> mob;
                        fout << "------------- NEW MODIFIED PERSON DATA ----------------" << endl;
                        fout << z.get_per () << endl;
                        fout << z.get_tem () << endl;
                        fout << "NEW" << mob << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt1 == 4)
                    {
                        cout << "Enter the new date : ";
                        cin >> date;
                        fout << "------------- NEW MODIFIED PERSON DATA ----------------" << endl;
                        fout << z.get_per () << endl;
                        fout << z.get_tem () << endl;
                        fout << z.get_mobi () << endl;
                        fout << "NEW" << date << endl;
                    }
                }
                if (opt == 2)
                {
                    cout << "What would u like to delete?\n";
                    cout << "1. Person name\n";
                    cout << "2. Email\n";
                    cout << "3. Mobile number\n";
                    cout << "4. Date\n : ";
                    cin >> opt2;
                    if (opt2 == 1)
                    {
                        fout << "-----------------# IS FOR DELETED DATA---------------------- " << endl;
                        fout << "#" << z.get_per () << endl;
                        fout << z.get_tem () << endl;
                        fout << z.get_mobi () << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt2 == 2)
                    {
                        fout << "-----------------# IS FOR DELETED DATA---------------------- " << endl;
                        fout << z.get_per () << endl;
                        fout << "#" << z.get_tem () << endl;
                        fout << z.get_mobi () << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt2 == 3)
                    {
                        fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                        fout << z.get_per () << endl;
                        fout << z.get_tem () << endl;
                        fout << "#" << z.get_mobi () << endl;
                        fout << z.get_dat () << endl;
                    }
                    if (opt2 == 4)
                    {
                        fout << "-----------------# IS FOR DELETED DATA---------------------- " << endl;
                        fout << z.get_per () << endl;
                        fout << z.get_tem () << endl;
                        fout << z.get_mobi () << endl;
                        fout << "#" << z.get_dat () << endl;
                    }
                }
            }
        }
        
        if (x == 2)
        {
            cout << "Enter company name : " << endl;
            cin >> cp;
            cout << "Enter mobile number : " << endl;
            cin >> mob;
            cout << "Enter email : " << endl;
            cin >> email;
            cout << "Enter your quantity :" << endl;
            cin >> quantity;
            cout << "Enter date : " << endl;
            cin >> date;
            z.set_datac (cp, mob, email, quantity, date);
            fout << z.get_cp () << endl;
            fout << z.get_tem () << endl;
            fout << z.get_mobi () << endl;
            fout << z.get_dat () << endl;
            fout << z.get_q () << endl;

            char e;
            int opti, opti1, opti2, opti3;
            cout << "Do you want to do more task in person details\nEnter y to continue : ";
            cin >> e;

            if (e == 'y' || e == 'Y')
            {
                cout << "What would u like to do ?\n";
                cout << "1. Modification\n";
                cout << "2. Delete\n : ";
                cin >> opti;
                int n, i;
                
                if (opti == 1)
                    {
                        cout << "what would u like to change?\n";
                        cout << "1. Company name\n";
                        cout << "2. Mobile number\n";
                        cout << "3. Email\n";
                        cout << "4. Date\n";
                        cout << "5. Quantity\n : ";
                        
                        cin >> opti1;
                        if (opti1 == 1)
                        {
                            cout << "Enter the new company name\n";
                            cin >> cp;

                            fout << "------------- NEW MODIFIED COMPANY DATA ----------------" << endl;
                            fout << "NEW" << cp << endl;
                            fout << z.get_tem() << endl;
                            fout << z.get_mobi() << endl;
                            fout << z.get_dat() << endl;
                            fout << z.get_q() << endl;
                        }
                        if (opti1 == 2)
                        {
                            cout << "Enter the new mobile number\n";
                            cin >> mob;
                            
                            fout << "------------- NEW MODIFIED COMPANY DATA ----------------" << endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout <<"NEW"<< mob << endl;
                            fout << z.get_dat () << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti1 == 3)
                        {
                            cout << "Enter the new email\n";
                            cin >> email;
                            
                            fout << "------------- NEW MODIFIED COMPANY DATA ----------------" << endl;
                            fout << z.get_cp () << endl;
                            fout <<"NEW"<< email << endl;
                            fout << z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti1 == 4)
                        {
                            cout << "Enter the new date\n";
                            cin >> date;
                            
                            fout << "------------- NEW MODIFIED COMPANY DATA ----------------" << endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout << z.get_mobi () << endl;
                            fout <<"NEW"<< date << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti1 == 5)
                        {
                            cout << "Enter the new quantity\n";
                            cin >> quantity;
                            
                            fout << "------------- NEW MODIFIED COMPANY DATA ----------------" << endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout << z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout <<"NEW"<< quantity << endl;
                        }
                    }
                    if (opti == 3)
                    {
                        cout << "What would u like to delete?\n";
                        cout << "1. Company name\n";
                        cout << "2. Email\n";
                        cout << "3. Mobile number\n";
                        cout << "4. Date\n";
                        cout << "5. Quantity\n : ";
                        cin >> opti2;

                        if (opti2 == 1)
                        {
                            fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                            fout <<"#"<<z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout << z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti2 == 2)
                        {
                            fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                            fout << z.get_cp () << endl;
                            fout <<"#"<< z.get_tem () << endl;
                            fout <<z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti2 == 3)
                        {
                            fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout <<"#"<< z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout << z.get_q () << endl;
                        }
                        if (opti2 == 4)
                        {
                            fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout << z.get_mobi () << endl;
                            fout <<"#"<< z.get_dat () << endl;
                            fout << z.get_q () << endl;  
                        }
                        if (opti2 == 5)
                        {
                            fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                            fout << z.get_cp () << endl;
                            fout << z.get_tem () << endl;
                            fout << z.get_mobi () << endl;
                            fout << z.get_dat () << endl;
                            fout <<"#"<<z.get_q () << endl;
                        }
                    }
                }
            }

            cout << "Enter type (desktop/laptop) : ";
            cin >> typ;
            cout << "Enter processor : ";
            cin >> pro;
            cout << "Enter ram : ";
            cin >> ram;
            cout << "Enter harddisk : ";
            cin >> hd;
            cout << "Enter usb port count : ";
            cin >> usb;
            cout << "Enter hdmi port count : ";
            cin >> hdmi;
            cout << "Enter battery backup time : ";
            cin >> time;

            z.set_data (typ, pro, ram, hd, usb, hdmi, time);

            fout << "--------COMPUTER DETAILS----------" << endl;
            fout << z.get_type () << endl;
            fout << z.get_pro () << endl;
            fout << z.get_ram () << endl;
            fout << z.get_hd () << endl;
            fout << z.get_usb () << endl;
            fout << z.get_hdmi () << endl;
            fout << z.get_time () << endl;

            char a;

        cout <<"Do you want to do more task in computer details\nEnter y to continue : ";
        cin >> a;

        int option, option1, option2, option3;
        
        if (a == 'y' || a == 'Y')
        {
            cout << "What would u like to do ?\n";
            cout << "1. Modification\n";
            cout << "2. Delete\n";
            cout << "3. View\n : ";

            cin >> option;
            
            if (option == 1)
            {
                cout << "What would u like to change?\n";
                cout << "1. Type\n";
                cout << "2. Processor\n";
                cout << "3. Ram\n";
                cout << "4. Harddisk\n";
                cout << "5. Usb port\n";
                cout << "6. Hdmi\n";
                cout << "7. Battery time\n";
                cin >> option2;

                if (option2 == 1)
                {
                    cout << "Enter the new type\n";
                    cin >> typ;
                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;
                
                    fout << "new type :" << typ << endl;
                    fout << z.get_pro () << endl;
                    fout << z.get_ram () << endl;
                    fout << z.get_hd () << endl;
                    fout << z.get_usb () << endl;
                    fout << z.get_hdmi () << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 2)
                {
                    cout << "Enter the new processor\n";
                    cin >> pro;
                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;

                    fout << z.get_type () << endl;
                    fout << "new processor : " << pro << endl;
                    fout << z.get_ram () << endl;
                    fout << z.get_hd () << endl;
                    fout << z.get_usb () << endl;
                    fout << z.get_hdmi () << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 3)
                {
                    cout << "Enter the new ram\n";
                    cin >> ram;
                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;
                    
                    fout << z.get_type () << endl;
                    fout << z.get_pro () << endl;
                    fout << "new ram : " << ram << endl;
                    fout << z.get_hd () << endl;
                    fout << z.get_usb () << endl;
                    fout << z.get_hdmi () << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 4)
                {
                    cout << "Enter the new hard disk \n";
                    cin >> hd;
                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;

                    fout << z.get_type () << endl;
                    fout << z.get_pro () << endl;
                    fout << z.get_ram () << endl;
                    fout << "new harddisk : " << hd << endl;
                    fout << z.get_usb () << endl;
                    fout << z.get_hdmi () << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 5)
                {
                    cout << "Enter the new usb port count\n";
                    cin >> usb;

                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;
                    fout << z.get_type () << endl;
                    fout << z.get_pro () << endl;
                    fout << z.get_ram () << endl;
                    fout << z.get_hd () << endl;
                    fout << "new usb :" << usb << endl;
                    fout << z.get_hdmi () << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 6)
                {
                    cout << "Enter the new hdmi port count\n";
                    cin >> hdmi;
                    
                    fout << "------------- NEW MODIFIED DATA ----------------" <<endl;
                    fout << z.get_type () << endl;
                    fout << z.get_pro () << endl;
                    fout << z.get_ram () << endl;
                    fout << z.get_hd () << endl;
                    fout << z.get_usb () << endl;
                    fout << "new hdmi :" << hdmi << endl;
                    fout << z.get_time () << endl;
                }
                if (option2 == 7)
                {
                    cout << "Enter the new battery backup time\n";
                    cin >> time;
                    z.set_data (typ, pro, ram, hd, usb, hdmi, time);
                    fout << "------------- NEW MODIFIED DATA ----------------" <<
                    endl;
                    fout << z.get_type () << endl;
                    fout << z.get_pro () << endl;
                    fout << z.get_ram () << endl;
                    fout << z.get_hd () << endl;
                    fout << z.get_usb () << endl;
                    fout << z.get_hdmi () << endl;
                    fout << "new time : " << z.get_time () << endl;
                }
            }
            if (option == 2)
            {
                cout << "what would u like to delete?\n";
                cout << "1. Type\n";
                cout << "2. processor\n";
                cout << "3. ram\n";
                cout << "4. harddisk\n";
                cout << "5. usb port\n";
                cout << "6. hdmi\n";
                cout << "7. battery time\n : ";
                cin >> option3;

            if (option3 == 1)
            {
                fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                fout << "#" << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 2)
            {
                fout <<
                "-----------------# IS FOR DELETED DATA---------------------- "
                << endl;
                fout << z.get_type () << endl;
                fout << "#" << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 3)
            {
                fout << " -----------------# IS FOR DELETED DATA----------------------"<< endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << "#" << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 4)
            {
                fout << "-----------------# IS FOR DELETED DATA---------------------- " << endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << "#" << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 5)
            {
                fout << "-----------------# IS FOR DELETED DATA---------------------- " << endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << "#" << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 6)
            {
                fout << "-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << "#" << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }
            if (option3 == 7)
            {
                fout <<"-----------------# IS FOR DELETED DATA---------------------- "<< endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << "#" << z.get_time () << endl;
            }
        }
            char j;
            int t;
            
            cout << "Do you want to add data : ";
            cin >> j;
            if(j=='y'||j=='Y')
            {
                cout << "1)person \n 2)company \n : ";
                cin >> t;
                if(t== 1)
                {
                    cout << "Enter person name : " ;
                    cin >> pern;
                    cout << "Enter mobile number : ";
                    cin >> mob;
                    cout << "Enter email : ";
                    cin >> email;
                    cout << "Enter date : ";
                    cin >> date;
                    
                    z.set_datap (pern, email, mob, date);
                    
                    fout << "Newly added data "<< endl;
                    fout << "----------PERSON DETAILS-------"<<endl;
                    fout << z.get_per () << endl;
                    fout << z.get_tem () << endl;
                    fout << z.get_mobi () << endl;
                    fout << z.get_dat () << endl;
                }
                if(t==2)
                {
                    cout << "Enter company name : ";
                    cin >> cp;
                    cout << "Enter mobile number : ";
                    cin >> mob;
                    cout << "Enter email  : " ;
                    cin >> email;
                    cout << "Enter the quantity : " << endl;
                    cin >> quantity;
                    cout << "Enter Date : " << endl;
                    cin >> date;
                    
                    z.set_datac (cp, mob, email, quantity, date);
                    
                    fout << "NEWLY ADDED DATA"<< endl;
                    fout << "----------COMPANY DETAILS-------"<<endl;
                    fout << z.get_cp () << endl;
                    fout << z.get_tem () << endl;
                    fout << z.get_mobi () << endl;
                    fout << z.get_dat () << endl;
                    fout << z.get_q () << endl;
                }
                
                cout << "Enter type (desktop/laptop) : ";
                cin >> typ;
                cout << "Enter processor : ";
                cin >> pro;
                cout << "Enter ram : " ;
                cin >> ram;
                cout << "Enter harddisk : ";
                cin >> hd;
                cout << "Enter usb port count : ";
                cin >> usb;
                cout << "Enter hdmi port count : ";
                cin >> hdmi;
                cout << "Enter battery backup time : ";
                cin >> time;

                z.set_data (typ, pro, ram, hd, usb, hdmi, time);

                fout << "--------COMPUTER DETAILS----------"<<endl;
                fout << z.get_type () << endl;
                fout << z.get_pro () << endl;
                fout << z.get_ram () << endl;
                fout << z.get_hd () << endl;
                fout << z.get_usb () << endl;
                fout << z.get_hdmi () << endl;
                fout << z.get_time () << endl;
            }       
        }       
    return 0;
}