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

  void setup(int pVel, int pAvancar, int pRecuar){
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
  /**
   *	Porta 6 - velocidade
   *	Porta 5 - avançar
   *	Porta 4 - recuar
   */
  motorDireito.setup(6, 5, 4);

  /**
   *	Porta 10 - velocidade
   *	Porta 9  - avançar
   *	Porta 8  - recuar
   */  	
  motorEsquerdo.setup(10, 9, 8);
}

void loop() {
	// Avancar com os dois motores por 2000 milissegundos
	motorDireito.avancar(200);
	motorEsquerdo.avancar(200);
	delay(2000);

	// Parar os dois motores por 500 milissegundos
	motorDireito.parar();
	motorEsquerdo.parar();
	delay(500);
	
	// Recuar com os dois motores por 2000 milisegundos
	motorDireito.recuar(180);
	motorEsquerdo.recuar(180);
	delay(2000);
	
	// Parar os dois motores por 500 milissegundos
	motorDireito.parar();
	motorEsquerdo.parar();
	delay(500);	
}
