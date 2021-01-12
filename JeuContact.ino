int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;
int ledEtBuzzer = 12;
int haut = 9;
int bas = 13;

int contact = 10;
int btnJaune = 11;
int valContact = 0;
int valJaune = 0;

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(ledEtBuzzer, OUTPUT);
  pinMode(haut, OUTPUT);
  pinMode(bas, OUTPUT);


  pinMode(contact, INPUT);
  pinMode(btnJaune, INPUT);
}

void loop() {

  int cmpt = 0;
  digitalWrite(haut, HIGH);
  digitalWrite(bas, LOW);

  while (true) {

    afficherNb(cmpt);
    digitalWrite(ledEtBuzzer, LOW);

    valContact = digitalRead(contact);
    valJaune = digitalRead(btnJaune);
    delay(250);

    if (valContact != LOW && cmpt != 2) {
      cmpt++;
      afficherNb(cmpt);
      delay(1000);
      
    } else if (valContact != LOW && cmpt == 2) {
      cmpt++;
      afficherNb(cmpt);

      while (valJaune != HIGH) {
        digitalWrite(ledEtBuzzer, HIGH);
        valJaune = digitalRead(btnJaune);

      }
      cmpt = 0;
    }

    if(valJaune != LOW) {
        digitalWrite(ledEtBuzzer, LOW);
        valJaune = digitalRead(btnJaune);
        cmpt = 0;
      }
      
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
