// File name:A3_SheetPb2_20220131
// Purpose: Document Similarity
// Author(s):Rana Esmail
// ID(s):20220131
// Section:S5
// Date: 12/7/2023
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
class StringSet{
    vector<string> allwordVector;
    vector <string> splitLines (string Line){
        vector <string > vstrings;
        string word;
        for (char c:Line){
            if (isalpha(c)){
                word+= tolower(c);
            }
            else if (!word.empty()){
                vstrings.push_back(word);
                word.clear();

            }
        }
        if (!word.empty()) {
            vstrings.push_back(word);
        }
        return vstrings;
    }
public:
    StringSet(){

    }
    StringSet(const string  & FileName,const string & txt){
        string Line;
        vector <string> vfilestrings;
        ifstream MyReadFile(FileName+".txt");
        while (getline (MyReadFile, Line)) {
            vfilestrings = splitLines(Line);
            allwordVector.insert(allwordVector.end(),vfilestrings.begin(),vfilestrings.end());//add vfile to vall
        }
    // Close the file
        MyReadFile.close();
    }
    StringSet(const string &text) {
        allwordVector = splitLines(text);

    }
    void AddString (const string & word){
        allwordVector.push_back(word);
    }
    void RemoveString (const string & word){
        auto it = find(allwordVector.begin(),allwordVector.end(),word);
        if (it!=allwordVector.end())
            allwordVector.erase(it);
    }
    void ClearSet (){
        allwordVector.clear();
    }
    int SetSize (){
        return allwordVector.size();
    }
    void OutputSet (){
        for (auto word: allwordVector){
            cout << word<<"\n";
        }
    }
    StringSet operator+(StringSet &other) {
        StringSet Res;
        set_union(allwordVector.begin(), allwordVector.end(), other.allwordVector.begin(), other.allwordVector.end(), back_inserter(Res.allwordVector));
        return Res;
    }

    StringSet operator*(StringSet &other) {
        StringSet result;
        sort(allwordVector.begin(), allwordVector.end());
        sort(other.allwordVector.begin(), other.allwordVector.end());

        set_intersection(allwordVector.begin(), allwordVector.end(), other.allwordVector.begin(), other.allwordVector.end(), back_inserter(result.allwordVector));

        return result;
    }
    double computeSimilarity( StringSet &other)  {
        StringSet intersectionSet = (*this) * other;
        double numerator = intersectionSet.SetSize();
        double denominator = sqrt((this->SetSize()) * other.SetSize());

        if (denominator == 0.0) {
            return 0.0;
        }

        return numerator / denominator;
    }

};
int main() {

    // Test the StringSet class
    StringSet document("document","txt");
    StringSet query1("chocolate ice cream is delicious");
    StringSet query2("vanilla ice cream is tasty");

    // Output the sets
    cout << "Document Set:\n";
    document.OutputSet();
    cout << "Document size ="<<document.SetSize()<<'\n';
    cout<<"-------------------------------------\n";
    cout << "Query 1 Set:\n";
    query1.OutputSet();
    cout << "Q1 size ="<<query1.SetSize()<<'\n';

    cout<<"-------------------------------------\n";

    cout << "Query 2 Set:\n";
    query2.OutputSet();
    cout << "Q2 size ="<<query2.SetSize()<<'\n';

    cout<<"-------------------------------------\n";
    cout<<"intersection between Q1 and document:"<<'\n';
    StringSet intersectionSet1 = document * query1;
    intersectionSet1.OutputSet();
    cout<<"-------------------------------------\n";
    cout<<"intersection between Q2 and document:"<<'\n';
    StringSet intersectionSet2 = document * query2;
    intersectionSet2.OutputSet();
    cout<<"-------------------------------------\n";
    cout<<"union between Q1 and Q2:"<<'\n';
    StringSet query3 = query2 + query1;
    query3.OutputSet();
    cout<<"-------------------------------------\n";
    cout<<"intersection between Q3 and document:"<<'\n';
    StringSet intersectionSet3 = document * query3;
    intersectionSet3.OutputSet();
    cout<<"-------------------------------------\n";

    // Test computeSimilarity
    double similarity1 = document.computeSimilarity(query1);
    double similarity2 = document.computeSimilarity(query2);
    double similarity3 = document.computeSimilarity(query3);

    cout << "Similarity between Document and Query 1: " << similarity1 << "\n";
    cout << "Similarity between Document and Query 2: " << similarity2 << "\n";
    cout << "Similarity between Document and Query 3: " << similarity3 << "\n";
    cout<<"-------------------------------------\n";

    cout << "Document Set after add new string 'is' :\n";
    document.AddString("is");
    document.OutputSet();
    cout << "Document size ="<<document.SetSize()<<'\n';
    cout<<"-------------------------------------\n";
    cout << "After removing 'chocolate':\n";
    document.RemoveString("chocolate");
    document.OutputSet();
    cout << "Document size ="<<document.SetSize()<<'\n';
    cout<<"-------------------------------------\n";
    cout << "Document Set after clear:\n";
    document.ClearSet();
    document.OutputSet();
    cout << "Document size ="<<document.SetSize()<<'\n';

    return 0;
}
