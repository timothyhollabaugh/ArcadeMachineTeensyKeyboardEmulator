//Code by Ben Goldberg, Logan Greif, and Tim Hollabaugh
//The arcade machine is staying at Logan's house after the fair!
#include <Bounce.h>
//declare the pin numbers in use as constances
#define ENTER 3
#define ESCAPE 4
#define P1 5
#define P2 7
#define A 21
#define S 22
#define D 23
#define UP 13
#define DOWN 14
#define LEFT 15
#define RIGHT 16
#define LED 6
#define PAUSE 17 // Add code for
#define TAB 1 
#define DIP_1 8
#define DIP_2 9
#define DIP_3 11
#define DIP_4 10

#define BLINK_TIME 1000

Bounce enter = Bounce(ENTER, 10);
Bounce esc = Bounce(ESCAPE, 10);
Bounce p1 = Bounce(P1, 10);
Bounce p2 = Bounce(P2, 10);
Bounce a = Bounce(A, 10);
Bounce s = Bounce(S, 10);
Bounce d = Bounce(D, 10);
Bounce up = Bounce(UP, 10);
Bounce down = Bounce(DOWN, 10);
Bounce left = Bounce(LEFT, 10);
Bounce right = Bounce(RIGHT, 10);
Bounce pause = Bounce(PAUSE, 10);
Bounce tab = Bounce(TAB, 10);
Bounce dip1 = Bounce(DIP_1, 10);
Bounce dip2 = Bounce(DIP_2, 10);
Bounce dip3 = Bounce(DIP_3, 10);
Bounce dip4 = Bounce(DIP_4, 10);

int oldTime = 0;
int ledState = HIGH;
boolean menu = false;
boolean tabToggle = false;
boolean pauseToggle = false;
boolean ctrToggle = false;

void setup() {
//set the sensor pins to input mode
  pinMode(ENTER, INPUT);
  pinMode(ESCAPE, INPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(A, INPUT);
  pinMode(S, INPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
  pinMode(D, INPUT);
  pinMode(TAB, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(PAUSE, INPUT);
  pinMode(DIP_1, INPUT);
  pinMode(DIP_2, INPUT);
  pinMode(DIP_3, INPUT);
  pinMode(DIP_4, INPUT);
  
  //turn on the pullup resistor on the input pins
  digitalWrite(ENTER, HIGH);
  digitalWrite(P1, HIGH);
  digitalWrite(P2, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(S, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(DOWN, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RIGHT, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(TAB, HIGH);
  digitalWrite(ESCAPE, HIGH);
  digitalWrite(LED, HIGH);
  digitalWrite(PAUSE, HIGH);
  digitalWrite(DIP_1, HIGH);
  digitalWrite(DIP_2, HIGH);
  digitalWrite(DIP_3, HIGH);
  digitalWrite(DIP_4, HIGH);

  oldTime = millis();
  
  if(digitalRead(DIP_1) == LOW){
    ctrToggle = true;
  }
  if(digitalRead(DIP_2) == LOW){
    pauseToggle = true;
  }
  if(digitalRead(DIP_3) == LOW){
    tabToggle = true;
  }
  if(digitalRead(DIP_4) == LOW){
    menu = true;
  }
}

void loop() {
  
  //Blink led every BLINK_TIME milliseconds
  int now = millis();
  if(now  - oldTime >= BLINK_TIME) {
    if(ledState == HIGH){
      ledState = LOW;
    }else if(ledState == LOW) {
      ledState = HIGH;
    }
    oldTime = now;
  }
  digitalWrite(LED, ledState);
  
  //look for arcade control input and output appropriate key press to Raspberry Pi
  
  if(ctrToggle == true){
    enter.update();
    if(enter.fallingEdge()) {
      Keyboard.press(KEY_ENTER);
    }
    if(enter.risingEdge()) {
      Keyboard.release(KEY_ENTER);
    }
  }
  
  p1.update();
  if(p1.fallingEdge()) {
    Keyboard.press(KEY_5);
    delay(500);
    Keyboard.press(KEY_1);
  }
  if (p1.risingEdge()){
    Keyboard.release(KEY_5);
    delay(500);
    Keyboard.release(KEY_1);
  }
  
  p2.update();
  if(p2.fallingEdge()) {
    Keyboard.press(KEY_5);
    delay(500);
    Keyboard.press(KEY_6);
    delay(500);
    Keyboard.press(KEY_2);
  }
  if (p2.risingEdge()){
    Keyboard.release(KEY_5);
    delay(500);
    Keyboard.release(KEY_6);
    delay(500);
    Keyboard.release(KEY_2);
  }

  if(digitalRead(A) == LOW) {
    Keyboard.press(KEY_A);
  }
  if(digitalRead(A) == HIGH) {
    Keyboard.release(KEY_A);
  }

  if(digitalRead(S) == LOW) {
    Keyboard.press(KEY_S);
  }
  if(digitalRead(S) == HIGH) {
    Keyboard.release(KEY_S);
  }
  
  if (menu == false) {
    if(digitalRead(UP) == LOW) {
      Keyboard.press(KEY_UP);
    }
    if(digitalRead(UP) == HIGH) {
      Keyboard.release(KEY_UP);
    }
  }
  if (menu == true) {
    up.update();
    if(up.fallingEdge()) {
     Keyboard.press(KEY_UP);
     Keyboard.release(KEY_UP);
    }
  } 
  
  if (menu == false) {
    if(digitalRead(DOWN) == LOW) {
      Keyboard.press(KEY_DOWN);
    }
    if(digitalRead(DOWN) == HIGH) {
      Keyboard.release(KEY_DOWN);
    }
  }
  if (menu == true) {
    down.update();
    if(down.fallingEdge()) {
     Keyboard.press(KEY_DOWN);
     Keyboard.release(KEY_DOWN);
    }
  }

  if (menu == false) {
    if(digitalRead(LEFT) == LOW) {
      Keyboard.press(KEY_LEFT);
    }
    if(digitalRead(LEFT) == HIGH) {
      Keyboard.release(KEY_LEFT);
    }
  }
  if (menu == true) {
    left.update();
    if(left.fallingEdge()) {
     Keyboard.press(KEY_LEFT);
     Keyboard.release(KEY_LEFT);
    }
  }

if (menu == false) {
    if(digitalRead(RIGHT) == LOW) {
      Keyboard.press(KEY_RIGHT);
    }
    if(digitalRead(RIGHT) == HIGH) {
      Keyboard.release(KEY_RIGHT);
    }
  }
  if (menu == true) {
    right.update();
    if(right.fallingEdge()) {
     Keyboard.press(KEY_RIGHT);
     Keyboard.release(KEY_RIGHT);
    }
  }

  if(digitalRead(D) == LOW) {
    Keyboard.press(KEY_D);
  }
  if(digitalRead(D) == HIGH) {
    Keyboard.release(KEY_D);
  }
  
  if(tabToggle == true){
    if(digitalRead(TAB) == LOW) {
      Keyboard.press(KEY_TAB);
    }
    if(digitalRead(TAB) == HIGH) {
      Keyboard.release(KEY_TAB);
    }
  }
  if(ctrToggle == true){
    if(digitalRead(ESCAPE) == LOW) {
      Keyboard.press(KEY_ESC);
    }
    if(digitalRead(ESCAPE) == HIGH) {
      Keyboard.release(KEY_ESC);
    }
  }
  
  if(pauseToggle == true){
    if(digitalRead(PAUSE) == LOW) {
      Keyboard.press(KEY_P);
    }
    if(digitalRead(PAUSE) == HIGH) {
      Keyboard.release(KEY_P);
    }
  }
  
  dip1.update();
  if (dip1.fallingEdge()) {
    ctrToggle = true;
  }
  if (dip1.risingEdge()) {
    ctrToggle = false;
  }
  
  dip2.update();
  if (dip2.fallingEdge()) {
    pauseToggle = true;
  }
  if (dip2.risingEdge()) {
    pauseToggle = false;
  }
  
  dip3.update();
  if (dip3.fallingEdge()) {
    tabToggle = true;
  }
  if (dip3.risingEdge()) {
    tabToggle = false;
  }
  
  dip4.update();
  if (dip4.fallingEdge()) {
    menu = true;
  }
  if (dip4.risingEdge()) {
    menu = false;
  }
}
