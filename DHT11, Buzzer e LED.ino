#include <dht.h>

#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1

const int led = 7;
const int buzzer = 10;

float temp, hum ;

dht DHT; //Inicializa o sensor

void setup()
{
  Serial.begin(9600);
  delay(1000);//Aguarda 1 seg antes de acessar as informações do sensor
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  DHT.read11(dht_dpin); //Lê as informações do sensor
  Serial.print("Umidade = ");
  Serial.print(DHT.humidity);
  hum = DHT.humidity;
  Serial.print(" %  ");
  Serial.print("Temperatura = ");
  Serial.print(DHT.temperature); 
  temp = DHT.temperature;
  Serial.println(" Celsius  ");
  
  if(temp > 26 || hum > 39){
    digitalWrite(led, HIGH);
    tone(buzzer, 2000);
  }
  else{
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
  //Não diminuir o valor abaixo. O ideal é a leitura a cada 2 segundos
  delay(1000);  
}
