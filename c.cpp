#include<bits/stdc++.h>
using namespace std;

class String_con{
    public:
    bool palindrom(string s){
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i] != s[n-i-1]){
                return false;
            }

        }
        return true;
    }
    void consonent(string s){
        int  vo=0 ,con=0,spa=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                vo++;
            }
            else if(s[i] >= 'a' and s[i] <= 'z'){
                con++;
            }else if (s[i] == ' '){
                spa++;
            }
        }
        cout<<vo<<endl<<con<<endl<<spa<<endl; 
    }
    string removeVowel(string s){
        for(int i=0;i<s.size();i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                s = s.substr(0,i) + s.substr(i+1);
                i--;
            }

        }
        return s;
    }
    string removeSpace(string s){
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i] != ' '){
                /*s = s.substr(0,i) + s.substr(i+1);
                i--;*/
                s[count] = s[i];
                count++;
            }
        }
                s[count] = '\0';
        return s;
    }
    string reverse(string s){
        int i=0,j=s.size()-1;
        while(i<j){
            swap(s[i],s[j]);
            i++ ;
            j--;
        }
        return s;
    }
    void frequency(string s){
        int arr[26] = {0};
        for(int i=0;i<s.size();i++){
            arr[s[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i] != 0){
                cout<<char(i + 'a')<<arr[i]<<endl;
            }
        }
    }
    void non_repating(string s){
        int arr[26] = {0};
        for(int i=0;i<s.size();i++){
            arr[s[i] - 'a']++;
        }
        for(int i=0;i<26;i++){
            if(arr[i] == 1){
                cout<<char(i + 'a')<<arr[i]<<endl;
            }
        }
    }
    bool CheckAnagrams(string s1,string s2){
        if(s1.length() != s2.length()){
            return false;
        }

        int freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i] - 'A']++;
        }
        for(int i=0;i<s2.length();i++){
            freq[s2[i] - 'A']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i] != 0){
                return  false;
            }
        }
        return true;
    }
     string solve(string s , int n){
         for(int i=0;i<n;i++){
             int ascii = (int)s[i];
             if(ascii == 90){
                 s[i] = char(57);
             }else if(ascii == 122){
                 s[i] = char(97);
             }else if((ascii >= 65 and ascii <90) || (ascii >= 97 and ascii <122)){
                 s[i] =char(ascii+1);
             }
         }
         return s;
     }
};

int main(){
    String_con obj;
    //cout<<obj.palindrom(s);
    //obj.consonent(s);
    //ascii int c=a; return int(a);
    //string ans = obj.removeVowel(s);
    // string ans = obj.removeSpace(s);
    //string ans = obj.reverse(s);
    //cout<<ans<<endl;
    // obj.frequency(s);
    //obj.non_repating(s);
   /* string Str1 = "b";
  string Str2 = "d";
  if(obj.CheckAnagrams(Str1, Str2))
  cout << "True" << endl;
  else
  cout<<"False"<<endl;
  return 0;*/

  string str = "abcdxyz";
  int length = str.length();
  cout<<"Original String: "<<"\n";
  cout<<str<<endl;
  cout << "New string: " << "\n";
  cout << obj.solve(str, length) << "\n";
}