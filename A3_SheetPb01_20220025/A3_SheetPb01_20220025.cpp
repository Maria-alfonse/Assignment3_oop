#include <bits\stdc++.h>
using namespace std;
#define BUFFALO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
class LabelGenerator{
protected:
     int _Labels ;
    string _Label;
public:
    LabelGenerator(string Label,int Labelidx);
     virtual string nextLabel();
};
LabelGenerator::LabelGenerator(string Label, int Labelidx) {
    _Label = Label;
    _Labels = Labelidx;
}
string LabelGenerator::nextLabel() {
    return _Label + to_string((_Labels++));
}
class FileLabelGenerator : public LabelGenerator{
private:
    string FileName;
    vector<string>vString;
public:
    FileLabelGenerator(string Labels , int Labelidx , string FileName) : LabelGenerator(Labels,Labelidx) , FileName(FileName){
 fstream MyFile;
    MyFile.open(FileName , ios::in);
    if(MyFile.is_open()){
        string line;

        while(getline(MyFile,line)){
        vString.push_back( line);

        }
    }
    MyFile.close();
    };
string nextLabel() override{
int Temp  = _Labels;
_Labels++;
    return  _Label + to_string((Temp)) + " " + vString[Temp-1];

}

};
int main() {
    BUFFALO
    LabelGenerator figureNumbers("Figure ", 1);
    LabelGenerator pointNumbers("P", 0);
    cout << "Figure numbers: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl << "Point numbers: ";
    for (int i = 0; i < 5; i++) {
        cout << pointNumbers.nextLabel() << ", ";
    }
    cout << endl << "More figures: ";
    for (int i = 0; i < 3; i++) {
        cout << figureNumbers.nextLabel() << ", ";
    }
    cout << endl;
    FileLabelGenerator figureLabels ("Figure ", 1, "labels.txt");
    cout << "Figure labels: \n";
    for (int i = 0; i < 3; i++)
        cout << figureLabels.nextLabel() << endl;

        return 1;
}
