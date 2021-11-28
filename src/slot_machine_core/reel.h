#ifndef SLOTMACHINE_REEL_H
#define SLOTMACHINE_REEL_H

#include <string>
#include <vector>

using namespace std;

class Reel{
private:
  vector<string> symbols;
  void parse(const char *symbolString);
  int offset;

public:
   Reel();
   Reel(const char *symbolsString);
   Reel(const Reel &other);
   Reel operator=(const Reel &other);
   string operator[](int index) const;
   int size() const;
   void spin();
   int getOffset() const;
};

#endif

