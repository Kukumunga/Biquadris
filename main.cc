#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <memory>
using namespace std;

#include "biquadris.h"

int main () {
  unique_ptr<Biquadris>q{new Biquadris()};
  q->start();
}
