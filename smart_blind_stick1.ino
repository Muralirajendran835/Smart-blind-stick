#define ePin1 10
#define tPin1 13
#define ePin2 9
#define tPin2 12
#define ePin3 8
#define tPin3 11
#define buz 7
#define vib1 5
#define vib2 4
#define vib3 3
#define pot A0
#define vc 6
// defines variables
long dur1,dur2,dur3; // variable for the duration of sound wave travel
int dist1,dist2,dist3; // variable for the distance measurement

void setup() {
  Serial.begin(9600);
  pinMode(tPin1, OUTPUT);
  pinMode(ePin1, INPUT);
  pinMode(tPin2, OUTPUT);
  pinMode(ePin2, INPUT);
  pinMode(tPin3, OUTPUT);
  pinMode(ePin3, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(vib1, OUTPUT);
  pinMode(vib2, OUTPUT);
  pinMode(vib3, OUTPUT);
 // pinMode(pot, OUTPUT);
  pinMode(vc, OUTPUT);
  digitalWrite(vc, HIGH);
}
void loop() {
  // Clears the trigPin condition
  delay(300);
  int vol=analogRead(pot);
  int v=30+vol/5;
  digitalWrite(tPin1, LOW);
  digitalWrite(tPin2, LOW);
  digitalWrite(tPin3, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(tPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin1, LOW);
  dur1 = pulseIn(ePin1, HIGH);
  
  digitalWrite(tPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin2, LOW);
  dur2 = pulseIn(ePin2, HIGH);
  
  digitalWrite(tPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(tPin3, LOW);
  dur3 = pulseIn(ePin3, HIGH);
  
  // Calculating the distance
  dist1 = dur1 * 0.034 / 2; 
  dist2 = dur2 * 0.034 / 2;
  dist3 = dur3 * 0.034 / 2;
  Serial.println(v);
  if(dist1<=v)
  {
    digitalWrite(vib1,HIGH);
    tone(buz,100,200);
  }
  else{
    digitalWrite(vib1,LOW);
  }
  if(dist2<=v)
  {
    digitalWrite(vib2,HIGH);
    tone(buz,300,200);
  }
  else{
    digitalWrite(vib2,LOW);
  }
  if(dist3<=v)
  {
    digitalWrite(vib3,HIGH);
    tone(buz,500,200);
  }
  else{
    digitalWrite(vib3,LOW);
  }
}