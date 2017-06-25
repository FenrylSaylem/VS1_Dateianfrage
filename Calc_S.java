/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Calc_Server;

import Calc_Impl.Calc_Impl;
import java.io.IOException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

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
    public static final String standardFile = "Namensliste_S.txt";

    public static void main (String[] args){
 
            try{
                Registry creg=LocateRegistry.createRegistry(1033);
                Calc_Impl di=new Calc_Impl(standardFile);
                creg.rebind("calc", di);//Server mit Reg wird an Aufruf Calc und di-Objekt gebunden.
                System.out.println("Server ist bereit");
            }catch (IOException ex){
                ex.printStackTrace();
            }catch (Exception ex){
                ex.printStackTrace();
            }
        }
}
