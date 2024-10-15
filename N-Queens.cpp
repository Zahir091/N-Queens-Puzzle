#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
  for (int i=0; i<c; i++) {
    if(q[i] == q[c] || c-i == abs(q[c] - q[i]))
      return false;
  }
  return true;
}
int numOfSolutions(int queens) {
  int sol = 0;
  int*q = new int[queens];
  for(int i=0;i<queens;i++) {
    *(q+i) = 0;
  }
  int c = 0;
  while(c>=0) {
  c++;
    if (c == queens) {
      ++sol;
      c--;
    }
    else 
      *(q+c) = -1;
    while(c>=0) {
      (*(q+c))++;
      if (*(q+c) == queens) c--;
      else if (ok(q,c)) break;
    }
  }
  delete[] q;
  return sol;
}
int main() {
  int n;
  cout << "Please enter a number for n: ";
  cin >> n;
  for (int i=1; i<=n; i++) {
    cout << "The " << i << " Queens problem has " << numOfSolutions(i) << " Solutions" << endl;
  }
  return 0;  
}