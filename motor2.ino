int motor1pin1 = PA7;
int motor1pin2 = PA8;

int motor2pin1 = PA1;
int motor2pin2 = PA2;


int ENA        = PA3;
int ENB        = PA4;

void setup() {
  
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1,   OUTPUT);
  pinMode(motor2pin2,   OUTPUT);
  pinMode(ENA       ,   OUTPUT);
  pinMode(ENB       ,   OUTPUT);
  Serial.begin(9600);
  
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
}

void loop() {
   // put your main code here, to run repeatedly:

  
 
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor1pin1, HIGH);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  delay(3000);

 
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor1pin1, LOW);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
 
  delay(3000);
}