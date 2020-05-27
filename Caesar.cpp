
#include <iostream>
#include <string>
#include "Caesar.h"
using namespace std;



Caesar::Caesar(string str) 
    //assigns key to an object
    : key(str)
    {}

string Caesar::get_key() const {
  // return the current cipher key
  //string cipher_key;
  //cout << "Enter Cipher key: " << endl;
  //cin >> cipher_key;
  return key;
}

string Caesar::decode(string encoded_message) const{
  // decode the string argument using the key, return decoded string
  string result = "";
  int minchar = 32;
  int maxchar = 122;
  string key = get_key();

  for (int i = 0; i < encoded_message.length(); i ++){
    char intchar = encoded_message[i];
    char shift = key[i % key.length()];

    char ogchar = ((intchar - shift) + (maxchar ));

if (ogchar >= 122) {
    
    ogchar = ogchar - 90;
}      
else{
    ogchar = char(ogchar + 1);
}
      
    result += ogchar;
  }
  return result;
}

string Caesar::encode(string message) const{
  // encode the string argument using the key, return encoded string
  string result;
  int minchar = 32;
  int maxchar = 122;
  string key = get_key();

  for (int i = 0; i < message.length(); i++){
    char intchar = message[i] - minchar;
    char shift = (key[i % key.length()] - minchar);
    char newchar = ( intchar + shift ) % (maxchar + 1 - minchar) + minchar;
      

    result += newchar;
  }
  return result;
}
