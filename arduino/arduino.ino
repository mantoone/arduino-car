#define E 7
#define T 6
#define W 5
#define S 4
#define A 3
#define D 2
#define M 12

void setup() {
  // put your setup code here, to run once:
  pinMode(D,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(S,OUTPUT);
  pinMode(W,OUTPUT);
  pinMode(E,INPUT);
  pinMode(T,OUTPUT);
  Serial.begin(9600);

  digitalWrite(S,HIGH);
  digitalWrite(D,HIGH);
  digitalWrite(A,HIGH);
  digitalWrite(W,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(2,LOW);
  //digitalWrite(3,HIGH);
  //digitalWrite(5,LOW);
  int dist = ping();
  if(dist > 10 && dist < 4000){
    if(dist > 50){
    digitalWrite(W,LOW);
    delay(300);
    digitalWrite(W,HIGH);    
  } else {
    digitalWrite(W,HIGH);
    digitalWrite(S,LOW);
    digitalWrite(D,LOW);
    delay(1000);
    digitalWrite(S,HIGH);
    digitalWrite(D,HIGH);
  }
  delay(300);
  }
}

int ping()
{
  // Clears the trigPin
digitalWrite(T, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(T, HIGH);
delayMicroseconds(10);
digitalWrite(T, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
long duration = pulseIn(E, HIGH);
// Calculating the distance
int distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance < 410){
  tone(M, 410 - distance);  
}

return distance;
}
