#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "deal.h"
using namespace std;

void boxSet(ifstream& reader, string d, string& n, float& p)
{
  reader >> d >> n >> p;
}

void getSum(Deal theDeal[26], float& s)
{
  s=0.0;
for (int w = 0; w<25; w++)
{
  s += theDeal[w].getBoxPrice();
}
}

void offerAmount(int c, float sU, float& bO)
{
  bO= 10000+(-2714.74 *c)+(0.040*sU);

}

int main()
{

  int  i=0, total =0, kept_boxNum =0, openBox =0, caseLeft =25;
  float price =0.0, sum = 0.0, bankOffer=0.0;
  string num = "", dummy = "", user_name = "", deal = "", rem = "";
  

Deal allDeals[26];

ifstream reader;
reader.open("file.txt");

boxSet(reader, dummy , num, price);

while (reader)
{
  allDeals[i].setBoxNum(num);
  allDeals[i].setBoxPrice(price);

boxSet(reader, dummy , num, price);

i++;
}

reader.close();

cout << "Enter your name" << endl;
getline(cin, user_name);
cout << user_name << " welcome to Deal or No Deal!" << endl;
cout << "Choose a box to keep  (Enter a number between 0 and 25)" << endl;
cin >> kept_boxNum;

while (deal != "d")
{
for (int x =0; x<5; x++)
{
cout << "Choose a box to open  (Enter a number between 0 and 25)" << endl;
cin >> openBox;
cout << "It has $" << fixed << showpoint << setprecision(2)<< allDeals[openBox].getBoxPrice() << " inside" << endl;

caseLeft = caseLeft-1;

allDeals[openBox].setBoxNum("X");
allDeals[openBox].setBoxPrice(0.0);
}

getSum(allDeals, sum);
offerAmount(caseLeft,sum, bankOffer);

cout << "Banker offer: : $" << fixed << showpoint << setprecision(2)<< bankOffer << endl;
cout << "Remaining boxes" << endl ;

for(int y =0; y<25; y++)
{
  cout << allDeals[y].getBoxNum() << "  " ;
}
cout << endl <<"deal or no deal (d/n)" << endl;
cin >> deal;
}

cout << "Potential Winnings: $" << fixed << showpoint << setprecision(2)<< bankOffer << endl;
cout << "Winnings: $" <<  fixed << showpoint << setprecision(2)<< allDeals[kept_boxNum].getBoxPrice() << endl;
cout << "Would you like to see what is in the remaining boxes?(yes/no)" << endl;
cin >> rem;
if (rem == "yes")
{
  for (int v =0; v<25 ; v++)
  {
cout << "Box " << v << ": $" << fixed << showpoint << setprecision(2)<< allDeals[v].getBoxPrice() << endl;
  }
}
}
