#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <map>
using namespace std;


struct DataTemplate
{
    int MaxSlices;
    int NoOfPizzas;
    map<int, int> slices;

    DataTemplate()
    {
        this -> MaxSlices = 0;
        this->NoOfPizzas = 0;
    }
};

struct DataTemplate* ConvertData(string);
string GetString();
void ProcessData(struct DataTemplate*);
void SetString(struct DataTemplate*);
unsigned int RecursionBackTracking(DataTemplate*, unsigned int, int);

int main()
{
    DataTemplate* ptr;
    string s = GetString();
    ptr = ConvertData(s);

    cout << "Input Str  :   " << s << endl << endl;
    cout << "Maxium No  :   " << ptr->MaxSlices << endl;
    cout << "Pizza No   :   " << ptr->NoOfPizzas << endl;
    cout << "Sequence   :   ";
    for (unsigned int i = 0; i < ptr->slices.size(); i++)
        cout << ptr->slices[i] << " ";
    cout << endl << endl;
    //ProcessData(ptr);
    //SetString(ptr);

    system("pause");
    return 0;
}

struct DataTemplate* ConvertData(string s)
{
    DataTemplate* ptr = new DataTemplate();
    size_t start = 0, end = 0;
    try
    {
        end = s.find(" ");
        ptr->MaxSlices = stoi(s.substr(start, end));

        start = end;
        end = s.find(" ", end + 1);
        ptr->NoOfPizzas = stoi(s.substr(start, end));
    }
    catch (...) {}

    for (int i = 0; i < ptr->NoOfPizzas; i++)
    {
        start = end;
        end = s.find(" ", end + 1);
        ptr->slices.insert(pair<int, int>(i, stoi(s.substr(start, end))));
    }
    return ptr;
}

void ProcessData(struct DataTemplate* ptr)
{
    unsigned int sliceSum = 0;
    RecursionBackTracking(ptr,sliceSum, ptr->NoOfPizzas-1);
}

unsigned int RecursionBackTracking(DataTemplate * ptr, unsigned int sliceSum, int index)
{
    if ((sliceSum + ptr->slices[index] > ptr->MaxSlices) ||
            (index < 0 || sliceSum == ptr->MaxSlices))
        return sliceSum;

    RecursionBackTracking(ptr, sliceSum, index-1);
    RecursionBackTracking(ptr, sliceSum + ptr->slices[index], index-1);
}

string GetString()
{
    string s1, s2;
    ifstream DATA_FILE;

    try
    {
        DATA_FILE.open("d_quite_big.in", ios::in);
        getline(DATA_FILE, s1);
        getline(DATA_FILE, s2);
        s1 = s1 + " " + s2;
        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl; }
    return s1;
}

void SetString(struct DataTemplate* ptr)
{
    size_t size = ptr->slices.size();
    string temp = "";
    try
    {
        ofstream DATA_FILE;
        DATA_FILE.open("Ans.out", ios::out);

        DATA_FILE << size << endl;
        for (int i = 0; i < size; i++)
            temp = temp + " " + to_string(ptr->slices[i]);
        temp.erase(0, 1);
        DATA_FILE << temp << endl;

        DATA_FILE.close();
    }
    catch (exception x) { cout << "File Error ... !" << endl; }
}
