    unsigned int value[23640];
    int a0;
void setup() {
  Serial.begin(74880);
  ADC->ADC_MR |= 0x80; // these lines set free running mode on adc 7 (pin A0)
  ADC->ADC_CR=2;
  ADC->ADC_CHER=0x80;

      while((ADC->ADC_ISR & 0x80)==0); // wait for conversion
      a0=ADC->ADC_CDR[7];              // read data
      for(int i=0;i<23640;i++)
      value[i]=a0;

      for(int a=0;a<23000;a++)
      Serial.println(value[a]);
}

void loop(){

}
