/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dude;

//import java.io.BufferedReader;
import java.io.BufferedReader;
import java.rmi.Remote;
import java.rmi.RemoteException;
//import java.rmi.RemoteException;

/**
 *
 * @author marc
 */

public interface Dude_Interface extends Remote {

    /**
     *
     * @param listenName
     * @return
     * @throws RemoteException
     */
    public BufferedReader ladeListe(String listenName) throws RemoteException ;
    
}
