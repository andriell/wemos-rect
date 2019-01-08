void ledSetup() {
  pinMode(BUILTIN_LED, OUTPUT);  // initialize onboard LED as output
  delay(10);
}

void ledBlink(int n, unsigned long d) {
  for (int i = 0; i <= n; i++) {
    digitalWrite(BUILTIN_LED, HIGH);  // turn on LED with voltage HIGH
    delay(d);                         // wait
    digitalWrite(BUILTIN_LED, LOW);   // turn off LED with voltage LOW
    delay(d);                         // wait
  }
}

