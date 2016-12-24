/*

///////////////////////////
// ADDITIONAL KEY CODES ///
///////////////////////////

KEY_LEFT_CTRL
KEY_LEFT_SHIFT    
KEY_LEFT_ALT    
KEY_LEFT_GUI    
KEY_RIGHT_CTRL    
KEY_RIGHT_SHIFT   
KEY_RIGHT_ALT 
KEY_RIGHT_GUI   

KEY_BACKSPACE   
KEY_TAB       
KEY_RETURN      
KEY_ESC       
KEY_INSERT      
KEY_DELETE      
KEY_PAGE_UP     
KEY_PAGE_DOWN   
KEY_HOME
KEY_END       
KEY_CAPS_LOCK 
  
KEY_F1        
KEY_F2        
KEY_F3        
KEY_F4        
KEY_F5        
KEY_F6        
KEY_F7        
KEY_F8        
KEY_F9        
KEY_F10
KEY_F11       
KEY_F12     

*/

#include "Keyboard.h"
#include "Mouse.h"

#define BTNS_COUNT 18

#define MOUSE_MOVE_UP       -1 
#define MOUSE_MOVE_DOWN     -2
#define MOUSE_MOVE_LEFT     -3
#define MOUSE_MOVE_RIGHT    -4

int btnsPin[BTNS_COUNT] = {1, 0, 2, 3, 4, 5, 6, 7, 8, 9, 10, 16, 14, 15, 18, 19, 20, 21};
boolean btnsStatus[BTNS_COUNT] = {false};
int btnsValue[BTNS_COUNT] = {
  'a',
  'w',
  's',
  'e',
  'd',
  'f',
  't',
  'g',
  'y',

  'h',
  'u',
  'j',
  'k',
  'o',
  'l',
  'z',
  'x',
  ' '
};

void _start() {
  for (int i = 0; i < BTNS_COUNT; i++) {
    digitalWrite(btnsPin[i], HIGH);
    if (digitalRead(btnsPin[i]) == 0) {
      if (btnsStatus[i] != true) {
        Keyboard.press(btnsValue[i]);
        btnsStatus[i] = true;
      }
    } else {
      if (btnsStatus[i] == true) {
        Keyboard.release(btnsValue[i]);
      }
      btnsStatus[i] = false;
     }
    digitalWrite(btnsPin[i], LOW);
  };
}

void setup() {
  for (int i = 0; i < BTNS_COUNT; i++) {
    pinMode(btnsPin[i], INPUT);
    digitalWrite(btnsPin[i], LOW);
  };
  Keyboard.begin();
}

void loop() {  
  _start();
  delay(50);
}
