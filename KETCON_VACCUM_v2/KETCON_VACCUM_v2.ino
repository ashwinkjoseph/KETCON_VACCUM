#define leftmotor_a 11
#define rightmotor_a 6
#define leftmotor_b 10
#define rightmotor_b 5 

int i;

// Declaring variables to hold the values from the input of the IR Sensors
int dat0;
int dat1;
int dat2;

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
}

void loop() {
  // Reading Values from the Sensors, Note this will be refreshed everytime the loop runs
  dat0 = analogRead(A0);
  dat1 = analogRead(A1);
  dat2 = analogRead(A2);
  //Checks if the vaccum has reached a dead end ahead
  if(dat0 > 400){
    Serial.println("I'm In");
    // case when there is not enough space left behind to move back and there is not enough space ahead
      // give signals to make the motors move back
      analogWrite(leftmotor_a, 0);
      analogWrite(leftmotor_b, 255);
      analogWrite(rightmotor_a, 0);
      analogWrite(rightmotor_b, 255);
      i = 0;
      // keeps the vaccum moving back for 5 seconds unless an obstacle is encountered
      delay(1250);
      // checks to see if there is any space to move to in the direction of dat2 and if there is, moves in that direction
      if(dat2 < 200){
        Serial.println("Im' turning to dat2");
        analogWrite(leftmotor_a, 255);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 0);
        analogWrite(rightmotor_b, 255);
        delay(500);
      }
      else{
        // same as previous but to opposite direction
        if(dat1 < 200){
          Serial.println("I'm turning to dat1");   
          analogWrite(leftmotor_a, 0);
          analogWrite(leftmotor_b, 255);
          analogWrite(rightmotor_a, 255);
          analogWrite(rightmotor_b, 0);
          delay(500);
        }
      }
  }
  else{
    // if there is an obstacle in this side, it moves in the opposite side
    if(dat1 > 300){
      analogWrite(leftmotor_a, 0);
      analogWrite(leftmotor_b, 255);
      analogWrite(rightmotor_a, 255);
      analogWrite(rightmotor_b, 0);
      delay(500);
    }
    else{
      // if there is an obstacle in this direction, it moves in the opposite side
      if(dat2 > 300){
        analogWrite(leftmotor_a, 255);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 0);
        analogWrite(rightmotor_b, 255);
        delay(500);
      }
      // if there is no obstacle in any direction, it keeps moving forward
      else{
        analogWrite(leftmotor_a, 255);
        analogWrite(leftmotor_b, 0);
        analogWrite(rightmotor_a, 255);
        analogWrite(rightmotor_b, 0);
      }
    }
  }
}
