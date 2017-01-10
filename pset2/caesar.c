/**
 * Caeser cipher: Ci = (Letter + Key) % 26
 * 
 * was soll gemacht werden?
 * 
 * also zuerst wird ein Key und Input vom User durch Commandline interface bekommen
 * dann wird den Text verschlüsselt
 * Falls die Eingabe nicht korrekt war, das Programm soll den Benutzer eine Warnung geben und exit mit 1
 * Anmerkung, Große Buchstaben bleibt groß, kleine bleibt klein
 
 * Fan Sun
 * 19.12.16
 * 
 *
*/
 
 #include <stdio.h>
 #include <cs50.h>
 #include <stdlib.h>
 #include <string.h>
 
 #define CaptL  65
 #define SmallL 97
 
 void caeserCipher(int schluessel);


 int main (int argc, char* argv[])
 {
   //key muss initialisiert werden (line31), ansonsten wird atoi(line36) auf einen Speicher zugreifen, 
   //wo nicht erlaubt ist also Segmetation fault!
   int key = 0; 
   //check ob die Eingabe für den Key erlaubt ist.
   //argc kann mind. gleich 1 sein, da ./caeser wird das Programm zum laufen bringen.
   if ((argc == 2) && (key >= 0))
   { 
    key = atoi(argv[1]);
    caeserCipher(key);
    return 0;
   }
   else
   {
   printf("please enter a key\n");
   return 1;
   }
 }
 

 void caeserCipher(int schluessel)
 {
  string plainT;
  string cipherT;
  
  plainT = GetString();
  cipherT = plainT;
  
//Ci = (Letter + Key) % 26 
  for (int i = 0, n = strlen(plainT); i<n; i++)
  {
   if (plainT[i]>='A' && plainT[i]<= 'Z')
   {
    //Substraktion von CapL und wieder dazu addieren, eliminiert die differzenz zwischen 26 Buchstaben 
    //und die tatsächliche Position der ASCII 
     cipherT[i] = ((plainT[i] - CaptL + schluessel) % (26)) + CaptL;
     printf("%c", cipherT[i]);
   }
   else if(plainT[i] >= 'a' && plainT[i] <= 'z' )
   {
     cipherT[i] = ((plainT[i] - SmallL + schluessel) % (26)) + SmallL;
     printf("%c", cipherT[i]);
   }
   else
   {
     cipherT[i] = plainT[i];
     printf("%c", cipherT[i]);
   }
  }
  printf("\n"); 
 }
 