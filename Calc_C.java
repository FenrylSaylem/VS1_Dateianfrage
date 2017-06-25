/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Client;

import Calc_Inter.Calc_Inter;
import static Calc_Server.Calc_S.standardFile;
//import static calc_Server.Calc_S.standardString;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author marc
 */
public class Calc_C {
    public static String namenSuchFile = "Namensliste_C.txt";

    public static void main (String[]args) throws RemoteException, NotBoundException{

        try{
            
            Registry creg=LocateRegistry.getRegistry("127.0.0.1",1033);
            Calc_Inter di=(Calc_Inter)creg.lookup("calc");
            System.out.println("Verbindung hergestellt...\n");
            String ziel = di.getString(standardFile);
            System.out.println(ziel+"-Ziel");
            System.out.println(namenSuchFile+"-Start");
            vergleicheNamen(leseNamen(namenSuchFile),leseZeilen(ziel));
        }catch (RemoteException | NotBoundException ex){
                ex.printStackTrace();
        }
            //System.out.println("1+1="+di.add(1,1));
            //System.out.println("1-1="+di.sub(1,1));
            //System.out.println("1*1="+di.mul(1,1));
            //System.out.println("1/1="+di.div(1,0));
            //String tmp="";5
            //System.out.println(tmp+" Cl");
    }

}
    
