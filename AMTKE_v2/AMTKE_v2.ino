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

#define BLINK_TIME 1000

Bounce enter = Bounce(ENTER, 10);
//Bounce esc = Bounce(ESCAPE, 10);
//Bounce p1 = Bounce(P1, 10);
//Bounce p2 = Bounce(P2, 10);
//Bounce a = Bounce(A, 10);
//Bounce s = Bounce(S, 10);
//Bounce d = Bounce(D, 10);
//Bounce up = Bounce(UP, 10);
//Bounce down = Bounce(DOWN, 10);
//Bounce left = Bounce(LEFT, 10);
//Bounce right = Bounce(RIGHT, 10);
//Bounce pause = Bounce(PAUSE, 10);
//Bounce tab = Bounce(TAB, 10);

int oldTime = 0;
int ledState = HIGH;
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
  digitalWrite(LED, HIGH);;
  digitalWrite(PAUSE, HIGH);

  oldTime  = millis();  
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
  
  enter.update();
  if(enter.fallingEdge()) {
    Keyboard.press(KEY_ENTER);
  }
  if(enter.risingEdge()) {
    Keyboard.release(KEY_ENTER);
  }


  if(digitalRead(P1) == LOW) {    Keyboard.print('5');
    delay(100);
    Keyboard.print('1');
  }

  if(digitalRead(P2) == LOW) {
    Keyboard.print('5');
    delay(100);
    Keyboard.print('5');
    delay(100);
    Keyboard.print('2');
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

  if(digitalRead(UP) == LOW) {
    Keyboard.press(KEY_UP);
  }
  if(digitalRead(UP) == HIGH) {
    Keyboard.release(KEY_UP);
  }

  if(digitalRead(DOWN) == LOW) {
    Keyboard.press(KEY_DOWN);
  }
  if(digitalRead(DOWN) == HIGH) {
    Keyboard.release(KEY_DOWN);
  }

  if(digitalRead(LEFT) == LOW) {
    Keyboard.press(KEY_LEFT);
  }
  if(digitalRead(LEFT) == HIGH) {
    Keyboard.release(KEY_LEFT);
  }

  if(digitalRead(RIGHT) == LOW) {
    Keyboard.press(KEY_RIGHT);
  }
  if(digitalRead(RIGHT) == HIGH) {
    Keyboard.release(KEY_RIGHT);
  }

  if(digitalRead(D) == LOW) {
    Keyboard.press(KEY_D);
  }
  if(digitalRead(D) == HIGH) {
    Keyboard.release(KEY_D);
  }

  if(digitalRead(TAB) == LOW) {
    Keyboard.press(KEY_TAB);
  }
  if(digitalRead(TAB) == HIGH) {
    Keyboard.release(KEY_TAB);
  }

  if(digitalRead(ESCAPE) == LOW) {
    Keyboard.press(KEY_ESC);
  }
  if(digitalRead(ESCAPE) == HIGH) {
    Keyboard.release(KEY_ESC);
  }

  if(digitalRead(PAUSE) == LOW) {
    Keyboard.press(KEY_P);
  }
  if(digitalRead(PAUSE) == HIGH) {
    Keyboard.release(KEY_P);
  }
}
