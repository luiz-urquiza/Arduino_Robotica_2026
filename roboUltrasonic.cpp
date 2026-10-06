/**
 * O circuito:
 * * O módulo HR-SC04 (quatro pinos)
 *   deve ser conectado às portas digitais da seginte forma:
 * --------------------- 
 * | HC-SC04 | Arduino | 
 * --------------------- 
 * |   Vcc   |   5V    | 
 * |   Trig  |   12    | 
 * |   Echo  |   13    | 
 * |   Gnd   |   GND   | 
 * ---------------------
 * Obs: Você não precisa usar obrigatoriamente as portas acima;
*/
#include <Ultrasonic.h>

Ultrasonic ultrasonic(12, 13);
int distancia;


/**
 *	A struct Motor representa um motor DC com controle de velocidade no pino PWM
 *		1 - Declare um registro do tipo Motor
 *		2 - Execute o método setup do registro dentro da função setup do Arduino
 *			2.1 - pAvancar: porta que controla o pino que faz o motor girar para frente
 *			2.2 - pRecuar: porta que controla o pino que faz o motor girar para trás
 *			2.3 - pVel: pino PWM que controla a velocidade do motor
 *		3 - Ao executar os métodos avancar e recuar você deve informar a velocidade
 *			do motor.
 *
 */
struct Motor{
  int pinoVel;   		// pino PWM que controla a velocidade
  int pinoA;            // pino que faz o motor girar para frente FORWARD
  int pinoR;            // pino que faz o motor girar para traz BACKWARD

  void setup(int pAvancar, int pRecuar, int pVel){
    pinoA = pAvancar;
    pinoR = pRecuar;
    pinoVel = pVel;
    
    pinMode(pinoVel, OUTPUT);
    pinMode(pinoA, OUTPUT);
    pinMode(pinoR, OUTPUT);
    
    parar();
  }

  void avancar(int vel){
    analogWrite(pinoVel, vel);
    digitalWrite(pinoA, HIGH);
    digitalWrite(pinoR, LOW);
  }

  void recuar(int vel){
    analogWrite(pinoVel, vel);
    digitalWrite(pinoA, LOW);
    digitalWrite(pinoR, HIGH);
  }

  void parar(){
    analogWrite(pinoVel, 0);
    digitalWrite(pinoA, LOW);
    digitalWrite(pinoR, LOW);
  }
};

Motor motorDireito, motorEsquerdo;

void setup() {
  motorDireito.setup(5, 4, 6);
  motorEsquerdo.setup(9, 8, 10);
}

void loop() {
  // Mede a distância até um obstáculo a frente
  distancia = ultrasonic.read();

  if (distancia >= 10){
    // Avança se a distancia for de pelo menos 10cm
    motorDireito.avancar(200);
    motorEsquerdo.avancar(200);
  }
  else if (distancia >= 5){
    // Para se a distância estiver entre 5cm e 10cm
    motorDireito.parar();
    motorEsquerdo.parar();
  }
  else {
    // Recua caso a distancia seja menor que 5cm
    motorDireito.recuar(180);
    motorEsquerdo.recuar(180);
  }

  // Espera 50ms antes de tentar outra vez
	delay(50);	
}