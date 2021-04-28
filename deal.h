#include <string>
using namespace std;

class Deal
{

private:
string boxNum;
float boxPrice;

public:
Deal();
string getBoxNum();
float getBoxPrice();

void setBoxNum(string);
void setBoxPrice(float);


};