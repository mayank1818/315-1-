const int led = 13;
const int motionsensor = 2;
volatile bool motiondetected = false;

void setup() {
  Serial.begin(9600);

  pinMode(motionsensor, INPUT);
  pinMode(led, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(motionsensor), motionInterrupt, RISING);
}

void loop() {

}

void motionInterrupt() {
  static bool light = LOW;  
  light = !light;
  digitalWrite(led, light);

  motiondetected = light;
  
  if (motiondetected) {
    Serial.println("Motion Detected");
  }
  
   delay(2000);
}