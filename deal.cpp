#include "deal.h"
#include <string>
using namespace std;

Deal::Deal()
{
boxNum = "";
boxPrice =0.0;
}

string Deal::getBoxNum()
{
  return boxNum;
}
void Deal::setBoxNum(string n)
{
  boxNum = n;
}

float Deal::getBoxPrice()
{
  return boxPrice;
}

void Deal::setBoxPrice(float p)
{
  boxPrice = p;
}