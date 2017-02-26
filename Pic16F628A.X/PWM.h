   void PWM_Init()
{
   PR2 = 0xFF; // 10 bits
   CCP1CONbits.CCP1Y =1;
   CCP1CONbits.CCP1X =1; // Place le CCP2 en PWM
 
   PIR1bits.TMR2IF=0;
   T1CONbits.T1CKPS=11;  //prescaler à 16
   T1CONbits.TMR1ON=1; //T2 On
   
  
}
   
   
   void PWM_Read(int data)
   { int j=data;
     
       CCP1CONbits.CCP1X= j&0x02;
       CCP1CONbits.CCP1Y= j&0x01;
         CCPR1L=j>>2;
       
   
   }