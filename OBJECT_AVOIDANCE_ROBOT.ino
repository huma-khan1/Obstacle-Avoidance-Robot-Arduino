// OBJECT AVOIDANCE BOT

#define TRIG 12
#define ECHO 13

#define ENA 5
#define ENB 6

#define IN1 8  
#define IN2 9  
#define IN3 11 
#define IN4 10 

void setup() {
  Serial.begin(9600); 

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {

  digitalWrite(TRIG,LOW);
delay(10);

digitalWrite(TRIG,HIGH);
delay(10);
digitalWrite(TRIG,LOW);

int duration=pulseIn(ECHO,HIGH);

int distance = duration*0.034/2;
distance = constrain(distance, 0 , 500);
Serial.println(distance);

  if (distance < 20) {
   
    stopMotors();
    delay(200);

   backward();
   delay(300);

    turnRight();
    delay(300);
  } else {
    
    forward();
  }

  delay(100); 
}

void forward() {
  analogWrite(ENA, 70); 
  analogWrite(ENB, 70);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void backward() {
  analogWrite(ENA, 70);
  analogWrite(ENB, 70);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, 60);
  analogWrite(ENB, 80);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}