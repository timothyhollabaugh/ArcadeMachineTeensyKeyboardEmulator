//Code by Ben Goldberg, Logan Greif, and Tim Hollabaugh
//The arcade machine is staying at logan’s house after the fair!

//declare the pin numbers in use as constances
//#define ENTER 3
#define P1 5
#define P2 7
#define A 8
#define S 9
#define UP 10
#define DOWN 11
#define LEFT 12
#define RIGHT 13
#define LED 6
//#define COIN 17
//#define TAB 20
//#define Q 21
//#define W 22
//#define E 23
//#define ESCAPE 4

#define BLINK_TIME 1000
 /*
const int right = 13;
const int s = 9;
const int left = 12;
const int w = 22;
*/

int oldTime = 0;
int ledState = HIGH;
void setup() {
//set the sensor pins to input mode
//  pinMode(ENTER, INPUT);
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(A, INPUT);
  pinMode(S, INPUT);
  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);
  pinMode(LEFT, INPUT);
  pinMode(RIGHT, INPUT);
//  pinMode(COIN, INPUT);
//  pinMode(TAB, INPUT);
//  pinMode(Q, INPUT);
//  pinMode(W, INPUT);
//  pinMode(E, INPUT);
//  pinMode(ESCAPE, INPUT);
  pinMode(LED, OUTPUT);
  
  //turn on the pullup resistor on the input pins
//  digitalWrite(enter, HIGH);
  digitalWrite(P1, HIGH);
  digitalWrite(P2, HIGH);
  digitalWrite(A, HIGH);
  digitalWrite(S, HIGH);
  digitalWrite(UP, HIGH);
  digitalWrite(DOWN, HIGH);
  digitalWrite(LEFT, HIGH);
  digitalWrite(RIGHT, HIGH);
//  digitalWrite(COIN, HIGH);
//  digitalWrite(TAB, HIGH);
//  digitalWrite(Q, HIGH);
//  digitalWrite(W, HIGH);
//  digitalWrite(E, HIGH);
//  digitalWrite(ESCAPE, HIGH);
//  digitalWrite(LED, HIGH);

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
  
  //look for adrcade contol input and output appropreate key press to Raspberry Pi
/*
  if(digitalRead(ENTER) == LOW) {
    Keyboard.press(KEY_ENTER);
  }
  if(digitalRead(ENTER) == HIGH) {
    Keyboard.release(KEY_ENTER);
  }
*/
  if(digitalRead(P1) == LOW) {
    Keyboard.print('5');
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
/*
  if(digitalRead(COIN) == LOW) {
    Keyboard.press(KEY_5);
  }
  if(digitalRead(COIN) == HIGH) {
    Keyboard.release(KEY_5);
  }
*/
/*
  if(digitalRead(TAB) == LOW) {
    Keyboard.press(KEY_TAB);
  }
  if(digitalRead(TAB) == HIGH) {
    Keyboard.release(KEY_TAB);
  }
*/
/*
  if(digitalRead(Q) == LOW) {
    Keyboard.press(KEY_Q);
  }
  if(digitalRead(Q) == HIGH) {
    Keyboard.release(KEY_Q);
  }
*/
/*
  if(digitalRead(W) == LOW) {
    Keyboard.press(KEY_W);
  }
  if(digitalRead(W) == HIGH) {
    Keyboard.release(KEY_W);
  }
*/
/*
  if(digitalRead(E) == LOW) {
    Keyboard.press(KEY_E);
  }
  if(digitalRead(E) == HIGH) {
    Keyboard.release(KEY_E);
  }
*/
/*
  if(digitalRead(ESCAPE) == LOW) {
    Keyboard.press(KEY_ESC);
  }
  if(digitalRead(ESCAPE) == HIGH) {
    Keyboard.release(KEY_ESC);
  }
*/
}
