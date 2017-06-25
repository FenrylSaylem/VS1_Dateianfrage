/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Client;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.Serializable;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.ArrayList;
/**
 *
 * @author marc
 */
public class Calc_Impl implements Calc_Inter, Serializable{    
    
        public static void main (String[]args){ //throws RemoteException, NotBoundException, FileNotFoundException, IOException{
        }
    /**
     *
     */
    public static String[][] baeckerle;
    
    /**
     *
     * @param quellDatei
     * @throws RemoteException
     */
    
    public Calc_Impl(String quellDatei) throws RemoteException{
        String[][] array;
        array = leseZeilen(quellDatei);
        Calc_Impl.baeckerle=array;
    }

    /**
     *
     * @param n
     * @param m
     * @return
     */
    //@Override
    //public int add(int n, int m){
    //    return n+m;
    //}

    //@Override
    //public int sub(int n, int m){
    //    return n-m;
    //}
    //@Override
    //public int mul(int n, int m){
    //    return n*m;
    //}

    //@Override
    //public int div(int n, int m){
    //    try {
    //        if(m!=0){
    //            return n/m;
    //        }
    //        else{
    //            throw new Exception ("div0 du HOchs!");
    //        }} catch (Exception ex) {
    //        Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
            
    //    }
    //    return -1;
   // }

    /**
     *
     * @param liste
     * @return
     */
    @Override
    public String getString(String liste){
        try{
            //System.out.println(liste+" Impl");
            return liste;
        } catch (Exception ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        }
        return "";
    }

    /** 
     *
     * @param text
     * @return 
     */
    public String[][] leseZeilen(String text){
    /*    try {
           FileReader datei = new FileReader(text);
           BufferedReader br =new BufferedReader(datei);
           String zeilen=br.readLine();
           short i=0;
           while(zeilen!=null){
               String[] parts= zeilen.split(" ");
               Calc_Impl Liste = new Calc_Impl(parts[0],parts[1],i);
               i++;
           }
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        }*/
        try {
           //Inits
           String zeilen;
           String [][] baecker = new String[200][200];
           short i=0;
           String [] woerds;
           System.out.println("Dateiname: " + text);
           FileReader datei = new FileReader(text);//Fileread- Fileptr
           BufferedReader br =new BufferedReader(datei);//Bufferedread- Stringptr
           while((zeilen = br.readLine()) != null){
               System.out.println("Counter: " + i);
               //Zeilenread
               woerds = zeilen.split(" ");//Zeile in Woerter teilen
               baecker[i][0]=woerds[0];//Vornamen ins Array uebernehmen
               baecker[0][i]=woerds[1];//Nachnamen ins Array uebernehmen
               i++;
           }// Lese Zeilen bis Sanktnimmerleinstag
           return baecker;
           } catch (IOException ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        }
        String [][] baecker = null;
        return baecker;
    }

    /**
     *
     * @param text
     * @return
     */
 //   @Override
  //  public String[] leseNamen(String text){
    //    try {
           //Inits
      //      String[] baecker = new String[200];
        //    FileReader datei = new FileReader(text);//Fileread- Fileptr
          //  BufferedReader br =new BufferedReader(datei);//Bufferedread- Stringptr
           // String zeile =br.readLine();
           // baecker = zeile.split(" ");
           // return baecker;
      //  }catch (IOException ex) {
      //      Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
      //  }
      //  String[] baecker=null;
      //  return baecker;
   // }

    /**
     *
     * @param namen
     * @param liste
     */
    //@Override
      //  public void vergleicheNamen(String[] namen,String[][] liste){
        //    for (int j=0; j<=namen.length;j++){
          //      for (int i=0; i<=liste.length;i++){
            //        if(namen[j].equals(liste[0][i])){
              //          System.out.println("\nTreffer bei "+liste[j][0]+" "+liste[j][1]);
              //      }
               // }
           // }
       // }
        
}
    
    
