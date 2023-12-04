#include <bits/stdc++.h>
using namespace std;

//This function is to convert a string to a lower case
string to_lower(string s){
    for(int i=0 ; i<s.size() ; i++){
        //if the character is in the range of the upper case ascii
        if(s[i]>=65 && s[i]<=90 ){
            //convert it lo lower by adding 32
            s[i]+=32;
        }
    }
    return s;
}


void scanner(string name){
    map<string, int>words;

    //to open the file for reading and saves it in a variable named file
    ifstream file (name);

    //to check if the file is opened successfully and if not it allows the user to reEnter the file name
    while (!file) {
        cout<< "Error: Unable to open file " << name << "\nPlease reEnter the name: ";
        cin>>name;
        //attempt to open the new file name
        file.open(name);
    }

    //string to save in it each line in the file and a cnt variable to count the total points of the scam words
    string line;
    int cnt=0;

    //while loop to loop over each line and saves it in line variable
    while(getline(file, line)){

        //to convert the whole line to a lower case letters
        string line2 = to_lower(line);

        string word;
        for(int i=0 ; i<line.size() ; i++){
            if(isalpha(line[i]) || line[i] == '-'){
                word+= line[i];
            }else{
                if(!word.empty()){
                    words[word]++;
                    word.clear();
                }
            }
        }
    }
    for(const auto& i:words){
        cout<<i.first<<": "<<i.second<<'\n';
    }
}
int main() {
    string name;
    cout<<"Enter the file name: ";
    cin>>name;
    string s = name+".txt";
    scanner(s);
    return 0;
}
