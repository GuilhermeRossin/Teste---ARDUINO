const int ledpin = 13;
const int botao = 2;
int estado = 0;

void setup(){
  pinMode(ledpin, OUTPUT);
  pinMode(botao, INPUT);
}

void loop(){
  estado = digitalRead(botao);

  if(estado == HIGH){
    digitalWrite(ledpin, LOW);   //Led desligado
  }
  if(estado == LOW){
    digitalWrite(ledpin, HIGH);   //Led ligado
  }
}