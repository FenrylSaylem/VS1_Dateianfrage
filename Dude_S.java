/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Dude;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

/**
 * @title Dude_Server
 * @author marc
 */
public class Dude_S {
    
    public static void main(String[] args){
        try{
            Registry reg=LocateRegistry.createRegistry(1099);
            Dude_Imp di=new Dude_Imp();
            reg.rebind("dude", di);
            System.out.println("Server ist bereit");
        }catch(Exception ex){
            System.out.println(ex);
        }   
    }
}
