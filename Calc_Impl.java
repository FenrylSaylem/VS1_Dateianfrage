/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Impl;

import Calc_Inter.Calc_Inter;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author marc
 */
public class Calc_Impl extends UnicastRemoteObject implements Calc_Inter{    

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
    @Override
    public int add(int n, int m){
        return n+m;
    }

    @Override
    public int sub(int n, int m){
        return n-m;
    }
    @Override
    public int mul(int n, int m){
        return n*m;
    }

    @Override
    public int div(int n, int m){
        try {
            if(m!=0){
                return n/m;
            }
            else{
                throw new Exception ("div0 du HOchs!");
            }} catch (Exception ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
            
        }
        return -1;
    }

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
    @Override
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
           String [][] baecker = null;
           short i=0;
           String [] woerds;
           
           FileReader datei = new FileReader(text);//Fileread- Fileptr
           BufferedReader br =new BufferedReader(datei);//Bufferedread- Stringptr
           do{
               zeilen = br.readLine(); //Zeilenread
               woerds = zeilen.split(" ");//Zeile in Woerter teilen
               baecker[i][0]=woerds[0];//Vornamen ins Array uebernehmen
               baecker[0][i]=woerds[1];//Nachnamen ins Array uebernehmen
           }while(zeilen!=null);// Lese Zeilen bis Sanktnimmerleinstag
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
    @Override
    public String[] leseNamen(String text){
        try {
           //Inits
           
            FileReader datei = new FileReader(text);//Fileread- Fileptr
            BufferedReader br =new BufferedReader(datei);//Bufferedread- Stringptr
            String zeile =br.readLine();
            String[] baecker = zeile.split(" ");
            return baecker;
        }catch (IOException ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        }
        String[] baecker=null;
        return baecker;
    }

    /**
     *
     * @param namen
     * @param liste
     */
    @Override
        public void vergleicheNamen(String[] namen,String[][] liste){
            for (int j=0; j<=namen.length;j++){
                for (int i=0; i<=liste.length;i++){
                    if(namen[j].equals(liste[0][i])){
                        System.out.println("\nTreffer bei "+liste[j][0]+" "+liste[j][1]);
                    }
                }
            }
        }
        
}
    
    
