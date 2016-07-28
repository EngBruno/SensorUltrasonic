
// variáveis
int triger = 9; // pino TRIG do sensor ultrassônico
int echo = 8; // pino ECHO do sensor ultrassônico
float tempo; // para armazenar o tempo de ida e volta do sinal em microsegundos
float distancia_cm; // para armazenar a distância em centímetros

void setup() {
  // configura pino GATILHO como saída
 pinMode(triger,OUTPUT);
 // deixa pino em LOW
 digitalWrite(triger,LOW);
 delayMicroseconds(10);
 
 // configura pino ECHO como entrada
 pinMode(echo,INPUT);
 Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
  // disparar pulso ultrassônico
 digitalWrite(triger, HIGH);
 delayMicroseconds(10);
 digitalWrite(triger, LOW);
 
 // medir tempo de ida e volta do pulso ultrassônico
 tempo = pulseIn(echo, HIGH);
 
 // calcular as distâncias em centímetros
 distancia_cm = tempo / 29.4 / 2;
 if(distancia_cm<10){
    Serial.println(distancia_cm);
 }

 // aguardar um pouquinho antes de começar tudo de novo
 delayMicroseconds(200);

}
