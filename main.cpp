#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "project4.h"

using namespace std;
using namespace std::chrono;
#define ll long long
void generate_random_strings(vector<vector<string> > &v)
{
  for (int i = 2; i <= 10; i++)
  {
    for (int j = 0; j < 500; j++)
    {
      string s = "";
      for (int k = 0; k < i; k++)
      {
        char c = 32 + rand() % 91;
        s += c;
      }
      v[i].push_back(s);
    }
  }
}

string generate_random_text()
{
  string randtext = "";
  for (int i = 0; i < 10000; i++)
  {
    char c = 32 + rand() % 91;
    randtext += c;
  }
  return randtext;
}

void fn(vector<vector<string> > &v, int algo, string &T, vector<double> &time_arr)
{
  // cout<<v.size();
  for (int i = 2; i < v.size(); i++)
  {
    auto start = high_resolution_clock::now();
    for (auto j : v[i])
    {
      switch (algo)
      {
      case 0:
        brute(T, j);
        break;
      case 1:
        kmp(T, j);
        break;
      case 2:
        bmh(T, j);
        break;
      case 3:
        rk(T, j);
        break;
      case 4:
        bitap(T, j);
        break;
      }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    time_arr.push_back(duration.count() / (double)v[i].size());
  }
}

void generate_text_strings(vector<vector<string> > &v)
{
  string temp;
  // Read from the text file
  ifstream MyReadFile("words2.txt");
  int c = 0;
  // Use a while loop together with the getline() function to read the file line by line
  while (getline(MyReadFile, temp))
  {
    if (temp.length() >= 2 and temp.length() <= 10 and v[temp.length()].size() < 150)
    {
      // cout<<"YES";
      v[temp.length()].push_back(temp);
    }
    c++;
  }

  MyReadFile.close();
}

string generate_file_text()
{
  string myText;
  string s;

  // Read from the text file
  ifstream MyReadFile("speeches.txt");

  // Use a while loop together with the getline() function to read the file line by line
  while (getline(MyReadFile, myText))
  {
    s += myText;
    s += ' ';
  }

  // Close the file
  MyReadFile.close();
  return s;
}
int main()
{
  srand((unsigned)time(NULL));
  cout << "RANDOM" << endl;
  vector<vector<string> > v(11);
  generate_random_strings(v);
  string randomText = generate_random_text();
  vector<double> time_arr;

  // Write to the file
  ofstream MyFile("result_random.txt");
  for (int algo = 0; algo < 5; algo++)
  {
    time_arr.clear();
    fn(v, algo, randomText, time_arr);
    // cout << algo << endl;
    MyFile << algo << ",";
    for (auto i : time_arr)
    {
      // cout << i << " ";
      MyFile << i << ",";
    }
    MyFile << "\n";
    // cout << endl<< endl;
  }
  // Close the file
  MyFile.close();
  
  vector<vector<string> > v2(11);
  cout << "Text"<<endl;
  generate_text_strings(v2);
  randomText = generate_file_text();
  ofstream MyFile2("result_speech.txt");
  for (int algo = 0; algo < 5; algo++)
  {
    time_arr.clear();
    fn(v2, algo, randomText, time_arr);
    // cout << algo << endl;
    MyFile2 << algo << ",";
    for (auto i : time_arr)
    {
      MyFile2 << i << ",";
      // cout << i << " ";
    }
    MyFile2 << "\n";
    // cout << endl
    //      << endl;
  }
  MyFile2.close();
  return 0;
}