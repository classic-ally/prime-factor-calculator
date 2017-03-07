//Cameron Bentley
//Multi-threaded factor calculator

#include <iostream>
#include <iomanip>
#include <cmath>
#include <thread>
#include <sstream>

using namespace std;
int bigFactor = 0;

int factorCompute(int startVal, double maxvalue) {
  stringstream msg;
  msg << "thread " << this_thread::get_id() << ": Now computing prime factors of " << setprecision(12) << maxvalue << " ending in " << startVal << endl;
  cout << msg.str();
  msg.str("");
  if(startVal==1) {
    startVal=11;
  }
  for(double i=startVal; i<=maxvalue; i=i+10) {
    bool terminate = false;
    bool isAFactor = false;
    if(fmod(maxvalue, i)==0) { //If 600851475143 divided by this number has no remainder, then it's a factor of 600851475143
      isAFactor = true;
    }
    else {
      terminate = true; //Not a prime, stop calculating
      //cout << i << " IS NOT a factor of 600851475143" << endl;
    }
    if(terminate == false) {
      for(double j=2; j<i && terminate == false && isAFactor == true; j++) { //Executes if this j is less than i, i hasn't already been determined to be non-prime, and i actually is a factor of 600851475143
        if(fmod(i, j)==0) { //If there's no remainder there it isn't a prime
          terminate = true; //Terminate if it's not a prime
        }
      }
      if(terminate == false) { //If the program didn't terminate, then it must be a prime
        stringstream msg;
        msg << "thread " << this_thread::get_id() << ": Found prime factor " << setprecision(12) << i << endl;
        cout << msg.str();
        if(i>bigFactor) {
          bigFactor = i;
        }
      }
    }
  }
  msg << "thread " << this_thread::get_id() << ": Reached " << maxvalue << ", terminating " << endl;
  cout << msg.str();
  return bigFactor;
}

int main() {
  double maxvalue = 600851475143;
  cout << "Enter value to compute prime factors of: ";
  cin >> maxvalue;
  thread compute1 (factorCompute, 1, maxvalue);
  thread compute3 (factorCompute, 3, maxvalue);
  thread compute7 (factorCompute, 7, maxvalue);
  thread compute9 (factorCompute, 9, maxvalue);
  compute1.join();
  compute3.join();
  compute7.join();
  compute9.join();
  cout << "Biggest prime factor computed: " << bigFactor << endl;

}
