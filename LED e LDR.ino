const int ldr = 0;
const int led = 6;
int valorlido = 0;
int pwm = 0;

void setup (){
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop(){
  valorlido = analogRead(ldr);
  Serial.print("Valor lido pelo LDR = ");
  Serial.println(valorlido);
  if(valorlido < 200){
    analogWrite(led, pwm);
    pwm++;
    delay(100);
  }
  else{
    digitalWrite(led, HIGH);
    pwm = 0;
  }
    if(pwm>255){
      pwm = 255;
    }
}