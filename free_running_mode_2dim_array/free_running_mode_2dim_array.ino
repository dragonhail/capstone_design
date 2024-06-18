void setup() {
  int value[3][23460];
  Serial.begin(74880);

  ADC->ADC_MR |= 0x80; // these lines set free running mode on adc 7 (pin A0)
  ADC->ADC_CR=2;
  ADC->ADC_CHER=0x80;

  for(int i=0;i<3;i++){
    for(int j=0;j<23460;j++){
    while((ADC->ADC_ISR & 0x80)==0); // wait for conversion
    int a0=ADC->ADC_CDR[7];              // read data
    value[i][j]=a0;
    }
  }
  
  for(int i=0;i<3;i++){
    for(int j=0;j<23460;j++){
      Serial.println(value[i][j]);
      }
  }
}
void loop(){}
