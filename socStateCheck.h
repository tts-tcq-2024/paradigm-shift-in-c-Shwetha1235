int soc_Ok(float soc,int language) {
   if (soc < 20 || soc > 80) {
        printMessage(socMessage[language]);
       return 0; 
   }
   return 1;
}
