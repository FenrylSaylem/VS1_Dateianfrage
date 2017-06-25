/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Client;

//import static calc_Server.Calc_S.standardString;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 *
 * @author marc
 */
public class Calc_C {
    public static String namenSuchFile = "/home/marc/Schreibtisch/vs1-2/Namensliste_C.txt";

    public static void main (String[]args) throws RemoteException, NotBoundException, FileNotFoundException, IOException{

        try{
            
            Registry creg=LocateRegistry.getRegistry("127.0.0.1");
            Calc_Inter di = (Calc_Inter)creg.lookup("calc");
            System.out.println("Verbindung hergestellt...\n");
            System.out.println(namenSuchFile + "-Start"); 
            String tmp= di.getString(Calc_S.standardFile);
            System.out.println(tmp + "-Start"); 
            FileReader fc=new FileReader(namenSuchFile);
            FileReader fs=new FileReader(tmp);
            BufferedReader bc=new BufferedReader (fc);
            BufferedReader bs=new BufferedReader (fs);
            String cline;cline = null;
            String sline;sline = null;
            //Referenzwerte:
            String[] cdata;cdata = new String[8];//Suchnamen
                cdata[0]="Zeller";
                cdata[1]="Sauer";
                cdata[2]="Regitz";
                cdata[3]="Ernst";
                cdata[4]="Lauer";
                cdata[5]="Brehm";
                cdata[6]="Schneider";
                cdata[7]="Biehl";
            String[][] sdata;sdata = new String[15][2];//Suchnamen
                sdata[0][0]="Michael";
                sdata[1][0]="Marc";
                sdata[2][0]="Christian";
                sdata[3][0]="Kai";
                sdata[4][0]="Jan";
                sdata[5][0]="Thomas";
                sdata[6][0]="Robert";
                sdata[7][0]="Thomas";
                sdata[8][0]="Willi";
                sdata[9][0]="Oliver";
                sdata[10][0]="Thomas";
                sdata[11][0]="Kirsten";
                sdata[12][0]="Sven";
                sdata[13][0]="Achim";
                sdata[14][0]="Thomas";
                sdata[0][1]="Zeller";
                sdata[1][1]="Willms";
                sdata[2][1]="Wolf";
                sdata[3][1]="Schultz";
                sdata[4][1]="Schmutz";
                sdata[5][1]="Winkler";
                sdata[6][1]="Bonacker";
                sdata[7][1]="Sauer";
                sdata[8][1]="Regitz";
                sdata[9][1]="Ernst";
                sdata[10][1]="Lauer";
                sdata[11][1]="Brehm";
                sdata[12][1]="Schneider";
                sdata[13][1]="Biehl";
                sdata[14][1]="Protz";
               //System.out.println(sdata.length+"sd");
               //System.out.println(cdata.length+"cd");
            for (int j=0; j<8;j++){
                int i=0;
                do{
                    if((cdata[j] == null ? (sdata[i][1]) == null : cdata[j].equals(sdata[i][1]))){
                        System.out.println("Treffer bei " + sdata[i][0] + " " + sdata[i][1]);
                    }
                    i++;
                }while(i<15);    
                }
            

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
    
