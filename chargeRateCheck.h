int charge_Ok(float charge_rate,int language) {
   if (charge_rate > 0.8) {
       printMessage(chargeRateMessage[language]);
       return 0; 
   }
   return 1;
}
