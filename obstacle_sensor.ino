const int TRIG_PIN = 9;
const int ECHO_PIN = 10;
const int LED_PIN  = 13;

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // إرسال إشارة الموجات فوق الصوتية
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // حساب زمن عودة الإشارة
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2; // تحويل الزمن لسم

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // المنطق التحكمي لتجنب الخطر
  if (distance < 20) {
    digitalWrite(LED_PIN, HIGH); // تنبيه: عقبة قريبة جداً
  } else {
    digitalWrite(LED_PIN, LOW);  // المسار آمن
  }

  delay(200);
}