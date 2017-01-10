#define leftmotor_a 11
#define rightmotor_a 11
#define leftmotor_b 9
#define rightmotor_b 9 

int i;

// Declaring variables to hold the values from the input of the IR Sensors
int dat0;
int dat1;
int dat2;
int dat3;

void setup() {
  // Motor Pins
  pinMode(leftmotor_a, OUTPUT);
  pinMode(rightmotor_a, OUTPUT);
  pinMode(leftmotor_b, OUTPUT);
  pinMode(rightmotor_b, OUTPUT);
  // IR Input pins
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {
  // Reading Values from the Sensors, Note this will be refreshed everytime the loop runs
  dat0 = analogRead(A0);
  dat1 = analogRead(A1);
  dat2 = analogRead(A2);
  dat3 = analogRead(A3);
  //Checks if the vaccum has reached a dead end ahead
  if(dat0 < 300){
    // case when there is not enough space left behind to move back and there is not enough space ahead
    if((dat3 < 200)&&(dat0 < 200)){
      analogWrite(leftmotor_a, 0);
      analogWrite(leftmotor_b, 0);
      analogWrite(rightmotor_a, 255);
      analogWrite(rightmotor_b, 0);
    }
    else{
      // give signals to make the motors move back
      analogWrite(leftmotor_a, 0);
      analogWrite(leftmotor_b, 255);
      analogWrite(rightmotor_a, 0);
      analogWrite(rightmotor_b, 255);
      i = 0;
      // keeps the vaccum moving back for 5 seconds unless an obstacle is encountered
      while((dat3 > 200)&&(i<100)){
        i++;
        delay(50);
      }
      // checks to see if there is any space to move to in the direction of dat2 and if there is, moves in that direction
      if(dat2 > 200){
        analogWrite(leftmotor_a, 125);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 255);
        analogWrite(rightmotor_b, 0);
      }
      else{
        if(dat1 > 200){
          analogWrite(leftmotor_a, 255);
          analogWrite(leftmotor_b, 0);
          analogWrite(rightmotor_a, 125);
          analogWrite(rightmotor_b, 0);
        }
      }
    }
  }
  else{
    if(dat1 < 200){
      analogWrite(leftmotor_a, 125);
      analogWrite(leftmotor_b, 0);
      analogWrite(rightmotor_a, 255);
      analogWrite(rightmotor_b, 0);
    }
    else{
      if(dat2 < 200){
        analogWrite(leftmotor_a, 255);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 125);
        analogWrite(rightmotor_b, 0);
      }
      else{
        analogWrite(leftmotor_a, 255);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 255);
        analogWrite(rightmotor_b, 0);
      }
    }
  }
}
