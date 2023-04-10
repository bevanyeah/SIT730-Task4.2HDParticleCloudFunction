


int red = D2;
int green = D3;
int blue = D4;


// The remote function callback. Note that using an RGB LED with a shared anode,
// means that we inverse our HIGHs/LOWs.  ie.  On = low!
int lightChange(String command)
{
    if (command.equals("red"))
    {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, HIGH);
        return 1;
    }
    else if (command.equals("green"))
    {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, HIGH);
        return 1;
    }
    else if (command.equals("orange"))
    {
        digitalWrite(red, LOW);
        analogWrite(green, 255-165);
        digitalWrite(blue, HIGH);
        return 1;
    }
    // No longer used, but might be useful to keep incase
    else if (command.equals("blue"))
    {
        digitalWrite(red, HIGH);
        analogWrite(green, HIGH);
        digitalWrite(blue, LOW);
        return 1;
    }
    else
    {
        // Unknown option
        return -1;
    }
}

// Allow code to run before cloud is connected
SYSTEM_THREAD(ENABLED);

void setup() {

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue,OUTPUT);
  
  Particle.function("led", lightChange);
  
//   Start state should be red light
  digitalWrite(red, LOW);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);

}


void loop() {



}

