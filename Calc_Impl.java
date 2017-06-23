/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc_Impl;

import calc_Inter.Calc_Inter;
//import static calc_Server.Calc_S.standardFile;
import java.io.BufferedReader;
import java.io.FileReader;
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
     * @throws java.rmi.Remote
     * @throws RemoteException
     */
    public Calc_Impl() throws RemoteException{
        
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
    @Override
    public BufferedReader getFilet(String list){
        try{
            BufferedReader br;
            list = "Namensliste_S.txt";
            br = new BufferedReader(new FileReader(list));
            for(String s =br.readLine();s!=null; s=br.readLine()){}
            //System.out.println(liste+" Impl");
            return br;
        } catch (Exception ex) {
            Logger.getLogger(Calc_Impl.class.getName()).log(Level.SEVERE, null, ex);
        }
        return null;
    }

}
