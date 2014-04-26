
//Code by Ben Goldberg, Logan Greif, and Tim Hollabaugh
//The arcade machine is staying at logan’s house after the fair!

//declare the pin numbers in use as constances
const int enter = 3;
const int p1 = 5;
const int p2 = 7;
const int a = 8;
const int s = 9;
const int up = 10;
const int down = 11;
const int left = 12;
const int right = 13;
const int coin = 17;
const int tab = 20;
const int q = 21;
const int w = 22;
const int e = 23;
const int escape = 4;

void setup() {
  
  //set the sensor pins to input mode
  pinMode(enter, INPUT);
  pinMode(p1, INPUT);
  pinMode(p2, INPUT);
  pinMode(a, INPUT);
  pinMode(s, INPUT);
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(coin, INPUT);
  pinMode(tab, INPUT);
  pinMode(q, INPUT);
  pinMode(w, INPUT);
  pinMode(e, INPUT);
  pinMode(escape, INPUT);
  
  //turn on the pullup resistor on the input pins
  digitalWrite(enter, HIGH);
  digitalWrite(p1, HIGH);
  digitalWrite(p2, HIGH);
  digitalWrite(a, HIGH);
  digitalWrite(s, HIGH);
  digitalWrite(up, HIGH);
  digitalWrite(down, HIGH);
  digitalWrite(left, HIGH);
  digitalWrite(right, HIGH);
  digitalWrite(coin, HIGH);
  digitalWrite(tab, HIGH);
  digitalWrite(q, HIGH);
  digitalWrite(w, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(escape, HIGH);
}

void loop() {
  //look for adrcade contol input and output appropreate key press to Raspberry Pi
  if(digitalRead(enter) == LOW) {
    Keyboard.press(KEY_ENTER);
  }
  if(digitalRead(enter) == HIGH) {
    Keyboard.release(KEY_ENTER);
  }

  if(digitalRead(p1) == LOW) {
    Keyboard.press(KEY_1);
  }
  if(digitalRead(p1) == HIGH) {
    Keyboard.release(KEY_1);
  }

  if(digitalRead(p2) == LOW) {
    Keyboard.press(KEY_2);
  }
  if(digitalRead(p2) == HIGH) {
    Keyboard.release(KEY_2);
  }

  if(digitalRead(a) == LOW) {
    Keyboard.press(KEY_A);
  }
  if(digitalRead(a) == HIGH) {
    Keyboard.release(KEY_A);
  }

  if(digitalRead(s) == LOW) {
    Keyboard.press(KEY_S);
  }
  if(digitalRead(s) == HIGH) {
    Keyboard.release(KEY_S);
  }

  if(digitalRead(up) == LOW) {
    Keyboard.press(KEY_UP);
  }
  if(digitalRead(up) == HIGH) {
    Keyboard.release(KEY_UP);
  }

  if(digitalRead(down) == LOW) {
    Keyboard.press(KEY_DOWN);
  }
  if(digitalRead(down) == HIGH) {
    Keyboard.release(KEY_DOWN);
  }

  if(digitalRead(left) == LOW) {
    Keyboard.press(KEY_LEFT);
  }
  if(digitalRead(left) == HIGH) {
    Keyboard.release(KEY_LEFT);
  }

  if(digitalRead(right) == LOW) {
    Keyboard.press(KEY_RIGHT);
  }
  if(digitalRead(right) == HIGH) {
    Keyboard.release(KEY_RIGHT);
  }

  if(digitalRead(coin) == LOW) {
    Keyboard.press(KEY_5);
  }
  if(digitalRead(coin) == HIGH) {
    Keyboard.release(KEY_5);
  }

  if(digitalRead(tab) == LOW) {
    Keyboard.press(KEY_TAB);
  }
  if(digitalRead(tab) == HIGH) {
    Keyboard.release(KEY_TAB);
  }

  if(digitalRead(q) == LOW) {
    Keyboard.press(KEY_Q);
  }
  if(digitalRead(q) == HIGH) {
    Keyboard.release(KEY_Q);
  }

  if(digitalRead(w) == LOW) {
    Keyboard.press(KEY_W);
  }
  if(digitalRead(w) == HIGH) {
    Keyboard.release(KEY_W);
  }

  if(digitalRead(e) == LOW) {
    Keyboard.press(KEY_E);
  }
  if(digitalRead(e) == HIGH) {
    Keyboard.release(KEY_E);
  }

  if(digitalRead(escape) == LOW) {
    Keyboard.press(KEY_ESC);
  }
  if(digitalRead(escape) == HIGH) {
    Keyboard.release(KEY_ESC);
  }
}
