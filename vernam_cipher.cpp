#include<bits/stdc++.h>
using namespace std;

#define ll long long int

string tobinary(string s)
{
    string ans="";

    for(int j=0; j<s.length(); j++)
    {
        unsigned char c=s[j];

        for(int i=7; i>=0; i--)
        {
            ans += ((c >> i) & 1) ? '1' : '0';
        }
    }

    return ans;
}


string xxor(string s,string key)
{
    string ans="";
    for(int i=0; i<s.length(); i++)
    {
        ans+=(s[i]==key[i]?'0':'1');
    }
    return ans;
}

string totext(string binary)
{
    string ans="";

    for(int i=0; i<binary.length(); i+=8)
    {

        string byte = binary.substr(i,8);

        int value=0;

        for(int j=0; j<8; j++)
        {
            value = value*2 + (byte[j]-'0');
        }

        ans += char(value);
    }

    return ans;
}



int main()
{
    cout<<"Vernam Cipher"<<endl;
    string matrix[2][2];

    cout<<"Give a 2 by 2 matrix : ";

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cin>>matrix[i][j];
        }
    }

    //transpose the matrix
    string transpose[2][2];
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            transpose[j][i]=matrix[i][j];
        }
    }

    cout<<"Tthe transpose matrix is : "<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<transpose[i][j]<<"\t";
        }
        cout<<endl;
    }

    cout<<"String to Binary : "<<endl;
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            transpose[i][j]=tobinary(transpose[i][j]);
            cout<<transpose[i][j]<<"\t";
        }
        cout<<endl;
    }

    string randomkey[2][2];
    srand(52);

    cout<<"Random key matrix :"<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            string key="";
            for(int m=0; m<transpose[i][j].length(); m++)
            {
                key+=(rand()%2)+'0';
            }
            randomkey[i][j]=key;
            transpose[i][j]=xxor(transpose[i][j],key);
            cout<<randomkey[i][j]<<" \t ";

        }
        cout<<endl;
    }



    cout<<"Tthe encrypted matrix is : "<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            cout<<transpose[i][j]<<"\t";
        }
        cout<<endl;
    }


    cout<<"===================================\n==============================="<<endl;

    cout<<"Tthe Decrypted matrix is : "<<endl;

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {
            transpose[i][j]=xxor(transpose[i][j],randomkey[i][j]);
            cout<<transpose[i][j]<<"\t";
        }
        cout<<endl;
    }



    cout << "\nDecrypted Text Matrix:\n";

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<2; j++)
        {

            string text = totext(transpose[i][j]);

            cout << text << "\t";
        }
        cout << endl;
    }


    return 0;
}
