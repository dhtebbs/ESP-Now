// Hall sensor test

int i;
long h;

void setup()
{
Serial.begin(115200);
}

void loop()
{
h=0;
for(i=0;i<1000;i++)
{
h += hallRead();
delayMicroseconds(100);
}
Serial.print("Hall sensor value: ");
Serial.println((double)h/1000.);
}
