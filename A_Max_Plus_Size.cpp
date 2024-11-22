#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {

}

int main()
{
    

    string s;
    cin>>s;
    
    if(s[8]=='P'){
        s=s.substr(0,8);
        if(s[0]=='1'&& s[1]=='2'){
            
        }
        else{
            int x=stoi(s.substr(0,2));
            x+=12;
            string a=to_string(x);
            a+=s.substr(2,6);
            s=a;
        }
        
    }
    else{
         s=s.substr(0,8);
        if(s[0]=='1'&& s[1]=='2'){
            s[0]='0';
            s[1]='0';
        }
        
        
    }
    cout<<s<<endl;


    return 0;
}
