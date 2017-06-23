/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc_Inter;

import java.io.BufferedReader;
import java.io.FileReader;
import java.rmi.Remote;
import java.rmi.RemoteException;

/**
 *
 * @author marc
 */
public interface Calc_Inter extends Remote{

    /**
     *
     * @param n
     * @param m
     * @return
     * @throws java.rmi.RemoteException
     */
    public int add(int n, int m)throws RemoteException;
    public int sub(int n, int m)throws RemoteException;
    public int mul(int n, int m)throws RemoteException;
    public int div(int n, int m)throws RemoteException; 
    public String getString(String liste) throws RemoteException;

    /**
     *
     * @param list
     * @return
     * @throws RemoteException
     */
    public BufferedReader getFilet(String list) throws RemoteException;
}
