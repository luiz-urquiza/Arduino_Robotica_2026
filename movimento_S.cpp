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
  
  Serial.begin(9600);
}

void loop() {
	// Avancar com os dois motores por 2000 milissegundos
	motorDireito.avancar(220);
	motorEsquerdo.avancar(160);
	delay(2000);

	// Recuar com os dois motores por 2000 milisegundos
	motorDireito.avancar(200);
	motorEsquerdo.avancar(200);
	delay(2000);
	
	// Avancar com os dois motores por 2000 milissegundos
	motorDireito.avancar(160);
	motorEsquerdo.avancar(220);
	delay(2000);

	// Parar os dois motores por 500 milissegundos
	motorDireito.parar();
	motorEsquerdo.parar();
	delay(500);	
}
