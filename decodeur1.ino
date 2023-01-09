#define outputA 6
#define outputB 7
 

 
int counter = 0;
int currentStateA;
int lastStateA;
String currentDir ="";
 
void setup() {
  
  // Set encoder pins as inputs
  pinMode(outputA,INPUT);
  pinMode(outputB,INPUT);
 
 
  // Setup Serial Monitor
  Serial.begin(9600);


  
delay(2000);

  // Read the initial state of outputA
  lastStateA = digitalRead(outputA);
}
 
void loop() {
  
  // Read the current state of outputA
  currentStateA = digitalRead(outputA);
 
 
  // If last and current state of outputA are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateA != lastStateA  && currentStateA == 1){
 
    // If the outputB state is different than the outputA state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(outputB) != currentStateA) {
      counter ++;
      currentDir ="CW";
    } else {
      // Encoder is rotating CW so increment
      counter --;
      currentDir ="ACW";
    }
 
    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);

  }
 
  // Remember last outputA state
  lastStateA = currentStateA;
 
  // Put in a slight delay to help debounce the reading
  delay(1);
}