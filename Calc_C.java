/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calc_Client;

import calc_Inter.Calc_Inter;
import static calc_Server.Calc_S.standardFile;
//import static calc_Server.Calc_S.standardString;
import java.io.BufferedReader;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author marc
 */
public class Calc_C {
    public static void main (String[]args){
        try{
            Registry creg=LocateRegistry.getRegistry("127.0.0.1",1051);
            Calc_Inter di=(Calc_Inter)creg.lookup("calc");
            System.out.println("Verbindung hergestellt...\n");
            //System.out.println("1+1="+di.add(1,1));
            //System.out.println("1-1="+di.sub(1,1));
            //System.out.println("1*1="+di.mul(1,1));
            //System.out.println("1/1="+di.div(1,0));
            //String tmp;
            //tmp = di.getString(standardString);
            BufferedReader br = null;
            br = getFilet(standardFile);
            //System.out.println(tmp+" Cl");
        }catch (RemoteException | NotBoundException ex){
                ex.printStackTrace();
        }
    }
}
    
