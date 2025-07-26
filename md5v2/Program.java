import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class Program{ 
      
public static void main (String args[]){
	
    String str = "Hello World";
	StringBuffer sb = new StringBuffer();
	try {    
		java.security.MessageDigest md = java.security.MessageDigest.getInstance("MD5");
		md.update(str.getBytes());
		byte byteData[] = md.digest();
	//convert the byte to hex format	
	for (int i = 0; i < byteData.length; i++) {
		sb.append(Integer.toString((byteData[i] & 0xff) + 0x100, 16).substring(1));
	}
	} catch (NoSuchAlgorithmException e) {
		throw new RuntimeException("MD5 algorithm not found", e);		
	}
	System.out.println(str + "\nmd5: " + sb.toString());
	// -> b10a8db164e0754105b7a99be72e3fe5
}
}
