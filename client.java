/**
 * @(#)socket.java
 *
 *
 * @author
 * @version 1.00 2023/9/4
 */

import java.net.*;
import java.io.*;
class client {

    public static void main(String args[])
    {
    	try
    	{
    		Socket o=new Socket("127.0.0.1",2001);
    		DataInputStream din=new DataInputStream(o.getInputStream());
    		DataOutputStream dout=new DataOutputStream(o.getOutputStream());
    		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

    		String str="",str2="";
    		while(!str.equals("stop"))
    		{
    			str=br.readLine();
    			dout.writeUTF(str);
    			dout.flush();
    			str2=din.readUTF();
    			System.out.println("Server says:"+str2);
    		}
    		dout.close();
    		o.close();
    	}
    	catch (Exception e){
    		System.out.println(e);
    	}
    }


}