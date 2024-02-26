int L_pin = 6; //pin for left line tracking sensor
int M_pin = 7; //pin for middle line tracking sensor
int R_pin = 8; //pin for right line tracking sensor
int val_L,val_R,val_M; //define variables for three sensors

void setup(){
  Serial.begin(9600);

  pinMode(4, OUTPUT); // define left motors, output
  pinMode(2, OUTPUT); // define right motors, output

  pinMode(L_pin, INPUT); // define left sensor, input
  pinMode(M_pin, INPUT); // define middle sensor, input
  pinMode(R_pin, INPUT); // define right sensor, input

}

void loop(){
  val_L = digitalRead(L_pin); // Read the left sensor
  val_M = digitalRead(M_pin); // Read the middle sensor
  val_R = digitalRead(R_pin); // Read the right sensor
  
  
  /* decision making statement (if statement) checks the given value from the sensors.
  If the stetement is correct it will call the given function */
  //0=white
  //1=black
  if (val_R == 0 && val_M == 1 && val_L == 0){  // if left and right sensor sense white and the middle sense black --> move formward
    MoveForward();
  }
  else if (val_R == 1 && val_M == 1 && val_L == 1){ // else if left, right and middle sensor sense black --> move formward
    MoveForward();
  }
  else if (val_R == 0 && val_M == 1 && val_L == 1){ // else if right sensor sense white and the middle and the right sense black --> turn left
    TurnLeft();
  }
  else if (val_R == 0 && val_M == 0 && val_L == 1){ // else if right and middle sensor sense white and the left sense black --> turn left
    TurnLeft();
  }
  else if (val_R == 1 && val_M == 1 && val_L == 0){ // else if left sensor sense white and the middle and the right sense black --> turn right
    TurnRight();
  }
  else if (val_R == 1 && val_M == 0 && val_L == 0){ // else if left and middle sensor sense white and the right sense black --> turn right
    TurnRight();
  }
  else if (val_R == 0 && val_M == 0 && val_L == 0){ // else if all the sensor sense white --> stop
    Stop();
  }

}

// function that move the car forward
void MoveForward(){
  digitalWrite(4,HIGH); // left motors on
  analogWrite(5,90); // controlls the speed
  digitalWrite(2,HIGH); // right motors on
  analogWrite(9,90); // controlls the speed
}

// function that move the car backwards (does not use, only for testing but keeps it to show how i started)
void MoveBackwards(){
  digitalWrite(4,LOW); // left motors off
  analogWrite(5,90); // controlls the speed
  digitalWrite(2,LOW); // right motors off
  analogWrite(9,90); // controlls the speed

}

// function that turn the car left
void TurnLeft(){
  digitalWrite(4,LOW); // left motors off
  analogWrite(5,0); // controlls the speed
  digitalWrite(2,HIGH); // right motors on
  analogWrite(9,150); // controlls the speed
  delay(200); 

}

// function that turn the car right
void TurnRight(){
  digitalWrite(4,HIGH); // left motors on
  analogWrite(5,150); // controlls the speed
  digitalWrite(2,LOW); // right motors off
  analogWrite(9,0); // controlls the speed
  delay(200);

}

// function that stops the car
void Stop(){
  analogWrite(5,0); // controlls the speed, stopping --> speed = 0
  analogWrite(9,0); // controlls the speed, stopping --> speed = 0
}

