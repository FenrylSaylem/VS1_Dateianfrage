/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Client;

import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author marc
 */
public interface Calc_Inter extends Remote{

    /**
     *
     */
    //public static String[][] baeckerle;
    
    /**
     *
     * @param n
     * @param m
     * @return
     * @throws java.rmi.RemoteException
     */
    //public Calc_Impl(String quellDatei) throws RemoteException;
    //public int add(int n, int m)throws RemoteException;
    //public int sub(int n, int m)throws RemoteException;
    //public int mul(int n, int m)throws RemoteException;
    //public int div(int n, int m)throws RemoteException; 
    public String getString(String liste) throws RemoteException;
    //public String[] leseNamen(String text) throws RemoteException;
    //public String[][] leseZeilen(String text)throws RemoteException;
    //public void vergleicheNamen(String[] namen,String[][]liste) throws RemoteException;
}