int []leds = {led1,led2,led3};
int echoPin = 7;
int trigPin = 8;
int leftMotor_forward = 9;
int leftMotor_backward = 10;
int rightMotor_forward = 11;
int rightMotor_backward = 12;
long duration;
int distance;

void setup() {
  
  
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

void backward(int duration){  
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

 
}
