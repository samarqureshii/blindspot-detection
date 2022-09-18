int led1 = 1; //red
int led2 = 2; //yellow
int led3 = 3; //green
int enA = 4;
int enB = 5;
int echoPin = 7;
int trigPin = 8;
int leftMotor_forward = 9;
int leftMotor_backward = 10;
int rightMotor_forward = 11;
int rightMotor_backward = 12;
long duration;
int distance;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(leftMotor_forward, OUTPUT);
  pinMode(leftMotor_backward, OUTPUT);
  pinMode(rightMotor_forward,OUTPUT);
  pinMode(rightMotor_backward, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

}

void backward(int duration){  
digitalWrite(leftMotor_forward, LOW);
digitalWrite(leftMotor_backward, HIGH);
digitalWrite(rightMotor_forward, LOW);
digitalWrite(rightMotor_backward, HIGH);
delay(duration);
}

void forward(int duration){  
digitalWrite(leftMotor_forward, HIGH);
digitalWrite(leftMotor_backward, LOW);
digitalWrite(rightMotor_forward, HIGH);
digitalWrite(rightMotor_backward, LOW);
delay(duration);
}


void pivotRight(int pivotDuration){
  digitalWrite(leftMotor_forward,HIGH);
  digitalWrite(leftMotor_backward,LOW);
  digitalWrite(rightMotor_forward, LOW);
  digitalWrite(rightMotor_backward, HIGH);
  delay(pivotDuration);
}

void pivotLeft(int pivotDuration){
  digitalWrite(leftMotor_forward,LOW);
  digitalWrite(leftMotor_backward,HIGH);
  digitalWrite(rightMotor_forward, HIGH);
  digitalWrite(rightMotor_backward, LOW);
  delay(pivotDuration);
}

void Stop(int pivotDuration){
  digitalWrite(leftMotor_forward,LOW);
  digitalWrite(leftMotor_backward,LOW);
  digitalWrite(rightMotor_forward, LOW);
  digitalWrite(rightMotor_backward, LOW);
  delay(pivotDuration);
}

void loop() {
  analogWrite(enA, 50);
  analogWrite(enB, 50);
  
  forward(500);

  digitalWrite(trigPin, LOW);
  delayMicroseconds(1000);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  Serial.print("\t\t\t\t\t\t\t\tDistance:");
  Serial.println(distance);

    
  if (distance <= 10 ){ 
    pivotRight(3000); //obstacle detection
    digitalWrite(led1, HIGH); //turns red LED on
    delay(2000);
    digitalWrite(led1, LOW);
  }

  else if (distance > 10 && distance <= 20){ 
    digitalWrite(led2, HIGH); //turns yellow LED on
    delay(2000);
    digitalWrite(led2, LOW);
     
  }

  else{
    digitalWrite(led3, HIGH); //turns green LED on
    delay(2000);
    digitalWrite(led3, LOW);
  }
  
 
}
