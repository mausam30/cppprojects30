#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include<unordered_map>
#include <sstream>
using namespace std;

class shopping{
    private:
    int pcode;
    float price;
    float dis;
    string pname;
    
    public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();

};

void shopping::menu(){
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t_____\n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t    Super Market Main Menu   \n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t_____\n";
    cout<<"\t\t\t\t                             \n";
    cout<<"\t\t\t\t   1)Administrator      \n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t\t   2)Buyer              \n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t\t   3)Exit               \n";
    cout<<"\t\t\t\t                        \n";
    cout<<"\t\t\t     Please Select:      ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        cout<<"\t\t\t Please Login "<<endl;
        cout<<"\t\t\t Enter email id"<<endl;
        cin>>email;
        cout<<"\t\t\t Password   "<<endl;
        cin>>password;
        if(email=="diya1001@gmail.com" && password=="diy@1001")
        {
            administrator();
        }
        else{
            cout<<"Invalid email/password"<<endl;
        }
        break;
    case 2:
        {
            buyer();
        }
    case 3:
        {
            exit(0);
        }
    default:
        {
            cout<<"Please select from the given menu"<<endl;
        }

    }
    
goto m;
}

void shopping:: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\t Administrator Menu";
    cout<<"\n\t\t\t    1. Add the Product          ";
    cout<<"\n\t\t\t                                ";
    cout<<"\n\t\t\t    2.Modify the Product        ";
    cout<<"\n\t\t\t                                ";
    cout<<"\n\t\t\t    3. Delete the Product       ";
    cout<<"\n\t\t\t                                ";
    cout<<"\n\t\t\t    4. Back to the main menu    ";
    
    cout<<"\n\n\t Please enter your choice ";
    cin>>choice;

    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"invlaid choice"<<endl;

    }
    goto m;
}


void shopping:: buyer(){
    m:
    int choice;
    cout<<"\t\t\t Buyer  \n";
    cout<<"\t\t\t___\n";
    cout<<"                 \n";
    cout<<"\t\t\t1. Buy Product\n";
    cout<<"                 \n";
    cout<<"\t\t\t2. Go back     \n";
    cout<<"\t\t\t Enter your choice : ";
    cin>>choice;

    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();

        default:
            cout<<"invalid choice";
    }
    goto m;
}

void shopping::add(){
    m:
    fstream data;
    int c;
    int token =0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discout on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data){
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    

    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app | ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }    
}
    cout<<"\n\n\t\t Record inserted! "<<endl;
}

void shopping ::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t Modify the Record "<<endl;
    cout<<"\n\t\t\t Product Code :";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n file doesnt exist";
    }
    else
    {
            data1.open("database1.txt", ios :: app|ios::out);

            data>>pcode>>pname>>price>>dis;
            while(!data.eof())
            {
                if(pkey==pcode)
                {
                    cout<<"\n\t\t Product new code : ";
                        cin>>c;
                    cout<<"\n\t\t name of the product :";
                    cin>>n;
                    cout<<"\n\t\t price : ";
                    cin>>p;
                    cout<<"\n\t\t discount: ";
                    cin>>d;
                    data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                    cout<<"\n\n\t\t Record Edited ";
                    token++;
                }
                else{
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
            data1.close();
            remove("database.txt");
            rename("database1.txt","database.txt");

            if(token==0)
            {
                cout<<"\n\n record not found sorry "<<endl;
            }
    }
}

void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t delete product ";
    cout<<"\n\n\t product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"file doesnt exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey)
            {
                cout<<"\n\t\t product deleted successfully ";
                token++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token ==0)
        {
            cout<<"\n\n\t record not found";
        }
    }
}

void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|____\n";
    cout<<"pro_no\t\tname\t\tprice\n";
    cout<<"\n\n______\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}

int Find(vector<int> arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key) return i;
    }
    return -1;
}

void shopping :: receipt()
{
    fstream data;
    vector<int> arrc;
    vector<int> arrq;
    char choice;
    float amount=0;
    float dis=0;
    float total =0;
    float distotal=0;
    
    cout<<"\n\n\t\t\t\t RECEIPT ";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty database";
    }
    else{
        data.close();
        list();
        cout<<"\n____\n";
        cout<<"\n   Place your order \n";
        cout<<"\n____\n";
        do
        {
            int tc, tq;
            cout << "Enter product code : ";
            cin >> tc;
            if (Find(arrc, tc) != -1)
            {
                cout << "duplicate product code, please try again";
                /*for (auto ptr = arrc.begin(); ptr != arrc.end(); ptr++)
                {
                    cout << *ptr << "\t";
                }*/
            }
            else
            {
                arrc.push_back(tc);
                cout << "Enter the product quantity : ";
                cin >> tq;
                arrq.push_back(tq);
            }
            cout<<"\n\n do you want to buy another product , y or n ";
            cin>>choice;
        }while(choice=='y');
        
        //cout<<"total number of items: "<<c;
        cout<<"\n\n\t\t\t Receipt \n";
        cout<<"\nProduct No\t Product Name\t Product quantity\t price\t amount with discount\n";
        unordered_map<int,vector<string> >table;
        ifstream myfile("database.txt");
        string strRow;
        while(getline(myfile, strRow))
        {
            vector<string> tempVec;
            istringstream iss(strRow);
            for (string s; iss>>s; )
            {
                tempVec.push_back(s);
            }
            table[stoi(tempVec[0])] = tempVec;
        }

        /*cout << "\nTABLE BEGIN\n";
        for (int i = 0; i < table.size(); i++)
        {
            for (int j = 0; j < table[i].size(); j++)
            {
                cout << table[i][j] << ",";
            }
            cout << "\n";
        }
        //cout << "\nTABLE END\n";
        cout << "ARRC_SIZE:" << arrc.size() << "\n\n";*/
        for(int i=0;i < arrc.size();i++)
        {
            vector<string> row = table[arrc[i]];
            cout << "\n" << row[0] << "\t\t" << row[1] << "\t\t" << arrq[i] << "\t\t" << row[2] << "\t\t" << arrq[i] * stod(row[2]) << "\t\t" << arrq[i] * stod(row[2]) * (1 - (stod(row[3])/100)) << "\n\n";
            total+=arrq[i] * stod(row[2]);
            dis=arrq[i] * stod(row[2]) * (1 - (stod(row[3])/100));
            distotal+=dis;
        }
        data.close();
    }
    cout<<"\n\n____";
    cout<<"\n total amount : "<<total << "\t\t"<<"After Discount : "<<distotal;
    cout<<endl;
}


int main(){
    shopping s;
    s.menu();
}
