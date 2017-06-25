/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Client;

import java.io.IOException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.AlreadyBoundException;
import java.rmi.RemoteException;
/**
 *
 * @author marc
 */
public class Calc_S {

    /**
     *
     */
    public static final String standardString = "Teststring";

    /**
     *
     */
    public static final String standardFile = "/home/marc/Schreibtisch/vs1-2/Namensliste_S.txt";

    public static void main (String[] args) throws RemoteException, AlreadyBoundException{
 
            try{
                LocateRegistry.createRegistry(Registry.REGISTRY_PORT);
                
                
                Calc_Impl di = new Calc_Impl(standardFile);
                Calc_Inter c;
                c = (Calc_Inter) UnicastRemoteObject.exportObject(di, 0);
                Registry creg = LocateRegistry.getRegistry();
                creg.bind("calc", c);//Server mit Reg wird an Aufruf Calc und di-Objekt gebunden.
                System.out.println("Server ist bereit");
            }catch (IOException ex){
                ex.printStackTrace();
            }
        }
}
