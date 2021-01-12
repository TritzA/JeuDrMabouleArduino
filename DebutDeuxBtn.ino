int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int btnRouge = 9;
int btnJaune = 10;
int valRouge = 0;
int valJaune = 0;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(btnRouge, INPUT);
  pinMode(btnJaune, INPUT);
}

void loop() {

  while (true) {
    int cmpt = 0;
    valJaune = digitalRead(btnJaune);

    if (valJaune != LOW) {//clic sur jaune debut
      delay(250);
      afficherNb(cmpt);
      valJaune = digitalRead(btnJaune);

      while (valJaune == LOW) {//clique sur jaune fin
        afficherNb(cmpt);
        valRouge = digitalRead(btnRouge);
        
        if (valRouge != LOW) {// compte les rouge
          delay(250);
          cmpt = ((cmpt + 1) % 10);

        }
        valJaune = digitalRead(btnJaune);
      }
    }
    afficherNb(cmpt);
  }
}

void afficherNb(int nb) {
  if (nb == 0) {
    afficherZero();
  }
  if (nb == 1) {
    afficherUn();
  }
  if (nb == 2) {
    afficherDeux();
  }
  if (nb == 3) {
    afficherTrois();
  }
  if (nb == 4) {
    afficherQuatre();
  }
  if (nb == 5) {
    afficherCinq();
  }
  if (nb == 6) {
    afficherSix();
  }
  if (nb == 7) {
    afficherSept();
  }
  if (nb == 8) {
    afficherHuit();
  }
  if (nb == 9) {
    afficherNeuf();
  }
}

void afficherZero() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}


void afficherUn() {
  toutEteindre(2, 8);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
}

void afficherDeux() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(d, HIGH);
}

void afficherTrois() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void afficherQuatre() {
  toutEteindre(2, 8);
  digitalWrite(b, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(c, HIGH);
}

void afficherCinq() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void afficherSix() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void afficherSept() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(b, HIGH);
}

void afficherHuit() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void afficherNeuf() {
  toutEteindre(2, 8);
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void toutEteindre(int min, int max) {
  for (int i = min; i <= max; i++) {
    digitalWrite(i, LOW);
  }
}

void toutAllumer(int min, int max) {
  for (int i = min; i <= max; i++) {
    digitalWrite(i, HIGH);
  }
}
