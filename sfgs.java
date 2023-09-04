import java.net.*;
import java.io.*;
class server {

    public static void main(String args[])
    {
    	try
    	{
    		ServerSocket s=new ServerSocket(2001);
    		Socket so=s.accept();
    		DataInputStream din=new DataInputStream(so.getInputStream());
    		DataOutputStream dout=new DataOutputStream(so.getOutputStream());
    		BufferedReader br= new BufferedReader(new InputStreamReader(System.in));

    		String str="",str2="";
    		while(!str.equals("stop"))
    		{
    			str=din.readUTF();
    			System.out.println("Client says:"+str);
    			str2=br.readLine();
    			dout.writeUTF(str2);
    			dout.flush();
    		}
    		din.close();
    		so.close();
    		s.close();
    	}
    	catch (Exception e){
    		System.out.println(e);
    	}
    }


}