    unsigned int value[10000];
    int i, a = 0;
    long a0;
void setup() {   

  Serial.begin(74880);
  
  ADC->ADC_MR |= 0x80; // these lines set free running mode on adc 7 (pin A0)
  ADC->ADC_CR=2;
  ADC->ADC_CHER=0x80;

  while(i<10000){
  while((ADC->ADC_ISR & 0x80)==0);// wait for conversion
  a0=ADC->ADC_CDR[7];              // read data
  value[i]=a0;
  Serial.println(value[i]);
  i++;
   }
}
void loop() {
}
