/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dude;

import static com.sun.org.apache.xalan.internal.xsltc.compiler.util.Type.String;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Dude_C {
    
    /**
     *
     * @param args
     * @throws RemoteException
     * @throws IOException
     */
    public static void main(String[] args) throws RemoteException, IOException{
        try{
            Registry creg=LocateRegistry.getRegistry("127.0.0.1",1099);
            Dude_Interface di=(Dude_Interface)creg.lookup("dude");
            System.out.println("Verbindung hergestellt...\n");
        }catch(Exception ex){
            System.out.println(ex);
        }
        try{
            BufferedReader br=ladeListe("Namensliste_c.txt");
       /*
            FileReader fr;
            fr = new FileReader("Namensliste_C");
            BufferedReader br=new BufferedReader(fr);
            String Namen=br.readLine();*/
        }catch(FileNotFoundException fnfe){
            System.out.println(fnfe);
        }
        //todo: ZähleEinträge von Namen; muss <=10 sein.
        //Wenn ok dann senden und auf antwort warten 
        
    }

    private static BufferedReader ladeListe(String listenName) throws FileNotFoundException{
        BufferedReader liste=null;
        try {
            liste = new BufferedReader(new FileReader(listenName));
        } catch (FileNotFoundException ex) {
            Logger.getLogger(Dude_Imp.class.getName()).log(Level.SEVERE, null, ex);
        }
        return liste;   
        }    
    
    }
