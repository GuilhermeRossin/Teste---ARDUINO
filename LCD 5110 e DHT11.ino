#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#include <dht.h>

#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1

dht DHT;

// pin 8 - Serial clock out (SCLK)
// pin 9 - Serial data out (DIN)
// pin 10 - Data/Command select (D/C)
// pin 11 - LCD chip select (CS/CE)
// pin 12 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

// Variáveis que guardam a temperatura máxima e mínima
int maxtemp = -100,mintemp = 100;

// Variáveis que guardam a umidade máxima e mínima 
int maxhum = -100, minhum = 100; 
int temperatura,umidade;


static unsigned char PROGMEM grau[] =
{ B00001100, B00010010, B00001100, B00000000,}; //Array simbolo grau

void setup()
{
  Serial.begin(9600);
  display.begin();
  display.setContrast(50); //Ajusta o contraste do display
  display.clearDisplay();   //Apaga o buffer e o display
  display.setTextSize(1);  //Seta o tamanho do texto
  display.drawRect(0,0, 84,48, BLACK); //Desenha o retangulo da borda
  display.drawRect(1,1, 82,46, BLACK); //Desenha o retangulo da borda
  display.display();
}

void loop()
{
  DHT.read11(dht_dpin); //Lê as informações do sensor
  temperatura = DHT.temperature;
  umidade = DHT.humidity;

  //Armazena a temperatura máxima na variável maxtemp
  if(temperatura > maxtemp) {maxtemp = temperatura;} 

  //Armazena a temperatura minima na variável mintemp
  if(temperatura < mintemp) {mintemp = temperatura;} 

  //Armazena a umidade máxima na variável maxhum
  if(umidade > maxhum) {maxhum = umidade;} 

  //Armazena a umidade minima na variável minhum
  if(umidade < minhum) {minhum = umidade;} 

  display.setTextColor(BLACK,WHITE); //Seta a cor do texto
  display.setCursor(3,5);  //Seta a posição do cursor
  display.print("Temp : ");  
  display.print(temperatura);
  //Desenha o simbolo do grau na posicao 56,5
  display.drawBitmap(56,5, grau, 8, 4, BLACK); 
  display.setCursor(65,5);
  display.println("C");
  display.setCursor(3,13);
  display.print("Umid : ");
  display.print(umidade);
  display.println(" %\n");

  display.setCursor(3,24);
  display.print("Max:");
  display.print(maxtemp);
  display.drawBitmap(37,24, grau, 8, 4, BLACK);
  display.setCursor(46,24);
  display.print("C/");
  display.print(maxhum);
  display.println(" %");
  display.setCursor(3,32);
  display.print("Min:");
  display.print(mintemp);
  display.drawBitmap(37,32, grau, 8, 4, BLACK);
  display.setCursor(46,32);
  display.print("C/");
  display.print(minhum);
  display.println(" %");
  display.display();

  delay(2000); //Aduarda 2 segundos e reinicia o processo
 }
